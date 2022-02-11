import java.util.concurrent.locks.*;
import java.util.concurrent.ThreadLocalRandom;
import java.util.Random;

class Bank
{
	public static final int N = 10;
	private int [] balances = new int[N];
	private Lock [] locks = new Lock[N];
	
	public Bank()
	{
		for(int i=0 ; i<locks.length ; i++)
			locks[i] = new ReentrantLock();
	}
	
	public void deposit(int accountId , int amount)
	{
		balances[accountId] += amount;
	}
	
	public int getBalance(int accountId)
	{
		return balances[accountId];
	}
	
	public boolean transfer(int fromAccount , int toAccount , int amount)
	{
		boolean devFrom = false;
		boolean devTo = false;
		
		if(getBalance(fromAccount)-amount >= 0)
		{
			while(true)
			{
				if(locks[fromAccount].tryLock())
				{
					try
					{
							balances[fromAccount] -= amount;
							devFrom = true;
					}finally
					{
						locks[fromAccount].unlock();
					}
					
					break;
				}
				else
					Thread.yield();
			}
			
			while(true)
			{
				if(locks[toAccount].tryLock())
				{
					try
					{
							balances[toAccount] += amount;
							devTo = true;

					}finally
					{
						locks[toAccount].unlock();
					}
					
					break;
				}
				else
					Thread.yield();
			}
		}
		
		return devFrom&&devTo;
	}
}

class Accountant extends Thread
{
	Bank bank;
	
	public Accountant(Bank bank)
	{
		this.bank = bank;
	}
	
	@Override
	public void run()
	{
		Random rng = ThreadLocalRandom.current();
		
		for(int i=0 ; i<1000 ; i++)
		{
			//Try to transfer a random amount between a pair of accounts // The account numbers(id's) are also selected randomly
			int fromAccount = rng.nextInt(Bank.N-1);
			int toAccount = rng.nextInt(Bank.N-1);
			
			while(toAccount == fromAccount) //Source should differ from the target
			{
				toAccount = rng.nextInt(Bank.N-1); // We keep trying again
			}
			
			bank.transfer(fromAccount, toAccount, rng.nextInt(100)); // Transfer a random amount (between 0 and 100)
		}
	}
}

public class Exercise2 
{
	public static void main(String [] args) throws InterruptedException
	{
		Bank bank = new Bank();
		
		for(int i=0 ; i<Bank.N ; i++)
			bank.deposit(i, 100);
		
		Thread [] threads = new Thread[10];
		
		for(int i=0 ; i<threads.length ; i++)
			threads[i] = new Accountant(bank);
		
		for(Thread t : threads)
			t.start();
		
		for(Thread t : threads)
			t.join();
		
		int total = 0;
		
		for(int i=0 ; i<Bank.N ; i++)
		{
			int b = bank.getBalance(i);
			total += b;
			
			System.out.printf("Account [%d] balance: %d\n" , i , b);
		}
		
		System.out.printf("Total balance is %d\tand the valid value is %d\n" , total , Bank.N*100);
	}
}
