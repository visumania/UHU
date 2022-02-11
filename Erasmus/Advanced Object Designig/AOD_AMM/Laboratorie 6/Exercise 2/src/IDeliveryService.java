import java.sql.SQLException;

public interface IDeliveryService 
{
	//Meal Table
	public void createMeal() throws SQLException;
	public void deleteMeal() throws SQLException;
	public void selectAllMeals() throws SQLException;
	public void modifyPrice() throws SQLException;
	public void modifyPossibleNumberOfOrders() throws SQLException;
	
	//Order Table
	public void createOrder() throws SQLException;
	public void deleteOrder() throws SQLException;
	public void selectAllOrders() throws SQLException;
}
