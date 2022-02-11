class Alice extends Thread
{
	Bob bob;
	
	public Alice(Bob bob)
	{
		this.bob = bob;
	}
	
	@Override
	public void run()
	{
		for(int i=0 ; i<10 ; i++)
		{
			bob.setInput(i+1);
			System.out.println("[Alice] Sending to Bob: " + (i+1));
			bob.interrupt();	
			
			try
			{
				Thread.sleep(1000);
			}catch(InterruptedException e)
			{
				System.out.println("Interrupted Exception [Alice] :(");
			}
		}
		
		bob.setInput(0); //Denotes the final of the calculations
		bob.interrupt();//Last interrupt 
	}
}

class Bob extends Thread
{
	int input; 
	
	public void setInput(int x)
	{
		this.input = x;
	}
	
	@Override
	public void run()
	{		
		while(true) //Infinite loop
		{
			if(Thread.interrupted() == true)
			{
				if(this.input == 0)
					System.out.println("[Bob] Finishing work");
				else
					System.out.println("[Bob] The result is: " + (this.input*2));
			}
		}
	}
}

public class Exercise_3 
{
	public static void main(String [] args)
	{
		Bob bob = new Bob();
		Alice alice = new Alice(bob);
		
		bob.start();
		alice.start();
	}
}
