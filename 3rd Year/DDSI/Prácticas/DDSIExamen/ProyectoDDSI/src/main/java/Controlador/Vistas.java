package Controlador;

import Modelo.Actividad;
import Modelo.Monitor;
import Modelo.Socio;
import Vista.VistaActualizacionPrecios;
import Vista.VistaMonitor;
import Vista.VistaSocio;
import Vista.VistaSociosActividad;
import Vista.VistaSociosActividades;
import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author adrianmorenomonterde
 */
public class Vistas {

    //Se sobreescribe el método isCellEditable paara hacer que las filas no se puedan editar al hacer doble click
    public DefaultTableModel modeloTablaMonitores = new DefaultTableModel() {
        @Override
        public boolean isCellEditable(int row, int column) {
            return false;
        }
    };

    public DefaultTableModel modeloTablaSocios = new DefaultTableModel() {
        @Override
        public boolean isCellEditable(int row, int column) {
            return false;
        }
    };

    public DefaultTableModel modeloTablaSociosActividad = new DefaultTableModel() {
        @Override
        public boolean isCellEditable(int row, int column) {
            return false;
        }
    };

    public DefaultTableModel modeloTablaSociosActividades = new DefaultTableModel() {
        @Override
        public boolean isCellEditable(int row, int column) {
            return false;
        }
    };
    
    public DefaultTableModel modeloTablaActualizaPrecios = new DefaultTableModel() {
        @Override
        public boolean isCellEditable(int row, int column) {
            return false;
        }
    };

    //Función dibujar de la tabla MONITORES
    public void dibujarTablaMonitores(VistaMonitor vMonitor) {
        vMonitor.jTableMonitores.setModel(modeloTablaMonitores);

        String[] columnasTabla = {"Código", "Nombre", "DNI", "Teléfono", "Correo", "Fecha Incorporación", "Nick"};
        modeloTablaMonitores.setColumnIdentifiers(columnasTabla);

        //Para no permitir el redimensionamiento de las columnas con el ratón
        vMonitor.jTableMonitores.getTableHeader().setResizingAllowed(false);
        vMonitor.jTableMonitores.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);

        //Así se fija el ancho de las columnas
        vMonitor.jTableMonitores.getColumnModel().getColumn(0).setPreferredWidth(40);
        vMonitor.jTableMonitores.getColumnModel().getColumn(1).setPreferredWidth(240);
        vMonitor.jTableMonitores.getColumnModel().getColumn(2).setPreferredWidth(70);
        vMonitor.jTableMonitores.getColumnModel().getColumn(3).setPreferredWidth(70);
        vMonitor.jTableMonitores.getColumnModel().getColumn(4).setPreferredWidth(200);
        vMonitor.jTableMonitores.getColumnModel().getColumn(5).setPreferredWidth(150);
        vMonitor.jTableMonitores.getColumnModel().getColumn(6).setPreferredWidth(60);

    }

    //Función dibujar de la tabla SOCIOS
    public void dibujarTablaSocios(VistaSocio vSocio) {
        vSocio.jTableSocios.setModel(modeloTablaSocios);

        String[] columnasTabla = {"Número Socio", "Nombre", "DNI", "Fecha nacimiento", "Teléfono", "Correo", "Fecha entrada", "Categoría"};
        modeloTablaSocios.setColumnIdentifiers(columnasTabla);

        //Para no permitir el redimensionamiento de las columnas con el ratón
        vSocio.jTableSocios.getTableHeader().setResizingAllowed(false);
        vSocio.jTableSocios.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);

        //Así se fija el ancho de las columnas
        vSocio.jTableSocios.getColumnModel().getColumn(0).setPreferredWidth(40);
        vSocio.jTableSocios.getColumnModel().getColumn(1).setPreferredWidth(200);
        vSocio.jTableSocios.getColumnModel().getColumn(2).setPreferredWidth(70);
        vSocio.jTableSocios.getColumnModel().getColumn(3).setPreferredWidth(90);
        vSocio.jTableSocios.getColumnModel().getColumn(4).setPreferredWidth(70);
        vSocio.jTableSocios.getColumnModel().getColumn(5).setPreferredWidth(230);
        vSocio.jTableSocios.getColumnModel().getColumn(6).setPreferredWidth(90);
        vSocio.jTableSocios.getColumnModel().getColumn(7).setPreferredWidth(20);
    }

    //Función dibujar la tabla SOCIOSACTIVIDAD
    public void dibujarTablaSociosActividad(VistaSociosActividad vSociosActividad) {
        vSociosActividad.jTableSociosActividad.setModel(modeloTablaSociosActividad);

        String[] columasTabla = {"Nombre", "Correo"};
        modeloTablaSociosActividad.setColumnIdentifiers(columasTabla);

        //Para no permitir el redimensionamiento de las columnas con el ratón
        vSociosActividad.jTableSociosActividad.getTableHeader().setResizingAllowed(false);
        vSociosActividad.jTableSociosActividad.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);

        //Fijamos el ancho de las columnas
        vSociosActividad.jTableSociosActividad.getColumnModel().getColumn(0).setPreferredWidth(150);
        vSociosActividad.jTableSociosActividad.getColumnModel().getColumn(1).setPreferredWidth(150);
    }

    //Función para dibujar la tabla SOCIOSACTIVIDADES
    public void dibujarTablaSociosActividades(VistaSociosActividades vSociosActividades) {
        vSociosActividades.jTableSociosActividades.setModel(modeloTablaSociosActividades);

        String[] columnasTabla = {"Socio", "Actividad"};
        modeloTablaSociosActividades.setColumnIdentifiers(columnasTabla);

        //Para no permitir el redimensionamiento de las columnas con el ratón
        vSociosActividades.jTableSociosActividades.getTableHeader().setResizingAllowed(false);
        vSociosActividades.jTableSociosActividades.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);

        //Fijamos el ancho de las columnas
        vSociosActividades.jTableSociosActividades.getColumnModel().getColumn(0).setPreferredWidth(120);
        vSociosActividades.jTableSociosActividades.getColumnModel().getColumn(1).setPreferredWidth(120);
    }
    
    //Función para dibujar la tabla ACTUALIZAPRECIOS
    public void dibujarTablaActualizaPrecios(VistaActualizacionPrecios vActualizacionPrecios) {
        vActualizacionPrecios.jTableActualizacionPrecios.setModel(modeloTablaActualizaPrecios);
        
        String[] columnasTabla = {"Código", "Nombre", "Precio"};
        modeloTablaActualizaPrecios.setColumnIdentifiers(columnasTabla);
        
        //Para no permitir el redimensionamiento de las columnas con el ratón
        vActualizacionPrecios.jTableActualizacionPrecios.getTableHeader().setResizingAllowed(false);
        vActualizacionPrecios.jTableActualizacionPrecios.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
        
        //Fijamos el ancho de las columnas
        vActualizacionPrecios.jTableActualizacionPrecios.getColumnModel().getColumn(0).setPreferredWidth(40);
        vActualizacionPrecios.jTableActualizacionPrecios.getColumnModel().getColumn(1).setPreferredWidth(100);
        vActualizacionPrecios.jTableActualizacionPrecios.getColumnModel().getColumn(2).setPreferredWidth(40);

    }

    //Función para mostrar los datos de la tabla MONITOR a partir de una lista de monitores
    public void rellenarTablaMonitores(ArrayList<Monitor> monitores) {
        Object[] fila = new Object[7];
        int numRegistros = monitores.size();

        for (int i = 0; i < numRegistros; i++) {
            fila[0] = monitores.get(i).getCodmonitor();
            fila[1] = monitores.get(i).getNombre();
            fila[2] = monitores.get(i).getDni();
            fila[3] = monitores.get(i).getTelefono();
            fila[4] = monitores.get(i).getCorreo();
            fila[5] = monitores.get(i).getFechaentrada();
            fila[6] = monitores.get(i).getNick();

            modeloTablaMonitores.addRow(fila);
        }
    }

    //Función para mostrar los datos de la tabla SOCIO a partir de una lista de socios
    public void rellenarTablaSocios(ArrayList<Socio> socios) {
        Object[] fila = new Object[8];
        int numRegistros = socios.size();

        for (int i = 0; i < numRegistros; i++) {
            fila[0] = socios.get(i).getNumerosocio();
            fila[1] = socios.get(i).getNombre();
            fila[2] = socios.get(i).getDni();
            fila[3] = socios.get(i).getFechanacimiento();
            fila[4] = socios.get(i).getTelefono();
            fila[5] = socios.get(i).getCorreo();
            fila[6] = socios.get(i).getFechaentrada();
            fila[7] = socios.get(i).getCategoria();

            modeloTablaSocios.addRow(fila);
        }
    }
    
    //Función para mostrar los datos de la tabla ACTUALIZAPRECIOS  partir de una lista actividades
    public void rellenarTablaActualizaPrecios(ArrayList<Actividad> actividades) {
        Object[] fila = new Object[3];
        int numRegistros = actividades.size();
        
        for (int i=0; i<numRegistros; i++){
            fila[0] = actividades.get(i).getIdactividad();
            fila[1] = actividades.get(i).getNombre();
            fila[2] = actividades.get(i).getPreciobasemes();
            
            modeloTablaActualizaPrecios.addRow(fila);
        }
    }

    //Función para vaciar el contenido de la tabla MONITOR
    public void vaciarTablaMonitores() {
        while (modeloTablaMonitores.getRowCount() > 0) {
            modeloTablaMonitores.removeRow(0);
        }
    }

    //Función para vaciar el contenido de la tabla SOCIO
    public void vaciarTablaSocios() {
        while (modeloTablaSocios.getRowCount() > 0) {
            modeloTablaSocios.removeRow(0);
        }
    }

    //Función para vaciar el contenido de la tabla SOCIOSACTIVIDAD
    public void vaciarTablaSociosActividad() {
        while (modeloTablaSociosActividad.getRowCount() > 0) {
            modeloTablaSociosActividad.removeRow(0);
        }
    }

    //Función para vaciar el contenido de la tabla SOCIOSACTIVIDADES
    public void vaciarTablaSociosActividades() {
        while (modeloTablaSociosActividades.getRowCount() > 0) {
            modeloTablaSociosActividades.removeRow(0);
        }
    }
    
    //Función para vaciar el contenido de la tabla ACTUALIZAPRECIOS
    public void vaciarTablaActualizaPrecios() {
        while (modeloTablaActualizaPrecios.getRowCount() > 0) {
            modeloTablaActualizaPrecios.removeRow(0);
        }
    }
}
