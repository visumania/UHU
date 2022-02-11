public class Armor extends WarriorDecorator 
{
	private int cost = 500;
	
	public Armor(Warrior w) 
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
		return super.getDescription() + "+ Armor \t" + cost + "\n";
	}
}
