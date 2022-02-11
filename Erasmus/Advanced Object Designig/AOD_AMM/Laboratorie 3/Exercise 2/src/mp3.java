public class mp3 implements IMusicPlayer
{
	@Override
	public void play(String pathToFile) 
	{
		System.out.println("Playing " + pathToFile + "." + this.getClass().getName());
	}
}
