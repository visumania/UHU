package libTests;

import java.io.IOException;
import java.util.Scanner;

import libClasses.*;


public class Main 
{
	public static void main(String[] srgs) throws IOException
	{
		System.out.println("Insert the name of the company: ");
		Scanner keyboard = new Scanner(System.in);
		String nameCompany = keyboard.nextLine();
		
		Company company = new Company();
		
		int opt=0;
		
		do
		{
			System.out.println("\t*******MENU " + nameCompany.toUpperCase() + " *******");
			System.out.println("1.- See clients");
			System.out.println("2.- Add client");
			System.out.println("3.- Delete client");
			System.out.println("4.- Apply discount (Only Client Mobile)");
			System.out.println("5.- Exit");
			System.out.print("\nInsert an option: ");
			opt = keyboard.nextInt();
			
			switch(opt)
			{
				case 1:
					System.out.println(nameCompany.toUpperCase() + " Company:\n" + company);
				break;
				
				case 2:
					company.add();
				break;
				
				case 3: 
					company.delete();
				break;
				
				case 4:
					System.out.print("Insert the percentage for discount (%): ");
					float disc = keyboard.nextFloat();
					company.discount(disc);
				break;
				
				case 5:
				break;
				
				default:
					System.out.println("Incorrect option");
			}
			
			System.out.println("Press enter to continue ...");
			System.in.read();
			
			
		}while(opt!=5);
		
		
		
		keyboard.close();
	}
}
