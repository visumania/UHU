package Controlador;

import Modelo.*;
import Vista.*;

import java.awt.CardLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import java.util.Date;
import org.hibernate.NonUniqueObjectException;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author adrianmorenomonterde
 */
public class Controlador implements ActionListener {

    private Session sesion = null; //Se asigna al atributo propio el parámetro recibido

    private VistaConsola vMensaje = null;
    private VistaPrincipal vPrincipal = null;
    private VistaSociosActividad vSociosActividad = null;
    private VistaSociosActividades vSociosActividades = null;
    private Vistas vistas = null;
    private VistaMensajes vMensajes = null;
    private VistaActualizacionPrecios vActualizacionPrecios = null;
    private VistaCuotaSocio vCuotaSocio = null;

    private VistaMonitor vMonitor = null;
    private VistaSocio vSocio = null;
    private VistaPorDefecto vPorDefecto = null;

    private MonitorDAO monitorDAO = null;
    private SocioDAO socioDAO = null;
    private ActividadDAO actividadDAO = null;

    private final SimpleDateFormat formatoFecha = new SimpleDateFormat("dd/MM/yyyy");

    public Controlador(Session sesion) {
        this.sesion = sesion;

        vMensaje = new VistaConsola();
        vPrincipal = new VistaPrincipal();
        vMonitor = new VistaMonitor();
        vSocio = new VistaSocio();
        vPorDefecto = new VistaPorDefecto();
        vSociosActividad = new VistaSociosActividad();
        vSociosActividades = new VistaSociosActividades();
        vistas = new Vistas();
        vMensajes = new VistaMensajes();
        vActualizacionPrecios = new VistaActualizacionPrecios();
        vCuotaSocio = new VistaCuotaSocio();

        monitorDAO = new MonitorDAO(sesion);
        socioDAO = new SocioDAO(sesion);
        actividadDAO = new ActividadDAO(sesion);

        addListeners();

        vPrincipal.setLocationRelativeTo(null);
        vPrincipal.setVisible(true);

        vSociosActividad.setLocationRelativeTo(null);
        vSociosActividad.setVisible(false);

        vSociosActividades.setLocationRelativeTo(null);
        vSociosActividades.setVisible(false);

        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vMonitor);
        vMonitor.setVisible(false);

        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vSocio);
        vSocio.setVisible(false);

        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vPorDefecto);
        vPorDefecto.setVisible(true);
        
        vActualizacionPrecios.setLocationRelativeTo(null);
        vActualizacionPrecios.setVisible(false);
        
        vCuotaSocio.setLocationRelativeTo(null);
        vCuotaSocio.setVisible(false);
    }

    private void addListeners() {
        vPrincipal.jMenuItemSalir.addActionListener(this);
        vPrincipal.jMenuItemMonitores.addActionListener(this);
        vPrincipal.jMenuItemSocios.addActionListener(this);
        vPrincipal.jMenuItemSociosPorActividad.addActionListener(this);
        vPrincipal.jMenuItemSociosActividades.addActionListener(this);
        vPrincipal.jMenuItemActualizacionDePrecios.addActionListener(this);
        vPrincipal.jMenuItemCuotaDeSocios.addActionListener(this);

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
        vSocio.jButtonFiltrarSociosCategoria.addActionListener(this);

        vSociosActividad.jButtonFiltrarProcedimiento.addActionListener(this);
        vSociosActividad.jButtonSalirProcedimiento.addActionListener(this);

        vSociosActividades.jButtonAltaSocioActividad.addActionListener(this);
        vSociosActividades.jButtonBajaSocioActividad.addActionListener(this);
        vSociosActividades.jButtonSalirSociosActividades.addActionListener(this);
        
        vActualizacionPrecios.jButtonActualizaPrecios.addActionListener(this);
        
        vCuotaSocio.jButtonVerCuota.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "CerrarVentanaPrincipal":
                vPrincipal.dispose();
                System.exit(0);
                break;

            case "GestionMonitores":
                vMonitor.setVisible(true);
                vSocio.setVisible(false);
                vPorDefecto.setVisible(false);
                vistas.dibujarTablaMonitores(vMonitor);
                
                //Limpieza de las etiquetas de texto
                vMonitor.jTextFieldCodigo.setText("");
                vMonitor.jTextFieldCorreo.setText("");
                vMonitor.jTextFieldDNI.setText("");
                vMonitor.jTextFieldNick.setText("");
                vMonitor.jTextFieldNombre.setText("");
                vMonitor.jTextFieldTelefono.setText("");
                vMonitor.jDateChooserFechaEntradaMonitor.setDate(new Date());

                //En este caso, se le añaden los listener de Mouse a la tabla jTableMonitores
                vMonitor.jTableMonitores.addMouseListener(new MouseAdapter() {
                    @Override
                    public void mouseClicked(MouseEvent evt) {
                        try {
                            vMonitorjTableMonitoresMouseClicked(evt);
                        } catch (SQLException | ParseException ex) {
                            Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                        } catch (Exception ex) {
                            Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                        }
                    }
                });

                try {
                    pideMonitores();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

            case "GestionSocios":
                vSocio.setVisible(true);
                vMonitor.setVisible(false);
                vPorDefecto.setVisible(false);
                vistas.dibujarTablaSocios(vSocio);
                
                //Limpieza de las etiquetas de texto
                vSocio.jTextFieldCategoria.setText("");
                vSocio.jTextFieldCorreo.setText("");
                vSocio.jTextFieldDNI.setText("");
                vSocio.jTextFieldFiltrarSociosCategorias.setText("");
                vSocio.jTextFieldNombre.setText("");
                vSocio.jTextFieldNumeroSocio.setText("");
                vSocio.jTextFieldTelefono.setText("");
                vSocio.jDateChooserFechaEntradaSocio.setDate(new Date());
                vSocio.jDateChooserFechaNacimientoSocio.setDate(new Date());

                //En este caso, se le añaden los listener de Mouse a la tabla jTableMonitores
                vSocio.jTableSocios.addMouseListener(new MouseAdapter() {
                    @Override
                    public void mouseClicked(MouseEvent evt) {
                        try {
                            vSociojTableSociosMouseClicked(evt);
                        } catch (SQLException | ParseException ex) {
                            Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                        } catch (Exception ex) {
                            Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                        }
                    }
                });

                try {
                    pideSocios();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

            case "GestionSociosActividad":
                vSociosActividad.setVisible(true);
                vistas.vaciarTablaSociosActividad();
                vistas.dibujarTablaSociosActividad(vSociosActividad);
                vSociosActividad.jComboBoxFiltrarProcedimiento.removeAllItems();

                try {
                    for (int i = 0; i < actividadDAO.getIdsActividad().size(); i++) {
                        vSociosActividad.jComboBoxFiltrarProcedimiento.addItem(actividadDAO.getIdsActividad().get(i));
                    }
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }

                break;

            case "Inscripciones de Socios en Actividades":
                vSociosActividades.setVisible(true);
                vistas.vaciarTablaSociosActividades();
                vistas.dibujarTablaSociosActividades(vSociosActividades);
                vSociosActividades.jComboBoxActividades.removeAllItems();
                vSociosActividades.jComboBoxSocios.removeAllItems();

                try {
                    ArrayList<String> idActividades = actividadDAO.getIdsActividad();
                    ArrayList<String> nombreActividades = actividadDAO.getNombreActividades();

                    //Rellenar el combobox de actividades y socios
                    for (int i = 0; i < idActividades.size(); i++) {
                        vSociosActividades.jComboBoxActividades.addItem(idActividades.get(i) + " - " + nombreActividades.get(i));
                    }

                    for (int i = 0; i < socioDAO.listaSocios().size(); i++) {
                        vSociosActividades.jComboBoxSocios.addItem(socioDAO.listaSocios().get(i).getNumerosocio() + " - " + socioDAO.listaSocios().get(i).getNombre());
                    }

                    //Rellenar la tablaSociosActividades con los valores correspondientes
                    pideSociosActividades();
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                break;

            case "Insertar":
                Monitor mon = new Monitor();
                mon.setCodmonitor(vMonitor.jTextFieldCodigo.getText());
                mon.setNombre(vMonitor.jTextFieldNombre.getText());
                mon.setDni(vMonitor.jTextFieldDNI.getText());
                mon.setTelefono(vMonitor.jTextFieldTelefono.getText());
                mon.setCorreo(vMonitor.jTextFieldCorreo.getText());
                mon.setNick(vMonitor.jTextFieldNick.getText());
                

                Date fechaChooser = vMonitor.jDateChooserFechaEntradaMonitor.getDate();
                if (fechaChooser != null) {
                    String fechaString = formatoFecha.format(fechaChooser);
                    mon.setFechaentrada(fechaString);
                }

                try {
                    monitorDAO.insertarMonitor(mon);
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }

                vistas.dibujarTablaMonitores(vMonitor);

                try {
                    pideMonitores();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;


            case "Actualizar":
                mon = new Monitor();

                mon.setCodmonitor(vMonitor.jTextFieldCodigo.getText());
                mon.setNombre(vMonitor.jTextFieldNombre.getText());
                mon.setDni(vMonitor.jTextFieldDNI.getText());
                mon.setTelefono(vMonitor.jTextFieldTelefono.getText());
                mon.setCorreo(vMonitor.jTextFieldCorreo.getText());
                mon.setNick(vMonitor.jTextFieldNick.getText());

                fechaChooser = vMonitor.jDateChooserFechaEntradaMonitor.getDate();
                if (fechaChooser != null) {
                    String fechaString = formatoFecha.format(fechaChooser);
                    mon.setFechaentrada(fechaString);
                }

                try {
                    monitorDAO.actualizarMonitor(mon);
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }

                vistas.dibujarTablaMonitores(vMonitor);

                try {
                    pideMonitores();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

            case "Eliminar":
                String cod = vMonitor.jTextFieldCodigo.getText();

                if (JOptionPane.showConfirmDialog(null, "¿Estás seguro de que desea eliminar al monitor con el código " + vMonitor.jTextFieldCodigo.getText() + "?", "Confirmar eliminación", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == 0)
                    try {

                        if (actividadDAO.existeMonitorActividad(cod).isEmpty()){ //Si el monitor no existe en la tabla REALIZA
                            monitorDAO.eliminarMonitor(cod);
                        } else {
                            //Insertamos monitor genérico en MONITOR (Si no existe)
                            if (monitorDAO.existeMonitor("M999").isEmpty()) {
                                mon = new Monitor();
                                mon.setCodmonitor("M999");
                                mon.setDni("00000000A");
                                mon.setNombre("Responsable Genérico");
                                monitorDAO.insertarMonitor(mon);
                            }
                            ArrayList<Actividad> actividad = actividadDAO.existeMonitorActividad(cod);

                            for (int i = 0; i < actividad.size(); i++) {
                                //Actualizamos todos los monitores de la tabla ACTIVIDAD con el monitor genérico
                                actividad.get(i).setMonitorresponsable(new Monitor("M999", "Responsable Genérico", "00000000A"));
                                actividadDAO.actualizaMonitorGenerico(actividad.get(i));
                            }

                            //Eliminamos el monitor
                            monitorDAO.eliminarMonitor(cod);
                        }
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }

                vistas.dibujarTablaMonitores(vMonitor);

                try {
                    pideMonitores();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

            case "VaciarTabla":
                vistas.vaciarTablaMonitores();
                break;

            case "ListarMonitores":
                vistas.dibujarTablaMonitores(vMonitor);

                try {
                    pideMonitores();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

            case "InsertarSocio":
                Socio soc = new Socio();

                soc.setNumerosocio(vSocio.jTextFieldNumeroSocio.getText());
                soc.setNombre(vSocio.jTextFieldNombre.getText());
                soc.setDni(vSocio.jTextFieldDNI.getText());
                soc.setTelefono(vSocio.jTextFieldTelefono.getText());
                soc.setCorreo(vSocio.jTextFieldCorreo.getText());
                soc.setCategoria(vSocio.jTextFieldCategoria.getText().charAt(0));

                fechaChooser = vSocio.jDateChooserFechaEntradaSocio.getDate();
                if (fechaChooser != null) {
                    String fechaString = formatoFecha.format(fechaChooser);
                    soc.setFechaentrada(fechaString);
                }

                fechaChooser = vSocio.jDateChooserFechaNacimientoSocio.getDate();
                if (fechaChooser != null) {
                    String fechaString = formatoFecha.format(fechaChooser);
                    soc.setFechanacimiento(fechaString);
                }

                try {
                    socioDAO.insertarSocio(soc);
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                vistas.dibujarTablaSocios(vSocio);

                try {
                    pideSocios();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

            case "ActualizarSocio":
                soc = new Socio();

                soc.setNumerosocio(vSocio.jTextFieldNumeroSocio.getText());
                soc.setNombre(vSocio.jTextFieldNombre.getText());
                soc.setDni(vSocio.jTextFieldDNI.getText());
                soc.setTelefono(vSocio.jTextFieldTelefono.getText());
                soc.setCorreo(vSocio.jTextFieldCorreo.getText());
                soc.setCategoria(vSocio.jTextFieldCategoria.getText().charAt(0));

                fechaChooser = vSocio.jDateChooserFechaEntradaSocio.getDate();
                if (fechaChooser != null) {
                    String fechaString = formatoFecha.format(fechaChooser);
                    soc.setFechaentrada(fechaString);
                }

                fechaChooser = vSocio.jDateChooserFechaNacimientoSocio.getDate();
                if (fechaChooser != null) {
                    String fechaString = formatoFecha.format(fechaChooser);
                    soc.setFechanacimiento(fechaString);
                }

                try {
                    socioDAO.actualizarSocio(soc.getNumerosocio(), soc);
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }

                vistas.dibujarTablaSocios(vSocio);

                try {
                    pideSocios();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

            case "EliminarSocio":
                String num = vSocio.jTextFieldNumeroSocio.getText();

                if (JOptionPane.showConfirmDialog(null, "¿Estás seguro de que desea eliminar al socio con numero " + vSocio.jTextFieldNumeroSocio.getText() + "?", "Confirmar eliminación", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == 0)
                    try {
                    socioDAO.eliminarSocio(num);
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }

                vistas.dibujarTablaSocios(vSocio);

                try {
                    pideSocios();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;

            case "VaciarTablaSocio":
                vistas.vaciarTablaSocios();
                break;

            case "ListarSocios":
                vistas.dibujarTablaSocios(vSocio);

                try {
                    pideSocios();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "FiltrarSocioCategoria":
                String letra = vSocio.jTextFieldFiltrarSociosCategorias.getText().toUpperCase();
            
                try {
                    vistas.vaciarTablaSocios();
                    vistas.rellenarTablaSocios(socioDAO.listaSociosCategoria(letra));
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                break;


            case "FiltrarProcedimiento":
                vistas.vaciarTablaSociosActividad();

                ArrayList<Object[]> sociosActividad = actividadDAO.verInfoSocioActividad(vSociosActividad.jComboBoxFiltrarProcedimiento.getSelectedItem().toString());

                for (int i = 0; i < sociosActividad.size(); i++) {
                    vistas.modeloTablaSociosActividad.addRow(sociosActividad.get(i));
                }
                break;

            case "SalirProcedimiento":
                vSociosActividad.setVisible(false);
                break;

            case "AltaSocioActividad":
                String numeroSocio = (String) vSociosActividades.jComboBoxSocios.getSelectedItem();
                String idActividad = (String) vSociosActividades.jComboBoxActividades.getSelectedItem();

                numeroSocio = numeroSocio.substring(0, 4);
                idActividad = idActividad.substring(0, 4);

                Transaction transaction = sesion.beginTransaction();

                soc = sesion.get(Socio.class, numeroSocio);
                Actividad act = sesion.get(Actividad.class, idActividad);

                if (act.addSocio(soc)) {
                    vMensajes.mensaje("El socio " + soc.getNombre() + " ha sido dado de alta en la actividad " + act.getNombre(), 1);
                } else {
                    vMensajes.mensaje("El socio " + soc.getNombre() + " ya está inscrito en la actividad " + act.getNombre(), 0);
                }

                //Una vez asignadas las relaciones en los dos sentidos, se pueden realizar una operación save() de cualquiera de los dos objetos para que
                //se almacene la tupla en la tabla intermedia
                sesion.save(soc);
                transaction.commit();

                vistas.vaciarTablaSociosActividades();
                vistas.dibujarTablaSociosActividades(vSociosActividades);

                try {
                    pideSociosActividades();
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                break;

            case "BajaSocioActividad":
                numeroSocio = (String) vSociosActividades.jComboBoxSocios.getSelectedItem();
                idActividad = (String) vSociosActividades.jComboBoxActividades.getSelectedItem();

                numeroSocio = numeroSocio.substring(0, 4);
                idActividad = idActividad.substring(0, 4);

                transaction = sesion.beginTransaction();

                soc = sesion.get(Socio.class, numeroSocio);
                act = sesion.get(Actividad.class, idActividad);

                if (act.eliminaSocio(soc)) {
                    vMensajes.mensaje(soc.getNombre() + " ha sido dado de baja correctamente de " + act.getNombre(), 1);
                } else {
                    vMensajes.mensaje(soc.getNombre() + " no ha sido dado de baja porque no está inscrito en la actividad " + act.getNombre(), 0);
                }

                sesion.save(act);
                transaction.commit();

                vistas.vaciarTablaSociosActividades();
                vistas.dibujarTablaSociosActividades(vSociosActividades);

                try {
                    pideSociosActividades();
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                break;

            case "SalirSociosActividades":
                vSociosActividades.setVisible(false);
                break;
                
            case "Actualización de Precios":
                vActualizacionPrecios.setVisible(true);
                vistas.vaciarTablaActualizaPrecios();
                vistas.dibujarTablaActualizaPrecios(vActualizacionPrecios);
            
                try {
                    pideActividades();
                } catch (Exception ex) {
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());                
                }
                break;
                
            case "Actualiza precios":
                int nuevoPrecio = Integer.parseInt(vActualizacionPrecios.jTextFieldIntroduceNumeroEntero.getText());
                
                try {
                    ArrayList<Actividad> actividades = actividadDAO.listaActividades();
                    
                    for(int i=0; i<actividades.size(); i++){
                        actividadDAO.actualizaPrecioActividades(actividades.get(i), nuevoPrecio);
                    }
                } catch (Exception ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                
                vistas.vaciarTablaActualizaPrecios();
                vistas.dibujarTablaActualizaPrecios(vActualizacionPrecios);
                
                try{
                    pideActividades();
                } catch(Exception ex){
                    vMensaje.Mensaje("error", "Error en la petición\n" + ex.getMessage());
                }
                break;
                
            case "Ventana de Cuotas":
                vCuotaSocio.setVisible(true);
                vCuotaSocio.jLabelCodigoDeSocio.setText("0");
                vCuotaSocio.jLabelCuotaMensual.setText("0");
                break;
                
            case "Ver Cuota":
                vCuotaSocio.jLabelNumeroDeActividades.setText(actividadDAO.);
                break;
        }
    }

    private void pideMonitores() throws Exception {
        ArrayList<Monitor> lMonitores = monitorDAO.listaMonitores();
        vistas.vaciarTablaMonitores();
        vistas.rellenarTablaMonitores(lMonitores);
    }

    private void pideSocios() throws Exception {
        ArrayList<Socio> lSocios = socioDAO.listaSocios();
        vistas.vaciarTablaSocios();
        vistas.rellenarTablaSocios(lSocios);
    }
    
    private void pideSociosActividades() throws Exception {
        vistas.vaciarTablaSociosActividades();
        System.out.println(socioDAO.listaSocios().size());

        for (int i = 0; i < socioDAO.listaSocios().size(); i++) {
            Actividad[] actividadesSocio = socioDAO.listaSocios().get(i).getActividades().toArray(new Actividad[socioDAO.listaSocios().get(i).getActividades().size()]);
            int counter = 0;

            for (Actividad actividadesSocio1 : actividadesSocio) {
                if (counter == 0) {
                    vistas.modeloTablaSociosActividades.addRow(new Object[]{socioDAO.listaSocios().get(i).getNombre(), actividadesSocio1.getNombre()});
                } else {
                    vistas.modeloTablaSociosActividades.addRow(new Object[]{"", actividadesSocio1.getNombre()});
                }

                System.out.println(socioDAO.listaSocios().get(i).getNombre() + "\t" + actividadesSocio1.getNombre());

                counter++;
            }
        }
    }
    
    private void pideActividades() throws Exception {
        ArrayList<Actividad> lActividades = actividadDAO.listaActividades();
        vistas.vaciarTablaActualizaPrecios();
        vistas.rellenarTablaActualizaPrecios(lActividades);
    }

    private void vMonitorjTableMonitoresMouseClicked(MouseEvent evt) throws SQLException, ParseException, Exception {
        int fila = vMonitor.jTableMonitores.getSelectedRow();

        vMonitor.jTextFieldCodigo.setText(monitorDAO.listaMonitores().get(fila).getCodmonitor());
        vMonitor.jTextFieldNombre.setText(monitorDAO.listaMonitores().get(fila).getNombre());
        vMonitor.jTextFieldDNI.setText(monitorDAO.listaMonitores().get(fila).getDni());
        vMonitor.jTextFieldTelefono.setText(monitorDAO.listaMonitores().get(fila).getTelefono());
        vMonitor.jTextFieldCorreo.setText(monitorDAO.listaMonitores().get(fila).getCorreo());
        vMonitor.jTextFieldNick.setText(monitorDAO.listaMonitores().get(fila).getNick());
        vMonitor.jDateChooserFechaEntradaMonitor.setDate(formatoFecha.parse(monitorDAO.listaMonitores().get(fila).getFechaentrada()));
    }

    private void vSociojTableSociosMouseClicked(MouseEvent evt) throws SQLException, ParseException, Exception {
        int fila = vSocio.jTableSocios.getSelectedRow();

        vSocio.jTextFieldNumeroSocio.setText(socioDAO.listaSocios().get(fila).getNumerosocio());
        vSocio.jTextFieldNombre.setText(socioDAO.listaSocios().get(fila).getNombre());
        vSocio.jTextFieldDNI.setText(socioDAO.listaSocios().get(fila).getDni());
        vSocio.jTextFieldTelefono.setText(socioDAO.listaSocios().get(fila).getTelefono());
        vSocio.jTextFieldCorreo.setText(socioDAO.listaSocios().get(fila).getCorreo());
        vSocio.jTextFieldCategoria.setText(socioDAO.listaSocios().get(fila).getCategoria().toString());
        vSocio.jDateChooserFechaEntradaSocio.setDate(formatoFecha.parse(socioDAO.listaSocios().get(fila).getFechaentrada()));
        vSocio.jDateChooserFechaNacimientoSocio.setDate(formatoFecha.parse(socioDAO.listaSocios().get(fila).getFechanacimiento()));
    }
}
