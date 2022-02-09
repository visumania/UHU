package libClases;

import libClases.*;

public class ClienteMovil extends Cliente
{
	private Fecha fechaPermanencia; 
	private float minutosHablados; 
	private float precioMinuto; 
	static private float precioContratoMovil; 
	static private float excesoLimiteMinutos;
	
	public ClienteMovil(String pNif , String pNombre , Fecha pFechaNac , Fecha pFechaAlta , Fecha pFechaPermanencia , float pMinutosHablados , float pPrecioMinuto)
	{
		//Atributos de Cliente:
		super(pNif, pNombre, pFechaNac, pFechaAlta);
		
		//Atributos de ClienteMovil:
		this.fechaPermanencia = pFechaPermanencia; 
		this.minutosHablados = pMinutosHablados; 
		this.precioMinuto = pPrecioMinuto; 
	}
	
	public ClienteMovil(String pNif , String pNombre , Fecha pFechaNac , float pMinutosHablados , float pPrecioMinuto)
	{
		//Atributos de Cliente:
		super(pNif, pNombre, pFechaNac);
		
		//Atributos de ClienteMovil:
		this.minutosHablados = pMinutosHablados; 
		this.precioMinuto = pPrecioMinuto; 
		this.fechaPermanencia = getFechaPorDefecto();
	}
	
	public ClienteMovil(ClienteMovil pClienteMovil)
	{
		super(pClienteMovil);

		this.fechaPermanencia = pClienteMovil.fechaPermanencia; 
		this.minutosHablados = pClienteMovil.minutosHablados; 
		this.precioMinuto = pClienteMovil.precioMinuto; 
	}
	
	
	public Fecha getFPermanencia()
	{
		Fecha aux = new Fecha(fechaPermanencia);
		return aux;
	}
	
	public void setFPermanencia(Fecha pFechaPermanencia)
	{
		this.fechaPermanencia = new Fecha(pFechaPermanencia);
	}
	
	public Object clone()
	{
		return new ClienteMovil(this);
	}
	
	public boolean equals(Object obj) //true si son iguales
	{
		if(this == obj) return true; //Si apuntan al mismo sitio son iguales
		if(obj == null) return false; 
		
		if(getClass() != obj.getClass())
			return false; 
		
		ClienteMovil c = (ClienteMovil)obj; 
		
		return(this.getNif().equals(c.getNif()));
	}
	
	public String toString()
	{
		return super.toString() + " " + this.fechaPermanencia + " " + this.minutosHablados + " x " +  this.precioMinuto + " --> " + this.minutosHablados*this.precioMinuto;
	}
}
