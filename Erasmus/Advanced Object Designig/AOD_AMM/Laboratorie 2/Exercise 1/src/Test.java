import java.io.IOException;
import java.util.Scanner;

public class Test 
{
	public static void main(String[] args) throws IOException
	{
		String opt;
		Scanner keyboard = new Scanner(System.in);
		
		//attributes of an address type object
		String contactName;
		String street;
		String city;
		String postalCode;
		Address senderAddress,recipientAddress; 
		
		//attributes of an order type object
		float orderValue; 
		Order order = null;
		
		do
		{
			System.out.println("DATA ABOUT SENDER ADDRESS");
			System.out.print("Enter contact name: ");
			contactName = keyboard.nextLine();
			
			System.out.print("Enter the street: ");
			street = keyboard.nextLine();
			
			System.out.print("Enter the city: ");
			city = keyboard.nextLine();
			
			System.out.print("Enter the postal code format XX-XXX: ");
			postalCode = keyboard.nextLine();
			
			senderAddress = new Address(contactName,street,city,postalCode);
			
			System.out.println("\nDATA ABOUT RECIPIENT ADDRESS");
			System.out.print("Enter contact name: ");
			contactName = keyboard.nextLine();
			
			System.out.print("Enter the street: ");
			street = keyboard.nextLine();
			
			System.out.print("Enter the city: ");
			city = keyboard.nextLine();
			
			System.out.print("Enter the postal code format XX-XXX: ");
			postalCode = keyboard.nextLine();
			
			recipientAddress = new Address(contactName,street,city,postalCode);
			
			System.out.println("\nDATA ABOUT THE ORDER");
			System.out.print("Enter the order value: ");
			orderValue = keyboard.nextFloat();
			
			TransportType[] tt = TransportType.values();
			OrderCalculator oc = new OrderCalculator();
			
			for(int i=0 ; i<tt.length ; i++)
			{
				order = new Order(recipientAddress, senderAddress, orderValue, tt[i]);
				
				switch(tt[i])
				{
					case DHL:
					System.out.println("\n1.- DHL --> 10-14 Days of shipment --> Extra price: 2.50$");
					System.out.println("Total price of product + shipment: "+oc.calculateShippingCosts(order) + "$");
					break;
					
					case UPS:
					System.out.println("\n2.- UPS --> 6-10 Days of shipment --> Extra price: 7.50$");
					System.out.println("Total price of product + shipment: "+oc.calculateShippingCosts(order) + "$");
					break;
					
					case GLS:
					System.out.println("\n3.- GLS --> <24 Hours of shipment --> Extra price: 15.00$");
					System.out.println("Total price of product + shipment: "+oc.calculateShippingCosts(order) + "$");
					break;
					
					default: System.out.println("Error");
				}
				
			}
		
			System.out.println("\nDo you want to calculate the price of another order? (y/n): ");
			opt = keyboard.next();
			opt = opt.toUpperCase();
			
			if(!opt.equals("N") && !opt.equals("Y"))
			{
				System.out.println("Error, incorrect option");
				System.out.println("Press enter to continue...");
				System.in.read();
			}
				
			
		}while(!opt.equals("N"));
		
		System.out.println("Exiting the program, press enter to finish...");
		System.in.read();
		
		keyboard.close();
	}
}
