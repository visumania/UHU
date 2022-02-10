package libClasses;

public class ClientFlatRate extends Client
{
	//Attributes of ClientFlatRate class
	static private float priceFR = 20.00f;
	static private float priceExcessMinutes = 0.15f; //This price is constant for all the clients
	static private float minuteLimit = 300.00f;
	private float minutesSpoken;
	private String nationality;
	
	//Methods of ClientFlatRate class:
	public ClientFlatRate(String pNif, String pName, Date pDateBirth, Date pDischargeDate, float pMinutesSpoken, String pNationality)
	{
		//Client Attributes
		super(pNif, pName, pDateBirth, pDischargeDate); //Values that go to the Client constructor (Dad)
		
		//ClientFlatRate Attributes
		this.minutesSpoken = pMinutesSpoken;
		this.nationality = pNationality;
	}
	
	public ClientFlatRate(String pNif, String pName, Date pDateBirth, float pMinutesSpoken, String pNationality)
	{
		//Client Attributes
		super(pNif, pName, pDateBirth);
		
		//ClientFlatRate Attributes
		this.minutesSpoken = pMinutesSpoken;
		this.nationality = pNationality;
	}
	
	public ClientFlatRate(ClientFlatRate pClientFlatRate)
	{
		super(pClientFlatRate);
		
		this.minutesSpoken = pClientFlatRate.minutesSpoken;
		this.nationality = pClientFlatRate.nationality;
	}
	
	public void setNationality(String pNationality)
	{
		this.nationality = pNationality;
	}
	
	public void setMinutes(float pMinutesSpoken)
	{
		this.minutesSpoken = pMinutesSpoken;
	}
	
	static public void setRate(float pMinuteLimit, float pPriceFR)
	{
		minuteLimit = pMinuteLimit;
		priceFR = pPriceFR;
	}
	
	static public float getPriceFR()
	{
		return priceFR;
	}
	
	static public float getLimit()
	{
		return minuteLimit;
	}
	
	static public float getPriceExcessMinutes()
	{
		return priceExcessMinutes;
	}
	
	static public float getRate()
	{
		return priceExcessMinutes;
	}
	
	public float getMinutesSpoken()
	{
		return this.minutesSpoken;
	}
	
	@Override
	public Object clone()
	{
		return new ClientFlatRate(this);
	}
	
	@Override
	public boolean equals(Object obj) //true if they are equals
	{
		if(this == obj) return true;
		if(obj == null) return false;
		
		if(getClass() != obj.getClass())
			return false;
		
		ClientFlatRate c = (ClientFlatRate)obj;
		
		if(obj instanceof ClientFlatRate)
			return true;
		
		return(this.getNif().equals(c.getNif()));
	}
	
	@Override
	public String toString()
	{
		float extra = this.priceFR;
		
		if(this.minutesSpoken > ClientFlatRate.minuteLimit)
			extra += (this.minutesSpoken-getLimit())*getPriceExcessMinutes();
		
		return super.toString() + " " + this.nationality + " [" + ClientFlatRate.minuteLimit + " for " + this.priceFR + "] " + this.minutesSpoken + " --> " + extra;
	}
	
	public float bill()
	{
		if(this.minutesSpoken > ClientFlatRate.getLimit())
			return ClientFlatRate.priceFR+(this.minutesSpoken-ClientFlatRate.getLimit())*ClientFlatRate.getPriceExcessMinutes();
		else
			return ClientFlatRate.priceFR;
	}
}
