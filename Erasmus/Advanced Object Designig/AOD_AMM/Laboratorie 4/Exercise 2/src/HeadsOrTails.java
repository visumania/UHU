import java.util.Random;

public class HeadsOrTails extends Game
{
	boolean player1 = false;
	boolean player2 = false;
	
	@Override
	public void setUp() 
	{
		System.out.println("Player 1 choose HEADS and Player 2 choose TAILS");
	}

	@Override
	public void play() 
	{
		System.out.println("Playing the game ...");
		
		Random r = new Random();
		
		if(r.nextInt(2) == 0)
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
