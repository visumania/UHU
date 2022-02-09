package libClases;

import libClases.*;

public class ClienteTarifaPlana extends Cliente
{
	//Atributos de la clase ClienteTarifaPlana
	static private float precioTP = 20.00f;
	static private float precioExcesoMinutos = 0.15f; // Este precio es constante para todos los clientes
	static private float limiteMinutos = 300.00f ; 
	private float minutosHablados;
	private String nacionalidad; 
	
	
	//Métodos de la clase ClienteTarifaPlana:
	public ClienteTarifaPlana(String pNif, String pNombre , Fecha pFechaNac , Fecha pFechaAlta, float pMinutosHablados, String pNacionalidad)
	{
		// Atributos de Cliente
		super(pNif, pNombre, pFechaNac, pFechaAlta); // Valores que pasan al constructor de Cliente (padre)
		
		// Atributos de ClienteTarifaPlana
		this.minutosHablados = pMinutosHablados;
		this.nacionalidad = pNacionalidad;
	}
	
	public ClienteTarifaPlana(String pNif, String pNombre , Fecha pFechaNac, float pMinutosHablados, String pNacionalidad)
	{
		// Atributos de Cliente
		super(pNif, pNombre, pFechaNac); // Valores que pasan al constructor de Cliente (padre)
		
		// Atributos de ClienteTarifaPlana
		this.minutosHablados = pMinutosHablados;
		this.nacionalidad = pNacionalidad;
	}
	
	public ClienteTarifaPlana(ClienteTarifaPlana pClienteTarifaPlana)
	{
		super(pClienteTarifaPlana);
		
		this.minutosHablados = pClienteTarifaPlana.minutosHablados;
		this.nacionalidad = pClienteTarifaPlana.nacionalidad;
	}
	
	public void setNacionalidad(String pNacionalidad)
	{
		this.nacionalidad = pNacionalidad; 
	}
	
	public void setMinutos(float pMinutosHablados)
	{
		this.minutosHablados = pMinutosHablados; 
	}
	
	static public void setTarifa(float pLimiteMinutos , float pPrecioTP)
	{
		limiteMinutos = pLimiteMinutos; 
		precioTP = pPrecioTP;
	}
	
	
	static public float getLimite()
	{
		return limiteMinutos; 
	}
	
	static public float getPrecioExcesoMinutos()
	{
		return precioExcesoMinutos;
	}
	
	static public float getTarifa()
	{
		return precioExcesoMinutos ; 
	}
	
	public Object clone()
	{
		return new ClienteTarifaPlana(this);
	}
	
	public boolean equals(Object obj) //true si son iguales
	{
		if(this == obj) return true; //Si apuntan al mismo sitio son iguales
		if(obj == null) return false; 
		
		if(getClass() != obj.getClass())
			return false; 
		
		ClienteTarifaPlana c = (ClienteTarifaPlana)obj; 
		
		if(obj instanceof ClienteTarifaPlana)
			return true; 
		
			return(this.getNif().equals(c.getNif()));
	}
	
	public String toString()
	{
		float extra = this.precioTP;
		
		if(this.minutosHablados > ClienteTarifaPlana.limiteMinutos)
			extra += (this.minutosHablados-getLimite())*getPrecioExcesoMinutos();
		
		return super.toString() + " " + this.nacionalidad + " [" + ClienteTarifaPlana.limiteMinutos + " por " + this.precioTP + "] " + this.minutosHablados + " --> " + extra; 	
	}
}
