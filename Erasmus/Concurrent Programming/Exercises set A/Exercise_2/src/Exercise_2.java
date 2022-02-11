class Singer implements Runnable
{
	int n;
	Singer next;
	
	public Singer(int n)
	{
		this.n = n;
	}
	
	public void setNext(Singer next)
	{
		this.next = next;
	}
	
	@Override
	public void run()
	{
		System.out.println(n + " bottles of beer on the wall, " + n + " bottles of beer");
		System.out.println("Take one down and pass it around, " + (n-1) + " bottles of beer on the wall");
	}
}

public class Exercise_2 
{
	public static void main(String [] args)
	{
		Singer [] threads = new Singer[100];
		
		for(int i=0 ; i<threads.length ; i++)
		{
			threads[i] = new Singer(i+1);
			
			if(i>=1)
			{
				threads[i-1].setNext(threads[i]);
			}
		}
		
		for(Thread t : threads)
		{
			t.start();
		}
	}
}
