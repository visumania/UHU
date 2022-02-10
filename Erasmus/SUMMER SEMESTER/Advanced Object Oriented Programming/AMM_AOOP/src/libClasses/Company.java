package libClasses;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Company implements Cloneable
{
	private List<Client> V;
	
	//We create a method that return a the position of a nif. This way we can make sure to search the nif by calling a method
	private int searchNIF(String nif)
	{
		for(int i=0 ; i<V.size() ; i++)
		{
			if(V.get(i).getNif().equals(nif))
				return i;
		}
		
		return -1; 
	}
	
	public Company()
	{
		this.V = new ArrayList<Client>();
	}
	
	public int getNumberClients()
	{
		return this.V.size();
	}
	
	public void add()
	{
		Scanner keyboard = new Scanner(System.in);
		System.out.println("NIF: ");
		String nif = keyboard.nextLine();
		
		if(this.searchNIF(nif) ==-1) //The client doesn't exits in the company
		{
			System.out.println("Name: "); String name = keyboard.nextLine();
			System.out.println("Date of birth: "); Date dateBirth = Date.askDate();
			System.out.println("Discharge date: "); Date dischargeDate = Date.askDate();
			System.out.println("Minutes talks per month: "); float minutesTalks = keyboard.nextFloat();
			System.out.println("Indicate type of client (1.- Mobile, 2.- Flat Rate): "); int type = keyboard.nextInt();
			
			if(type == 1) //Mobile Client
			{
				System.out.println("Minute price: "); float minutePrice = keyboard.nextFloat();
				System.out.println("Permanence date: "); Date permanenceDate = new Date(Date.askDate());
				Client c = new ClientMobile(nif, name, dateBirth, dischargeDate, permanenceDate, minutesTalks, minutePrice);
				this.add(c);
			}
			else
			{
				if(type == 2) //Flat Rate Client
				{
					keyboard.nextLine();
					System.out.println("Nationality: "); String nationality = keyboard.nextLine();
					Client c = new ClientFlatRate(nif, name, dateBirth, dischargeDate, minutesTalks,nationality);
					this.add(c);
				}
			}
		}
		else
		{
			System.out.println("There are a client with that nif ");
			this.V.get(this.searchNIF(nif)).see();
		}
		
	}
	
	public void add(Client c)
	{
		if(this.searchNIF(c.getNif()) == -1)
			V.add(c);
	}
	
	public void delete()
	{
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("Insert nif of the client for delete: ");
		String nif = keyboard.nextLine();
		
		if(this.searchNIF(nif) != -1)
		{
			this.V.get(this.searchNIF(nif)).see();
			
			System.out.println("Are you sure to delete it (y/n)?");
			String op = keyboard.nextLine();
			
			if(op.equals("y"))
			{
				System.out.println("The client " + this.V.get(this.searchNIF(nif)).getName() + " with nif " + nif + " has been deleted");
				this.delete(nif);
			}
			
			if(op.equals("n"))
				System.out.println("The client with nif " + nif + " has not been deleted");
		}
		else
			System.out.println("No client has been found with that nif to delete");
	}
	
	public void delete(String nif)
	{
		for(int i=0 ; i<V.size() ; i++)
		{
			if(V.get(i).getNif().equals(nif))
				V.remove(i);
		}
	}
	
	public String toString()
	{
		String output = "";
		
		for(int i=0 ; i<V.size() ; i++)
		{
			if(V.get(i) instanceof ClientMobile)
				output += ((ClientMobile)this.V.get(i)).toString();
			else
				output += ((ClientFlatRate)this.V.get(i)).toString();
			
			output += "\n";
		}
		
		return output;
	}
	
	public float bill()
	{
		float res = 0;
		
		for(int i=0 ; i<V.size() ; i++)
		{
			if(V.get(i).getClass() == ClientMobile.class)
				res += ((ClientMobile)this.V.get(i)).bill();
			else
				res += ((ClientFlatRate)this.V.get(i)).bill();
		}
		
		return res;
	}
	
	public void discount(float disc)
	{
		for(int i=0 ; i<V.size() ; i++)
		{
			if(this.V.get(i).getClass() == ClientMobile.class)
				((ClientMobile)this.V.get(i)).setMinutePrice(((ClientMobile)this.V.get(i)).getMinutePrice()*(1-(disc/100)));
		}
	}
	
	public int nClientMobile()
	{
		int counter = 0;
		
		for(int i=0 ; i<V.size() ; i++)
		{
			if(this.V.get(i) instanceof ClientMobile)
				counter++;
		}
		
		return counter;
	}
	
	public Object clone()
	{
		Company obj = new Company();
		
		for(int i=0 ; i<this.V.size() ; i++)
		{
			if(this.V.get(i).getClass() == ClientMobile.class)
				obj.add((ClientMobile)this.V.get(i).clone());
			else
				obj.add((ClientFlatRate)this.V.get(i).clone());
		}
		
		return (Object)obj;
	}
}
