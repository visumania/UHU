package libClases;

public class ContratoMovilNavega extends ClienteMovil
{
	static private float precioMega = 0.01f; 
	private float megasConsumidos; 
	
	public ContratoMovilNavega(String pNif , String pNombre , Fecha pFechaNac , Fecha pFechaAlta , Fecha pFechaPermanencia , float pMinutosHablados , float pPrecioMinuto , float pMegasConsumidos)
	{
		super( pNif ,  pNombre ,  pFechaNac ,  pFechaAlta ,  pFechaPermanencia ,  pMinutosHablados ,  pPrecioMinuto);
		
		this.megasConsumidos = pMegasConsumidos; 
	}
	
	public ContratoMovilNavega(String pNif , String pNombre , Fecha pFechaNac , float pMinutosHablados , float pPrecioMinuto , float pMegasConsumidos)
	{
		super( pNif ,  pNombre ,  pFechaNac ,  pMinutosHablados ,  pPrecioMinuto);
		
		this.megasConsumidos = pMegasConsumidos; 
	}
	
	public ContratoMovilNavega(ContratoMovilNavega cmv)
	{
		super(cmv);
		
		this.megasConsumidos = cmv.megasConsumidos;
	}
	
	static public void setPrecioMega(float pPrecioMega)
	{
		precioMega = pPrecioMega; 
	}
	
	public float factura()
	{
		return super.factura() + this.megasConsumidos*precioMega;
	}
	
	public String toString()
	{
		return super.toString() + "+" + this.megasConsumidos + "x" + precioMega + "-->" + this.factura();
	}
}
