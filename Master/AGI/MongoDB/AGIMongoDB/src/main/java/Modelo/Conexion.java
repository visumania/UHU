package Modelo;

import com.mongodb.MongoClient;
import com.mongodb.MongoClientURI;
import com.mongodb.MongoException;
import javax.swing.JOptionPane;

public class Conexion {
    
    private MongoClient mongo = null;
    
    public Conexion(String servidor, int puerto) throws MongoException
    {
        try{
            mongo = new MongoClient(servidor, puerto);
        } catch(MongoException e)
        {
            JOptionPane.showMessageDialog(null, "Error al conectarse a la base de datos: " + e.getMessage(), "Error de conexión", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    public Conexion(String uri) throws MongoException
    {
        try{
            mongo = new MongoClient(new MongoClientURI(uri));
        } catch(MongoException e)
        {
            JOptionPane.showMessageDialog(null, "Error al conectarse a la base de datos: " + e.getMessage(), "Error de conexión", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    public MongoClient getConexion()
    {
        return mongo;
    }
    
    public void desconexion() throws MongoException
    {
        mongo.close();
    }
}
