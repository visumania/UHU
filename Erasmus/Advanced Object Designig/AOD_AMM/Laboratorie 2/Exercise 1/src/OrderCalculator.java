public class OrderCalculator implements IShippingCosts//this class calculate the total cost of the order (product value + shipping)
{

	@Override
	public double calculateShippingCosts(Order order) {
		// TODO Auto-generated method stub
		return order.getTransportType().calculateShippingCosts(order)+order.getOrderValue();
	}
	
}
