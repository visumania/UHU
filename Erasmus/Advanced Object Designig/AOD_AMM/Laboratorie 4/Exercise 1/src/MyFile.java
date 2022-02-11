import java.util.ArrayList;
import java.util.List;

public class MyFile implements IData
{
	private String name;
	private double size;
	private String content;
	
	private List<IData> iData = new ArrayList<>();
	
	public MyFile(String name, String content)
	{
		this.name = name;
		this.content = content;
	}
	
	@Override
	public void readContent() 
	{
		System.out.println(this.name + "\n" + content);
	}

	@Override
	public void addContent(IData iData) 
	{
		this.iData.add(iData);
	}

	@Override
	public void removeContent(IData iData)
	{
		this.iData.remove(iData);
	}

	@Override
	public double calculateSize() 
	{
		this.size = this.content.length();
		
		return this.size;
	}

	@Override
	public String getName() 
	{
		return this.name;
	}
}
