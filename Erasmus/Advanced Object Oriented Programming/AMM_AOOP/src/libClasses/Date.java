package libClasses;

import java.util.Scanner;

public final class Date implements Cloneable, Process 
{
	//Attributes of the date class:
	private int day;
	private int month;
	private int year;
	
	//Methods of the date class:
	public Date(int pDay, int pMonth, int pYear) //Constructor of date class
	{
		setDate(pDay,pMonth,pYear);
	}

	public Date(Date pDate)
	{
		this.day = pDate.day;
		this.month = pDate.month;
		this.year = pDate.year;
	}
	
	public void setDate(int pDay, int pMonth, int pYear)
	{
		int dmax, dayMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
		this.year = pYear; //I must assign year to call leap later
		
		if(pMonth<1)//if month is incorrect (less than 1)
			pMonth=1;
		else if(pMonth>12) //if month is incorrect (more than 12)
				pMonth = 12;
		
		dmax = dayMonth[pMonth-1];
		
		if(pMonth==2 && leap())
			dmax++;
		
		if(pDay>dmax)
			pDay=dmax;
		else if(pDay<1)
				pDay = 1;
		
		this.day = pDay;
		this.month = pMonth;
	}
	
	public static Date askDate()
	{
		Date date = null;
		boolean valid = false;
		Scanner sc = new Scanner(System.in);
		int pDay, pMonth, pYear;
		
		do
		{
			System.out.println("Insert the date (dd/mm/yyyy): ");
			String chain = sc.nextLine();
			String[] tokens = chain.split("/");
			
			try
			{
				if(tokens.length != 3)
					throw new NumberFormatException();
				
				pDay = Integer.parseInt(tokens[0]); //parseInt throws an exception
				pMonth = Integer.parseInt(tokens[1]); // NumberFormatException if
				pYear = Integer.parseInt(tokens[2]); //can't convert the String to integer
				
				date = new Date(pDay,pMonth,pYear);
				
				if(date.getDay() != pDay || date.getMonth() != pMonth)
					throw new NumberFormatException();
				
				valid = true;
			}catch(NumberFormatException e)
			{
				System.out.println("Not valid date");
			}
		}while(!valid);
		
		
		return date;
	}
	
	final public int getDay()
	{
		return this.day;
	}
	
	final public int getMonth()
	{
		return this.month;
	}
	
	final public int getYear()
	{
		return this.year;
	}
	
	final public boolean leap()
	{
		return (year%4 == 0 && (year%100 != 0 || year%400 ==0));
	}
	
	static public boolean higher(Date d1, Date d2)
	{
		if(d1.getYear()*1000 + d1.getMonth()*100 + d1.getDay() > d2.getYear()*1000 + d2.getMonth()*100 + d2.getDay())
			return true;
		else
			return false;
	}

	@Override
	public void see() 
	{
		System.out.println(this);
	}
	
	@Override
	public String toString()
	{
		return String.format("%02d/%02d/%02d", this.day,this.month,this.year);
	}
	
	@Override
	public Object clone()
	{
		return new Date(this);
	}
	
	@Override
	public boolean equals(Object obj) //true if they are equals
	{
		if(this == obj) return true; //if they point to the same site they are equal
		if(obj == null) return false;
		
		if(getClass() != obj.getClass())
			return false;
		
		Date c = (Date)obj;
		
		return(day==c.day && month==c.month && year==c.year);
	}
	
	public Date nextDay() //this is like operator++ overload
	{
		int pDay, pMonth, pYear;
		
		Date aux = new Date(this);
		pDay = aux.getDay();
		pMonth = aux.getMonth();
		pYear = aux.getYear();
		int DaysMax[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		
		if(aux.leap())
			DaysMax[2]=29;
		
		
		if(pDay+1>DaysMax[aux.getMonth()])
		{
			pDay = 1;
			pMonth++;
			if(pMonth>12)
			{
				pMonth = 1;
				pYear++;
			}
		}
		else
			pDay++;
		
		aux.setDate(pDay, pMonth, pYear);
		
		return aux; 
	}
	
	public static void main(String[] args)
	{
		Date d1 = new Date(29,2,2001), d2 = new Date(d1), d3 = new Date(29,2,2004);
		final Date d4=new Date(05,12,2023); 
		System.out.print("Dates: " + d1.toString() + ", "+d2+ ", " +d3+ ", " +d4+ "\n"); 
		d1=new Date(31,12,2016); 
		d4.setDate(28, 2, 2008); 
		System.out.println(d1 + " " + d2.toString() + " " + d3 + " " + d4 + " " + d1);
		d1=new Date(d4.getDay()-10, d4.getMonth(), d4.getYear()-7);  
		d3=Date.askDate(); 
		if (d3.leap() && Date.higher(d2,d1))
		System.out.print("The " + d3.getYear() + " was leap, " + d1 + ", " + d3);
	}

}
