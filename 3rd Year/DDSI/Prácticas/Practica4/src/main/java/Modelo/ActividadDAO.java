package Modelo;

import java.sql.CallableStatement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import oracle.jdbc.OracleTypes;

/**
 *
 * @author adrianmorenomonterde
 */

public class ActividadDAO 
{
    Conexion conexion = null;
    PreparedStatement ps = null;
    
    public ActividadDAO(Conexion c)
    {
        this.conexion = c;
    }
    
    //Método que llama al procedimiento almacenado
    public ResultSet verInfoSocioActividad(String idActividad) throws SQLException
    {
        String getUserCursorSql = "{call INFOSOCIOACTIVIDAD(?,?)}";
        CallableStatement call = conexion.getConexion().prepareCall(getUserCursorSql);

        call.setString(1, idActividad);
        call.registerOutParameter(2, OracleTypes.CURSOR);
        call.executeUpdate();
        
        return (ResultSet) call.getObject(2);
    }
    
    public ArrayList<Actividad> existeMonitorActividad(String letra) throws SQLException
    {
        ArrayList listaRealiza = new ArrayList();
        String consulta = "SELECT * FROM ACTIVIDAD WHERE MONITORRESPONSABLE='"+ letra +"'";
        ps = conexion.getConexion().prepareStatement(consulta);
        ResultSet rs = ps.executeQuery();
        
        while(rs.next())
        {
            Actividad actividad = new Actividad(rs.getString(1), rs.getString(2), rs.getString(3), rs.getInt(4), rs.getString(5));
            listaRealiza.add(actividad);
        }
        
        return listaRealiza;
    }
     
    public void actualizaMonitorGenerico(String codMonitor) throws SQLException
    {
        String consulta = "UPDATE ACTIVIDAD SET MONITORRESPONSABLE = 'M999' WHERE MONITORRESPONSABLE ='" + codMonitor + "'";
        ps = conexion.getConexion().prepareStatement(consulta);
        
        ps.executeUpdate();
        ps.close();
    }
    
    public ArrayList<String> getIdsActividad() throws SQLException
    {
        ArrayList listaIds = new ArrayList();
        String consulta = "SELECT IDACTIVIDAD FROM ACTIVIDAD";
        ps = conexion.getConexion().prepareStatement(consulta);
        ResultSet rs = ps.executeQuery();
        
        while(rs.next())
        {
            listaIds.add(rs.getString(1));
        }
        return listaIds;
    }
}
