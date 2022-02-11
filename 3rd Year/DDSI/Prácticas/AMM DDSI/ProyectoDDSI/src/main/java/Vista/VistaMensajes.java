package Vista;

import javax.swing.JOptionPane;

/**
 *
 * @author adrianmorenomonterde
 */
public class VistaMensajes {

    /*public void vistaMensajeExito() {
        JOptionPane.showMessageDialog(null, "Conexion correcta", "", 1);
    }

    public void vistaMensajeError(String error) {
        JOptionPane.showMessageDialog(null, "Conexion incorrecta. Revise los parámetros introducidos\n" + error, "", 0);
    }
    
    public void altaSocioActividadExito(String nombreSocio, String nombreActividad) {
        JOptionPane.showMessageDialog(null, "El socio " + nombreSocio + " ha sido dado de alta en la actividad " + nombreActividad + " correctamente", "", 1);
    }

    public void altaSocioActividadError(String nombreSocio, String nombreActividad) {
        JOptionPane.showMessageDialog(null, "El socio " + nombreSocio + " ya está inscrito en la actividad " + nombreActividad, "", 0);
    }

    public void bajaSocioActividadExito(String nombreSocio, String nombreActividad) {
        JOptionPane.showMessageDialog(null, nombreSocio + " ha sido dado de baja correctamente de " + nombreActividad, "", 1);
    }

    public void bajaSocioActividadError(String nombreSocio, String nombreActividad) {
        JOptionPane.showMessageDialog(null, nombreSocio + " no ha sido dado de baja porque no está inscrito en la actividad " + nombreActividad, "", 0);
    }*/
    
    public void mensaje(String texto, int tipo){
        JOptionPane.showMessageDialog(null, texto, "", tipo);
    }
}
