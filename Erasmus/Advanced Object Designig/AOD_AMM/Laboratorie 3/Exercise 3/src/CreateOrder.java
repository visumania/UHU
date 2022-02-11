public class CreateOrder implements ICommand 
{
	private Order delivered;
	
	public CreateOrder(Order delivered)
	{
		this.delivered = delivered;
	}
	
	@Override
	public void execute() 
	{
		delivered.createNewOrder();
	}
}
