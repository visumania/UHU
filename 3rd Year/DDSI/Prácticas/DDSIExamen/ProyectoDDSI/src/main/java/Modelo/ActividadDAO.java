package Modelo;

import Vista.VistaMensajes;
import java.sql.PreparedStatement;
import java.util.ArrayList;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

/**
 *
 * @author adrianmorenomonterde
 */
public class ActividadDAO {

    Conexion conexion = null;
    PreparedStatement ps = null;
    Session sesion = null;
    VistaMensajes vMensajes = new VistaMensajes();

    public ActividadDAO(Session sesion) {
        this.sesion = sesion;
    }

    public ArrayList<Object[]> verInfoSocioActividad(String idActividad) {
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT NOMBRE, CORREO FROM SOCIO INNER JOIN REALIZA USING(NUMEROSOCIO) WHERE IDACTIVIDAD = :idActividad").setParameter("idActividad", idActividad);
        ArrayList<Object[]> socioActividad = (ArrayList<Object[]>) consulta.list();

        transaction.commit();
        return socioActividad;
    }

    public ArrayList<Actividad> existeMonitorActividad(String letra) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT * FROM ACTIVIDAD A WHERE MONITORRESPONSABLE = :letra", Actividad.class).setParameter("letra", letra);
        ArrayList<Actividad> actividades = (ArrayList<Actividad>) consulta.list();

        transaction.commit();
        return actividades;
    }

    public void actualizaMonitorGenerico(Actividad act) throws Exception {
        Transaction transaction = sesion.beginTransaction();

        Actividad actividad = sesion.get(Actividad.class, act.getIdactividad());

        actividad.setMonitorresponsable(act.getMonitorresponsable());

        sesion.update(actividad);

        transaction.commit();
    }

    public ArrayList<String> getIdsActividad() throws Exception {
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT IDACTIVIDAD FROM ACTIVIDAD A ORDER BY IDACTIVIDAD ASC");
        ArrayList<String> listaIds = (ArrayList<String>) consulta.list();

        transaction.commit();
        return listaIds;
    }

    public ArrayList<String> getNombreActividades() throws Exception {
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT NOMBRE FROM ACTIVIDAD A ORDER BY IDACTIVIDAD ASC");
        ArrayList<String> listaNombres = (ArrayList<String>) consulta.list();

        transaction.commit();
        return listaNombres;
    }
    
    public ArrayList<Actividad> listaActividades() throws Exception {
        Transaction transaction = sesion.beginTransaction();
        
        Query consulta = sesion.createQuery("FROM Actividad A ORDER BY IDACTIVIDAD ASC");
        ArrayList<Actividad> actividades = (ArrayList<Actividad>) consulta.list();
        
        transaction.commit();
        return actividades;
    }
    
    public void actualizaPrecioActividades(Actividad act, int nuevoPrecio) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        
        try{
            Actividad actividad = sesion.get(Actividad.class, act.getIdactividad());
            
            actividad.setPreciobasemes(nuevoPrecio + actividad.getPreciobasemes());
            
            sesion.update(actividad);
            transaction.commit();
        } catch(Exception ex){
            transaction.rollback();
            vMensajes.mensaje("Error en la actualización del precio\n" + ex.getMessage(), 0);
        }
    }
}
