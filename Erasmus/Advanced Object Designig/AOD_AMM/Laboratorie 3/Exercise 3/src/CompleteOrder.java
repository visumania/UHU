public class CompleteOrder implements ICommand 
{
	private Order delivered;
	
	public CompleteOrder(Order delivered)
	{
		this.delivered = delivered;
	}

	@Override
	public void execute() 
	{
		delivered.completeOrder();
	}
}