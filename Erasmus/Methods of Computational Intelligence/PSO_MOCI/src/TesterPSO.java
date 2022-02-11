import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

class Particle
{
	double velocity[];
	double position[];
	float k; //Clamping factor
	int vMax;
	int vMin;
	
	public Particle(int nVar , int vMax , int vMin)
	{
		Random r;
		
		this.vMax = vMax;
		this.vMin = vMin;
		
		this.velocity = new double[nVar];
		this.position = new double[nVar];
		
		for(int i=0 ; i<velocity.length ; i++)
			this.velocity[i] = 0; 
		
		for(int i=0 ; i<position.length ; i++)
		{
			r = new Random();
			this.position[i] = (r.nextDouble()*(vMax-vMin))+vMin;
		}
		
		this.k = (float) 0.5;
	}
	
	public void setVelocity(double vel , int index)
	{
		if(vel > (k*vMax))
			vel = k*vMax;
		else
		{
			if(vel < vMin)
				this.velocity[index] = k*vMin;
			else
				this.velocity[index] = vel; 
		}
	}
	
	public void setPosition(double pos , int index)
	{
		if(pos > vMax)
			this.position[index] = 10.0;
		else
		{
			if(pos < vMin)
				this.position[index] = -10.0;
			else
				this.position[index] = pos;
		}
	}
	
	public double getVelocity(int index)
	{
		return this.velocity[index];
	}
	
	public double getPosition(int index)
	{
		return this.position[index];
	}
}

class PSO
{
	private int nPop; //Number of population
	private Particle particles[];
	private int maxIt; //Number of iteration
	private float w; //Inertia coefficient
	private float c1; //Cognitive coefficient
	private float c2; //Social coefficient
	private double bestGlobal; //Fitness
	
	public PSO(int nVar, int varMin , int varMax)
	{
		this.nPop = 50; 
		this.maxIt = 100; 
		this.particles = new Particle[nPop];
		this.w = (float) 0.6; 
		this.c1 = (float) 1.0;
		this.c2 = (float) 1.0;
		this.bestGlobal = -1;
		
		for(int i=0 ; i<nPop ; i++)
			this.particles[i] = new Particle(nVar,varMax,varMin);
	}
	
	public double algorithmMax(int nVar , int varMin , int varMax , String function)
	{		
		double velocityNext = 0;
		double positionNext = 0;
		double inertia = 0;
		double cognitiveC = 0;
		double socialC = 0;
		Random r = new Random();
		this.bestGlobal = 0;
		double bestPersonal[] = new double[this.particles.length]; 
		
		for(int i=0 ; i<particles.length ; i++) // FIRST ROUTE WITH THE STARTING POSITIONS TO KNOW WHO HAS THE BEST OVERALL VALUE
		{
			for(int j=0 ; j<nVar ; j++)
			{
				if(i==0 && j==0)
					bestGlobal = this.function(particles[i].getPosition(j), function, nVar);
				
				if(bestGlobal < this.function(particles[i].getPosition(j), function, nVar))
					bestGlobal = this.function(particles[i].getPosition(j), function, nVar);
				
				if(j==0)
					bestPersonal[i] = this.function(particles[i].getPosition(j), function, nVar);
				
				if(bestPersonal[i] < this.function(particles[i].getPosition(j), function, nVar))
					bestPersonal[i] = this.function(particles[i].getPosition(j), function, nVar);

			}
		}
		
		for(int i=0 ; i<maxIt ; i++) //Number of iterations that we apply the algorithm
		{
			for(int j=0 ; j<particles.length ; j++) //We go through each particle one by one
			{
				for(int z=0 ; z<nVar ; z++) //We go through the number of variables (position and speed) that EACH PARTICLE has
				{
					inertia = (this.w*this.particles[j].getVelocity(z));
					cognitiveC = r.nextDouble()*this.c1*(bestPersonal[j]-this.particles[j].getPosition(z));
					socialC = r.nextDouble()*this.c2*(bestGlobal-this.particles[j].getPosition(z));
					
					velocityNext = inertia + cognitiveC + socialC;
					positionNext = this.particles[j].getPosition(z) + velocityNext;
					
					this.particles[j].setPosition(positionNext, z);
					this.particles[j].setVelocity(velocityNext, z);
					
					if(bestPersonal[j] < this.function(particles[j].getPosition(z), function, nVar))
						bestPersonal[j] = this.function(particles[j].getPosition(z), function , nVar);
					
					if(bestGlobal < this.function(particles[j].getPosition(z), function , nVar))
						bestGlobal = this.function(particles[j].getPosition(z), function , nVar);
				}
			}
		}
		
		return this.bestGlobal;
	}
	
	public double algorithmMin(int nVar , int varMin , int varMax , String function)
	{
		double velocityNext = 0;
		double positionNext = 0;
		double inertia = 0;
		double cognitiveC = 0;
		double socialC = 0;
		Random r = new Random();
		this.bestGlobal = 0;
		double bestPersonal[] = new double[this.particles.length]; 
		
		for(int i=0 ; i<particles.length ; i++) //FIRST ROUTE WITH THE STARTING POSITIONS TO KNOW WHO HAS THE BEST OVERALL VALUE
		{
			for(int j=0 ; j<nVar ; j++)
			{
				if(i==0 && j==0)
					bestGlobal = this.function(particles[i].getPosition(j), function , nVar);
				
				if(bestGlobal > this.function(particles[i].getPosition(j), function , nVar))
					bestGlobal = this.function(particles[i].getPosition(j), function , nVar);
				
				if(j==0)
					bestPersonal[i] = this.function(particles[i].getPosition(j), function , nVar);
				
				if(bestPersonal[i] > this.function(particles[i].getPosition(j), function , nVar))
					bestPersonal[i] = this.function(particles[i].getPosition(j), function , nVar);

			}
		}
		
		for(int i=0 ; i<maxIt ; i++) //Number of iterations that we apply the algorithm
		{
			for(int j=0 ; j<particles.length ; j++) //We go through each particle one by one
			{
				for(int z=0 ; z<nVar ; z++) //We go through the number of variables (position and speed) that EACH PARTICLE has
				{
					inertia = (this.w*this.particles[j].getVelocity(z));
					cognitiveC = r.nextDouble()*this.c1*(bestPersonal[j]-this.particles[j].getPosition(z));
					socialC = r.nextDouble()*this.c2*(bestGlobal-this.particles[j].getPosition(z));
					
					velocityNext = inertia + cognitiveC + socialC;
					positionNext = this.particles[j].getPosition(z) + velocityNext;
					
					this.particles[j].setPosition(positionNext, z);
					this.particles[j].setVelocity(velocityNext, z);
					
					if(bestPersonal[j] > this.function(particles[j].getPosition(z), function , nVar))
						bestPersonal[j] = this.function(particles[j].getPosition(z), function , nVar);
					
					if(bestGlobal > this.function(particles[j].getPosition(z), function , nVar))
						bestGlobal = this.function(particles[j].getPosition(z), function , nVar);
				}
			}
		}
		
		return this.bestGlobal;
	}
	
	public double function(double x,String func , int nVar)
	{
		double ret = 0;
		
		switch(func)
		{
			case "Sphere":
				for(int i=1 ; i<=nVar ; i++)
					ret += (x*x);
			break;
		
			case "Michalewicz":
				for(int i=1 ; i<=nVar ; i++)
					ret -= Math.sin(x)*Math.pow(Math.sin((i+1)*Math.pow(x,2)/Math.PI), 2*10);
			break;
			
			case "Rastrigin":
				ret = 10*nVar;
				
				for(int i=1 ; i<=nVar ; i++)
					ret += ((x*x)-(10*Math.cos(2*Math.PI*x)));
			break;
			
			case "Schwefel":
				ret = 418.9829*nVar;
				
				for(int i=1 ; i<=nVar ; i++)
					ret -= x*Math.sin(Math.sqrt(Math.abs(x)));
			break;
			
			case "Sum squares":
				for(int i=1 ; i<=nVar ; i++)
					ret += i*x*x;
			break;
		}
		
		return ret; 
	}
}

public class TesterPSO 
{
	public static void main(String []args) throws IOException
	{
		int opt;
		int nVar;
		int varMin , varMax;
		PSO pso;
		String m; 
		Scanner keyboard = new Scanner(System.in);
		
		do
		{
			System.out.println("Particle Swarm Optimization\tADRIAN MORENO MONTERDE ©\n");
			System.out.println("1.- Sphere function");
			System.out.println("2.- Michalewicz function");
			System.out.println("3.- Rastrigin function");
			System.out.println("4.- Schwefel function");
			System.out.println("5.- Sum squares function");
			System.out.println("6.- Exit");
			System.out.print("\nChoose an option: ");
			opt = keyboard.nextInt();
			
			switch(opt)
			{
				case 1:
					System.out.print("Enter number of unknown variables (decision): ");
					nVar = keyboard.nextInt();
					
					System.out.print("Enter lower limit of decision variables: ");
					varMin = keyboard.nextInt();
					
					System.out.print("Enter upper limit of decision variables: ");
					varMax = keyboard.nextInt();
					
					do
					{
						System.out.print("Do you want maximize or minimize the function?(max/min): ");
						m = keyboard.next();
						
					}while(!m.equals("max") && !m.equals("min") && !m.equals("MAX") && !m.equals("MIN"));
					
					pso = new PSO(nVar, varMin , varMax);
					
					if(m.equals("max") || m.equals("MAX"))
						System.out.println("Best global: " + pso.algorithmMax(nVar, varMin, varMax, "Sphere"));
					
					if(m.equals("min") || m.equals("MIN"))
						System.out.println("Best global: " + pso.algorithmMin(nVar, varMin, varMax, "Sphere"));					
				break;
					
				case 2:
					System.out.print("Enter number of unknown variables (decision): ");
					nVar = keyboard.nextInt();
					
					System.out.print("Enter lower limit of decision variables: ");
					varMin = keyboard.nextInt();
					
					System.out.print("Enter upper limit of decision variables: ");
					varMax = keyboard.nextInt();
					
					do
					{
						System.out.print("Do you want maximize or minimize the function?(max/min): ");
						m = keyboard.next();
						
					}while(!m.equals("max") && !m.equals("min") && !m.equals("MAX") && !m.equals("MIN"));
					
					pso = new PSO(nVar, varMin , varMax);
					
					if(m.equals("max") || m.equals("MAX"))
						System.out.println("Best global: " + pso.algorithmMax(nVar, varMin, varMax, "Michalewicz"));
					
					if(m.equals("min") || m.equals("MIN"))
						System.out.println("Best global: " + pso.algorithmMin(nVar, varMin, varMax, "Michalewicz"));					
				break;
				
				case 3:
					System.out.print("Enter number of unknown variables (decision): ");
					nVar = keyboard.nextInt();
					
					System.out.print("Enter lower limit of decision variables: ");
					varMin = keyboard.nextInt();
					
					System.out.print("Enter upper limit of decision variables: ");
					varMax = keyboard.nextInt();
					
					do
					{
						System.out.print("Do you want maximize or minimize the function?(max/min): ");
						m = keyboard.next();
						
					}while(!m.equals("max") && !m.equals("min") && !m.equals("MAX") && !m.equals("MIN"));
					
					pso = new PSO(nVar, varMin , varMax);
					
					if(m.equals("max") || m.equals("MAX"))
						System.out.println("Best global: " + pso.algorithmMax(nVar, varMin, varMax, "Rastrigin"));
					
					if(m.equals("min") || m.equals("MIN"))
						System.out.println("Best global: " + pso.algorithmMin(nVar, varMin, varMax, "Rastrigin"));					
				break;
				
				case 4:
					System.out.print("Enter number of unknown variables (decision): ");
					nVar = keyboard.nextInt();
					
					System.out.print("Enter lower limit of decision variables: ");
					varMin = keyboard.nextInt();
					
					System.out.print("Enter upper limit of decision variables: ");
					varMax = keyboard.nextInt();
					
					do
					{
						System.out.print("Do you want maximize or minimize the function?(max/min): ");
						m = keyboard.next();
						
					}while(!m.equals("max") && !m.equals("min") && !m.equals("MAX") && !m.equals("MIN"));
					
					pso = new PSO(nVar, varMin , varMax);
					
					if(m.equals("max") || m.equals("MAX"))
						System.out.println("Best global: " + pso.algorithmMax(nVar, varMin, varMax, "Schwefel"));
					
					if(m.equals("min") || m.equals("MIN"))
						System.out.println("Best global: " + pso.algorithmMin(nVar, varMin, varMax, "Schwefel"));					
				break;
				
				case 5:
					System.out.print("Enter number of unknown variables (decision): ");
					nVar = keyboard.nextInt();
					
					System.out.print("Enter lower limit of decision variables: ");
					varMin = keyboard.nextInt();
					
					System.out.print("Enter upper limit of decision variables: ");
					varMax = keyboard.nextInt();
					
					do
					{
						System.out.print("Do you want maximize or minimize the function?(max/min): ");
						m = keyboard.next();
						
					}while(!m.equals("max") && !m.equals("min") && !m.equals("MAX") && !m.equals("MIN"));
					
					pso = new PSO(nVar, varMin , varMax);
					
					if(m.equals("max") || m.equals("MAX"))
						System.out.println("Best global: " + pso.algorithmMax(nVar, varMin, varMax, "Sum squares"));
					
					if(m.equals("min") || m.equals("MIN"))
						System.out.println("Best global: " + pso.algorithmMin(nVar, varMin, varMax, "Sum squares"));					
				break;
				
				case 6:
					System.out.println("\nExiting the program ...");
				break;
				
				default:
				{
					System.out.println("\nError. Wrong option");
				}
			}
			
			System.out.println("Press enter to continue");
			System.in.read();
			
		}while(opt!=6);
		
		keyboard.close();
	}
}