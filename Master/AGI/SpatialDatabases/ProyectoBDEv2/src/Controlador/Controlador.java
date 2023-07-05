package Controlador;

import Modelo.Conexion;
import Modelo.Estacion;
import Modelo.EstacionDAO;
import Vista.VistaPrincipal;
import Vista.VistaMensajes;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.ArrayList;

public class Controlador implements ActionListener {

    private Conexion conexion = null;
    private VistaPrincipal vPrincipal = null;
    private VistaMensajes vMensajes = null;
    private Tablas tablas = null;
    private EstacionDAO estacionDAO = null;

    public Controlador(Conexion conexion) {
        this.conexion = conexion;
        vPrincipal = new VistaPrincipal();
        vMensajes = new VistaMensajes();
        tablas = new Tablas();
        estacionDAO = new EstacionDAO(conexion);

        addListeners();

        vPrincipal.setLocationRelativeTo(null);
        vPrincipal.setVisible(true);
        tablas.dibujarTablaEstaciones(vPrincipal);
    }

    private void addListeners() {
        vPrincipal.jButtonCargarDatos.addActionListener(this);
        vPrincipal.jButtonFiltrar.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "Cargar datos":
                try {
                muestraEstaciones();
                vMensajes.vistaMensajeExito("Datos cargados correctamente!!");
                ArrayList<String> provincias = estacionDAO.listadoProvincias();
                vPrincipal.jComboBoxProvincias.addItem("Todas las provincias");
                for (String provincia : provincias) {
                    vPrincipal.jComboBoxProvincias.addItem(provincia);
                }
            } catch (Exception ex) {
                vMensajes.vistaMensajeError("Error a la hora de cargar los datos", ex.getMessage());
            }
            break;

            case "Filtrar":
                tablas.vaciarTablaEstaciones();

                try {
                    ArrayList<Estacion> filProvincia = estacionDAO.filtradoProvincia(String.valueOf(vPrincipal.jComboBoxProvincias.getSelectedItem()));
                    tablas.rellenarTablaEstaciones(filProvincia);
                    vPrincipal.jLabel1.setText(String.valueOf(filProvincia.size()));
                } catch (SQLException ex) {
                    vMensajes.vistaMensajeError("Error a la hora de filtrar los datos por provincia", ex.getMessage());
                }

                break;

        }
    }

    private void muestraEstaciones() throws Exception {
        ArrayList<Estacion> lEstaciones = estacionDAO.listaEstaciones();
        tablas.vaciarTablaEstaciones();
        tablas.rellenarTablaEstaciones(lEstaciones);
        vPrincipal.jLabel1.setText(String.valueOf(lEstaciones.size()));
    }

}
