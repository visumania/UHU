package Modelo;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 *
 * @author adrianmorenomonterde
 */

public class MonitorDAO 
{
    Conexion conexion = null;
    PreparedStatement ps = null;
    
    public MonitorDAO(Conexion c)
    {
        this.conexion = c; 
    }
    
    public ArrayList<Monitor> listaMonitores() throws SQLException //Ejemplo de función para recuperar toda la información de una tabla
    {
        ArrayList listaMonitores = new ArrayList();
        String consulta = "SELECT * FROM MONITOR ORDER BY CODMONITOR ASC";
        ps = conexion.getConexion().prepareStatement(consulta);
        ResultSet rs = ps.executeQuery();
        
        while(rs.next())
        {
            Monitor monitor = new Monitor(rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getString(5), rs.getString(6), rs.getString(7));
            listaMonitores.add(monitor);
        }
        
        return listaMonitores;
    }
    
    public ArrayList<Monitor> existeMonitor(String cod) throws SQLException
    {
        ArrayList listaRealiza = new ArrayList();
        String consulta = "SELECT * FROM MONITOR WHERE CODMONITOR='"+ cod +"'";
        ps = conexion.getConexion().prepareStatement(consulta);
        ResultSet rs = ps.executeQuery();
        
        while(rs.next())
        {
            Monitor monitor = new Monitor(rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getString(5), rs.getString(6), rs.getString(7));
            listaRealiza.add(monitor);
        }
        
        return listaRealiza;
    }
    
    public ArrayList<Monitor> listaMonitorPorLetra(String letra) throws SQLException //Ejemplo de función parametrizada para recuperar información --> Este método recupera los monitores cuyo nombre empiece por la letra que se pasa por parámetro
    {
        ArrayList listaMonitores = new ArrayList();
        String consulta = "SELECT * FROM MONITOR WHERE nombre LIKE ?";
        ps = conexion.getConexion().prepareStatement(consulta);
        letra = letra + "%";
        ps.setString(1, letra);
        ResultSet rs = ps.executeQuery();
        
        while(rs.next())
        {
            Monitor monitor = new Monitor(rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getString(5), rs.getString(6), rs.getString(7));
            listaMonitores.add(monitor);
        }
        
        return listaMonitores;
    }
    
    public void insertarMonitor(Monitor mon) throws SQLException
    {
        String consulta = "INSERT INTO MONITOR (CODMONITOR, NOMBRE, DNI, TELEFONO, CORREO, FECHAENTRADA, NICK) VALUES (?,?,?,?,?,?,?)";
        ps = conexion.getConexion().prepareStatement(consulta);
        
        ps.setString(1, mon.getCodMonitor());
        ps.setString(2, mon.getNombre());
        ps.setString(3, mon.getDni());
        ps.setString(4, mon.getTelefono());
        ps.setString(5, mon.getCorreo());
        ps.setString(6, mon.getFechaEntrada());
        ps.setString(7, mon.getNick());
        
        ps.executeUpdate();
        ps.close();
    }
    
    public void actualizarMonitor(String cod, Monitor mon) throws SQLException //Dado un código (clave principal) de un monitor, se actualizará lo que haga falta de sus atributos
    {
        String consulta = "UPDATE MONITOR SET NOMBRE=?, DNI=?, TELEFONO=?, CORREO=?, FECHAENTRADA=?, NICK=? WHERE CODMONITOR = '" + cod +  "'";
        ps = conexion.getConexion().prepareStatement(consulta);
        
        ps.setString(1, mon.getNombre());
        ps.setString(2, mon.getDni());
        ps.setString(3, mon.getTelefono());
        ps.setString(4, mon.getCorreo());
        ps.setString(5, mon.getFechaEntrada());
        ps.setString(6, mon.getNick());
        
        ps.executeUpdate();
        ps.close();
    }
    
    public void eliminarMonitor(String cod) throws SQLException //Dado el código de un monitor (clave principal), se eliminará la tupla correspondiente a ese monitor
    {
        String consulta = "DELETE FROM MONITOR WHERE CODMONITOR = '" + cod + "'";
        ps = conexion.getConexion().prepareStatement(consulta);
                
        ps.executeUpdate();
        ps.close();
    }
}
