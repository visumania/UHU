package Controlador;

import Modelo.*;
import Vista.*;

import java.awt.CardLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author adrianmorenomonterde
 */

public class Controlador implements ActionListener
{
    private Conexion conexion = null; // Se asigna al atributo propio el parámetro recibido
    
    private VistaConsola vMensaje = null;
    private VistaPrincipal vPrincipal = null;
    private VistaEliminacion vEliminacion = null;
    
    private VistaMonitor vMonitor = null;
    private VistaSocio vSocio = null;
    private VistaPorDefecto vPorDefecto = null;
    
    private MonitorDAO monitorDAO = null;
    
    public Controlador(Conexion conexion)
    {
        this.conexion = conexion;
        
        vMensaje = new VistaConsola();
        vPrincipal = new VistaPrincipal();
        vMonitor = new VistaMonitor();
        vSocio = new VistaSocio();
        vPorDefecto = new VistaPorDefecto();
        vEliminacion = new VistaEliminacion();
        
        monitorDAO = new MonitorDAO(conexion);
        
        addListeners();
        
        vPrincipal.setLocationRelativeTo(null);
        vPrincipal.setVisible(true);
        
        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vMonitor);
        vMonitor.setVisible(false);
        
        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vSocio);
        vSocio.setVisible(false);
        
        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vPorDefecto);
        vPorDefecto.setVisible(true);
    }
    
    private void addListeners()
    {
        vPrincipal.jMenuItemSalir.addActionListener(this);
        vPrincipal.jMenuItemMonitores.addActionListener(this);
        vPrincipal.jMenuItemSocios.addActionListener(this);
        
        vMonitor.jButtonInsertar.addActionListener(this);
        vMonitor.jButtonActualizar.addActionListener(this);
        vMonitor.jButtonEliminar.addActionListener(this);
        vMonitor.jButtonVaciarTabla.addActionListener(this);
        vMonitor.jButtonListarMonitores.addActionListener(this);
        
        vEliminacion.jButtonEliminarMonitorNo.addActionListener(this);
        vEliminacion.jButtonEliminarMonitorSi.addActionListener(this);
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
                
            case "GestionMonitores":
                vMonitor.setVisible(true);
                vSocio.setVisible(false);
                vPorDefecto.setVisible(false);
                //utilTablas.dibujarTablaMonitores(vMonitor);
                vMonitor.dibujarTablaMonitores(vMonitor);
                
                //En este caso, se le añaden los listener de Mouse a la tabla jTableMonitores
                vMonitor.jTableMonitores.addMouseListener(new MouseAdapter()
                {
                    @Override
                    public void mouseClicked(MouseEvent evt)
                    {
                        try {
                            vMonitorjTableMonitoresMouseClicked(evt);
                        } catch (SQLException ex) {
                            Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                        }
                    }
                });
                
               
                
                try
                {
                    pideMonitores();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "GestionSocios":
                vSocio.setVisible(true);
                vMonitor.setVisible(false);
                vPorDefecto.setVisible(false);
                //vPrincipal.setVisible(false);
                break;
                
            case "Insertar":
                Monitor mon = new Monitor();
                
                mon.setCodMonitor(vMonitor.jTextFieldCodigo.getText());
                mon.setNombre(vMonitor.jTextFieldNombre.getText());
                mon.setDni(vMonitor.jTextFieldDNI.getText());
                mon.setTelefono(vMonitor.jTextFieldTelefono.getText());
                mon.setCorreo(vMonitor.jTextFieldCorreo.getText());
                mon.setFechaEntrada(vMonitor.jTextFieldFechaEntrada.getText());
                mon.setNick(vMonitor.jTextFieldNick.getText());
                
                try {
                    monitorDAO.insertarMonitor(mon);
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }

                break;
                
            case "Actualizar":
                mon = new Monitor();
                
                mon.setCodMonitor(vMonitor.jTextFieldCodigo.getText());
                mon.setNombre(vMonitor.jTextFieldNombre.getText());
                mon.setDni(vMonitor.jTextFieldDNI.getText());
                mon.setTelefono(vMonitor.jTextFieldTelefono.getText());
                mon.setCorreo(vMonitor.jTextFieldCorreo.getText());
                mon.setFechaEntrada(vMonitor.jTextFieldFechaEntrada.getText());
                mon.setNick(vMonitor.jTextFieldNick.getText());
                
                try {
                    monitorDAO.actualizarMonitor(mon.getCodMonitor(), mon);
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
            
                break;

            
            case "Eliminar":
                String cod = vMonitor.jTextFieldCodigo.getText();
                
                //System.out.println(JOptionPane.showConfirmDialog(null, "¿Estás seguro de que desea eliminar al monitor con el código " + vMonitor.jTextFieldCodigo.getText() + "?", "Confirmar eliminación", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE));
                
                //vEliminacion.setLocationRelativeTo(null);
                //vEliminacion.setVisible(true);
                if(JOptionPane.showConfirmDialog(null, "¿Estás seguro de que desea eliminar al monitor con el código " + vMonitor.jTextFieldCodigo.getText() + "?", "Confirmar eliminación", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == 0)
                    try {
                        monitorDAO.eliminarMonitor(cod);
        } catch (SQLException ex) {
            Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
        }
                
        
                /*try {
                    
                    switch(e.getActionCommand())
                    {
                        case "EliminarSi":
                            System.out.println(e.getActionCommand());
                            //if(e.getActionCommand().equals("EliminarSi"))
                            //{
                                 monitorDAO.eliminarMonitor(cod);
                            //}
                            break;
                    }
                    
                    //System.out.println(e.getActionCommand());
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }*/
                
            
           
                //vEliminacion.setVisible(false);
                break;

            
            case "VaciarTabla":
                vMonitor.vaciarTablaMonitores();
                break;
            
            case "ListarMonitores":
                vMonitor.dibujarTablaMonitores(vMonitor);
                
                try
                {
                    pideMonitores();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break; 
        }
    }
    
    private void pideMonitores() throws SQLException
    {
        ArrayList<Monitor> lMonitores = monitorDAO.listaMonitores();
        vMonitor.vaciarTablaMonitores();
        vMonitor.rellenarTablaMonitores(lMonitores);
    }
    
    private void vMonitorjTableMonitoresMouseClicked(MouseEvent evt) throws SQLException
    {
        int fila = vMonitor.jTableMonitores.getSelectedRow();
        
        //TODO - Rellenar todos los textfields con los valores de las columnas de la fila que esté señalada cuando se haga un click de ratón
        
        vMonitor.jTextFieldCodigo.setText(monitorDAO.listaMonitores().get(fila).getCodMonitor());
        vMonitor.jTextFieldNombre.setText(monitorDAO.listaMonitores().get(fila).getNombre());
        vMonitor.jTextFieldDNI.setText(monitorDAO.listaMonitores().get(fila).getDni());
        vMonitor.jTextFieldTelefono.setText(monitorDAO.listaMonitores().get(fila).getTelefono());
        vMonitor.jTextFieldCorreo.setText(monitorDAO.listaMonitores().get(fila).getCorreo());
        vMonitor.jTextFieldFechaEntrada.setText(monitorDAO.listaMonitores().get(fila).getFechaEntrada());
        vMonitor.jTextFieldNick.setText(monitorDAO.listaMonitores().get(fila).getNick());
    }
}
