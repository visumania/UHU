/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Vista;

import java.sql.DatabaseMetaData;
import java.sql.SQLException;

/**
 *
 * @author Adrián Moreno Monterde
 */
public class VistaConsola 
{
    public void vistaConsolaLogin(String texto)
    {
        System.out.println("************************");
        System.out.println(texto);
        System.out.println("************************");
    }
    
    public void vistaConsolaLogin(String texto, String error)
    {
        System.out.println("************************");
        System.out.println(texto);
        System.out.println(error);
        System.out.println("************************");
    }
    
    public void vistaMetadatos(DatabaseMetaData dbmd) throws SQLException
    {
        System.out.println("Versión de la base de datos: " + dbmd.getDatabaseProductVersion());
        System.out.println("URL de la conexion: " + dbmd.getURL());
        System.out.println("Nombre del driver: " + dbmd.getDriverName());
        System.out.println("Nombre del usuario con el que se ha conectado: " + dbmd.getUserName());
        System.out.println("Número máximo de caracteres para el nombre de usuario: " + dbmd.getMaxUserNameLength());
        System.out.println("Número máximo de columnas que se permiten en una tabla: " + dbmd.getMaxColumnsInTable());
    }
}
