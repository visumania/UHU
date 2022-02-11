public class Order 
{
	private Address recipientAddress;
	private Address senderAddress;
	private float orderValue;
	private TransportType transportType;
	
	public Order(Address recipientAddress, Address senderAddress, float orderValue, TransportType transportType)
	{
		this.recipientAddress = new Address(recipientAddress.getContactName(), recipientAddress.getStreet(), recipientAddress.getCity(), recipientAddress.getPostalCode());		
		this.senderAddress = new Address(senderAddress.getContactName(), senderAddress.getStreet(), senderAddress.getCity(), senderAddress.getPostalCode());
		this.orderValue = orderValue;
		this.transportType = transportType;
	}
	
	//get methods
	
	public Address getRecipientAddress()
	{
		return this.recipientAddress;
	}
	
	public Address getSenderAddress()
	{
		return this.senderAddress;
	}
	
	public float getOrderValue()
	{
		return this.orderValue;
	}
	
	public TransportType getTransportType()
	{
		return this.transportType;
	}
	
	public Order getOrder()
	{
		return this;
	}
	
	//set methods
	
	public void setRecipientAddress(Address recipientAddress)
	{
		this.recipientAddress.setAddress(recipientAddress);
	}
	
	public void setSenderAddress(Address senderAddress)
	{
		this.senderAddress.setAddress(senderAddress);
	}
	
	public void setOrderValue(float orderValue)
	{
		this.orderValue = orderValue;
	}
	
	public void setTransportType(TransportType transportType)
	{
		this.transportType = transportType;
	}
	
	public void setOrder(Order order)
	{
		this.recipientAddress.setAddress(order.recipientAddress);
		this.senderAddress.setAddress(order.senderAddress);
		this.orderValue = order.orderValue;
		this.transportType = order.transportType;
	}
}
