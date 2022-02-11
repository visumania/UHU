public class Address 
{
	private String contactName; 
	private String street;
	private String city;
	private String postalCode; 
	
	public Address(String contactName, String street, String city, String postalCode)
	{
		this.contactName = contactName; 
		this.street = street;
		this.city = city;
		this.postalCode = postalCode;
	}
	
	//Getter methods
	
	public String getContactName()
	{
		return this.contactName;
	}
	
	public String getStreet()
	{
		return this.street;
	}
	
	public String getCity()
	{
		return this.city;
	}
	
	public String getPostalCode()
	{
		return this.postalCode;
	}
	
	public Address getAddress()
	{
		return this; 
	}
	
	//Setter methods
	
	public void setContactName(String contactName)
	{
		this.contactName = contactName;
	}
	
	public void setStreet(String street)
	{
		this.street = street;
	}
	
	public void setCity(String city)
	{
		this.city = city; 
	}
	
	public void setPostalCode(String postalCode)
	{
		this.postalCode = postalCode;
	}
	
	public void setAddress(Address address)
	{
		this.contactName = address.contactName;
		this.street = address.street;
		this.city = address.city;
		this.postalCode = address.postalCode;
	}
}
