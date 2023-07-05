package Controlador;

import Modelo.*;
import Vista.*;
import com.mongodb.client.MongoIterable;
import java.awt.CardLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Controlador implements ActionListener
{    
    private VistaMensajes vMensajes = null;
    private VistaPrincipal vPrincipal = null;
    private VistaEstadisticas vEstadisticas = null;
    private VistaConsultas vConsultas = null;
    private VistaPorDefecto vPorDefecto = null;
    private Vistas vistas = null;
    
    private TweetDAO tweetDAO = null;
    
    private MongoIterable<String> nColecciones = null;
    private List<Map.Entry<String, Integer>> lista = null;
    private ArrayList<String> hashtagsMasUtilizados = null;
    private ArrayList<String> idiomasMasFrecuentes = null;
    private ArrayList<String> usuariosConMasTweets = null;
    
    public Controlador(Conexion conexion)
    {
        vMensajes = new VistaMensajes();
        vPrincipal = new VistaPrincipal();
        vEstadisticas = new VistaEstadisticas();
        vConsultas = new VistaConsultas();
        vPorDefecto = new VistaPorDefecto();
        vistas = new Vistas();
        
        tweetDAO = new TweetDAO(conexion);
        
        
        addListeners();
        
        vPrincipal.setLocationRelativeTo(null);
        vPrincipal.setVisible(true);
        
        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vEstadisticas);
        vEstadisticas.setVisible(false);
        
        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vConsultas);
        vConsultas.setVisible(false);
        
        vPrincipal.getContentPane().setLayout(new CardLayout());
        vPrincipal.add(vPorDefecto);
        vPorDefecto.setVisible(true);
    }
    
    private void addListeners()
    {
        vPrincipal.jMenuItemSalir.addActionListener(this);
        vPrincipal.jMenuItemEstadisticas.addActionListener(this);
        vPrincipal.jMenuItemConsultas.addActionListener(this);
        
        vEstadisticas.jButtonCambiarColeccionEstadisticas.addActionListener(this);
        
        vConsultas.jButtonConsultar.addActionListener(this);
        vConsultas.jButtonCambiarColeccion.addActionListener(this);
        vConsultas.jButtonVolcarAColeccion.addActionListener(this);
    }
    
    @Override
    public void actionPerformed(ActionEvent e)
    {
       switch(e.getActionCommand())
       {
           case "CerrarVentanaPrincipal":
               vPrincipal.dispose();
               System.exit(0);
               break;
               
           case "Estadisticas":
               vEstadisticas.setVisible(true);
               vConsultas.setVisible(false);
                              
               vEstadisticas.jComboBoxColecciones.removeAllItems();
               nColecciones = tweetDAO.nombreColecciones();
               
               //Rellenamos el ComboBox
               for(String nColeccion:nColecciones)
               {
                   vEstadisticas.jComboBoxColecciones.addItem(nColeccion);
               }
                              
               vEstadisticas.jLabelNTweetsAlmacenados.setText(String.valueOf(tweetDAO.numTweets("tweets")) + " tweets");
               
               vEstadisticas.jLabelUsername.setText(tweetDAO.usuarioConMasSeguidores("tweets").getUsername());
               vEstadisticas.jLabelNFollowers.setText(String.valueOf(tweetDAO.usuarioConMasSeguidores("tweets").getFollowers()));
               
               vEstadisticas.jLabelFechaMasReciente.setText(tweetDAO.fechaMasReciente("tweets").toString());
               vEstadisticas.jLabelFechaMenosReciente.setText(tweetDAO.fechaMenosReciente("tweets").toString());
               
               
               lista = tweetDAO.usuariosMasMencionados("tweets");
               
               vEstadisticas.jLabelUsuarioConMasMenciones1.setText(lista.get(0).toString() + " menciones");
               vEstadisticas.jLabelUsuarioConMasMenciones2.setText(lista.get(1).toString() + " menciones");
               vEstadisticas.jLabelUsuarioConMasMenciones3.setText(lista.get(2).toString() + " menciones");
               vEstadisticas.jLabelUsuarioConMasMenciones4.setText(lista.get(3).toString() + " menciones");
               vEstadisticas.jLabelUsuarioConMasMenciones5.setText(lista.get(4).toString() + " menciones");
                
               hashtagsMasUtilizados = tweetDAO.hashtagsMasUtilizados("tweets");
               vEstadisticas.jLabelHashtagMasUtilizado1.setText(hashtagsMasUtilizados.get(0));
               vEstadisticas.jLabelHashtagMasUtilizado2.setText(hashtagsMasUtilizados.get(1));
               vEstadisticas.jLabelHashtagMasUtilizado3.setText(hashtagsMasUtilizados.get(2));
               vEstadisticas.jLabelHashtagMasUtilizado4.setText(hashtagsMasUtilizados.get(3));
               vEstadisticas.jLabelHashtagMasUtilizado5.setText(hashtagsMasUtilizados.get(4));
               
               vEstadisticas.jLabelNumeroIdiomasDiferentes.setText(String.valueOf(tweetDAO.numeroIdiomasDiferentes("tweets")));
               
               idiomasMasFrecuentes = tweetDAO.idiomasMasFrecuentes("tweets");
               vEstadisticas.jLabelIdiomaMasUtilizado1.setText(idiomasMasFrecuentes.get(0));
               vEstadisticas.jLabelIdiomaMasUtilizado2.setText(idiomasMasFrecuentes.get(1));
               vEstadisticas.jLabelIdiomaMasUtilizado3.setText(idiomasMasFrecuentes.get(2));
               vEstadisticas.jLabelIdiomaMasUtilizado4.setText(idiomasMasFrecuentes.get(3));
               vEstadisticas.jLabelIdiomaMasUtilizado5.setText(idiomasMasFrecuentes.get(4));
               
               vEstadisticas.jLabelNumeroRTs.setText(String.valueOf(tweetDAO.numeroDeRT("tweets")) + " RTs");
               
               vEstadisticas.jLabelNUsuariosDiferentes.setText(String.valueOf(tweetDAO.numeroDeUsuariosDiferentes("tweets")) + " usuarios");
               
               usuariosConMasTweets = tweetDAO.usuariosFrecuenciaTweets("tweets");
               vEstadisticas.jLabelUsuarioConMasTweets1.setText(usuariosConMasTweets.get(0));
               vEstadisticas.jLabelUsuarioConMasTweets2.setText(usuariosConMasTweets.get(1));
               vEstadisticas.jLabelUsuarioConMasTweets3.setText(usuariosConMasTweets.get(2));
               vEstadisticas.jLabelUsuarioConMasTweets4.setText(usuariosConMasTweets.get(3));
               vEstadisticas.jLabelUsuarioConMasTweets5.setText(usuariosConMasTweets.get(4));
               
               break;
               
           case "cambiarColeccion":
               
               vEstadisticas.jLabelNTweetsAlmacenados.setText(String.valueOf(tweetDAO.numTweets(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem()))) + " tweets");
               
               vEstadisticas.jLabelUsername.setText(tweetDAO.usuarioConMasSeguidores(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem())).getUsername());
               vEstadisticas.jLabelNFollowers.setText(String.valueOf(tweetDAO.usuarioConMasSeguidores(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem())).getFollowers()));
               
               vEstadisticas.jLabelFechaMasReciente.setText(tweetDAO.fechaMasReciente(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem())).toString());
               vEstadisticas.jLabelFechaMenosReciente.setText(tweetDAO.fechaMenosReciente(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem())).toString());
               
               lista = tweetDAO.usuariosMasMencionados(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem()));
               
               //Inicializamos las etiquetas a "" (vacío)
               vEstadisticas.jLabelUsuarioConMasMenciones1.setText("");
               vEstadisticas.jLabelUsuarioConMasMenciones2.setText("");
               vEstadisticas.jLabelUsuarioConMasMenciones3.setText("");
               vEstadisticas.jLabelUsuarioConMasMenciones4.setText("");
               vEstadisticas.jLabelUsuarioConMasMenciones5.setText("");          
               
               if(lista.size()==1)
                   vEstadisticas.jLabelUsuarioConMasMenciones1.setText(lista.get(0).toString() + " menciones");

               if(lista.size()==2)
               {
                   vEstadisticas.jLabelUsuarioConMasMenciones1.setText(lista.get(0).toString() + " menciones");
                   vEstadisticas.jLabelUsuarioConMasMenciones2.setText(lista.get(1).toString() + " menciones");              
               }
               
               if(lista.size()==3)
               {
                   vEstadisticas.jLabelUsuarioConMasMenciones1.setText(lista.get(0).toString() + " menciones");
                   vEstadisticas.jLabelUsuarioConMasMenciones2.setText(lista.get(1).toString() + " menciones");
                   vEstadisticas.jLabelUsuarioConMasMenciones3.setText(lista.get(2).toString() + " menciones");
               }
               
               if(lista.size()==4)
               {
                   vEstadisticas.jLabelUsuarioConMasMenciones1.setText(lista.get(0).toString() + " menciones");
                   vEstadisticas.jLabelUsuarioConMasMenciones2.setText(lista.get(1).toString() + " menciones");
                   vEstadisticas.jLabelUsuarioConMasMenciones3.setText(lista.get(2).toString() + " menciones");
                   vEstadisticas.jLabelUsuarioConMasMenciones4.setText(lista.get(3).toString() + " menciones");

               }
               
               if(lista.size()==5)
               {
                    vEstadisticas.jLabelUsuarioConMasMenciones1.setText(lista.get(0).toString() + " menciones");
                    vEstadisticas.jLabelUsuarioConMasMenciones2.setText(lista.get(1).toString() + " menciones");
                    vEstadisticas.jLabelUsuarioConMasMenciones3.setText(lista.get(2).toString() + " menciones");
                    vEstadisticas.jLabelUsuarioConMasMenciones4.setText(lista.get(3).toString() + " menciones");
                    vEstadisticas.jLabelUsuarioConMasMenciones5.setText(lista.get(4).toString() + " menciones");
               }
               
               hashtagsMasUtilizados = tweetDAO.hashtagsMasUtilizados(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem()));
               
               //Inicializamos las etiquetas a "" (vacias)
               vEstadisticas.jLabelHashtagMasUtilizado1.setText("");
               vEstadisticas.jLabelHashtagMasUtilizado2.setText("");
               vEstadisticas.jLabelHashtagMasUtilizado3.setText("");
               vEstadisticas.jLabelHashtagMasUtilizado4.setText("");
               vEstadisticas.jLabelHashtagMasUtilizado5.setText("");
               
               if(hashtagsMasUtilizados.size()==1)
                   vEstadisticas.jLabelHashtagMasUtilizado1.setText(hashtagsMasUtilizados.get(0));
               
               if(hashtagsMasUtilizados.size()==2)
               {
                   vEstadisticas.jLabelHashtagMasUtilizado1.setText(hashtagsMasUtilizados.get(0));
                   vEstadisticas.jLabelHashtagMasUtilizado2.setText(hashtagsMasUtilizados.get(1));
               }
               
               if(hashtagsMasUtilizados.size()==3)
               {
                   vEstadisticas.jLabelHashtagMasUtilizado1.setText(hashtagsMasUtilizados.get(0));
                   vEstadisticas.jLabelHashtagMasUtilizado2.setText(hashtagsMasUtilizados.get(1));
                   vEstadisticas.jLabelHashtagMasUtilizado3.setText(hashtagsMasUtilizados.get(2));
               }
               
               if(hashtagsMasUtilizados.size()==4)
               {
                   vEstadisticas.jLabelHashtagMasUtilizado1.setText(hashtagsMasUtilizados.get(0));
                   vEstadisticas.jLabelHashtagMasUtilizado2.setText(hashtagsMasUtilizados.get(1));
                   vEstadisticas.jLabelHashtagMasUtilizado3.setText(hashtagsMasUtilizados.get(2));
                   vEstadisticas.jLabelHashtagMasUtilizado4.setText(hashtagsMasUtilizados.get(3));
               }
               
               if(hashtagsMasUtilizados.size()==5)
               {
                   vEstadisticas.jLabelHashtagMasUtilizado1.setText(hashtagsMasUtilizados.get(0));
                   vEstadisticas.jLabelHashtagMasUtilizado2.setText(hashtagsMasUtilizados.get(1));
                   vEstadisticas.jLabelHashtagMasUtilizado3.setText(hashtagsMasUtilizados.get(2));
                   vEstadisticas.jLabelHashtagMasUtilizado4.setText(hashtagsMasUtilizados.get(3));
                   vEstadisticas.jLabelHashtagMasUtilizado5.setText(hashtagsMasUtilizados.get(4));
               }

               
               vEstadisticas.jLabelNumeroIdiomasDiferentes.setText(String.valueOf(tweetDAO.numeroIdiomasDiferentes(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem()))));
               
               idiomasMasFrecuentes = tweetDAO.idiomasMasFrecuentes(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem()));
               
               //Inicializamos los valores de los idiomas mas frecuentes a "" (vacio)
               vEstadisticas.jLabelIdiomaMasUtilizado1.setText("");
               vEstadisticas.jLabelIdiomaMasUtilizado2.setText("");
               vEstadisticas.jLabelIdiomaMasUtilizado3.setText("");
               vEstadisticas.jLabelIdiomaMasUtilizado4.setText("");
               vEstadisticas.jLabelIdiomaMasUtilizado5.setText("");
               
               if(idiomasMasFrecuentes.size()==1)
                   vEstadisticas.jLabelIdiomaMasUtilizado1.setText(idiomasMasFrecuentes.get(0));

               if(idiomasMasFrecuentes.size()==2)
               {
                   vEstadisticas.jLabelIdiomaMasUtilizado1.setText(idiomasMasFrecuentes.get(0));
                   vEstadisticas.jLabelIdiomaMasUtilizado2.setText(idiomasMasFrecuentes.get(1));
               }
               
               if(idiomasMasFrecuentes.size()==3)
               {
                   vEstadisticas.jLabelIdiomaMasUtilizado1.setText(idiomasMasFrecuentes.get(0));
                   vEstadisticas.jLabelIdiomaMasUtilizado2.setText(idiomasMasFrecuentes.get(1));
                   vEstadisticas.jLabelIdiomaMasUtilizado3.setText(idiomasMasFrecuentes.get(2));
               }
               
               if(idiomasMasFrecuentes.size()==4)
               {
                   vEstadisticas.jLabelIdiomaMasUtilizado1.setText(idiomasMasFrecuentes.get(0));
                   vEstadisticas.jLabelIdiomaMasUtilizado2.setText(idiomasMasFrecuentes.get(1));
                   vEstadisticas.jLabelIdiomaMasUtilizado3.setText(idiomasMasFrecuentes.get(2));
                   vEstadisticas.jLabelIdiomaMasUtilizado4.setText(idiomasMasFrecuentes.get(3));
               }
               
               if(idiomasMasFrecuentes.size()==5)
               {
                   vEstadisticas.jLabelIdiomaMasUtilizado1.setText(idiomasMasFrecuentes.get(0));
                   vEstadisticas.jLabelIdiomaMasUtilizado2.setText(idiomasMasFrecuentes.get(1));
                   vEstadisticas.jLabelIdiomaMasUtilizado3.setText(idiomasMasFrecuentes.get(2));
                   vEstadisticas.jLabelIdiomaMasUtilizado4.setText(idiomasMasFrecuentes.get(3));
                   vEstadisticas.jLabelIdiomaMasUtilizado5.setText(idiomasMasFrecuentes.get(4));
               }
               
               vEstadisticas.jLabelNumeroRTs.setText(String.valueOf(tweetDAO.numeroDeRT(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem()))) + " RTs");
               
               vEstadisticas.jLabelNUsuariosDiferentes.setText(String.valueOf(tweetDAO.numeroDeUsuariosDiferentes(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem()))) + " usuarios");
               
               usuariosConMasTweets = tweetDAO.usuariosFrecuenciaTweets(String.valueOf(vEstadisticas.jComboBoxColecciones.getSelectedItem()));
               
               //Inicializamos las etiquetas de los usuarios con mas tweets a "" (vacio)
               vEstadisticas.jLabelUsuarioConMasTweets1.setText("");
               vEstadisticas.jLabelUsuarioConMasTweets2.setText("");
               vEstadisticas.jLabelUsuarioConMasTweets3.setText("");
               vEstadisticas.jLabelUsuarioConMasTweets4.setText("");
               vEstadisticas.jLabelUsuarioConMasTweets5.setText("");
               
               if(usuariosConMasTweets.size()==1)
                   vEstadisticas.jLabelUsuarioConMasTweets1.setText(usuariosConMasTweets.get(0));
               
               if(usuariosConMasTweets.size()==2)
               {
                   vEstadisticas.jLabelUsuarioConMasTweets1.setText(usuariosConMasTweets.get(0));
                   vEstadisticas.jLabelUsuarioConMasTweets2.setText(usuariosConMasTweets.get(1));
               
               }
               
               if(usuariosConMasTweets.size()==3)
               {
                   vEstadisticas.jLabelUsuarioConMasTweets1.setText(usuariosConMasTweets.get(0));
                   vEstadisticas.jLabelUsuarioConMasTweets2.setText(usuariosConMasTweets.get(1));
                   vEstadisticas.jLabelUsuarioConMasTweets3.setText(usuariosConMasTweets.get(2));
               
               }
               
               if(usuariosConMasTweets.size()==4)
               {
                   vEstadisticas.jLabelUsuarioConMasTweets1.setText(usuariosConMasTweets.get(0));
                   vEstadisticas.jLabelUsuarioConMasTweets2.setText(usuariosConMasTweets.get(1));
                   vEstadisticas.jLabelUsuarioConMasTweets3.setText(usuariosConMasTweets.get(2));
                   vEstadisticas.jLabelUsuarioConMasTweets4.setText(usuariosConMasTweets.get(3));
               }
               
               if(usuariosConMasTweets.size()==5)
               {
                   vEstadisticas.jLabelUsuarioConMasTweets1.setText(usuariosConMasTweets.get(0));
                   vEstadisticas.jLabelUsuarioConMasTweets2.setText(usuariosConMasTweets.get(1));
                   vEstadisticas.jLabelUsuarioConMasTweets3.setText(usuariosConMasTweets.get(2));
                   vEstadisticas.jLabelUsuarioConMasTweets4.setText(usuariosConMasTweets.get(3));
                   vEstadisticas.jLabelUsuarioConMasTweets5.setText(usuariosConMasTweets.get(4));
               }
               break;
               
            case "Consultas":
               vConsultas.setVisible(true);
               vEstadisticas.setVisible(false);
               vistas.dibujarTablaTweets(vConsultas);
               vConsultas.jSpinnerNumMaxSeguidores.setValue(tweetDAO.usuarioConMasSeguidores("tweets").getFollowers());
               vConsultas.jSpinnerNumMinSeguidores.setValue(tweetDAO.usuarioConMenosSeguidores("tweets").getFollowers());
               vConsultas.jListIdiomas.removeAll();
               vConsultas.jListIdiomas.setListData(tweetDAO.listadoIdiomas("tweets").toArray(new String[0]));
               vConsultas.jListIdiomas.removeAll();
               List<String> listaIdiomas = vConsultas.jListIdiomas.getSelectedValuesList();
               vConsultas.jLabelNumeroTweets.setText(String.valueOf(tweetDAO.numTweets("tweets")) + " tweets");
               
               vConsultas.jComboBoxColecciones.removeAllItems();
               
               nColecciones = tweetDAO.nombreColecciones();
               
               //Rellenamos el ComboBox
               for(String nColeccion:nColecciones)
               {
                   vConsultas.jComboBoxColecciones.addItem(nColeccion);
               }
               
               try {
                   muestraTweets("tweets", 0, tweetDAO.usuarioConMasSeguidores("tweets").getFollowers(), "", "", "", listaIdiomas, false, "");
               } catch (Exception ex) {
                   Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
               }
           
               break;
               
           case "Consultar":
               
               vConsultas.jLabelNumeroTweets.setText(String.valueOf(tweetDAO.numTweets(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem()))));
               
           
               try {
                   vConsultas.jLabelNumeroTweets.setText(String.valueOf(muestraTweets(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem()), 
                                Integer.parseInt(vConsultas.jSpinnerNumMinSeguidores.getValue().toString()), 
                                Integer.parseInt(vConsultas.jSpinnerNumMaxSeguidores.getValue().toString()), 
                                vConsultas.jTextFieldNombreUsuario.getText(),
                                vConsultas.jTextFieldHashtag.getText(), 
                                vConsultas.jTextFieldPalabra.getText(),
                                vConsultas.jListIdiomas.getSelectedValuesList(),
                                false,
                                "").size()));
               } catch (Exception ex) {
                   Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
               }
           
               break;
               
           case "CambiarColeccionConsultas":
               vConsultas.jListIdiomas.removeAll();
               vConsultas.jListIdiomas.setListData(tweetDAO.listadoIdiomas(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem())).toArray(new String[0]));
               vConsultas.jLabelNumeroTweets.setText(String.valueOf(tweetDAO.numTweets(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem()))));
               vConsultas.jSpinnerNumMinSeguidores.setValue(tweetDAO.usuarioConMenosSeguidores(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem())).getFollowers());
               vConsultas.jSpinnerNumMaxSeguidores.setValue(tweetDAO.usuarioConMasSeguidores(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem())).getFollowers());
               
               try {
                   muestraTweets(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem()),
                                 0, 
                                 tweetDAO.usuarioConMasSeguidores("tweets").getFollowers(),
                                 "", 
                                 "",
                                 "",
                                 tweetDAO.listadoIdiomas(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem())),
                                 false,
                                 "");
               } catch (Exception ex) {
                   Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
               }
               break;
               
           case "VolcarAColeccion":
               try {
                   muestraTweets(String.valueOf(vConsultas.jComboBoxColecciones.getSelectedItem()), 
                                Integer.parseInt(vConsultas.jSpinnerNumMinSeguidores.getValue().toString()), 
                                Integer.parseInt(vConsultas.jSpinnerNumMaxSeguidores.getValue().toString()), 
                                vConsultas.jTextFieldNombreUsuario.getText(),
                                vConsultas.jTextFieldHashtag.getText(), 
                                vConsultas.jTextFieldPalabra.getText(),
                                vConsultas.jListIdiomas.getSelectedValuesList(),
                                true,
                                vConsultas.jTextFieldVolcarAColeccion.getText());
               } catch (Exception ex) {
                   Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
               }
               break;

       }
    }
    
   private ArrayList<Tweet> muestraTweets(String coleccion, int nMinSeguidores, int nMaxSeguidores, String usuario, String hashtag, String palabra, List<String> idiomas, boolean volcar, String nombreNuevaColeccion) throws Exception
    {
        ArrayList<Tweet> lTweets = tweetDAO.listaTweets(coleccion, nMinSeguidores, nMaxSeguidores, usuario, hashtag, palabra, idiomas, volcar, nombreNuevaColeccion);
        vistas.vaciarTablaConsultas();
        vistas.rellenarTablaConsulta(lTweets);
        
        return lTweets;
    }
}
