package Controlador;

import Modelo.Conexion;
import Vista.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Adrián Moreno Monterde
 */
public class ControladorLogin implements ActionListener
{
    private Conexion conexion = null;
    private boolean conexionOK;
    private VistaConsola vConsola;
    private VistaLogin vLogin;
    private VistaMensajes vMensaje;
    private VistaPrincipal vPrincipal;
    
    public ControladorLogin()
    {
       vLogin = new VistaLogin();
       vMensaje = new VistaMensajes(); // Usaremos un objeto de tipo vMensaje para mostrar Mensajes
       vConsola = new VistaConsola();
       
       addListeners();
       
       vLogin.setLocationRelativeTo(null); // Sitúa la ventana en el centro de la pantalla
       vLogin.setVisible(true); //Muestra la ventana
    }
    
    private void addListeners()
    {
        vLogin.btnSalirDialogoConexion.addActionListener(this);
        vLogin.jButtonConectar.addActionListener(this);
    }
    
    public boolean conectar()
    {
        boolean resultado = false;
        
        String sgbd = (String)(vLogin.jComboBoxServidores.getSelectedItem().toString().toLowerCase());
        String ip = vLogin.jTextFieldIP.getText(); //172.17.20.75
        String bd = vLogin.jTextFieldService_BD.getText(); //rabida
        String usuario = vLogin.jTextFieldUsuario.getText(); //DDSI_046
        String password = new String(vLogin.jPasswordField.getPassword()); // Se hace new String porque es un objeto de tipo password //casona
        
        try {
            conexion = new Conexion(sgbd,ip,bd,usuario,password);
            resultado = true; 
        } catch (SQLException ex) {
            vMensaje.vistaMensajeError(ex.getMessage());
        }
        
        return (resultado);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) 
    {
        switch(e.getActionCommand())
        {
            case "Conectar": // Propiedad actionCommand del botón "Conectar"
                conexionOK = conectar();
                
                if(conexionOK)
                {
                    vMensaje.vistaMensajeExito(); //Mostrar un mensaje para indicar que la conexión ha tenido éxito
                    vLogin.dispose(); //Cerrar la ventana "Acceso a la aplicacion"
                    Controlador controlador = new Controlador(conexion); //Instanciar un objeto de tipo Controlador
                    try {
                        vConsola.vistaMetadatos(conexion.informacionBD());
                    } catch (SQLException ex) {
                        Logger.getLogger(ControladorLogin.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                break;
                
            case "SalirDialogoConexion": // Propiedad actionCommand del botón "Salir"
                vLogin.dispose();
                System.exit(0);
                break;
        }
    }
}