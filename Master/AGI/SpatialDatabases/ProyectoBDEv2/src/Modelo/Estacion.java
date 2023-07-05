package Modelo;

public class Estacion {

    String provincia;
    String nombre;
    double latitud;
    double longitud;

    public Estacion() {
        this.provincia = null;
        this.nombre = null;
        this.latitud = 0f;
        this.longitud = 0f;
    }

    public Estacion(String provincia, String ciudad, float latitud, float longitud) {
        this.provincia = provincia;
        this.nombre = ciudad;
        this.latitud = latitud;
        this.longitud = longitud;
    }

    public String getProvincia() {
        return provincia;
    }

    public void setProvincia(String provincia) {
        this.provincia = provincia;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double getLatitud() {
        return latitud;
    }

    public void setLatitud(double latitud) {
        this.latitud = latitud;
    }

    public double getLongitud() {
        return longitud;
    }

    public void setLongitud(double longitud) {
        this.longitud = longitud;
    }
}
