import java.time.*;

public class Message 
{
	private LocalDate date;
	private LocalTime time;
	private String m; 
	
	public Message()
	{
		//Empty
	}
	
	public Message(String m)
	{
		this.date = LocalDate.now();
		this.time = LocalTime.now(); 
		this.m = m;
	}
	
	public LocalDate getDate()
	{
		return this.date;
	}
	
	public LocalTime getTime()
	{
		return this.time;
	}
	
	public String getMessage()
	{
		return this.m;
	}
	
	public void setMessage(String m)
	{
		this.m = m;
		this.date = LocalDate.now();
		this.time = LocalTime.now();
	}
	
	@Override
	public String toString()
	{
		return getMessage();
	}
}
