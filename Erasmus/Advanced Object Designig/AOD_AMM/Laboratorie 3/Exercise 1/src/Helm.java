public class Helm extends WarriorDecorator
{
	private int cost = 100;
	
	public Helm(Warrior w) 
	{
		super(w);
	}
	
	@Override
	public double calculateCost()
	{
		return  super.calculateCost() + cost;
	}
	
	@Override
	public String getDescription()
	{
		return super.getDescription() + "+ Helm  \t" + cost + "\n";
	}
}
