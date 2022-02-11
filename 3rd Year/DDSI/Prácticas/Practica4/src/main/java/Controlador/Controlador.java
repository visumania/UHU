package Controlador;

import Modelo.*;
import Vista.*;

import java.awt.CardLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import java.util.Date;

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
    private VistaSociosActividad vSociosActividad = null; 
    
    private VistaMonitor vMonitor = null;
    private VistaSocio vSocio = null;
    private VistaPorDefecto vPorDefecto = null;
    
    private MonitorDAO monitorDAO = null;
    private SocioDAO socioDAO = null;
    private ActividadDAO actividadDAO = null;
    
    private SimpleDateFormat formatoFecha = new SimpleDateFormat("dd/MM/yyyy");
    
    public Controlador(Conexion conexion)
    {
        this.conexion = conexion;
        
        vMensaje = new VistaConsola();
        vPrincipal = new VistaPrincipal();
        vMonitor = new VistaMonitor();
        vSocio = new VistaSocio();
        vPorDefecto = new VistaPorDefecto();
        vEliminacion = new VistaEliminacion();
        vSociosActividad = new VistaSociosActividad();
        
        monitorDAO = new MonitorDAO(conexion);
        socioDAO = new SocioDAO(conexion);
        actividadDAO = new ActividadDAO(conexion);
        
        addListeners();
        
        vPrincipal.setLocationRelativeTo(null);
        vPrincipal.setVisible(true);
        
        vSociosActividad.setLocationRelativeTo(null);
        vSociosActividad.setVisible(false);
        
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
        vPrincipal.jMenuItemSociosPorActividad.addActionListener(this);
        
        vMonitor.jButtonInsertar.addActionListener(this);
        vMonitor.jButtonActualizar.addActionListener(this);
        vMonitor.jButtonEliminar.addActionListener(this);
        vMonitor.jButtonVaciarTabla.addActionListener(this);
        vMonitor.jButtonListarMonitores.addActionListener(this);
        
        vSocio.jButtonInsertar.addActionListener(this);
        vSocio.jButtonActualizar.addActionListener(this);
        vSocio.jButtonEliminar.addActionListener(this);
        vSocio.jButtonVaciarTabla.addActionListener(this);
        vSocio.jButtonListarMonitores.addActionListener(this);
        
        vEliminacion.jButtonEliminarMonitorNo.addActionListener(this);
        vEliminacion.jButtonEliminarMonitorSi.addActionListener(this);
        
        vSociosActividad.jButtonFiltrarProcedimiento.addActionListener(this);
        vSociosActividad.jButtonSalirProcedimiento.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) 
    {
        switch(e.getActionCommand())
        {
            case "CerrarVentanaPrincipal":
                vPrincipal.dispose();
                System.exit(0);
                break;
                
            case "GestionMonitores":
                vMonitor.setVisible(true);
                vSocio.setVisible(false);
                vPorDefecto.setVisible(false);
                vMonitor.dibujarTablaMonitores(vMonitor);
                
                //En este caso, se le añaden los listener de Mouse a la tabla jTableMonitores
                vMonitor.jTableMonitores.addMouseListener(new MouseAdapter()
                {
                    @Override
                    public void mouseClicked(MouseEvent evt)
                    {
                        try {
                            vMonitorjTableMonitoresMouseClicked(evt);
                        } catch (SQLException | ParseException ex) {
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
                vSocio.dibujarTablaSocios(vSocio);
                
                //En este caso, se le añaden los listener de Mouse a la tabla jTableMonitores
                vSocio.jTableSocios.addMouseListener(new MouseAdapter()
                {
                    @Override
                    public void mouseClicked(MouseEvent evt)
                    {
                        try {
                            vSociojTableSociosMouseClicked(evt);
                        } catch (SQLException | ParseException ex) {
                            Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                        }
                    }
                });
                
                try
                {
                    pideSocios();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "GestionSociosActividad":
                vSociosActividad.setVisible(true);
                vSociosActividad.dibujarTablaSociosActividad(vSociosActividad);
            
                try {
                        for(int i=0; i<actividadDAO.getIdsActividad().size(); i++)
                        {
                            vSociosActividad.jComboBoxFiltrarProcedimiento.addItem(actividadDAO.getIdsActividad().get(i));
                        }
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
            
                break;

                
            case "Insertar":
                Monitor mon = new Monitor();
                
                mon.setCodMonitor(vMonitor.jTextFieldCodigo.getText());
                mon.setNombre(vMonitor.jTextFieldNombre.getText());
                mon.setDni(vMonitor.jTextFieldDNI.getText());
                mon.setTelefono(vMonitor.jTextFieldTelefono.getText());
                mon.setCorreo(vMonitor.jTextFieldCorreo.getText());
                mon.setNick(vMonitor.jTextFieldNick.getText());
                
                Date fechaChooser = vMonitor.jDateChooserFechaEntradaMonitor.getDate();
                if(fechaChooser != null)
                {
                    String fechaString = formatoFecha.format(fechaChooser);
                    mon.setFechaEntrada(fechaString);
                }
                
                try {
                    monitorDAO.insertarMonitor(mon);
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                vMonitor.dibujarTablaMonitores(vMonitor);
                
                try
                {
                    pideMonitores();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "Actualizar":
                mon = new Monitor();
                
                mon.setCodMonitor(vMonitor.jTextFieldCodigo.getText());
                mon.setNombre(vMonitor.jTextFieldNombre.getText());
                mon.setDni(vMonitor.jTextFieldDNI.getText());
                mon.setTelefono(vMonitor.jTextFieldTelefono.getText());
                mon.setCorreo(vMonitor.jTextFieldCorreo.getText());
                mon.setNick(vMonitor.jTextFieldNick.getText());
                
                fechaChooser = vMonitor.jDateChooserFechaEntradaMonitor.getDate();
                if(fechaChooser != null)
                {
                    String fechaString = formatoFecha.format(fechaChooser);
                    mon.setFechaEntrada(fechaString);
                }
                
                try {
                    monitorDAO.actualizarMonitor(mon.getCodMonitor(), mon);
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                vMonitor.dibujarTablaMonitores(vMonitor);
                
                try
                {
                    pideMonitores();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "Eliminar":
                String cod = vMonitor.jTextFieldCodigo.getText();
                
                if(JOptionPane.showConfirmDialog(null, "¿Estás seguro de que desea eliminar al monitor con el código " + vMonitor.jTextFieldCodigo.getText() + "?", "Confirmar eliminación", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == 0)
                    try {
                        conexion.inicioTransaccion();

                        if(actividadDAO.existeMonitorActividad(cod).isEmpty()) //Si el monitor no existe en la tabla REALIZA
                        {
                            monitorDAO.eliminarMonitor(cod); 
                        } 
                        else
                        {
                            //Insertamos monitor genérico en MONITOR (Si no existe)
                            if(monitorDAO.existeMonitor("M999").isEmpty())
                            {
                                mon = new Monitor();
                                mon.setCodMonitor("M999");
                                mon.setDni("00000000A");
                                mon.setNombre("Responsable Genérico");
                                monitorDAO.insertarMonitor(mon);
                            }
                            
                            //Actualizamos todos los monitores de la tabla ACTIVIDAD con el monitor genérico
                            actividadDAO.actualizaMonitorGenerico(cod);
                            
                            //Eliminamos el monitor
                            monitorDAO.eliminarMonitor(cod);
                            
                        }
                        conexion.confirmarTransaccion();
                        conexion.finalTransaccion();
                    } catch (SQLException ex) {
                        try
                        {
                            conexion.retrocederTransaccion();
                        }catch(SQLException exe)
                        {
                            System.out.println("Fallo en el rollback: " + exe.getMessage());
                        }
                    }finally
                    {
                        try{
                            conexion.finalTransaccion();
                        }catch(SQLException ex)
                        {
                            System.out.println(ex.getMessage());
                        }
                    }
                
                vMonitor.dibujarTablaMonitores(vMonitor);
                
                try
                {
                    pideMonitores();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
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
                
            case "InsertarSocio":
                Socio soc = new Socio();
                
                soc.setNumeroSocio(vSocio.jTextFieldNumeroSocio.getText());
                soc.setNombre(vSocio.jTextFieldNombre.getText());
                soc.setDni(vSocio.jTextFieldDNI.getText());
                soc.setTelefono(vSocio.jTextFieldTelefono.getText());
                soc.setCorreo(vSocio.jTextFieldCorreo.getText());
                soc.setCategoria(vSocio.jTextFieldCategoria.getText());
                
                fechaChooser = vSocio.jDateChooserFechaEntradaSocio.getDate();
                if(fechaChooser != null)
                {
                    String fechaString = formatoFecha.format(fechaChooser);
                    soc.setFechaEntrada(fechaString);
                }
                
                fechaChooser = vSocio.jDateChooserFechaNacimientoSocio.getDate();
                if(fechaChooser != null)
                {
                    String fechaString = formatoFecha.format(fechaChooser);
                    soc.setFechaNacimiento(fechaString);
                }
                
                try {
                    socioDAO.insertarSocio(soc);
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                vSocio.dibujarTablaSocios(vSocio);
                
                try
                {
                    pideSocios();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "ActualizarSocio":
                soc = new Socio();
                
                soc.setNumeroSocio(vSocio.jTextFieldNumeroSocio.getText());
                soc.setNombre(vSocio.jTextFieldNombre.getText());
                soc.setDni(vSocio.jTextFieldDNI.getText());
                soc.setTelefono(vSocio.jTextFieldTelefono.getText());
                soc.setCorreo(vSocio.jTextFieldCorreo.getText());
                soc.setCategoria(vSocio.jTextFieldCategoria.getText());
                
                fechaChooser = vSocio.jDateChooserFechaEntradaSocio.getDate();
                if(fechaChooser != null)
                {
                    String fechaString = formatoFecha.format(fechaChooser);
                    soc.setFechaEntrada(fechaString);
                }
                
                fechaChooser = vSocio.jDateChooserFechaNacimientoSocio.getDate();
                if(fechaChooser != null)
                {
                    String fechaString = formatoFecha.format(fechaChooser);
                    soc.setFechaNacimiento(fechaString);
                }
                
                try {
                    socioDAO.actualizarSocio(soc.getNumeroSocio(), soc);
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                vSocio.dibujarTablaSocios(vSocio);
                
                try
                {
                    pideSocios();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

                
            case "EliminarSocio":
                String num = vSocio.jTextFieldNumeroSocio.getText();
                
                if(JOptionPane.showConfirmDialog(null, "¿Estás seguro de que desea eliminar al socio con numero " + vSocio.jTextFieldNumeroSocio.getText() + "?", "Confirmar eliminación", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == 0)
                    try {
                        socioDAO.eliminarSocio(num);
                    } catch (SQLException ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                
                vSocio.dibujarTablaSocios(vSocio);
                
                try
                {
                    pideSocios();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "VaciarTablaSocio":
                vSocio.vaciarTablaSocios();
                break;
                
            case "ListarSocios":
                vSocio.dibujarTablaSocios(vSocio);
                
                try
                {
                    pideSocios();
                }catch(SQLException ex)
                {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "FiltrarProcedimiento":
            {
                vSociosActividad.vaciarTablaSociosActividad();
                try {
                    ResultSet rs = actividadDAO.verInfoSocioActividad(vSociosActividad.jComboBoxFiltrarProcedimiento.getSelectedItem().toString());
                    
                    while(rs.next())
                    {
                        vSociosActividad.modeloTablaSociosActividad.addRow(new String[] {rs.getString("NOMBRE"), rs.getString("CORREO")});
                    }
                    rs.close();
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
                break;

                
            case "SalirProcedimiento":
                vSociosActividad.setVisible(false);
                break;
        }
    }
    
    private void pideMonitores() throws SQLException
    {
        ArrayList<Monitor> lMonitores = monitorDAO.listaMonitores();
        vMonitor.vaciarTablaMonitores();
        vMonitor.rellenarTablaMonitores(lMonitores);
    }
    
    private void pideSocios() throws SQLException
    {
        ArrayList<Socio> lSocios = socioDAO.listaSocios();
        vSocio.vaciarTablaSocios();
        vSocio.rellenarTablaSocios(lSocios);
    }
    
    private void vMonitorjTableMonitoresMouseClicked(MouseEvent evt) throws SQLException, ParseException
    {
        int fila = vMonitor.jTableMonitores.getSelectedRow();
                
        vMonitor.jTextFieldCodigo.setText(monitorDAO.listaMonitores().get(fila).getCodMonitor());
        vMonitor.jTextFieldNombre.setText(monitorDAO.listaMonitores().get(fila).getNombre());
        vMonitor.jTextFieldDNI.setText(monitorDAO.listaMonitores().get(fila).getDni());
        vMonitor.jTextFieldTelefono.setText(monitorDAO.listaMonitores().get(fila).getTelefono());
        vMonitor.jTextFieldCorreo.setText(monitorDAO.listaMonitores().get(fila).getCorreo());
        vMonitor.jTextFieldNick.setText(monitorDAO.listaMonitores().get(fila).getNick());
        vMonitor.jDateChooserFechaEntradaMonitor.setDate(formatoFecha.parse(monitorDAO.listaMonitores().get(fila).getFechaEntrada()));
    }
    
    private void vSociojTableSociosMouseClicked(MouseEvent evt) throws SQLException, ParseException
    {
        int fila = vSocio.jTableSocios.getSelectedRow();
        
        vSocio.jTextFieldNumeroSocio.setText(socioDAO.listaSocios().get(fila).getNumeroSocio());
        vSocio.jTextFieldNombre.setText(socioDAO.listaSocios().get(fila).getNombre());
        vSocio.jTextFieldDNI.setText(socioDAO.listaSocios().get(fila).getDni());
        vSocio.jTextFieldTelefono.setText(socioDAO.listaSocios().get(fila).getTelefono());
        vSocio.jTextFieldCorreo.setText(socioDAO.listaSocios().get(fila).getCorreo());
        vSocio.jTextFieldCategoria.setText(socioDAO.listaSocios().get(fila).getCategoria());
        vSocio.jDateChooserFechaEntradaSocio.setDate(formatoFecha.parse(socioDAO.listaSocios().get(fila).getFechaEntrada()));
        vSocio.jDateChooserFechaNacimientoSocio.setDate(formatoFecha.parse(socioDAO.listaSocios().get(fila).getFechaNacimiento()));
    }
}
