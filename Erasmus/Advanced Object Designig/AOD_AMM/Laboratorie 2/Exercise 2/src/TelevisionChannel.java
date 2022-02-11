import java.util.Observer; 
import java.util.Observable;

public class TelevisionChannel implements Observer
{
private Message message = new Message();
	
	public TelevisionChannel()
	{
		//Empty
	}

	@Override
	public void update(Observable arg0, Object arg1) {
		// TODO Auto-generated method stub
		
		this.message = new Message(arg1.toString());
	}
	
	public Message getMessage()
	{
		return this.message;
	}
	
	@Override
	public String toString()
	{
		return "Date: " + message.getDate() + "\nTime: " + message.getTime() + "\nMessage: " + message.toString() + "\nMedium: " + this.getClass();
	}
}
