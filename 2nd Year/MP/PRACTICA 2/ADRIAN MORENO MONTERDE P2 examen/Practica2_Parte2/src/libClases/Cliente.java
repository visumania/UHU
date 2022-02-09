package libClases;

import libClases.Fecha; 

public class Cliente implements Cloneable , Proceso
{
	private final String nif; //dni del cliente (letra incluida) (NO puede cambiar)
	private final int codCliente; //código unico (y fijo) generado por la aplicación
	private String nombre; //nombre completo del cliente (si se puede modificar)
	private final Fecha fechaNac; // fecha de nacimiento del cliente (no se puede modificar)
	private Fecha fechaAlta; // fecha de alta del cliente(SI se puede modificar)
	static private int contador = 1;
	static private Fecha fechaPorDefecto = new Fecha(1, 1, 2018);
	
	//Constructores de la clase Cliente: 
	public Cliente(String pNif, String pNombre , Fecha pFechaNac , Fecha pFechaAlta)
	{
		this.codCliente = contador++;
		this.nif = pNif;
		this.setNombre(pNombre);
		this.fechaNac = pFechaNac;
		this.fechaAlta = pFechaAlta;
	}
	
	public Cliente(String pNif , String pNombre , Fecha pFechaNac)
	{
		this.codCliente = contador++;
		this.nif = pNif; 
		this.nombre = pNombre; 
		this.fechaNac = pFechaNac;
		this.fechaAlta = fechaPorDefecto;
	}
	
	public Cliente(Cliente pCliente)
	{
		this.codCliente = contador++;
		this.nif = pCliente.getNif();
		this.nombre = pCliente.getNombre();
		this.fechaNac = pCliente.getFechaNac();
		this.fechaAlta = pCliente.getFechaAlta();
	}
	
	public String toString() //devuelve una cadena con la informacion del cliente (este metodo es como la sobrecarga del ostream<< en c++)
	{
		String pantalla = this.nif + " " + this.fechaNac.toString() + ": " + this.nombre + " (" + this.codCliente + " - " + this.fechaAlta.toString() + ")";
		
		return pantalla;
	}
	
	public String getNombre()
	{
		return this.nombre;
	}
	
	public void setNombre(String pNombre)
	{
		this.nombre = pNombre; 
	}
	
	public static Fecha getFechaPorDefecto()
	{
		Fecha aux = new Fecha(Cliente.fechaPorDefecto); 
		
		return aux;
	}
	
	static public void setFechaPorDefecto(Fecha pFechaAlta)
	{
		fechaPorDefecto = new Fecha(pFechaAlta);
	}
	
	public String getNif()
	{
		return this.nif;
	}

	public void ver()
	{
		System.out.println(this.toString());
	}
	
	public void setFechaAlta(Fecha pFechaAlta)
	{
		this.fechaAlta = new Fecha(pFechaAlta); 
	}
	
	public Fecha getFechaAlta()
	{
		Fecha aux = new Fecha(this.fechaAlta);
		
		return aux; 
	}
	
	public Fecha getFechaNac()
	{
		Fecha aux = new Fecha(this.fechaNac);
		
		return aux; 
	}
	
	public int getCodCliente()
	{
		return this.codCliente;
	}
	
	public Object clone()
	{
		return new Cliente(this);
	}
	
	public boolean equals(Object obj) //true si son iguales
	{
		if(this == obj) return true; //Si apuntan al mismo sitio son iguales
		if(obj == null) return false; 
		
		if(getClass() != obj.getClass())
			return false; 
		
		Cliente c = (Cliente)obj; 
		
		return(nif.equals(c.nif));
	}
	
	static public void mayorQue(Cliente pCliente1 , Cliente pCliente2)
	{
		Fecha FCliente1 = new Fecha(pCliente1.getFechaAlta().getDia(), pCliente1.getFechaAlta().getMes(), pCliente1.getFechaAlta().getAnio());
		Fecha FCliente2 = new Fecha(pCliente2.getFechaAlta().getDia(), pCliente2.getFechaAlta().getMes(), pCliente2.getFechaAlta().getAnio());
		
		if(Fecha.mayor(FCliente1 , FCliente2))
			System.out.println("\nLa Fecha de alta del Cliente: " + pCliente1 + "\nes mayor que la del cliente \n" + pCliente2);
		else
			System.out.println("\nLa Fecha de alta del Cliente: " + pCliente2 + "\nes mayor que la del cliente \n" + pCliente1);
	}
	
}
