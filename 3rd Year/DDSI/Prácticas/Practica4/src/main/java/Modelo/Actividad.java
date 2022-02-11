package Modelo;

/**
 *
 * @author adrianmorenomonterde
 */

public class Actividad 
{
    private String idActividad;
    private String nombre;
    private String descripcion;
    private float precioBaseMes;
    private String monitorResponsable;

    public Actividad(String idActividad, String nombre, String descripcion, float precioBaseMes, String monitorResponsable) 
    {
        this.idActividad = idActividad;
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.precioBaseMes = precioBaseMes;
        this.monitorResponsable = monitorResponsable;
    }

    public String getIdActividad() 
    {
        return idActividad;
    }

    public void setIdActividad(String idActividad) 
    {
        this.idActividad = idActividad;
    }

    public String getNombre() 
    {
        return nombre;
    }

    public void setNombre(String nombre) 
    {
        this.nombre = nombre;
    }

    public String getDescripcion() 
    {
        return descripcion;
    }

    public void setDescripcion(String descripcion) 
    {
        this.descripcion = descripcion;
    }

    public float getPrecioBaseMes() 
    {
        return precioBaseMes;
    }

    public void setPrecioBaseMes(float precioBaseMes) 
    {
        this.precioBaseMes = precioBaseMes;
    }

    public String getMonitorResponsable() 
    {
        return monitorResponsable;
    }

    public void setMonitorResponsable(String monitorResponsable) 
    {
        this.monitorResponsable = monitorResponsable;
    }
}
