public class Test 
{
	public static void main(String []args) throws InterruptedException
	{
		//Observable class
		ObservedMessage observedMessage = new ObservedMessage();
		
		//Observer class
		RadioChannel rc1 = new RadioChannel();
		RadioChannel rc2 = new RadioChannel();
		TelevisionChannel tc1 = new TelevisionChannel();
		TelevisionChannel tc2 = new TelevisionChannel();
		
		//Add observer into observable
		observedMessage.addObserver(rc1);
		observedMessage.addObserver(rc2);
		observedMessage.addObserver(tc1);
		observedMessage.addObserver(tc2);
		
		//Change observable state
		observedMessage.messageUpdate("Exercise 2 Laboratorie 2 Advanced Object Designing");
		
		//Observer was notified
		System.out.println(rc1.toString() + "\n");
		System.out.println(rc2.toString() + "\n");
		System.out.println(tc1.toString() + "\n");
		System.out.println(tc2.toString());
	}
}
