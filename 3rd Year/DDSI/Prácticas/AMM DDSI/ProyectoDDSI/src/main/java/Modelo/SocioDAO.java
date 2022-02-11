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
public class SocioDAO {

    Conexion conexion = null;
    PreparedStatement ps = null;
    Session sesion = null;
    VistaMensajes vMensajes = null;

    public SocioDAO(Session sesion) {
        this.sesion = sesion;
        this.vMensajes = new VistaMensajes();
    }

    public ArrayList<Socio> listaSocios() throws Exception {
        Transaction transaction = sesion.beginTransaction();

        Query consulta = sesion.createQuery("FROM Socio S ORDER BY NUMEROSOCIO ASC");
        ArrayList<Socio> socios = (ArrayList<Socio>) consulta.list();

        transaction.commit();
        return socios;
    }

    public ArrayList<Socio> listaSociosCategoria(String letra) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        letra = letra + "%";
        Query consulta = sesion.createNativeQuery("SELECT * FROM SOCIO S WHERE categoria LIKE :letra", Socio.class).setParameter("letra", letra);
        ArrayList<Socio> socios = (ArrayList<Socio>) consulta.list();

        transaction.commit();
        return socios;
    }

    public void insertarSocio(Socio soc) throws Exception {
        Transaction transaction = sesion.beginTransaction();

        try {
            sesion.save(soc);
            transaction.commit();
        } catch (Exception ex) {
            transaction.rollback();
            vMensajes.mensaje("Error en la inserción del socio con código " + soc.getNumerosocio() + "\n" + ex.getMessage(), 0);
        }
    }

    public void actualizarSocio(String cod, Socio soc) throws Exception {
        Transaction transaction = sesion.beginTransaction();

        try {
            Socio socio = sesion.get(Socio.class, cod);

            socio.setNombre(soc.getNombre());
            socio.setDni(soc.getDni());
            socio.setFechanacimiento(soc.getFechanacimiento());
            socio.setTelefono(soc.getTelefono());
            socio.setCorreo(soc.getCorreo());
            socio.setFechaentrada(soc.getFechaentrada());
            socio.setCategoria(soc.getCategoria());

            sesion.update(socio);

            transaction.commit();
        } catch (Exception ex) {
            transaction.rollback();
            vMensajes.mensaje("Error en la actualización del socio con código " + cod + "\n" + ex.getMessage(), 0);
        }
    }

    public void eliminarSocio(String cod) throws Exception {
        Transaction transaction = sesion.beginTransaction();

        try {
            Socio socio = sesion.get(Socio.class, cod);
            sesion.delete(socio);
            transaction.commit();
        } catch (Exception ex) {
            transaction.rollback();
            vMensajes.mensaje("Error en la eliminación del socio con código " + cod + "\n" + ex.getMessage(), 0);
        }
    }
}
