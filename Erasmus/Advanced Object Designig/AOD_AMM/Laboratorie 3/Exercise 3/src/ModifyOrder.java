public class ModifyOrder implements ICommand 
{
	private Order delivered;
	
	public ModifyOrder(Order delivered)
	{
		this.delivered = delivered;
	}
	
	@Override
	public void execute() 
	{
		delivered.modifyOrder();
	}
}