package Modelo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.nio.charset.Charset;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.StringTokenizer;
import org.osgeo.proj4j.*;
import org.osgeo.proj4j.proj.Projection;

public class EstacionDAO {

    private Conexion conexion = null;

    public EstacionDAO(Conexion conexion) {
        this.conexion = conexion;
    }

    public ArrayList<Estacion> listaEstaciones() throws SQLException {
        ArrayList<Estacion> lEstaciones = new ArrayList<>();

        try {
            //BLOQUE DE EXTRACCIÓN DE LOS DATOS A PARTIR DEL ENLACE DEL .TXT DE INTERNET
            URL url = new URL("http://www.uhu.es/jluis.dominguez/AGI/estaciones.txt");
            InputStream inputStream = url.openStream();
            Charset charset = Charset.forName("ISO-8859-1"); // Especifica la codificación actual del archivo
            InputStreamReader inputStreamReader = new InputStreamReader(inputStream, charset);
            BufferedReader in = new BufferedReader(inputStreamReader);
            in.readLine(); //Lee la primera fila (se la salta), la cual corresponde a los nombres de las columnas
            String line;

            //Comprueba si existe la tabla en la BD, en caso afirmativo la borra (junto a todos sus valores)
            Statement stmt = conexion.getConexion().createStatement();
            String sql = "DO $$ BEGIN IF EXISTS (SELECT * FROM information_schema.tables WHERE table_name = 'estaciones') THEN DROP TABLE estaciones; END IF; END $$;";
            stmt.execute(sql);
            sql = "CREATE TABLE estaciones (id SERIAL PRIMARY KEY,Provincia VARCHAR(255),Nombre VARCHAR(255),Latitud double precision,Longitud double precision);";
            stmt.execute(sql);

            while ((line = in.readLine()) != null) {
                //Separa los valores de la línea por comas
                StringTokenizer st = new StringTokenizer(line, ",");
                Estacion estacion = new Estacion();

                if (st.countTokens() == 4) {
                    estacion.setProvincia(st.nextToken());
                    estacion.setNombre(st.nextToken());

                    //Conversión de UTM a coordenadas geográficas
                    CRSFactory factory = new CRSFactory();
                    Projection utmProjection = factory.createFromName("EPSG:32630").getProjection();
                    ProjCoordinate utmCoordinate = new ProjCoordinate(Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken()));
                    ProjCoordinate latLonCoordinate = new ProjCoordinate();
                    utmProjection.inverseProject(utmCoordinate, latLonCoordinate);
                    double lat = latLonCoordinate.y;
                    double lon = latLonCoordinate.x;

                    estacion.setLatitud(lat);
                    estacion.setLongitud(lon);

                    //Inserción de los valores en la BD 
                    sql = "INSERT INTO estaciones (Provincia, Nombre, Latitud, Longitud) VALUES ('" + estacion.getProvincia() + "', '" + estacion.getNombre() + "'," + estacion.getLatitud() + ", " + estacion.getLongitud() + ");";
                    stmt.execute(sql);
                }

                lEstaciones.add(estacion);
            }
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return lEstaciones;
    }

    public ArrayList<String> listadoProvincias() throws SQLException {
        ArrayList<String> provincias = new ArrayList<String>();
        Statement stmt = conexion.getConexion().createStatement();
        String sql = "SELECT provincia FROM estaciones GROUP BY provincia ORDER BY provincia;";
        ResultSet rs = stmt.executeQuery(sql);

        while (rs.next()) {
            provincias.add(rs.getString("provincia"));
        }

        return provincias;
    }

    public ArrayList<Estacion> filtradoProvincia(String provincia) throws SQLException {
        ArrayList<Estacion> estaciones = new ArrayList<Estacion>();
        Estacion estacion = null;
        Statement stmt = conexion.getConexion().createStatement();
        String sql = "SELECT * FROM estaciones";

        if (!provincia.equals("Todas las provincias")) {
            sql += " WHERE provincia='" + provincia + "';";
        }

        ResultSet rs = stmt.executeQuery(sql);

        while (rs.next()) {
            estacion = new Estacion();
            estacion.setProvincia(rs.getString("provincia"));
            estacion.setNombre(rs.getString("nombre"));
            estacion.setLatitud(rs.getDouble("latitud"));
            estacion.setLongitud(rs.getDouble("longitud"));

            estaciones.add(estacion);
        }

        return estaciones;
    }
}
