import java.sql.*;
import java.util.Scanner;

public class AccountService implements IAccountService
{
	private Statement statement = null;
	private Scanner keyboard = new Scanner(System.in);
	
	public static Connection cn = null;
	
	public static Connection con()
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			cn = DriverManager.getConnection("jdbc:mysql://localhost/Exercise1_Lab6","root","casona98");
		}catch(Exception ex)
		{
			System.out.println(ex.getMessage());
		}
		
		return cn;
	}
	
	@Override
	public void createUser() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert Username: "); 
			String userName = keyboard.next(); 
			keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert Name: "); 
			String name = keyboard.nextLine();
			//keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert Surname: ");
			String surname = keyboard.nextLine();
			//keyboard.nextLine();//Clean buffer

			System.out.print("Insert Password: ");
			String password = keyboard.nextLine();
			//keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert Email: ");
			String email = keyboard.next();
			keyboard.nextLine();//Clean buffer

			System.out.print("Insert Date of Registration (dd/mm/yyyy): ");
			String dto = keyboard.next();
			keyboard.nextLine();//Clean buffer

			System.out.print("Insert Phone Number (+PPXXXXXXXXX): ");
			String phoneNumber = keyboard.next();
			keyboard.nextLine();//Clean buffer

			String selectedTableSQL = "INSERT INTO USER (Username,Name,Surname,Password,Email,DateOfRegistration,PhoneNumber) "
									+ "VALUES ('"+userName+"','"+name+"','"+surname+"','"+password+"','"+email+"','"+dto+"',"+phoneNumber+");";
			
			statement.executeUpdate(selectedTableSQL);
			
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}
	
	@Override
	public void changePassword() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdUser: ");
			String id = keyboard.nextLine();
			//keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert new Password: ");
			String password = keyboard.next();
			//keyboard.nextLine(); //Clean buffer
			
			String selectedTableSQL = "UPDATE USER SET Password = '"+password+"' WHERE IdUser = "+id;
			
			statement.executeUpdate(selectedTableSQL);
			
			
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}
	
	@Override
	public void changeAddress() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdAddress: ");
			String id = keyboard.nextLine();
			//keyboard.nextLine();//Clean buffer
			
			String selectedTableSQL = "DELETE FROM ADDRESS WHERE IdAddress=" +id;
			
			statement.executeUpdate(selectedTableSQL); //OK
			
			System.out.print("Insert city: ");
			String city = keyboard.nextLine();
			
			System.out.print("Insert street: ");
			String street = keyboard.nextLine();
			
			System.out.print("Insert house number: ");
			int numberHouse = keyboard.nextInt();
			
			System.out.print("Insert Zip code (XX-XXX): ");
			String zipCode = keyboard.next();
			
			selectedTableSQL = "INSERT INTO ADDRESS (City,Street,HouseNumber,ZipCODE)" +
							   " VALUES ('"+city+"','"+street+"',"+numberHouse+",'"+zipCode+"')";
					
			statement.executeUpdate(selectedTableSQL);	//OK
			
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}
	
	@Override
	public void deleteUser() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdUser: ");
			String id = keyboard.next();
			
			String selectedTableSQL = "DELETE FROM USER WHERE IdUser="+id;
			
			statement.executeUpdate(selectedTableSQL);
			
			
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}
	
	@Override
	public void selectAllUsers() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			String selectedTableSQL = "SELECT * FROM USER";
			ResultSet rs = statement.executeQuery(selectedTableSQL);
			
			while(rs.next())
			{
				int id = rs.getInt("IdUser");
				String userName = rs.getString("Username");
				String name = rs.getString("Name");
				String surname = rs.getString("Surname");
				String password = rs.getString("Password");
				String email = rs.getString("Email");
				String dateOfRegistration = rs.getString("DateOfRegistration");
				String phoneNumber = rs.getString("PhoneNumber");
				
				System.out.println("\nIdUser: " + id);
				System.out.println("Username: " + userName);
				System.out.println("Name: " + name);
				System.out.println("Surname: " + surname);
				System.out.println("Password: " + password);
				System.out.println("Email: " + email);
				System.out.println("Date of Registration: " + dateOfRegistration);
				System.out.println("Phone number: " + phoneNumber);
			}
			
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}
	
	@Override
	public void changeEmail() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdUser: ");
			int id = keyboard.nextInt();
			//keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert new email: ");
			String email = keyboard.next();
			keyboard.nextLine(); //clean buffer
			
			String selectedTableSQL = "UPDATE USER SET Email='" + email + "' WHERE IdUser = "+id;
			
			statement.executeUpdate(selectedTableSQL);
						
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}

	@Override
	public void changePhoneNumber() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdUser: ");
			int id = keyboard.nextInt();
			//keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert new phone number: ");
			String phone = keyboard.next();
			keyboard.nextLine(); //clean buffer
			
			String selectedTableSQL = "UPDATE USER SET PhoneNumber='" + phone + "' WHERE IdUser = "+id;
			
			statement.executeUpdate(selectedTableSQL);
						
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
		
	}

	@Override
	public void deleteAddress() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdAddress: ");
			int id = keyboard.nextInt();
			//keyboard.nextLine();//Clean buffer
						
			String selectedTableSQL = "DELETE FROM ADDRESS WHERE IdAddress="+id;
			
			statement.executeUpdate(selectedTableSQL);
						
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}

	@Override
	public void createAddress() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert City: ");
			String city = keyboard.nextLine();
			
			System.out.print("Insert Street: ");
			String street = keyboard.nextLine();
			
			System.out.print("Insert House Number: ");
			int houseNumber = keyboard.nextInt();
			
			System.out.print("Insert ZIP Code XX-XXX: ");
			String zipCode = keyboard.next();
						
			String selectedTableSQL = "INSERT INTO ADDRESS (City,Street,HouseNumber,ZipCODE)" +
					   				  " VALUES ('"+city+"','"+street+"',"+houseNumber+",'"+zipCode+"')";
			
			statement.executeUpdate(selectedTableSQL);
						
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}
	
	public void selectAllAddress() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			String selectedTableSQL = "SELECT * FROM ADDRESS";
			ResultSet rs = statement.executeQuery(selectedTableSQL);
			
			while(rs.next())
			{
				int id = rs.getInt("IdAddress");
				String city = rs.getString("City");
				String street = rs.getString("Street");
				int houseNumber = rs.getInt("HouseNumber");
				String zipCode = rs.getString("ZipCODE");
				
				System.out.println("\nIdAddress: " + id);
				System.out.println("City: " + city);
				System.out.println("Street: " + street);
				System.out.println("House Number: " + houseNumber);
				System.out.println("ZIP Code: " + zipCode);
			}
			
		} catch (SQLException e) 
		{
			System.out.println(e.getMessage());
		} finally
		{
			if(statement != null)
				statement.close();
			
			if(cn != null)
				cn.close();
		}
	}

	
	public static void main(String []args) throws SQLException
	{
		if(Conexion.con() != null)
		{
			System.out.println("Successful connection");
			AccountService as = new AccountService();
			
			
			as.selectAllAddress();
			System.out.println();
			
			as.createAddress();
			
			System.out.println();
			as.selectAllAddress();
		}
		else
			System.out.println("Connection error");
	}
}
