import java.io.IOException;
import java.sql.SQLException;
import java.util.Scanner;

public class Test 
{
	public static void main(String []args) throws IOException, SQLException
	{
		Scanner keyboard = new Scanner(System.in);
		int opt; 
		

		AccountService as = new AccountService();
		DeliveryService ds = new DeliveryService();
		
		do
		{
			
			System.out.println("-----DATABASE-----\n");
			System.out.println("-----User Table-----");
			System.out.println("1.- Create User");
			System.out.println("2.- Change Password");
			System.out.println("3.- Delete User");
			System.out.println("4.- View all Users");
			System.out.println("5.- Change Email");
			System.out.println("6.- Change Phone Number");
			System.out.println("-----Address Table-----");
			System.out.println("7.- Delete Address");
			System.out.println("8.- Create Address");
			System.out.println("9.- View all Address");
			System.out.println("-----Meal Table-----");
			System.out.println("10.- Create Meal");
			System.out.println("11.- Delete Meal");
			System.out.println("12.- View all Meals");
			System.out.println("13.- Modify price");
			System.out.println("14.- Modify Possible Number Of Orders");
			System.out.println("-----Order Table-----");
			System.out.println("15.- Create Order");
			System.out.println("16.- Delete Order");
			System.out.println("17.- View all orders");
			System.out.println("18.- END PROGRAM");
			System.out.print("\nChoose an option: ");
			opt = keyboard.nextInt();
			
			switch(opt)
			{
				case 1:
					as.createUser();
				break;
				
				case 2:
					as.changePassword();
				break;
				
				case 3:
					as.deleteUser();
				break;
				
				case 4:
					as.selectAllUsers();
				break;
				
				case 5:
					as.changeEmail();
				break;
				
				case 6:
					as.changePhoneNumber();
				 break;
				 
				case 7:
					as.deleteAddress();
				break;
				
				case 8:
					as.createAddress();
				break;
				
				case 9:
					as.selectAllAddress();
				break;
				
				case 10:
					ds.createMeal();
				break;
				
				case 11:
					ds.deleteMeal();
				break;
				
				case 12:
					ds.selectAllMeals();
				break;
				
				case 13:
					ds.modifyPrice();
				break;
				
				case 14:
					ds.modifyPossibleNumberOfOrders();
				break;
				
				case 15:
					ds.createOrder();
				break;
				
				case 16:
					ds.deleteOrder();
				break;
			
				case 17:
					ds.selectAllOrders();
				break;
				
				case 18:
					System.out.println("Exiting ...");
				break;
				
				default:
				{
					System.out.println("Incorrect option ...");
				}
			}
		
		}while(opt!=18);
		
		
		System.out.println("Press enter to finalize ...");
		System.in.read();
		
		keyboard.close();
	}
}

