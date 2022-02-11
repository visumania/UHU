import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class DeliveryService implements IDeliveryService
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
	public void createMeal() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert Meal name: "); 
			String mealName = keyboard.next(); 
			keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert price: "); 
			float price = keyboard.nextFloat();
			//keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert possible number of orders: ");
			int pno = keyboard.nextInt();
			//keyboard.nextLine();//Clean buffer

			System.out.print("Is vegetarian that meal?(y/n): ");
			String veg = keyboard.next();
			keyboard.nextLine();//Clean buffer
			boolean isVegan=false;
			
			if(veg.equals("y"))
				isVegan = true;
				
			String selectedTableSQL = "INSERT INTO MEAL(Name,Price,PossibleNumberOfOrders,IsVegetarian) " +
									  " VALUES ('"+mealName+"',"+price+","+pno+","+isVegan+")";
			
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
	public void deleteMeal() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdMeal: ");
			String id = keyboard.next();
			
			String selectedTableSQL = "DELETE FROM MEAL WHERE IdMeal="+id;
			
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
	public void selectAllMeals() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			String selectedTableSQL = "SELECT * FROM MEAL";
			ResultSet rs = statement.executeQuery(selectedTableSQL);
			
			while(rs.next())
			{
				int id = rs.getInt("IdMeal");
				String name = rs.getString("Name");
				float price = rs.getFloat("Price");
				int pon = rs.getInt("PossibleNumberOfOrders");
				boolean isVeg = rs.getBoolean("IsVegetarian");
				
				System.out.println("\nId Meal: " + id);
				System.out.println("Name: " + name);
				System.out.println("Price: " + price);
				System.out.println("Possible number of Orders: " + pon);
				System.out.println("Is Vegetarian: " + isVeg);
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
	public void modifyPrice() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdMeal: ");
			String id = keyboard.nextLine();
			//keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert new Price: ");
			float price = keyboard.nextFloat();
			//keyboard.nextLine(); //Clean buffer
			
			String selectedTableSQL = "UPDATE MEAL SET Price = "+price+" WHERE IdMeal = "+id;
			
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
	public void modifyPossibleNumberOfOrders() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdMeal: ");
			String id = keyboard.nextLine();
			//keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert new possible number of orders: ");
			int num = keyboard.nextInt();
			//keyboard.nextLine(); //Clean buffer
			
			String selectedTableSQL = "UPDATE MEAL SET PossibleNumberOfOrders = "+num+" WHERE IdMeal = "+id;
			
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
	public void createOrder() throws SQLException //Fails
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert Id order: ");
			int idOrder = keyboard.nextInt();
			
			System.out.print("Insert Meal name: "); 
			String mealName = keyboard.next(); 
			keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert Order date (dd/mm/yyyy): "); 
			String orderDate = keyboard.next();
			keyboard.nextLine();//Clean buffer
			
			System.out.print("Insert Order time (hh:mm): "); 
			String orderTime = keyboard.next();
			keyboard.nextLine();//Clean buffer
				
			String selectedTableSQL = "INSERT INTO ORD3R(IdOrder,NameMeal,OrderDate,OrderTime)" +
					"VALUES ("+idOrder+",'"+mealName+"','"+orderDate+"','"+orderTime+"')";
			
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
	public void deleteOrder() throws SQLException //OK
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			
			System.out.print("Insert IdOrder: ");
			String id = keyboard.next();
			
			String selectedTableSQL = "DELETE FROM ORD3R WHERE IdOrder="+id;
			
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
	public void selectAllOrders() throws SQLException //Ok
	{
		try 
		{
			cn = con();
			statement = cn.createStatement();
			String selectedTableSQL = "SELECT * FROM ORD3R";
			ResultSet rs = statement.executeQuery(selectedTableSQL);
			
			while(rs.next())
			{
				int idUser = rs.getInt("IdUser");
				String nameMeal = rs.getString("NameMeal");
				String orderDate = rs.getString("OrderDate");
				String orderTime = rs.getString("OrderTime");
				int idOrder = rs.getInt("IdOrder");
				
				System.out.println("\nIdOrder: " + idOrder);
				System.out.println("IdUser: " + idUser);
				System.out.println("Name meal: " + nameMeal);
				System.out.println("Order date: " + orderDate);
				System.out.println("Order time: " + orderTime);
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
		DeliveryService ds = new DeliveryService();
		
		ds.selectAllOrders();
		ds.createOrder();
		ds.selectAllOrders();
	}

}
