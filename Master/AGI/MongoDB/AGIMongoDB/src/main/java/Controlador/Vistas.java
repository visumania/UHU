package Controlador;

import Modelo.Tweet;
import Vista.VistaConsultas;
import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class Vistas 
{
    //Se sobreescribe el método is cellEditable para hacer que las filas no se puedan editar al hacer doble click
    public DefaultTableModel modeloTablaConsultas = new DefaultTableModel(){
        @Override
        public boolean isCellEditable(int row, int column){
            return false;
        }
    };
    
    //Función dibujar de la tabla CONSULTAS
    public void dibujarTablaTweets(VistaConsultas vConsultas)
    {
        vConsultas.jTableConsultas.setModel(modeloTablaConsultas);
        
        String[] columnasTabla = {"Nombre de usuario", "Seguidores", "Tweet", "Idioma", "Fecha del tweet"};
        modeloTablaConsultas.setColumnIdentifiers(columnasTabla);
        
        //Para no permitir el redimensionamiento de las columnas con el ratón
        vConsultas.jTableConsultas.getTableHeader().setResizingAllowed(false);
        vConsultas.jTableConsultas.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
        
        //Así se fija el ancho de las columnas
        vConsultas.jTableConsultas.getColumnModel().getColumn(0).setPreferredWidth(70);
        vConsultas.jTableConsultas.getColumnModel().getColumn(1).setPreferredWidth(10);
        vConsultas.jTableConsultas.getColumnModel().getColumn(2).setPreferredWidth(400);
        vConsultas.jTableConsultas.getColumnModel().getColumn(3).setPreferredWidth(10);
        vConsultas.jTableConsultas.getColumnModel().getColumn(4).setPreferredWidth(150);

    }
    
    //Función para mostrar los datos de la tabla CONSULTAS a partir de una lista de tweets
    public void rellenarTablaConsulta(ArrayList<Tweet> tweets)
    {
        Object[] fila = new Object[5];
        int numRegistros = tweets.size();
        
        for(int i=0; i<numRegistros; i++)
        {
            fila[0] = tweets.get(i).getUsername();
            fila[1] = tweets.get(i).getFollowers();
            fila[2] = tweets.get(i).getText();
            fila[3] = tweets.get(i).getLanguage();
            fila[4] = tweets.get(i).getDate();
            
            modeloTablaConsultas.addRow(fila);
        }
    }
    
    //Función para vaciar el contenido de la tabla CONSULTAS
    public void vaciarTablaConsultas(){
        while(modeloTablaConsultas.getRowCount() > 0){
            modeloTablaConsultas.removeRow(0);
        }
    }
}
