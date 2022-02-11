public class Test 
{
	public static void main(String[] args) 
	{		
		WarriorDecorator warrior1 = new Shield(new Sword(new Helm(new Armor(new Knight("---Knight 1---")))));
		WarriorDecorator warrior2 = new Sword(new Sword(new Knight("---Knight 2---")));
		
		System.out.println(warrior1.getDescription() + "Total Cost:\t" + warrior1.calculateCost() + "\n");
		System.out.println(warrior2.getDescription() + "Total Cost:\t" + warrior2.calculateCost());
	}

}
