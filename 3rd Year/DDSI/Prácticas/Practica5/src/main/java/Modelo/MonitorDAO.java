package Modelo;

import java.sql.PreparedStatement;
import java.util.ArrayList;
import org.hibernate.query.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author adrianmorenomonterde
 */
public class MonitorDAO {

    Conexion conexion = null;
    PreparedStatement ps = null;
    Session sesion = null;

    public MonitorDAO(Session sesion) {
        this.sesion = sesion;
    }

    public ArrayList<Monitor> listaMonitores() throws Exception //Ejemplo de función para recuperar toda la información de una tabla
    {
        Transaction transaction = sesion.beginTransaction();

        Query consulta = sesion.createQuery("FROM Monitor M ORDER BY CODMONITOR ASC");
        ArrayList<Monitor> monitores = (ArrayList<Monitor>) consulta.list();

        transaction.commit();
        return monitores;
    }

    public ArrayList<Monitor> existeMonitor(String cod) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT * FROM MONITOR M WHERE codmonitor LIKE :cod", Monitor.class).setParameter("cod", cod);
        ArrayList<Monitor> monitores = (ArrayList<Monitor>) consulta.list();

        transaction.commit();
        return monitores;
    }

    public ArrayList<Monitor> listaMonitorPorLetra(String letra) throws Exception //Ejemplo de función parametrizada para recuperar información --> Este método recupera los monitores cuyo nombre empiece por la letra que se pasa por parámetro
    {
        Transaction transaction = sesion.beginTransaction();
        letra = letra + "%";
        Query consulta = sesion.createNativeQuery("SELECT * FROM MONITOR M WHERE nombre LIKE :letra", Monitor.class).setParameter("letra", letra);
        ArrayList<Monitor> monitores = (ArrayList<Monitor>) consulta.list();

        transaction.commit();
        return monitores;
    }

    public void insertarMonitor(Monitor mon) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        sesion.save(mon);
        transaction.commit();
    }

    public void actualizarMonitor(Monitor mon) throws Exception //Dado un código (clave principal) de un monitor, se actualizará lo que haga falta de sus atributos
    {
        Transaction transaction = sesion.beginTransaction();

        Monitor monitor = sesion.get(Monitor.class, mon.getCodmonitor());

        monitor.setCorreo(mon.getCorreo());
        monitor.setDni(mon.getDni());
        monitor.setFechaentrada(mon.getFechaentrada());
        monitor.setNick(mon.getNick());
        monitor.setNombre(mon.getNombre());
        monitor.setTelefono(mon.getTelefono());

        sesion.update(monitor);

        transaction.commit();
    }

    public void eliminarMonitor(String codMonitor) throws Exception //Dado el código de un monitor (clave principal), se eliminará la tupla correspondiente a ese monitor
    {
        Transaction transaction = sesion.beginTransaction();
        Monitor monitor = sesion.get(Monitor.class, codMonitor);
        sesion.delete(monitor);
        transaction.commit();
    }
}
