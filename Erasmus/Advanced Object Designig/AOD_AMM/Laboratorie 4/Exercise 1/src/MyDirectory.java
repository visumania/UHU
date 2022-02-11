import java.util.ArrayList;
import java.util.List;

public class MyDirectory implements IData 
{
	private List<IData> files = new ArrayList<>();
	//private List<IData> folders = new ArrayList<>();
	private String directory;
	
	public MyDirectory(String directory)
	{
		this.directory = directory;
	}
	
	@Override
	public void readContent() 
	{
		for(int i=0 ; i<files.size() ; i++)
		{
			System.out.println(this.getName() + files.get(i).getName());
		}
	}

	@Override
	public void addContent(IData iData) 
	{
		files.add(iData);
		//folders.add(iData);
	}

	@Override
	public void removeContent(IData iData) 
	{
		files.remove(iData);
		//folders.remove(iData);
	}

	@Override
	public double calculateSize() 
	{
		double ret = 0.0d;
				
		for(int i=0 ; i<files.size() ; i++)
			ret += files.get(i).calculateSize();
		
		System.out.println("Size of " + this.getName() + ": " + ret);
		
		return ret;
	}

	@Override
	public String getName() 
	{
		return this.directory;
	}
}
