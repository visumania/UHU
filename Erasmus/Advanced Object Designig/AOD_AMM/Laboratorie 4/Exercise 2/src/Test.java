import java.util.Scanner;

public class Test 
{
	public static void main(String []args)
	{
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("HEADS OR TAILS");
		Game game = new HeadsOrTails();
		game.playGame();
				
		System.out.println("\nEVEN OR ODD");
		game = new EvenOrOdd();
		game.playGame();
		
		keyboard.close();
	}
}
