package Controlador;

import Modelo.HibernateUtil;
import Vista.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import org.hibernate.Session;

/**
 *
 * @author Adrián Moreno Monterde
 */
public class ControladorLogin implements ActionListener {

    private VistaConsola vConsola;
    private VistaLogin vLogin;
    private VistaMensajes vMensaje;
    private Session sesion = null;

    public ControladorLogin() {
        vLogin = new VistaLogin();
        vMensaje = new VistaMensajes(); // Usaremos un objeto de tipo vMensaje para mostrar Mensajes
        vConsola = new VistaConsola();

        addListeners();

        vLogin.setLocationRelativeTo(null); // Sitúa la ventana en el centro de la pantalla
        vLogin.setVisible(true); //Muestra la ventana
    }

    private void addListeners() {
        vLogin.btnSalirDialogoConexion.addActionListener(this);
        vLogin.jButtonConectar.addActionListener(this);
    }

    public Session conectar() {
        String server = (String) (vLogin.jComboBoxServidores.getSelectedItem());
        String ip = vLogin.jTextFieldIP.getText();
        String service_bd = vLogin.jTextFieldService_BD.getText();
        String u = vLogin.jTextFieldUsuario.getText();
        String p = new String(vLogin.jPasswordField.getPassword());

        if ("MySQL".equals(server)) {
            server = "mysql";
        } else if ("Oracle".equals(server)) {
            server = "oracle";
        }

        if ("oracle".equals(server) && "172.17.20.75".equals(ip) && "rabida".equals(service_bd) && "DDSI_046".equals(u) && "casona".equals(p)) {
            sesion = HibernateUtil.getSessionFactory().openSession();
        }

        if ("oracle".equals(server) && "172.17.20.39".equals(ip) && "etsi".equals(service_bd) && "DDSI_046".equals(u) && "casona".equals(p)) {
            sesion = HibernateUtil.getSessionFactory().openSession();
        }

        return (sesion);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "Conectar": // Propiedad actionCommand del botón "Conectar"
                sesion = conectar();

                if (sesion != null) {
                    vConsola.Mensaje("info", "Conexión correcta con Hibernate");
                    vMensaje.mensaje("Conexion correcta", 1);
                    vLogin.dispose();
                    Controlador controlador = new Controlador(sesion);
                } else {
                    vConsola.Mensaje("error", "Error en la conexión con Hibernate. Revise los valores de conexión");
                    vMensaje.mensaje("Error en la conexión con Hibernate. Revise los valores de conexión", 0);
                }
                break;

            case "SalirDialogoConexion": // Propiedad actionCommand del botón "Salir"
                vLogin.dispose();
                System.exit(0);
                break;
        }
    }
}
