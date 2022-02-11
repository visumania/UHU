public class AdapterWMV implements IMusicPlayer
{
	private wmv wmv = new wmv();
	
	@Override
	public void play(String pathToFile) 
	{
		wmv.playWMV(pathToFile);
	}
}
