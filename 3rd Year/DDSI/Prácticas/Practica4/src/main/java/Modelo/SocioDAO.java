package Modelo;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 *
 * @author adrianmorenomonterde
 */
public class SocioDAO 
{
    Conexion conexion = null;
    PreparedStatement ps = null;
    
    public SocioDAO(Conexion c)
    {
        this.conexion = c;
    }
    
    public ArrayList<Socio> listaSocios() throws SQLException
    {
        ArrayList listaSocios = new ArrayList();
        String consulta = "SELECT * FROM SOCIO ORDER BY NUMEROSOCIO ASC";
        ps = conexion.getConexion().prepareStatement(consulta);
        ResultSet rs = ps.executeQuery();
        
        while(rs.next())
        {
            Socio socio = new Socio(rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getString(5), rs.getString(6), rs.getString(7), rs.getString(8));
            listaSocios.add(socio);
        }
        
        return listaSocios; 
    }
    
    public void insertarSocio(Socio soc) throws SQLException
    {
        String consulta = "INSERT INTO SOCIO (NUMEROSOCIO, NOMBRE, DNI, FECHANACIMIENTO, TELEFONO, CORREO, FECHAENTRADA, CATEGORIA) VALUES (?,?,?,?,?,?,?,?)";
        ps = conexion.getConexion().prepareStatement(consulta);
        
        ps.setString(1, soc.getNumeroSocio());
        ps.setString(2, soc.getNombre());
        ps.setString(3, soc.getDni());
        ps.setString(4, soc.getFechaNacimiento());
        ps.setString(5, soc.getTelefono());
        ps.setString(6, soc.getCorreo());
        ps.setString(7, soc.getFechaEntrada());
        ps.setString(8, soc.getCategoria());
        
        ps.executeUpdate();
        ps.close();
    }
    
    public void actualizarSocio(String cod, Socio soc) throws SQLException
    {
        String consulta = "UPDATE SOCIO SET NOMBRE=?, DNI=?, FECHANACIMIENTO=?, TELEFONO=?, CORREO=?, FECHAENTRADA=?, CATEGORIA=? WHERE NUMEROSOCIO = '" + cod + "'";
        ps = conexion.getConexion().prepareStatement(consulta);
        
        ps.setString(1, soc.getNombre());
        ps.setString(2, soc.getDni());
        ps.setString(3, soc.getFechaNacimiento());
        ps.setString(4, soc.getTelefono());
        ps.setString(5, soc.getCorreo());
        ps.setString(6, soc.getFechaEntrada());
        ps.setString(7, soc.getCategoria());
        
        ps.executeUpdate();
        ps.close();    
    }
    
    public void eliminarSocio(String cod) throws SQLException
    {
        String consulta = "DELETE FROM SOCIO WHERE NUMEROSOCIO = '" + cod + "'";
        ps = conexion.getConexion().prepareStatement(consulta);
        
        ps.executeUpdate();
        ps.close();
    }
}


