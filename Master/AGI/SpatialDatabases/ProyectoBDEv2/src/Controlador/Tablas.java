package Controlador;

import javax.swing.table.DefaultTableModel;
import javax.swing.JTable;
import Modelo.Estacion;
import Vista.VistaPrincipal;
import java.util.ArrayList;

public class Tablas {

    //Se sobreescribe el método isCellEditable para hacer que las filas no se puedan editar al hacer doble click
    public DefaultTableModel modeloTablaEstaciones = new DefaultTableModel() {
        @Override
        public boolean isCellEditable(int row, int column) {
            return false;
        }
    };

    //Función dibujar de la tabla ESTACIONES
    public void dibujarTablaEstaciones(VistaPrincipal vPrincipal) {
        vPrincipal.jTableEstaciones.setModel(modeloTablaEstaciones);

        String[] columnasTabla = {"Provincia", "Nombre Estación", "Latitud", "Longitud"};
        modeloTablaEstaciones.setColumnIdentifiers(columnasTabla);

        //Para no permitir el redimensionamiento de las columnas con el ratón
        vPrincipal.jTableEstaciones.getTableHeader().setResizingAllowed(false);
        vPrincipal.jTableEstaciones.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);

        //Así se fija el ancho de las columnas
        vPrincipal.jTableEstaciones.getColumnModel().getColumn(0).setPreferredWidth(70);
        vPrincipal.jTableEstaciones.getColumnModel().getColumn(1).setPreferredWidth(150);
        vPrincipal.jTableEstaciones.getColumnModel().getColumn(2).setPreferredWidth(50);
        vPrincipal.jTableEstaciones.getColumnModel().getColumn(3).setPreferredWidth(50);
    }

    //Función para mostrar los datos de la tabla ESTACIONES a partir de una lista de estaciones
    public void rellenarTablaEstaciones(ArrayList<Estacion> estaciones) {
        Object[] fila = new Object[5];
        int numRegistros = estaciones.size();

        for (int i = 0; i < numRegistros; i++) {
            fila[0] = estaciones.get(i).getProvincia();
            fila[1] = estaciones.get(i).getNombre();
            fila[2] = estaciones.get(i).getLatitud();
            fila[3] = estaciones.get(i).getLongitud();

            modeloTablaEstaciones.addRow(fila);
        }
    }

    //Función para vaciar el contenido de la tabla CONSULTAS
    public void vaciarTablaEstaciones() {
        while (modeloTablaEstaciones.getRowCount() > 0) {
            modeloTablaEstaciones.removeRow(0);
        }
    }
}
