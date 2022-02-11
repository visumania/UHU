import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class StarTrekTDD 
{
	String mapGlobal [][];
	
	int posEnterpriceX;
	int posEnterpriceY;
		
	int nKlington;
	int nStarfleet;
	int nStars;
	
	int nStarDates;
	int nEnergy;
	
	public StarTrekTDD()
	{
		this.mapGlobal = new String [64][64];
		
		for(int i=0 ; i<64 ; i++) //First define the empty universe 
		{
			for(int j=0 ; j<64 ; j++)
			{
				mapGlobal[i][j]=".";
			}
		}
		
		this.posEnterpriceX = 31;
		this.posEnterpriceY = 31;
		this.mapGlobal[this.posEnterpriceX][this.posEnterpriceY] = "<*>"; //Setting the initial position of the EP (center)
		
		this.nKlington = 7;
		this.nStarfleet = 2;
		this.nStars = 20;
		
		this.nStarDates = 30;
		this.nEnergy = 600;
		
		Random r;
		int posX ,posY;
		int i=0;
				
		while(i<this.nKlington) //Random position of the klington
		{
			r = new Random();
			posX = r.nextInt(64);
			posY = r.nextInt(64);
			
			if(this.mapGlobal[posX][posY].equals("."))
			{
				this.mapGlobal[posX][posY] = "+++";
				i++;
			}
		}
		
		i=0;
		
		while(i<this.nStarfleet) //Random position of the start fleet
		{
			r = new Random();
			posX = r.nextInt(64);
			posY = r.nextInt(64);
			
			if(this.mapGlobal[posX][posY].equals("."))
			{
				this.mapGlobal[posX][posY] = ">!<";
				i++;
			}
		}
		
		i=0;
		
		while(i<this.nStars) //Random position of the stars
		{
			r = new Random();
			posX = r.nextInt(64);
			posY = r.nextInt(64);
			
			if(this.mapGlobal[posX][posY].equals("."))
			{
				this.mapGlobal[posX][posY] = "*";
				i++;
			}
		}
	}
	
	public void viewAllMap()
	{
		for(int i=0 ; i<64 ; i++)
		{
			System.out.print("\t" + (i));
		}
		
		System.out.println();
		
		for(int i=0 ; i<64 ; i++)
		{
			System.out.print("\t_");
		}
		
		for(int i=63 ; i>=0 ; i--)
		{
			System.out.println();
			System.out.print((i) + "|");
			
			for(int j=0 ; j<64 ; j++)
			{
				System.out.print("\t" + this.mapGlobal[j][i]);
			}
			
			System.out.print("\t|" + (i));
		}
		
		System.out.println();
		
		for(int i=0 ; i<64 ; i++)
		{
			System.out.print("\t_");
		}
		
		System.out.println();
		
		for(int i=0 ; i<64 ; i++)
		{
			System.out.print("\t" + (i));
		}
	}
	
	public void statusReport() //OK
	{
		System.out.println("\nRemaining energy: " + this.nEnergy);
		System.out.println("Enterprice in quadrant (" + ((this.posEnterpriceX)/8) + "," + ((this.posEnterpriceY)/8) + ") , sector (" + ((this.posEnterpriceX)%8) + "," + ((this.posEnterpriceY)%8) + ")");
		System.out.println("Reaiming stardates: " + this.nStarDates);
	}
	
	public boolean moveEnterprise(int vectorX , int vectorY)
	{
		boolean ret = true; 
		
		int initialQX = this.posEnterpriceX/8;
		int initialQY = this.posEnterpriceY/8;
		
		boolean changeQ=false;
		
		if(this.posEnterpriceX+vectorX<64 && this.posEnterpriceX>=0 &&this.posEnterpriceY+vectorY<64 && this.posEnterpriceY>=0) //No go outside of the galaxy
		{
			if(this.nEnergy-(Math.abs(vectorX+vectorY))>0) //We check that there is enough energy left
			{
				this.mapGlobal[this.posEnterpriceX][this.posEnterpriceY] = "."; //Update the content of the position
				
				if(this.nStarDates-(Math.abs(initialQX-vectorX/8)+(Math.abs(initialQY-vectorY/8)))<=0 && this.nKlington>0) //We check that there is enough star date left and klington
				{
					ret = false;
					System.out.println("Insufficiente amount of stardates");
				}
				else
				{
					if(Math.abs(initialQX-vectorX/8)+(Math.abs(initialQY-vectorY/8)) != 0)
						changeQ=true;
					
					if(this.mapGlobal[this.posEnterpriceX+vectorX][this.posEnterpriceY+vectorY].equals(".")) //The position is empty
					{
						this.posEnterpriceX+=vectorX;
						this.posEnterpriceY+=vectorY;
						this.nEnergy -= (Math.abs(vectorX+vectorY));
						this.mapGlobal[this.posEnterpriceX][this.posEnterpriceY] = "<*>";
						this.nStarDates -= (Math.abs(initialQX-this.posEnterpriceX/8)+(Math.abs(initialQY-this.posEnterpriceY/8)));
						
						if(changeQ==true)
							this.randomGalaxy(); //As the quadrant changes the positions of the objects change randomly throughout the galaxy
						
						int i=0;
						int j=0;

						boolean adjacent = false;
						
						while(i<64 && !adjacent)
						{
							j=0;
							
							while(j<64 && !adjacent)
							{
								if(this.mapGlobal[i][j].equals(">!<")) //Find an star fleet
								{
									if((this.posEnterpriceX/8)==(i/8) && (this.posEnterpriceY/8)==(j/8)) //Same quadrant
									{
										if((Math.abs((this.posEnterpriceX%8)-(i%8))==1 && Math.abs((this.posEnterpriceY%8)-(j%8))==0) || Math.abs((this.posEnterpriceX%8)-(i%8))==0 && Math.abs((this.posEnterpriceY%8)-(j%8))==1) //Adjacent sector
										{
											this.nEnergy = 600; //Restore to the max valor of the energy
											adjacent = true;
										}
									}
								}
								
								if(!adjacent)
									j++;
							}
							
							if(!adjacent)
								i++;
						}
						
						//Escribir código para que reciba ataque solamente en el caso de que en mi cuadrante haya una nave kilgon
						
						int nK =0;
						int damageX=0;
						int damageY=0;
						
						for(int z=posEnterpriceX-(posEnterpriceX%8)+7 ; z>=posEnterpriceX-(posEnterpriceX%8) ; z--)
						{							
							for(int k=posEnterpriceY-(posEnterpriceY%8) ; k<posEnterpriceY-(posEnterpriceY%8)+8 ; k++)
							{
								if(mapGlobal[z][k].equals("+++"))
								{
									nK++;
									
									damageX = Math.abs(posEnterpriceX-z);
									damageY = Math.abs(posEnterpriceY-k);
									
									System.out.println("Damage X: " + damageX + "\tDamage Y: " + damageY);
									
									double random = Math.random();
																		
									double probability= damageX+damageY+4;
									probability = 5/probability;
									probability = probability/100;
									
									System.out.println("Random: " + random + "\tProbability: " + probability);
									
									if(random>probability)
									{
										nEnergy -= (damageX+damageY);
										System.out.println("Damage done.");
									}
									
									System.out.println("Damage received by the kilgon " + nK + ": " + (damageX+damageY));
								}
							}
						}
						
						System.out.println("\n" + nK + " kilgons in this quadrant");
					}
					else
					{
						ret = false; 
						System.out.println("The position is not empty");
					}
				}
			}
			else
				System.out.println("Error, insufficient amount of energy to perform the movement");
		}
		else
			System.out.println("Error, the coordinates are not within the galaxy. No move made");

		return ret; 
	}
	
	public int getNEnergy() //OK
	{
		return this.nEnergy;
	}
	
	public void shortRangeSensor() //OK
	{		
		
		int x=7;
		System.out.println();
		
		for(int i=0 ; i<8 ; i++)
		{
			System.out.print("\t" + (i));
		}
		
		System.out.println();
		
		for(int i=0 ; i<8 ; i++)
		{
			System.out.print("\t_");
		}
		
		for(int i=this.posEnterpriceY-((this.posEnterpriceY)%8)+7 ; i>=this.posEnterpriceY-((this.posEnterpriceY)%8) ; i--)
		{
			System.out.println();
			System.out.print(x + "|");
			
			for(int j=this.posEnterpriceX-((this.posEnterpriceX)%8) ; j<this.posEnterpriceX-((this.posEnterpriceX)%8)+8 ; j++)
			{
				System.out.print("\t" + this.mapGlobal[j][i]);
			}
			
			System.out.print("\t|" + x);
			x--;
		}
		
		System.out.println();
		
		for(int i=0 ; i<8 ; i++)
		{
			System.out.print("\t_");
		}
		
		System.out.println();
		
		for(int i=0 ; i<8 ; i++)
		{
			System.out.print("\t" + (i));
		}
	}
	
	public void longRangeSensor() //Diseñarla para el caso en el que este enterprise en una esquina
	{				
		int k;
		int b;
		int s;

		int initialQX = ((this.posEnterpriceX/8)-1)*8;
		int initialQY = ((this.posEnterpriceY/8)+1)*8;
		int finalQX = ((this.posEnterpriceX/8)+1)*8;
		int finalQY = ((this.posEnterpriceY/8)-1)*8;
		
		for(int i=initialQY+8 ; i>=finalQY+8 ; i-=8) //Movement quadrant Y
		{
			System.out.println();
			
			for(int j=initialQX ; j<=finalQX ; j+=8) //Movement quadrant X
			{
				k=0;
				b=0;
				s=0;
				
				for(int z=j ; z<j+8 ; z++) //Movement sector X
				{					
					for(int x=i ; x>=i-7 ; x--) //Movement sector Y
					{
						if(this.mapGlobal[z][x].equals("+++"))
							k++;
						
						if(this.mapGlobal[z][x].equals(">!<"))
							b++;
						
						if(this.mapGlobal[z][x].equals("*"))
							s++;
					}
				}
				
				System.out.print("\t" + k + b + s);
			}
		}
	}
	
	public void randomGalaxy() //Ok
	{
		for(int i=0 ; i<64 ; i++) //First redefine the empty universe 
		{
			for(int j=0 ; j<64 ; j++)
			{
				mapGlobal[i][j]=".";
			}
		}
		
		this.mapGlobal[this.posEnterpriceX][this.posEnterpriceY] = "<*>"; //Setting the actual position of the EP
		
		Random r;
		int posX ,posY;
		int i=0;
				
		while(i<this.nKlington) //Random position of the klington
		{
			r = new Random();
			posX = r.nextInt(64);
			posY = r.nextInt(64);
			
			if(this.mapGlobal[posX][posY].equals("."))
			{
				this.mapGlobal[posX][posY] = "+++";
				i++;
			}
		}
		
		i=0;
		
		while(i<this.nStarfleet) //Random position of the start fleet
		{
			r = new Random();
			posX = r.nextInt(64);
			posY = r.nextInt(64);
			
			if(this.mapGlobal[posX][posY].equals("."))
			{
				this.mapGlobal[posX][posY] = ">!<";
				i++;
			}
		}
		
		i=0;
		
		while(i<this.nStars) //Random position of the stars
		{
			r = new Random();
			posX = r.nextInt(64);
			posY = r.nextInt(64);
			
			if(this.mapGlobal[posX][posY].equals("."))
			{
				this.mapGlobal[posX][posY] = "*";
				i++;
			}
		}
		
	}
		
	public int battleMode(int amountEnergy) // 0->normal battle 1->win game 2-->lose game
	{		
		int klingonX=0;
		int klingonY=0;
		int shieldK=0;
		
		int ret = 0;
				
		for(int i=0 ; i<64 ; i++) //Movement vectorX
		{
			for(int j=0 ; j<64 ; j++) //Movement vectorY
			{
				if(this.mapGlobal[i][j].equals("+++"))
				{
					if(klingonX==0 && klingonY==0)
					{
						klingonX=i;
						klingonY=j;
					}
					
					if(Math.abs(posEnterpriceX-i)+Math.abs(posEnterpriceY-j)<Math.abs(posEnterpriceX-klingonX)+Math.abs(posEnterpriceY-klingonY))
					{
						klingonX = i;
						klingonY = j;
					}
				}
			}
		}
		
		if(klingonX!=0 || klingonY!=0)
		{
			shieldK = (int) (Math.random() * (75 - 25)) + 25;
			
			if(shieldK-amountEnergy<=0)
			{
				System.out.println("klingon of position (" + klingonX + "," + klingonY + ") destroyed");
				nKlington--;
				System.out.println(this.nKlington + " klingon remaining");
				this.mapGlobal[klingonX][klingonY] = ".";
				this.nEnergy-=amountEnergy;
				
				if(this.nKlington==0)
					ret = 1;
			}
			else
			{
				System.out.println("Klingon endured the attack with his shield, now he attack");
				
				double random = Math.random();
				
				double probability= klingonX+klingonY+4;
				probability = 5/probability;
				probability = probability/100;
				
				System.out.println("Random: " + random + "\tProbability: " + probability);
				
				if(random>probability)
				{
					nEnergy -= (klingonX+klingonY);
					System.out.println("Damage done.");
				}
				
				System.out.println("Damage received by the kilgon: " + (klingonX+klingonY));
				
				if(this.nEnergy<=0)
					ret=2;
			}			
		}
		
		return ret;
	}
	
	public void mapGalaxy() //OK
	{
		int k;
		int b;
		int s;
		
		int l=7;
		
		for(int i=0 ; i<8 ; i++)
		{
			System.out.print("\t " + (i));
		}
		
		System.out.println();
		
		for(int i=0 ; i<8 ; i++)
		{
			System.out.print("\t___");
		}
		
		
		for(int i=63 ; i>=0 ; i-=8) //Movement quadrantY
		{
			System.out.println();
			System.out.print(l +"|");
			
			for(int j=0 ; j<64 ; j+=8) //Movement quadrantX
			{	
				k=0;
				b=0;
				s=0;
				
				for(int z=j ; z<j+8 ; z++) //Movement sector X
				{					
					for(int x=i ; x>=i-7 ; x--) //Movement sector Y
					{
						if(this.mapGlobal[z][x].equals("+++"))
							k++;
						
						if(this.mapGlobal[z][x].equals(">!<"))
							b++;
						
						if(this.mapGlobal[z][x].equals("*"))
							s++;
					}
				}
				
				System.out.print("\t" + k + b + s);
			}	
			
			System.out.print("\t|" + l);
			l--;
		}
		
		System.out.println();
		
		for(int i=0 ; i<8 ; i++)
		{
			System.out.print("\t___");
		}
		
		System.out.println();
		
		for(int i=0 ; i<8 ; i++)
		{
			System.out.print("\t " + (i));
		}
	}
	
	public static void main(String []args) throws IOException
	{
		Scanner keyboard = new Scanner(System.in);
		int opt; 
		//String level;
		StarTrekTDD st = new StarTrekTDD();
		
		System.out.println("**** STAR TREK 1977 (REMASTERED) **** © Adrián Moreno Monterde\n");
		
		/*do
		{
			System.out.print("The are three levels of difficulty: junior/mid/senior. Please choose one (j/m/s): ");
			level = keyboard.next();
			
			if(!level.equals("j") && !level.equals("m") && !level.equals("s") && !level.equals("J") && !level.equals("M") && !level.equals("S"))
			{
				System.out.println("WRONG OPTION");
				System.out.println("Press enter to continue...");
				System.in.read();
			}
		}while(!level.equals("j") && !level.equals("m") && !level.equals("s") && !level.equals("J") && !level.equals("M") && !level.equals("S"));*/
		
		
		do
		{
			st.statusReport();
			
			System.out.println("\n0.- Manoeuvring of Enterprise");
			System.out.println("1.- Scanning the galaxy --> Short-range sensor scan");
			System.out.println("2.- Scanning the galaxy --> Long-range sensor scan");
			System.out.println("3.- Battle protocol");
			System.out.println("4.- Map of the galaxy");
			System.out.println("5.- Detailed map of the galaxy");
			System.out.println("6.- Exit game");
			System.out.print("Choose an option: ");
			opt = keyboard.nextInt();
			
			switch(opt)
			{
				case 0:
					int vectorX, vectorY;
					
					System.out.println("X axis movement: ");
					vectorX = keyboard.nextInt();
					
					System.out.println("Y axis movement: ");
					vectorY = keyboard.nextInt();
					
					if(st.moveEnterprise(vectorX, vectorY) == false)
					{
						System.out.println("You lose this game ...");
						System.exit(0);
					}					
				break;
				
				case 1:					
					st.shortRangeSensor();
					
					//System.out.println("\n\nPress enter to continue");
					//System.in.read();
				break;
				
				case 2:					
					st.longRangeSensor();
					
					//System.out.println("\n\nPress enter to continue");
					//System.in.read();
				break;
				
				case 3:					
					int amountEnergy;
					
					System.out.println("The klingon ship has a random valor between 25-75 units of energy");
					
					do
					{
						System.out.println("Amount of energy avaliable: " + st.getNEnergy());
						System.out.print("\nInsert the amount of energy that you want to shoot: ");
						amountEnergy = keyboard.nextInt();
						
						if(amountEnergy>0)
						{
							int v = st.battleMode(amountEnergy);
							
							if(v==1)// 0->normal battle 1->win game 2-->lose game
							{
								System.out.println("CONGRATULATIONS!!! You win this game :)");
								System.exit(0);
							}
							
							if(v==2)// 0->normal battle 1->win game 2-->lose game
							{
								System.out.println("You lose this game...");
								System.exit(0);
							}
						}
						else
						{
							if(amountEnergy<0)
								System.out.println("The amount of energy have to be a positive number");
						}
					}while(amountEnergy!=0);
					
					System.out.println("\nReturning to the normal commands mode ...");
					//System.out.println("Press enter to continue");
					//System.in.read();
				break;
				
				case 4:					
					st.mapGalaxy();

					//System.out.println("\n\nPress enter to continue");
					//System.in.read();
				break;
				
				case 5:
					System.out.println("\n\n");
					
					st.viewAllMap();

					//System.out.println("\n\nPress enter to continue");
					//System.in.read();
				break;
				
				case 6:
				break;
				
				default:
				{
					System.out.println("\nIncorrect option...");
					System.out.println("Press enter to continue");
					System.in.read();
				}
			}
				
		}while(opt!=6);
		
		System.out.println("\nEnding the programm");
		System.out.println("Press enter to finalize ...");
		System.in.read();
		
		keyboard.close();
	}
}
