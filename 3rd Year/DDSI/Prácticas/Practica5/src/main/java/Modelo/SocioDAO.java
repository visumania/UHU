package Modelo;

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

    public SocioDAO(Session sesion) {
        this.sesion = sesion;
    }

    public ArrayList<Socio> listaSocios() throws Exception {
        Transaction transaction = sesion.beginTransaction();

        Query consulta = sesion.createQuery("FROM Socio S ORDER BY NUMEROSOCIO ASC");
        ArrayList<Socio> socios = (ArrayList<Socio>) consulta.list();

        transaction.commit();
        return socios;
    }

    public void insertarSocio(Socio soc) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        sesion.save(soc);
        transaction.commit();
    }

    public void actualizarSocio(String cod, Socio soc) throws Exception {
        Transaction transaction = sesion.beginTransaction();

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
    }

    public void eliminarSocio(String cod) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        Socio socio = sesion.get(Socio.class, cod);
        sesion.delete(socio);
        transaction.commit();
    }
}
