import java.sql.*;

public class Conexion 
{
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
	
	public static void main(String []args)
	{
		if(Conexion.con() != null)
			System.out.println("Conexion exitosa");
		else
			System.out.println("Error de conexion");
		
	}
}
