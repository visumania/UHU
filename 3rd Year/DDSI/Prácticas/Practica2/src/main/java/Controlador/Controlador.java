package Controlador;

import Modelo.Conexion;
import Vista.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 *
 * @author adrianmorenomonterde
 */
public class Controlador implements ActionListener
{
    private Conexion conexion = null; // Se asigna al atributo propio el parámetro recibido
    private VistaConsola vMensaje = null;
    private VistaPrincipal vPrincipal = null;
    
    public Controlador(Conexion conexion)
    {
        this.conexion = conexion;
        vMensaje = new VistaConsola();
        vPrincipal = new VistaPrincipal();
        
        addListeners();
        
        vPrincipal.setLocationRelativeTo(null);
        vPrincipal.setVisible(true);
    }
    
    private void addListeners()
    {
        vPrincipal.jButtonCerrar.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) 
    {
        switch(e.getActionCommand())
        {
            case "CerrarVentanaPrincipal":// De momento la vista principal solo tiene un botón que, al pulsarlo, cierra la ventana y sale de la aplicación 
                vPrincipal.dispose();
                System.exit(0);
                break;
        }
    }
}
