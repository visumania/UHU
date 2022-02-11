public class AdapterMP4 implements IMusicPlayer
{
	private mp4 mp4 = new mp4();
	
	@Override
	public void play(String pathToFile) 
	{
		mp4.playMP4(pathToFile);
	}
}
