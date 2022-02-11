class Singer implements Runnable
{
	int n;
	
	public Singer(int n)
	{
		this.n = n; 
	}
	
	@Override
	public void run()
	{
		System.out.println(n + " bottles of beer on the wall, " + n + " bottles of beer");
		System.out.println("Take one down and pass it around, " + (n-1) + " bottles of beer on the wall");
	}
}

public class Exercise_1 
{
	public static void main(String [] args) throws InterruptedException
	{	
		Thread [] threads = new Thread[100];
				
		for(int i=0 ; i<threads.length ; i++)
		{
			threads[i] = new Thread(new Singer(i+1));
		}
		
		
		for(int i=threads.length-1 ; i>=0 ; i--) //for instead for each because I want a reverse travel
		{
			threads[i].start();
			
			try 
			{
				Thread.sleep(100); //This sleep is for the order that Threads go appearing on the screen
			} catch (InterruptedException e) 
			{
				e.printStackTrace();
			}
		}
	}
}
