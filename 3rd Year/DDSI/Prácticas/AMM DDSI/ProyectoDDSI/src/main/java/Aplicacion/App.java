package Aplicacion;

import Controlador.ControladorLogin;

import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;
import javax.swing.UnsupportedLookAndFeelException;

/**
 *
 * @author Adrián Moreno Monterde
 */
public class App {

    public static void main(String[] args) {
        try {
            for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException | IllegalAccessException | InstantiationException | UnsupportedLookAndFeelException e) {
            //If Nimbus is not avaliable, you can set the GUI to another look and feel
            System.out.println("Nimbus design is not avaliable");
        }

        ControladorLogin cLogin = new ControladorLogin();
    }
}
