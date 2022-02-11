import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class OnlineShop 
{
	public static void main(String []args) throws IOException
	{
		int opt=0; 
		String name; 
		int amount; 
		int id=1;
		float totalAmount=0;
		Scanner keyboard = new Scanner(System.in);
		ArrayList<Product> products = new ArrayList<Product>();
		ArrayList<Product> shoppingCart = new ArrayList<Product>();
		ArrayList<Integer> amountProduct = new ArrayList<Integer>();
		
		//Initial insertion of products
		products.add(new Product("Mobile phone", 250));
		products.add(new Product("SmartWatch", 125));
		products.add(new Product("TV 4K 43inches", 1000));
		products.add(new Product("Robot vacuum cleaner", 400));
		products.add(new Product("Microwave", 30));
		products.add(new Product("Expresso coffe maker", 50));
		products.add(new Product("Toaster", 10));
		products.add(new Product("Mask", (float) 0.99));


		System.out.println("Welcome to MEGABIEDRONKA ONLINE ***********\n");
		
		do
		{
			System.out.println("1.- See catalog of avaliable products");
			System.out.println("2.- View shopping cart and payment account");
			System.out.println("3.- Add product to cart");
			System.out.println("4.- Finalize purchase");
			System.out.println("5.- Exit MEGABIENDRONKA ONLINE");
			System.out.print("Choose an option: ");
			opt = keyboard.nextInt();
			
			switch(opt)
			{
				case 1:
					System.out.println("\nPrice($)\t\tProduct");
					System.out.println("____________________________________________");
					for(int i=0 ; i<products.size() ; i++)
						System.out.println(products.get(i).getPrice() + "\t\t\t" + products.get(i).getName());
				break;
				
				case 2:
					if(shoppingCart.isEmpty() && amountProduct.isEmpty())
						System.out.println("\nYour shopping cart is empty");
					else
					{
						System.out.println("\nAmount\t\t\tPrice($)\t\tProduct"); 
						System.out.println("_____________________________________________________________");
						
						for(int i=0 ; i<shoppingCart.size() ; i++)
						{
							System.out.println(amountProduct.get(i) + "\t\t\t" + shoppingCart.get(i).getPrice() + "\t\t\t" + shoppingCart.get(i).getName());
							totalAmount += (amountProduct.get(i)*shoppingCart.get(i).getPrice());
						}
						
						System.out.println("_____________________________________________________________");
						System.out.println("\nPurchase price: " + totalAmount + " $");
						totalAmount = 0;
					}
				break;
				
				case 3:
					keyboard.nextLine(); //Clean the buffer
					boolean find=false;
					int i=0;
					
					System.out.print("\nInsert product name: ");
					name = keyboard.nextLine();
					
					while(!find && i<products.size())
					{
						if(name.equals(products.get(i).getName()))
							find = true;
						else
							i++;
					}
					
					if(find)
					{
						System.out.print("Enter the " + name + " units you want: ");
						amount = keyboard.nextInt();
						
						shoppingCart.add(new Product(name,products.get(i).getPrice()));
						amountProduct.add(amount);
					}
					else
						System.out.println("Unfortunately, we do not have that product in stock right now");
				break;
				
				case 4:
					int optPayment;
					
					if(shoppingCart.isEmpty() && amountProduct.isEmpty())
						System.out.println("\nYou can't pay anything because your cart is empty");
					else
					{
						do
						{
							System.out.println("\nPayment menu\n");
							System.out.println("1.- Credit card");
							System.out.println("2.- Bank transfer");
							System.out.print("Please select the way you are going to pay: ");
							optPayment = keyboard.nextInt();
							
							keyboard.nextLine(); //Clean the buffer
							
							switch(optPayment)
							{
								case 1:
									String cardNumber; 
									String expiryDate;
									
									System.out.print("\nInsert the card number in the format XXXX XXXX XXXX XXXX: ");
									cardNumber = keyboard.nextLine();
									
									System.out.print("Insert the expiry date of the card(mm/yy): ");
									expiryDate = keyboard.nextLine();
																										
									System.out.println("\nAmount\t\t\tPrice($)\t\tProduct"); 
									System.out.println("_____________________________________________________________");
									
									for(int i1=0 ; i1<shoppingCart.size() ; i1++)
									{
										System.out.println(amountProduct.get(i1) + "\t\t\t" + shoppingCart.get(i1).getPrice() + "\t\t\t" + shoppingCart.get(i1).getName());
										totalAmount += (amountProduct.get(i1)*shoppingCart.get(i1).getPrice());
									}
									
									Card c = new Card(id,"Pay with card in MEGABIEDRONKA ONLINE","NaN",totalAmount,cardNumber, expiryDate);
									
									if(c.generateOrderConfirmation(totalAmount))
									{
										c.registerPayment();
										System.out.println("\nThank you for using the Megabiedronka online store, come back soon :)");
										shoppingCart = new ArrayList<Product>(); //Empty the contents of the cart
										amountProduct = new ArrayList<Integer>(); //Empty the number of products that the client has in his cart
										id++;
									}

									totalAmount = 0; //Reset the amount of money 
								break;
								
								case 2:
									String accountNumber; 
									
									System.out.print("\nInsert your account number in the format PLXX XXXX XXXX XXXX XXXX XXXX XXXX: PL");
									accountNumber = keyboard.nextLine(); 
									
									System.out.println("\nAmount\t\t\tPrice($)\t\tProduct"); 
									System.out.println("_____________________________________________________________");
									
									for(int i1=0 ; i1<shoppingCart.size() ; i1++)
									{
										System.out.println(amountProduct.get(i1) + "\t\t\t" + shoppingCart.get(i1).getPrice() + "\t\t\t" + shoppingCart.get(i1).getName());
										totalAmount += (amountProduct.get(i1)*shoppingCart.get(i1).getPrice());
									}
									
									BankTransfer bt = new BankTransfer(id, "Pay with bank transfer in MEGABIEDRONKA ONLINE", "NaN", totalAmount, accountNumber);
									
									if(bt.generateOrderConfirmation(totalAmount))
									{
										bt.registerPayment();
										System.out.println("\nThank you for using the Megabiedronka online store, come back soon :)");
										shoppingCart = new ArrayList<Product>(); //Empty the contents of the cart
										amountProduct = new ArrayList<Integer>(); //Empty the number of products that the client has in his cart
										id++;
									}
									else
										System.out.println("Error, there is not enough money in the bank account to make the payment");
									
									totalAmount = 0; 
								break;
								
								default:
								{
									System.out.println("Error. Incorrect option");
								}
							}
							
							System.out.println("\nPress enter to continue...");
							System.in.read();
							
						}while(optPayment!=1 && optPayment!=2);
					}
				break;
				
				case 5:
					System.out.println("Coming out...");
				break;
				
				default:
				{
					System.out.println("Error. Incorrect option");
				}
			}
			
			System.out.println("\n\nPress enter to continue...");
			System.in.read();
			
		}while(opt!=5);
		
		keyboard.close();
	}
}
