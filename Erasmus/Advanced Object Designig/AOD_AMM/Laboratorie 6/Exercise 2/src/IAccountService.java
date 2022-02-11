import java.sql.SQLException;

public interface IAccountService 
{
	//User Table
	public void createUser() throws SQLException;
	public void changePassword() throws SQLException;
	public void deleteUser() throws SQLException;
	public void selectAllUsers() throws SQLException;
	public void changeEmail() throws SQLException;
	public void changePhoneNumber() throws SQLException;
	//Address Table
	public void changeAddress() throws SQLException;
	public void deleteAddress() throws SQLException;
	public void createAddress() throws SQLException;
	public void selectAllAddress() throws SQLException;
}
