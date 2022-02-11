package Vista;

import javax.swing.JOptionPane;

/**
 *
 * @author adrianmorenomonterde
 */
public class VistaMensajes 
{
   public void vistaMensajeExito()
   {
       JOptionPane.showMessageDialog(null, "Conexion correcta", "", 1);
   }
   
   public void vistaMensajeError(String error)
   {
       JOptionPane.showMessageDialog(null, "Conexion incorrecta. Revise los parámetros introducidos\n" + error, "", 0);
   }
}
