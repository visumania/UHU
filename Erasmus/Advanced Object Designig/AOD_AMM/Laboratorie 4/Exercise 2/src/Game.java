public abstract class Game 
{
	public abstract void setUp();
	public abstract void play();
	public abstract void finish();
	public abstract void winner();
	
	public final void playGame()
	{
		setUp();
		play();
		finish();
		winner();
	}
}
