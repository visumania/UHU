public class Knight extends Warrior
{
	private String description;
	
	public Knight(String description)
	{
		this.description = description;
	}
	
	@Override
	public String getDescription()
	{
		return description + "\n";
	}
	
	@Override
	public double calculateCost()
	{
		return 0d;
	}
}
