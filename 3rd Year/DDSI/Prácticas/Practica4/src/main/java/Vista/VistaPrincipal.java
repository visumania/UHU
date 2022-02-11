/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Vista;

import Modelo.Conexion;
import java.sql.SQLException;
import javax.swing.JOptionPane;

/**
 *
 * @author adrianmorenomonterde
 */
public class VistaPrincipal extends javax.swing.JFrame {
    
    static Conexion co = null;
    
    /**
     * Creates new form VistaPrincipal
     */
    public VistaPrincipal() 
    {
        try
        {
            co = new Conexion();
            initComponents();
        } catch(Exception ex)
        {
            JOptionPane.showMessageDialog(null, ex.getMessage());
            System.exit(1);
        }
    }
    
    private void vSubMenuSalirActionPerformed(java.awt.event.ActionEvent evt)
    {
        try
        {
            co.desconexion();
        }catch(SQLException ex)
        {
            JOptionPane.showMessageDialog(null, ex.getMessage());
        }finally
        {
            this.dispose();
        }
    }
    
    /*private void vSubMenuGestionMonitoresActionPerformed(java.awt.event.ActionEvent evt)
    {
        try
        {
            VistaMonitor vM = new VistaMonitor(co);
            vM.
        }
    }*/

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenuBar1 = new javax.swing.JMenuBar();
        jMenuSalir = new javax.swing.JMenu();
        jMenuItemSalir = new javax.swing.JMenuItem();
        jMenuMonitores = new javax.swing.JMenu();
        jMenuItemMonitores = new javax.swing.JMenuItem();
        jMenuSocios = new javax.swing.JMenu();
        jMenuItemSocios = new javax.swing.JMenuItem();
        jMenuActividades = new javax.swing.JMenu();
        jMenuItemSociosPorActividad = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Ventana principal de la aplicación");

        jMenuSalir.setText("Salir");
        jMenuSalir.setToolTipText("");
        jMenuSalir.setActionCommand("");

        jMenuItemSalir.setText("Salir de la Aplicación");
        jMenuItemSalir.setActionCommand("CerrarVentanaPrincipal");
        jMenuSalir.add(jMenuItemSalir);

        jMenuBar1.add(jMenuSalir);

        jMenuMonitores.setText("Monitores");
        jMenuMonitores.setActionCommand("");

        jMenuItemMonitores.setText("Gestión de Monitores");
        jMenuItemMonitores.setActionCommand("GestionMonitores");
        jMenuMonitores.add(jMenuItemMonitores);

        jMenuBar1.add(jMenuMonitores);

        jMenuSocios.setText("Socios");
        jMenuSocios.setActionCommand("");

        jMenuItemSocios.setText("Gestión de Socios");
        jMenuItemSocios.setActionCommand("GestionSocios");
        jMenuSocios.add(jMenuItemSocios);

        jMenuBar1.add(jMenuSocios);

        jMenuActividades.setText("Actividades");

        jMenuItemSociosPorActividad.setText("Socios por Actividad");
        jMenuItemSociosPorActividad.setActionCommand("GestionSociosActividad");
        jMenuActividades.add(jMenuItemSociosPorActividad);

        jMenuBar1.add(jMenuActividades);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 1033, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 546, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
   
    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JMenu jMenuActividades;
    public javax.swing.JMenuBar jMenuBar1;
    public javax.swing.JMenuItem jMenuItemMonitores;
    public javax.swing.JMenuItem jMenuItemSalir;
    public javax.swing.JMenuItem jMenuItemSocios;
    public javax.swing.JMenuItem jMenuItemSociosPorActividad;
    public javax.swing.JMenu jMenuMonitores;
    public javax.swing.JMenu jMenuSalir;
    public javax.swing.JMenu jMenuSocios;
    // End of variables declaration//GEN-END:variables
}
