package Controlador;

import Modelo.Conexion;
import Vista.*;
import com.mongodb.MongoException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class ControladorLogin implements ActionListener
{
    private Conexion conexion = null;
    private boolean conexionOK;
    private boolean desconexionOK;
    private VistaConsola vConsola;
    private VistaLoginPrincipal vLoginPrincipal;
    private VistaMensajes vMensajes;
    private VistaLoginLocalhost vLoginLocalhost;
    private VistaLoginCluster vLoginCluster;
    
    public ControladorLogin()
    {
        vLoginPrincipal = new VistaLoginPrincipal();
        vConsola = new VistaConsola();
        vMensajes = new VistaMensajes();
        vLoginLocalhost = new VistaLoginLocalhost();
        vLoginCluster = new VistaLoginCluster();
        
        addListeners();
        
        vLoginPrincipal.setLocationRelativeTo(null);
        vLoginPrincipal.setVisible(true);
    }
    
    private void addListeners()
    {
        vLoginPrincipal.jButtonCluster.addActionListener(this);
        vLoginPrincipal.jButtonLocalHost.addActionListener(this);
        
        vLoginLocalhost.jButtonConectar.addActionListener(this);
        
        vLoginCluster.jButtonConectarCluster.addActionListener(this);
    }
    
    
    public boolean conectar()
    {
        boolean resultado = false;
        
        String servidor = vLoginLocalhost.jTextFieldLocalhost.getText();
        int puerto = Integer.parseInt(vLoginLocalhost.jTextFieldPuerto.getText());
        conexion = new Conexion(servidor, puerto);
        
        if(conexion != null)
        {
            vMensajes.vistaMensajeExito();
            resultado = true;
        }
        else
            vMensajes.vistaMensajeError("Error en la conexión");
        
        return resultado; 
    }
    
    public boolean conectarCluster()
    {
        boolean resultado = false;
        String uri = vLoginCluster.jTextFieldURI.getText();
        conexion = new Conexion(uri);
        
        if(conexion != null)
        {
            vMensajes.vistaMensajeExito();
            resultado = true;
        }
        else
            vMensajes.vistaMensajeError("Error en la conexión con el clúster");
                
        return resultado; 
    }
    
    public boolean desconectar()
    {
        boolean resultado = false;
        
        try {
            conexion.desconexion();
            vConsola.vistaConsolaLogin("Desconexion correcta ... ¡¡Enhorabuena!!");
            resultado = true;
        } catch (MongoException e) {
            vConsola.vistaConsolaLogin("Error en la desconexion", e.getMessage());
        }
        
        return resultado; 
    }
    
    @Override
    public void actionPerformed(ActionEvent e)
    {
        switch(e.getActionCommand())
        {
            case "localhost":
                vLoginPrincipal.dispose();
                vLoginLocalhost.setLocationRelativeTo(null);
                vLoginLocalhost.setVisible(true);
                //Controlador controlador = new Controlador(conexion);
                
                break;
                
            case "cluster":
                vLoginPrincipal.dispose();
                vLoginCluster.setLocationRelativeTo(null);
                vLoginCluster.setVisible(true);
                break;
                
            case "ConectarLocalHost":
                conexionOK = conectar();
                if(conexionOK)
                {
                    vLoginLocalhost.dispose();
                    Controlador controlador = new Controlador(conexion);
                }
                break;
                
            case "ConectarCluster":
                conexionOK = conectarCluster();
                if(conexionOK)
                {
                    vLoginCluster.dispose();
                    Controlador controlador =  new Controlador(conexion);
                }
                break;
        }
    }
}
