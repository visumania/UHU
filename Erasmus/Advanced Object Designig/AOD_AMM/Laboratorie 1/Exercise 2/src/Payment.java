public class Payment implements IPayment
{
	private String titleT; 
	private String description;
	private float price;
	private  int id;
	
	private float avaliableMoney = 500; //It is the amount of example that I have put as maximum to pay
	
	public Payment(int id, String titleT, String description, float price)
	{
		this.id = id;
		this.titleT = titleT;
		this.description = description;
		this.price = price;
	}
	
	public void setPayment(int id, String titleT, String description, float price)
	{
		this.id = id;
		this.titleT = titleT;
		this.description = description;
		this.price = price;
	}
	
	public void registerPayment()
	{
		//Empty
	}
	
	public boolean generateOrderConfirmation(float amountMoney)
	{
		if(amountMoney <= avaliableMoney)
		{
			this.id++;
			return true;
		}
		else
			return false;
	}
}