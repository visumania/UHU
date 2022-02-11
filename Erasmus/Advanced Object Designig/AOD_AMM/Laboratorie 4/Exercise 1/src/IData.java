public interface IData 
{
	public void readContent();
	public void addContent(IData iData);
	public void removeContent(IData iData);
	public double calculateSize();
	public String getName();
}
