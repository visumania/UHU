/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import Modelo.Conexion;
import Vista.VistaConsola;
import java.sql.DatabaseMetaData;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Adrián Moreno Monterde
 */
public class ControladorLogin 
{
    private Conexion conexion = null;
    private boolean conexionOK;
    private boolean desconexionOK;
    private VistaConsola vista = new VistaConsola();
    
    public ControladorLogin()
    {
        conexionOK = conectar();
        metadatos();
        desconexionOK = desconectar();
    }
    
    public boolean conectar()
    {
        boolean resultado = false;
        
        String sgbd = "oracle";
        String ip = "172.17.20.75";
        String bd = "rabida"; 
        String usuario = "DDSI_046";
        String password = "casona"; 
        
        try {
            conexion = new Conexion(sgbd,ip,bd,usuario,password);
            vista.vistaConsolaLogin("Conexion correcta ... ¡¡Enhorabuena!!");
            resultado = true; 
        } catch (SQLException ex) {
            vista.vistaConsolaLogin("Error en la conexion", ex.getMessage());
        }
        
        return (resultado);
    }
    
    public boolean desconectar()
    {
        boolean resultado = false;
        try {
            conexion.desconexion();
            vista.vistaConsolaLogin("Desconexion correcta ... ¡¡Enhorabuena!!");
            resultado = true;
        } catch (SQLException ex) {
            vista.vistaConsolaLogin("Error en la desconexion", ex.getMessage());
        }
        
        return (resultado);
    }
    
    public void metadatos()
    {
        try{
            vista.vistaMetadatos(conexion.getConexion().getMetaData());
        }catch(SQLException ex)
        {
            System.out.println("Error en la obtención de los metadatos");
        }
    }
}
