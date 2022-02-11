public class Shield extends WarriorDecorator
{
	private int cost=300;
	
	public Shield(Warrior w) 
	{
		super(w);
	}
	
	@Override
	public double calculateCost()
	{
		return super.calculateCost()+cost;
	}
	
	@Override
	public String getDescription()
	{
		return super.getDescription() + "+ Shield\t" + cost + "\n";
	}
}
