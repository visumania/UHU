package libClases;

import java.util.Scanner;


public final class Fecha implements Cloneable, Proceso
{
	//Atributos de la clase Fecha:
	private int dia;
	private int mes;
	private int anio; 
	
	//Métodos de la clase Fecha: 
	public Fecha(int pDia, int pMes , int pAnio)//Constructor de la clase Fecha
	{
		setFecha(pDia , pMes , pAnio);
	}
	
	public Fecha(Fecha pFecha)
	{
		this.dia = pFecha.dia; 
		this.mes = pFecha.mes; 
		this.anio = pFecha.anio;
	}
	
	public void setFecha(int pDia, int pMes , int pAnio)
	{
		int dmax, diaMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
		this.anio = pAnio; //VIP debo asignar año para llamar a bisiesto() tengo el año bien
		
		if(pMes<1)//si el mes es incorrecto (Menor que 1)
			pMes = 1;
		else if(pMes>12) // si el mes es incorrecto (mayor que 12)
				pMes=12; 

		dmax = diaMes[pMes-1];
		
		if(pMes==2 && bisiesto())
			dmax++;
		
		if(pDia>dmax)
			pDia = dmax; 
		else if (pDia<1)
			pDia = 1; 
		
		this.dia = pDia; 
		this.mes = pMes; 
	}
	
	public static Fecha  pedirFecha()
	{
		Fecha fecha = null; 
		boolean valida = false; 
		Scanner sc = new Scanner(System.in);
		int pDia, pMes, pAnio; 
		
		do
		{
			System.out.println("Introduce la Fecha (dd/mm/aaaa): ");
			String cadena = sc.next();
			String[] tokens = cadena.split("/");
			
			try
			{
				if(tokens.length !=3)
					throw new NumberFormatException();
				
				pDia = Integer.parseInt(tokens[0]); // parseInt lanza una excepcion
				pMes = Integer.parseInt(tokens[1]); // NumberFormatException si no 
				pAnio = Integer.parseInt(tokens[2]); // puede convertir el String a int
				
				fecha = new Fecha(pDia, pMes , pAnio);
				
				if(fecha.getDia() != pDia || fecha.getMes() != pMes)
					throw new NumberFormatException();
				
				valida = true; 
			}catch(NumberFormatException e) {System.out.println("Fecha no valida");}
		}while(!valida);
		
		sc.close();
		
		return fecha; 
	}
	
	final public int getDia(){return this.dia;}
	
	final public int getMes(){return this.mes;}
	
	final public int getAnio(){return this.anio;}
	
	final public boolean bisiesto()  {return(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));}
	
	static public boolean mayor(Fecha f1, Fecha f2)
	{
		if(f1.getAnio()*1000 + f1.getMes()*100 + f1.getDia() > f2.getAnio()*1000 + f2.getMes()*100 + f2.getDia())
			return true; 
		else
			return false; 
	}
	
	public void ver()
	{
		System.out.println(this);
	}
	
	public String toString()
	{
		return String.format("%02d/%02d/%02d", this.dia , this.mes , this.anio);
	}
	
	public Object clone()
	{
		return new Fecha(this);
	}
	
	public boolean equals(Object obj) //true si son iguales
	{
		if(this == obj) return true; //Si apuntan al mismo sitio son iguales
		if(obj == null) return false; 
		
		if(getClass() != obj.getClass())
			return false; 
		
		Fecha c = (Fecha)obj; 
		
		return(dia==c.dia && mes==c.mes && anio==c.anio);
	}
	
	public Fecha diaSig() //Esto es como una sobrecarga del operador++ 
	{
		int pDia , pMes , pAnio; 
		
		
		Fecha aux = new Fecha(this);
		pDia = aux.getDia();
		pMes = aux.getMes();
		pAnio = aux.getAnio();
		int DiasMax[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
		
		if(aux.bisiesto())
			DiasMax[2] = 29; 
		
		if(pDia>DiasMax[aux.getMes()])
		{
			pDia = 1;
			pMes++;
			if(pMes>12)
			{
				pMes = 1; 
				pAnio++;
			}
		}
		else
		{
			pDia++;
		}
		
		aux.setFecha(pDia, pMes, pAnio);
		
		return aux; 
	}
	
}