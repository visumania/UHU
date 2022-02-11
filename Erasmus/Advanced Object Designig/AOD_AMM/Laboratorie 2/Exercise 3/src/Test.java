import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Set;
import org.reflections.Reflections;

public class Test 
{
	public static ICar constructor(String type) //throws ClassNotFoundException, NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException
	{
		switch(type)
		{
			case "Punto":
				return new Punto();
				
			case "Yaris":
				return new Yaris();
				
			case "Fabia": 
				return new Fabia();
				
				default: 
					System.out.println("The program does not find this object in the factory");
					return null; 
		}
		
		
		/*Reflections reflections = new Reflections("org.apache.usergrid.chop.webapp.dao");
	    Set<Class<? extends Dao>> daoClasses = reflections.getSubTypesOf(Dao.class);*/
		
		/*Reflections reflections = new Reflections(type);
		Set<Class<? extends ICar>> classes = reflections.getSubTypesOf(ICar.class);
		Class<?> clazz = Class.forName(type); //Creating instance
		Constructor<?> ctor = clazz.getConstructor(String.class);
		Object object = ctor.newInstance(new Object[] {type});*/
		
		//I do not know how to use reflections in java, despite having
		//searched a lot of information on the internet and having tried 
		//the advice you give in the practice statement, I have been unable 
		//to implement it correctly. So sorry.
	}
	
	public static void main(String []args) //throws ClassNotFoundException, NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException
	{
		ICar ic1 = Test.constructor("Punto");
		System.out.println(ic1.name());
		ic1.turnOn();
		ic1.turnOff();
		
		ICar ic2 = Test.constructor("Yaris");
		System.out.println("\n" + ic2.name());
		ic2.turnOn();
		ic2.turnOff();
		
		ICar ic3 = Test.constructor("Fabia");
		System.out.println("\n" + ic3.name());
		ic3.turnOn();
		ic3.turnOff();
	}
}
