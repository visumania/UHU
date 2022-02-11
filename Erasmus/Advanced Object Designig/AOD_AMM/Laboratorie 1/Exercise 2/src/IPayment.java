public interface IPayment 
{
	public void registerPayment();
	public boolean generateOrderConfirmation(float amountMoney);
}
