import java.util.Scanner;

public class Client 
{
	void play(String fileType, String pathToFile)
	{
		IMusicPlayer mp;
		
		switch(fileType)
		{
			case ".mp3":
			mp = new mp3();
			mp.play(pathToFile);
			break;
			
			case ".mp4":
			mp = new AdapterMP4();
			mp.play(pathToFile);
			break;
			
			case ".wmv":
			mp = new AdapterWMV();
			mp.play(pathToFile);
			break;
			
			default: System.out.println("File type incorrect");
		}
	}
	
	public static void main(String[] args)
	{		
		Client client = new Client();
		String fileType;
		String pathToFile;
		Scanner keyboard = new Scanner(System.in);
		String opt; 
		
		do
		{
			System.out.print("Enter path to file: ");
			pathToFile = keyboard.nextLine();
			
			System.out.print("Choose the extension (.mp3, .mp4, .wmv): ");
			fileType = keyboard.nextLine();
			fileType.toLowerCase();
			
			client.play(fileType, pathToFile);
			
			System.out.print("\nDo you want to play another song?(y/n): ");
			opt = keyboard.next();
			opt.toLowerCase();
			
			keyboard.nextLine(); //Clean the buffer
			
		}while(opt.equals("y"));
				
		keyboard.close();
	}
}
