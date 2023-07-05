package Vista;

import javax.swing.JOptionPane;

public class VistaMensajes {

    public void vistaMensajeExito(String mensaje) {
        JOptionPane.showMessageDialog(null, mensaje, "", 1);
    }

    public void vistaMensajeError(String mensaje, String error) {
        JOptionPane.showMessageDialog(null, mensaje + "\n" + error, "", 0);
    }
}
