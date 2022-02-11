import java.util.ArrayList;
import java.util.Observable;

public class ObservedMessage extends Observable
{
	ArrayList<Message> listMessages = new ArrayList<Message>();
	
	public void messageUpdate(String message)
	{
		Message m = new Message(message);
		listMessages.add(m);
		setChanged();
		notifyObservers(listMessages);
	}
	
	public ArrayList<Message> getListMessage()
	{
		return this.listMessages;
	}
}
