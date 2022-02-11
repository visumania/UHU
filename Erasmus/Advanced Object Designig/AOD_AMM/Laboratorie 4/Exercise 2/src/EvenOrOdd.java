import java.util.Random;

public class EvenOrOdd extends Game
{
	boolean player1 = false;
	boolean player2 = false;
	
	@Override
	public void setUp() 
	{
		System.out.println("Player 1 choose EVEN and Player 2 choose ODD");
	}

	@Override
	public void play() 
	{
		System.out.println("Playing the game ...");
		
		Random r = new Random();
		
		if(r.nextInt(101)%2 == 0)
			player1 = true;
		else
			player2 = false;
	}

	@Override
	public void finish() 
	{
		System.out.println("The game have finished");
	}

	@Override
	public void winner() 
	{
		if(player1)
			System.out.println("Player 1 WINS the game");
		else
			System.out.println("Player 2 WINS the game");
	}
}
