public class BankTransfer extends Payment
{
	private int id; 
	private String titleT; 
	private String description;
	private float price;
	
	private String numberAccount; 
	
	public BankTransfer(int id, String titleT, String description, float price, String numberAccount)
	{
		super(id,titleT,description,price);
		this.id = id; 
		this.titleT = titleT;
		this.description = description; 
		this.price = price; 
		
		this.numberAccount = numberAccount; 
	}
	
	public void registerPayment()
	{
		System.out.println("\nREGISTER PAYMENT\n");
		
		System.out.println("ID: " + id);
		System.out.println("Title: " + titleT);
		System.out.println("Description: " + description);
		System.out.println("Total price: " + price);
		System.out.println("Number account: " + numberAccount);
	}
	
	public boolean generateOrderConfirmation(float amountMoney)
	{
		return super.generateOrderConfirmation(amountMoney);
	}
}
