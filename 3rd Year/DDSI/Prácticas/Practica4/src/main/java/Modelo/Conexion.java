package Modelo;

import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author Adrián Moreno Monterde
 */
public class Conexion
{
    Connection conexion = null;
    
    public Conexion() throws SQLException
    {
        String cadenaConexion = "jdbc:oracle:thin:@172.17.20.75:1521:rabida";
        String usuario = "DDSI_046";
        String password = "casona";
        
        conexion = DriverManager.getConnection(cadenaConexion, usuario, password);
    }
    
    public Conexion(String sgbd, String ip, String bd, String usuario, String password) throws SQLException
    {
        String cadenaConexion = "jdbc:" + sgbd + ":thin:@" + ip + ":1521:" + bd;
        
        conexion = DriverManager.getConnection(cadenaConexion, usuario, password);
    }
    
    public Connection getConexion()
    {
        return (conexion);
    }
    
    public void desconexion() throws SQLException
    {
        conexion.close();
    }
    
    public DatabaseMetaData informacionBD() throws SQLException
    {
        return (conexion.getMetaData());
    }
    
    public void inicioTransaccion() throws SQLException
    {
        conexion.setAutoCommit(false);
    }
    
    public void finalTransaccion() throws SQLException
    {
        conexion.setAutoCommit(true);
    }
    
    public void retrocederTransaccion() throws SQLException
    {
        conexion.rollback();
    }
    
    public void confirmarTransaccion() throws SQLException
    {
        conexion.commit();
    }
}