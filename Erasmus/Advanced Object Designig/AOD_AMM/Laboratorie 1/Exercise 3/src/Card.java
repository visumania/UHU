public class Card extends Payment 
{
	private int id; 
	private String titleT; 
	private String description;
	private float price;
	
	//private float avaliableMoney = 500;
	
	private String numCard; 
	private String expiryDate;
	
	public Card(int id, String titleT, String description, float price, String numCard, String expiryDate)
	{
		super(id,titleT,description,price);
		this.id = id;
		this.titleT = titleT;
		this.description = description;
		this.price = price;
		
		this.numCard = numCard;
		this.expiryDate = expiryDate; 
	}
	
	public void registerPayment()
	{
		System.out.println("\nREGISTER PAYMENT\n");
		
		System.out.println("ID: " + id);
		System.out.println("Title: " + titleT);
		System.out.println("Description: " + description);
		System.out.println("Total price: " + price);
		System.out.println("Card number: " + numCard);
		System.out.println("Card expiration day (mm/yy): " + expiryDate);
	}
	
	public boolean generateOrderConfirmation(float amountMoney)
	{
		//return super.generateOrderConfirmation(amountMoney);
		try
		{
			if(amountMoney > super.getAvaliableMoney())
				throw new NotEnoughFundsOnCreditCardException("Payment error, you do not have enough money on your credit card");
				
		}catch(NotEnoughFundsOnCreditCardException ex)
		{
			System.out.println(ex.getMessage());
		}
		
		return super.generateOrderConfirmation(amountMoney);
	}
}
