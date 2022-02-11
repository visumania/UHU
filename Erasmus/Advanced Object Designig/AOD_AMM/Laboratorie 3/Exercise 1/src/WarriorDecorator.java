public class WarriorDecorator extends Warrior 
{
	protected Warrior w;
	
	public WarriorDecorator(Warrior w)
	{
		super();
		this.w = w;
	}
	
	@Override
	public double calculateCost() 
	{
		 return w.calculateCost();
	}

	@Override
	public String getDescription() 
	{
		return w.getDescription();
	}

}
