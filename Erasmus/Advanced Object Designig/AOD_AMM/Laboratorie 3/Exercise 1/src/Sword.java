public class Sword extends WarriorDecorator
{
	private int cost = 250;
	
	public Sword(Warrior w) 
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
		return super.getDescription() + "+ Sword \t" + cost + "\n";
	}
}
