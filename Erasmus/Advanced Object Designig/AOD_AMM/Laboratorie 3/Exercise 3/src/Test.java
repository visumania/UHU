public class Test 
{
	public static void main(String []args)
	{
		CommandManager cm = new CommandManager();
		
		cm.setCommand(new CreateOrder(new Order(1)));
		cm.setCommand(new CreateOrder(new Order(2)));
		cm.setCommand(new CreateOrder(new Order(3)));
		cm.setCommand(new ModifyOrder(new Order(2)));
		cm.setCommand(new CompleteOrder(new Order(1)));
		cm.setCommand(new CompleteOrder(new Order(2)));
		
		cm.executeWork();	
	}
}
