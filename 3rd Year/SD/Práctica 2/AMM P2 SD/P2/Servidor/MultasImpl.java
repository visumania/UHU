/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.LinkedList;
import java.util.Iterator;

/**
 *
 * @author adrianmorenomonterde
 */

public class MultasImpl extends UnicastRemoteObject implements MultasIntf
{
    private LinkedList<Persona> listaPersonas = new LinkedList<Persona>();
    
    public MultasImpl() throws RemoteException
    {
        super();
    }
    
    public int ComprobarPuntos(int Dni, String Matricula) throws RemoteException //Hecho
    {
        int puntos = -1; 
        int i=0;
        boolean encontradoPersona = false; 
        
        while(i<listaPersonas.size() && !encontradoPersona) //Busqueda por la lista enlazada de personas
        {
            if(listaPersonas.get(i).getDni() == Dni) //Si coinciden el dni de una persona con el que me pasan por parametro
            {
                encontradoPersona = true; 
                int j=0; 
                boolean encontradoVehiculo = false; 
                
                while(j<listaPersonas.get(i).getListaMatricula().size() && !encontradoVehiculo) //Busqueda por los diferentes vehiculos que puede tener esa persona
                {
                    if(listaPersonas.get(i).getMatriculaVehiculo(j).equals(Matricula))
                    {
                        encontradoVehiculo = true; 
                        puntos = listaPersonas.get(i).getPuntos();
                    }
                    else
                        j++;
                }
            }
            else
                i++;
        }
        
        System.out.println("SERVIDOR ha hecho: Comprobar Puntos--> " + puntos);
        
        return puntos;
    }
    
    public LinkedList ComprobarMultas(int Dni, String Matricula) throws RemoteException
    {
        LinkedList<Multa> mu = new LinkedList<Multa>();
        boolean encontradaMatricula = false; 
        boolean encontradoDni = false;
        int i=0;
        int j=0;
        
        while(i<listaPersonas.size() && !encontradoDni)
        {
            if(listaPersonas.get(i).getDni() == Dni)
            {
                encontradoDni=true; 
                
                while(j<listaPersonas.get(i).getListaMatricula().size() && !encontradaMatricula)
                {
                    if(listaPersonas.get(i).getListaMatricula().get(j).equals(Matricula))
                        encontradaMatricula = true; 
                    else
                        j++;
                }
            }
            else
                i++;
        }
        
        if(encontradoDni && encontradaMatricula)
        {
            for(int k=0 ; k<listaPersonas.get(i).getListaMultas().size() ; k++)
            {
               mu.add((Multa)listaPersonas.get(i).getListaMultas().get(k));
               
              // if((listaPersonas.get(i).getListaMultas().get(k)))
            }
            
            for(int k=0 ; k<mu.size() ; k++)
            {
                if(!(mu.get(k).getMatricula().equals(Matricula)))
                    mu.remove(k);
            }
            
           // if(mu.isEmpty())
               // System.out.println("Este vehiculo está dado de alta pero no tiene multas");
        }
        
        System.out.println("SERVIDOR ha hecho: Comprobar Multas(" + mu.size() + " elementos)");
        
        for(int k=0 ; k<mu.size() ; k++)
            System.out.println(mu.get(i));
        
        return mu;
    }
    
    public int Identificacion(String Password) throws RemoteException //Hecho 
    {
        int devuelve = 0; 
        
        if(Password.equals("541293AGP"))
            devuelve = 1; 
        
        System.out.println("SERVIDOR ha hecho: Identificacion(" + devuelve + ")");
        
        return devuelve; 
    }
    
    public int PonerMulta(String Matricula, String Fecha, int Puntos) throws RemoteException //Hecho
    {
        int devolver = 0; 
        int i=0;
        boolean encontradaMatricula = false; 
        
        while(i<listaPersonas.size() && !encontradaMatricula)
        {
            int j=0;
            
            while(j<listaPersonas.get(i).getListaMatricula().size() && !encontradaMatricula)
            {
                if(listaPersonas.get(i).getListaMatricula().get(j).equals(Matricula))
                    encontradaMatricula = true; 
                else
                    j++;
            }
            
            if(!encontradaMatricula)
                i++;
        }
        
        if(encontradaMatricula)
        {
            devolver = 1;
            Multa m = new Multa(Matricula,Fecha,Puntos);
            listaPersonas.get(i).getListaMultas().add(m);
            listaPersonas.get(i).setPuntos(listaPersonas.get(i).getPuntos()-Puntos);
        }
        
        System.out.println("SERVIDOR ha hecho: Poner Multa(" + devolver + ")");
        
        return devolver;
    }
    
    public int QuitarMulta(String Matricula, String Fecha) throws RemoteException //Hecho
    {
        int devolver = 0; 
        int i=0;
        int j=0;
        boolean encontradaMatriculayFecha=false;
        Multa m = new Multa(Matricula,Fecha,0);
        
        while(i<listaPersonas.size() && !encontradaMatriculayFecha)
        {
            j=0;
            
            while(j<listaPersonas.get(i).getListaMultas().size() && !encontradaMatriculayFecha)
            {
                if(listaPersonas.get(i).getListaMultas().get(j).equals(m))
                    encontradaMatriculayFecha = true; 
                else
                    j++;
            }
            
            if(!encontradaMatriculayFecha)
                i++;
        }
        
        if(encontradaMatriculayFecha)
        {
            devolver = 1; 
            m=(Multa)listaPersonas.get(i).getListaMultas().get(j);
            listaPersonas.get(i).setPuntos(listaPersonas.get(i).getPuntos()+m.getPuntosPerdidos());
            listaPersonas.get(i).getListaMultas().remove(j);  
        }
        
        System.out.println("SERVIDOR ha hecho: Quitar Multa(" + devolver +")");
        
        return devolver; 
    }
    
    public int AltaVehiculo(int Dni, String Matricula) throws RemoteException //Hecho
    {
        int devolver = 0;
        int i=0; 
        boolean encontradoPersona = false;
        boolean encontradaMatricula = false;
        
        while(i<listaPersonas.size() && !encontradoPersona) //Busqueda por la lista de personas
        {
            if(listaPersonas.get(i).getDni() == Dni) // En el caso de encontrar una personas con dni = al que nos pasan por parámetro
            {
                encontradoPersona = true;
                int j=0;
                 
                while(j<listaPersonas.get(i).getListaMatricula().size() && !encontradaMatricula)
                {
                    if(Matricula.equals(listaPersonas.get(i).getMatriculaVehiculo(j)))
                        encontradaMatricula = true;
                    else
                        j++;
                }
            }
            else
                i++;
        }
        
        if(!encontradoPersona && !encontradaMatricula)
        {
            Persona p = new Persona(Dni, Matricula);
            listaPersonas.add(p);
            devolver = 1;
        }
        
        if(encontradoPersona && !encontradaMatricula)
        {
            listaPersonas.get(i).getListaMatricula().add(Matricula);
            devolver = 1; 
        }
        
        System.out.println("SERVIDOR ha hecho: Alta Vehiculo(" + devolver + ")");
        
        return devolver;  
    }
    
    public int BajaVehiculo(int Dni, String Matricula) throws RemoteException //Hecho 
    {
        int devolver=0;
        int i=0; 
        boolean encontradaPersona = false;
        boolean encontradaMatricula = false; 
        
        while(i<listaPersonas.size() && !encontradaPersona) //Recorrido por la lista de personas
        {
            if(listaPersonas.get(i).getDni() == Dni) //Encuentra una persona con el mismo Dni que nos pasan por parametro
            {
                encontradaPersona = true;
                int j=0; 
                
                while(j<listaPersonas.get(i).getListaMatricula().size() && !encontradaMatricula)
                {
                    if(listaPersonas.get(i).getMatriculaVehiculo(j).equals(Matricula))
                    {
                        encontradaMatricula=true;
                        
                        if(listaPersonas.get(i).getListaMultas().isEmpty())
                        {
                            listaPersonas.get(i).getListaMatricula().remove(j);
                            devolver = 1; 
                        }
                    }
                    else
                        j++;
                }
            }
            else
                i++;
        }
        
        System.out.println("SERVIDOR ha hecho: Baja Vehiculo(" + devolver +")");
        
        return devolver; 
    }
    
    public boolean CambioTitularidad(int DniActual, String Matricula, int NuevoDni) throws RemoteException
    {
        boolean devolver = false; 
        boolean encontradaPersona = false; 
        boolean encontradaMatricula = false; 
        int i=0;
        int j=0;
        
        while(i<listaPersonas.size() && !encontradaPersona)
        {
            if(listaPersonas.get(i).getDni() == DniActual)
            {
                encontradaPersona = true; 
                
                while(j<listaPersonas.get(i).getListaMatricula().size() && !encontradaMatricula)
                {
                    if(Matricula.equals("*"))
                    {
                        while(!listaPersonas.get(i).getListaMatricula().isEmpty())
                        {
                            AltaVehiculo(NuevoDni,listaPersonas.get(i).getMatriculaVehiculo(j));
                            BajaVehiculo(DniActual,listaPersonas.get(i).getMatriculaVehiculo(j));
                            encontradaMatricula = true; 
                        }
                    }
                    else
                    {
                        if(listaPersonas.get(i).getMatriculaVehiculo(j).equals(Matricula))
                        {
                            AltaVehiculo(NuevoDni,listaPersonas.get(i).getMatriculaVehiculo(j));
                            BajaVehiculo(DniActual,listaPersonas.get(i).getMatriculaVehiculo(j));
                            encontradaMatricula = true; 
                        }
                    }
                    
                    if(!encontradaMatricula)
                        j++;
                }
            }
            else
                i++;
        }
        
        if(encontradaPersona && encontradaMatricula)
            devolver = true; 
        
        System.out.println("SERVIDOR ha hecho: Cambio Titularidad (" + devolver + ")");
        
        return devolver; 
    }
    
   /* public static void main(String[] args) throws RemoteException //Para comprobar el correcto funcionamiento de los metodos
    {
        MultasImpl administracion = new MultasImpl();
        
        administracion.AltaVehiculo(1, "1A");
        administracion.AltaVehiculo(1, "2A");
        administracion.AltaVehiculo(2, "3A");
        
        System.out.println(administracion.listaPersonas.get(0));
        System.out.println(administracion.listaPersonas.get(1));

       
        administracion.CambioTitularidad(1, "1A", 2);
        System.out.println(administracion.listaPersonas.get(0));
        System.out.println(administracion.listaPersonas.get(1));
        
        administracion.CambioTitularidad(1, "*", 2); 
        System.out.println(administracion.listaPersonas.get(0));
        System.out.println(administracion.listaPersonas.get(1));
    }*/
    
}

class Multa
{
    private String Matricula; 
    private String Fecha; 
    private int PuntosPerdidos;
    
    public Multa()
    {
        this.Matricula = "";
        this.Fecha = "";
        this.PuntosPerdidos = 0; 
    }
    
    public Multa(String m, String f, int p)
    {
        this.Matricula = m;
        this.Fecha = f;
        this.PuntosPerdidos = p;
    }
    
    public Multa(Multa m)
    {
        this.Matricula = m.Matricula;
        this.Fecha = m.Fecha;
        this.PuntosPerdidos = m.PuntosPerdidos;
    }
    
    public Multa getMulta()
    {
        return this;
    }
    
    public String getMatricula()
    {
        return Matricula;
    }
    
    public String getFecha()
    {
        return Fecha;
    }
    
    public int getPuntosPerdidos()
    {
        return PuntosPerdidos;
    }
    
    public void setMatricula(String m)
    {
        this.Matricula = m ; 
    }
    
    public void setFecha(String f)
    {
        this.Fecha = f;
    }
    
    public void setPuntosPerdidos(int p)
    {
        this.PuntosPerdidos = p;
    }
    
    public void setMulta(String m, String f, int p)
    {
        this.Matricula = m;
        this.Fecha = f;
        this.PuntosPerdidos = p;
    }
    
    public boolean equals(Object obj)
    {
        if(this == obj) return true; //Si apuntan al mismo sitio son iguales
		if(obj == null) return false; 
		
		if(getClass() != obj.getClass())
			return false; 
		
		Multa c = (Multa)obj; 
		
		return(Matricula.equals(c.Matricula) && Fecha.equals(c.Fecha));
    }
    
    public Object clone()
    {
        return new Multa(this);
    }
    
    public String toString()
    {
        String pantalla = "\nMatricula: " + this.Matricula + "\nFecha: " + this.Fecha + "\nPuntos Perdidos: " + this.PuntosPerdidos;
        
        return pantalla;
    }
}

class Persona
{
    private int Dni; //Atributos DNI
    private LinkedList<String> MatriculasVehiculos = new LinkedList<String>(); //Lista de los diferentes coches que puede tener una persona
    private int Puntos; //Puntos totales que tiene esa persona
    private LinkedList<Multa> Multas = new LinkedList<Multa>(); //Lista de las diferentes multas que puede tener una persona
    
    public Persona(int d, String m)
    {
        Dni = d; 
        Puntos = 12; //Cuando se crea una persona automaticamente se le asignan 12 puntos, despues conforme se le vayan poniendo multas , se actualiza esta variable
        MatriculasVehiculos.add(m);
    }
    
    public int getDni()
    {
        return this.Dni; 
    }
    
    public int getPuntos()
    {
        return this.Puntos;
    }
    
    public String getMatriculaVehiculo(int pos)
    {
        return MatriculasVehiculos.get(pos);
    }
    
    public LinkedList getListaMatricula()
    {
        return this.MatriculasVehiculos;
    }
    
    public LinkedList getListaMultas()
    {
        return this.Multas;
    }
    
    public void setDni(int d)
    {
        this.Dni = d; 
    }
    
    public void setPuntos(int p)
    {
        this.Puntos = p; 
    } 
    
    public String toString()
    {        
        String mostrar = "\nDni: " + this.Dni ;
        
        for(int i=0 ; i<MatriculasVehiculos.size() ; i++)
            mostrar += "\nVehiculo " + (i+1) + ": " + MatriculasVehiculos.get(i);
        
        return mostrar;
    }
}