package Modelo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Conexion {

    Connection conexion = null;

    public Conexion(String hostName, String port, String dbName, String username, String password) throws SQLException {
        String cadenaConexion = "jdbc:postgresql://" + hostName + ":" + port + "/" + dbName;
        conexion = DriverManager.getConnection(cadenaConexion, username, password);
    }

    public Connection getConexion() {
        return conexion;
    }

    public void desconexion() throws SQLException {
        conexion.close();
    }
}
