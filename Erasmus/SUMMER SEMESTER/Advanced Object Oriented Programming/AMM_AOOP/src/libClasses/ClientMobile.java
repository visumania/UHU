package libClasses;

public class ClientMobile extends Client
{
	private Date permanenceDate;
	private float minutesSpoken;
	private float minutePrice;
	
	public ClientMobile(String pNif, String pName, Date pDateBirth, Date pDischargeDate, Date pPermanenceDate, float pMinutesSpoken, float pMinutePrice)
	{
		//Client Attributes:
		super(pNif, pName, pDateBirth, pDischargeDate);
		
		//ClientMobile Attributes:
		this.permanenceDate = pPermanenceDate;
		this.minutesSpoken = pMinutesSpoken;
		this.minutePrice = pMinutePrice;
	}
	
	public ClientMobile(String pNif, String pName, Date pDateBirth, float pMinutesSpoken, float pMinutePrice)
	{
		//Client Attributes:
		super(pNif, pName, pDateBirth);
		
		//ClientMobile Attributes:
		this.minutesSpoken = pMinutesSpoken;
		this.minutePrice = pMinutePrice;
		this.permanenceDate = new Date(1,1,2019);
	}
	
	public ClientMobile(ClientMobile pClientMobile)
	{
		super(pClientMobile);
		
		this.permanenceDate = pClientMobile.permanenceDate;
		this.minutesSpoken = pClientMobile.minutesSpoken;
		this.minutePrice = pClientMobile.minutePrice;
	}
	
	public Date getPermanenceDate()
	{
		Date aux = new Date(permanenceDate);
		
		return aux;
	}
	
	public float getMinutesSpoken()
	{
		return this.minutesSpoken;
	}
	
	public float getMinutePrice()
	{
		return this.minutePrice;
	}
	
	public void setPermanenceDate(Date pPermanenceDate)
	{
		this.permanenceDate = new Date(pPermanenceDate);
	}
	
	public void setMinutePrice(float pMinutePrice)
	{
		this.minutePrice = pMinutePrice;
	}
	
	@Override
	public Object clone()
	{
		return new ClientMobile(this);
	}
	
	@Override
	public boolean equals(Object obj)
	{
		if(this == obj) return true;
		if(obj == null) return false;
		
		if(getClass() != obj.getClass())
			return false;
		
		ClientMobile c = (ClientMobile)obj;
		
		return(this.getNif().equals(c.getNif()));
	}
	
	@Override
	public String toString()
	{
		return super.toString() + " " + this.permanenceDate + " " + this.minutesSpoken + " x " + this.minutePrice + " --> " + this.minutesSpoken*this.minutePrice;
	}
	
	public float bill()
	{
		return this.getMinutesSpoken()*this.getMinutePrice();
	}
}
