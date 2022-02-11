import java.util.List;
import java.util.ArrayList;

public class CommandManager 
{
	private final List<ICommand> collection  = new ArrayList<>();
	
	public void setCommand(ICommand command)
	{
		collection.add(command);
	}
	
	public void removeLastCommand()
	{
		collection.remove(collection.size()-1);
	}
	
	public void executeWork()
	{
		for(int i=0 ; i<collection.size() ; i++)
		{
			collection.get(i).execute();
			
			if(i+1 < collection.size())
				System.out.print(" --> ");
		}
	}
}