package Aplicacion;

import Controlador.ControladorLogin;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;

public class Main 
{
    public static void main(String[] args) 
    {
        try
        {
            for(LookAndFeelInfo info : UIManager.getInstalledLookAndFeels())
            {
                if("Nimbus".equals(info.getName()))
                {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch(Exception e)
        {
            JOptionPane.showMessageDialog(null, "Error a la hora de establecer el tema Nimbus", "Error", 0);
        }
        
        ControladorLogin cLogin = new ControladorLogin();
    }
}
