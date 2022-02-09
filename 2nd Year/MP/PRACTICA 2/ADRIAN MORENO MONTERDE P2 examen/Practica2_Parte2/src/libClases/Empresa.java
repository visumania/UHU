package libClases;

import java.util.Scanner;;

public class Empresa implements Cloneable{

	private Cliente V[];
	private int nClientes;
	private int nmaxClientes;
	
	/*Creamos un metodo que nos devuelve la posicion de un DNI
	 * de esta forma nos aseguramos de buscar el DNI llamando a un metodo*/
	private int buscarDNI(String dni) 
	{
		for(int i=0 ; i<this.getN() ; i++) 
		{
			if(this.V[i].getNif().equals(dni))
				return i;
		}
		return -1;
	}
	
	public Empresa() 
	{
		this.nClientes = 0; 
		this.nmaxClientes = 20; 
		this.V = new Cliente[this.nmaxClientes];
	}
	
	public Empresa(Empresa E)
	{
		this.nClientes= E.getN();
		this.nmaxClientes = E.getMaxClientes();
		this.V = new Cliente[this.getMaxClientes()];
		
		for(int i=0; i<E.getN(); i++)
		{
			if(E.V[i].getClass() == ClienteTarifaPlana.class)
				this.alta((ClienteMovil)this.V[i].clone());
			else
				this.alta((ClienteMovil)E.V[i].clone());
		}
	}
	
	public int getMaxClientes() {return this.nmaxClientes;}
	public int getN() {return this.nClientes;}
	
	public void alta()
	{
		@SuppressWarnings("resource")
		Scanner leerAlta = new Scanner(System.in);
		System.out.println("DNI: ");
		String dni = leerAlta.nextLine();
		
		if(this.buscarDNI(dni) == -1)
		{
			System.out.println("Nombre: "); String nombre = leerAlta.nextLine();
			System.out.println("Fecha Nacimiento: "); Fecha fNac = Fecha.pedirFecha();
			System.out.println("Fecha de Alta: "); Fecha fAlta = Fecha.pedirFecha();
			System.out.println("Minutos que habla al mes: "); float mHab = leerAlta.nextFloat();
			System.out.println("Indique tipo de cliente (1-Movil, 2-Tarifa Plana): "); int tipo = leerAlta.nextInt();
			
			if(tipo == 1)
			{
				System.out.println("Precio por minuto: "); float pMin = leerAlta.nextFloat();
				System.out.println("Fecha fin permanencia: "); Fecha fPer = new Fecha(Fecha.pedirFecha());
				Cliente c = new ClienteMovil(dni, nombre, fNac, fAlta, fPer, mHab, pMin);
				this.alta(c);
			}
			else
				if(tipo == 2)
				{
					//aqui pedimos los datos de un ClienteTarifaPlana
				}
		}
		else
		{
			System.out.println("Ya existe un Cliente con ese dni: "); this.V[this.buscarDNI(dni)].ver();
		}
	}
	
	public void alta(Cliente c)
	{
		if(this.buscarDNI(c.getNif()) == -1)
		{
			if(this.getN() == this.getMaxClientes())
			{
				this.nmaxClientes = this.nmaxClientes*2;
				Cliente [] aux = new Cliente[this.getMaxClientes()];
				
				for(int i=0;i<this.getN();i++)
				{
					aux[i] = this.V[i];
				}
				
				this.V = new Cliente[this.nmaxClientes];
				
				for(int j=0;j<this.getN();j++)
					this.V[j]= aux[j];
			}
			
			V[this.getN()] = c;
			this.nClientes++;
		}
	}

	public void baja()
	{
		@SuppressWarnings("resource")
		Scanner leerBaja = new Scanner(System.in);
		
		System.out.println("Introduzca nif cliente a dar de baja: ");
		String dni = leerBaja.nextLine();
		
		if(this.buscarDNI(dni)!=-1)
		{
			this.V[this.buscarDNI(dni)].ver();
			
			System.out.println("¿Seguro que desea eliminarlo (s/n)? ");
			String op = leerBaja.next();
			
			if(op.equals("s"))
			{
				System.out.println("El cliente " + this.V[this.buscarDNI(dni)].getNombre()+" con nif "+dni+" ha sido eliminado");
				this.baja(dni);
			}
			if(op.equals("n"))
				System.out.println("El cliente con nif " + dni + " no se elimina");	
		}
		else
			System.out.println("No se ha encontrado a ningun cliente con ese dni para eliminar");
	}
	
	public void baja(String dni)
	{
		for(int i=0;i<this.getN();i++)
		{
			if(this.V[i].getNif().equals(dni))
			{
				for(int j=i;j<this.getN();j++)
				{
					this.V[j] = this.V[j+1];
				}
				
				this.nClientes--;
			}
		}
	}

	public String toString()
	{
		String salida = "";
		
		for(int i=0; i<this.nClientes; i++)
		{
			if(this.V[i] instanceof ClienteMovil)
				salida += ((ClienteMovil)this.V[i]).toString();
			else
				salida += ((ClienteTarifaPlana)this.V[i]).toString();
			
			salida += "\n";
		}
		
		return salida;
	}
	
	public float factura()
	{
		float res =0;
		for(int i=0;i<this.getN();i++)
		{
			if(this.V[i].getClass() == ClienteMovil.class)
				res = res + ((ClienteMovil)this.V[i]).factura();
			else
				res = res + ((ClienteTarifaPlana)this.V[i]).factura();	
		}
		return res;
	}
	
	public void descuento(float desc)
	{
		for(int i=0;i<this.getN();i++)
		{
			if(this.V[i].getClass() == ClienteMovil.class)
				((ClienteMovil)this.V[i]).setPrecioMinuto(((ClienteMovil)this.V[i]).getPrecioMinuto()*(1-(desc/100)));//(((ClienteMovil)this.V[i]).factura()*(1-(desc/100)));
		}
	}
	
	public int nClienteMovil()
	{
		int cont=0;
		for(int i=0;i<this.getN();i++)
		{
			if(this.V[i] instanceof ClienteMovil)
				cont++;
		}
		
		return cont;
	}
	
	public Object clone()
	{
		Empresa obj = new Empresa();
		for(int i=0;i<this.getN();i++)
		{
			if(this.V[i].getClass() == ClienteMovil.class)
				obj.alta((ClienteMovil)this.V[i].clone());
			else
				obj.alta((ClienteTarifaPlana)this.V[i].clone());
		}
		
		return (Object)obj;
	}
	
	public float ganancia(Fecha fInicio , Fecha fFinal)//Comparamos fechasDeAltas
	{
		
		float gnc = 0.00f; 
		
		for(int i=0 ; i<this.getN() ; i++)
		{
			if(Fecha.mayor(V[i].getFechaAlta(), fInicio) && Fecha.mayor(fFinal, V[i].getFechaAlta()))
			{
				System.out.println(V[i] + "\n");
				
				if(this.V[i].getClass() == ClienteMovil.class)
					gnc = gnc + ((ClienteMovil)this.V[i]).factura();
				else
					gnc = gnc + ((ClienteTarifaPlana)this.V[i]).factura();	
			}
		}
		
		System.out.print("Ganancia: " + gnc);
		
		return gnc;
	}
	
	public void robarClientesTarifaPlana(Empresa e)
	{
		for(int i=0 ; i<this.getN() ; i++)
		{
			if(V[i] instanceof ClienteTarifaPlana)
			{
				e.alta(this.V[i]);
			}
		}
	}
}

