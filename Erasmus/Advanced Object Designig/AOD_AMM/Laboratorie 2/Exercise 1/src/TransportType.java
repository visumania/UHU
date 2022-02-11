public enum TransportType implements IShippingCosts
{
	DHL(2.5f),
	UPS(7.5f),
	GLS(15f);
	
	private float price;
	
	private TransportType(float price)
	{
		this.price = price;
	}
	
	public float getPrice()
	{
		return this.price;
	}

	@Override
	public double calculateShippingCosts(Order order) {
		// TODO Auto-generated method stub
		
		return order.getTransportType().getPrice();
	}
}
