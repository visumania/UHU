public class NotEnoughFundsOnCreditCardException extends Exception
{
	private String msg;
	
	public NotEnoughFundsOnCreditCardException(String msg)
	{
		this.msg = msg; 
	}
	
	@Override
	public String getMessage()
	{
		return msg;
	}
}
