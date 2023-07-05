package Controlador;

import Modelo.Conexion;
import Vista.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class ControladorLogin implements ActionListener {

    private VistaLogin vLogin = null;
    private VistaMensajes vMensajes = null;
    private Tablas tablas = null;
    private Conexion conexion = null;

    public ControladorLogin() {
        vLogin = new VistaLogin();
        vMensajes = new VistaMensajes();

        tablas = new Tablas();

        addListeners();

        vLogin.setLocationRelativeTo(null);
        vLogin.setVisible(true);
    }

    private void addListeners() {
        vLogin.jButtonConectar.addActionListener(this);
    }

    public boolean conectar() {
        boolean resultado = false;

        String hostName = vLogin.jTextFieldHostName.getText();
        String puerto = vLogin.jTextFieldPort.getText();
        String nombreBD = vLogin.jTextFieldDatabaseName.getText();
        String username = vLogin.jTextFieldUsername.getText();
        String password = String.valueOf(vLogin.jPasswordField.getPassword());

        try {
            conexion = new Conexion(hostName, puerto, nombreBD, username, password);
            resultado = true;
        } catch (SQLException e) {
            vMensajes.vistaMensajeError("Conexión incorrecta. Revise los parámetros introducidos", e.getMessage());
        }

        return resultado;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "Conectar":
                if (conectar()) {
                    vMensajes.vistaMensajeExito("Conexión correcta");
                    vLogin.dispose();
                    Controlador controlador = new Controlador(conexion);
                }
                break;
        }
    }

}
