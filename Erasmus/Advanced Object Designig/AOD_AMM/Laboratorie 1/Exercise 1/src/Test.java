import java.util.ArrayList;

public class Test 
{
	public static void main(String []args)
	{
		ArrayList<Object> container = new ArrayList<Object>();
		
		FBReporter fbr = new FBReporter();
		TwittReporter twr = new TwittReporter();
		GPlusReporter gpr = new GPlusReporter();
		
		container.add(fbr);
		container.add(twr);
		container.add(gpr);
		container.add(gpr);
		container.add(twr);
		container.add(fbr);
		container.add(fbr);
		
		for(int i=0 ; i<container.size() ; i++)
		{
			if(container.get(i).getClass() == fbr.getClass())
				System.out.println("FB");
			
			if(container.get(i).getClass() == twr.getClass())
				System.out.println("Twitt");
			
			if(container.get(i).getClass() == gpr.getClass())
				System.out.println("GPlus");
		}
	}
}
