public class Order 
{
	private int num;
	
	public Order(int num)
	{
		this.num = num;
	}
	
	public void createNewOrder()
	{
		System.out.print("Create Order " + this.num);
	}
	
	public void modifyOrder()
	{
		System.out.print("Update Order " + this.num);
	}
	
	public void completeOrder()
	{
		System.out.print("Complete Order " + this.num);
	}
}
