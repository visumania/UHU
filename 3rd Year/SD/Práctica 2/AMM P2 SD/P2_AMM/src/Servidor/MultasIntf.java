/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adrianmorenomonterde
 */
import java.rmi.*;
import java.util.LinkedList;

public interface MultasIntf extends Remote
{
    int ComprobarPuntos(int Dni, String Matricula) throws RemoteException; 
    //Dado los datos de un usuario (Dni y Matricula) la función comprobará que el vehículo está dado de alta y devolverá los puntos asociados al usuario. Si no 
    //se encuentra el usuario devolvera -1
    
    LinkedList ComprobarMultas(int Dni, String Matricula) throws RemoteException; 
    //Dado los datos de un usuario (Dni y Matricula) la función comprobará que el vehículo está dado de alta y devolverá los datos de las multas mediante una lista
    //de objetos que contienen los atributos Matricula, Fecha y Puntos perdidos
    
    int Identificacion(String password) throws RemoteException; 
    //Dado el password del agente la función comprobará si coincide con el 541293AGP. Si coincide devuelve 1 si no devuelve 0
    
    int PonerMulta(String Matricula, String Fecha, int Puntos) throws RemoteException; 
    //Dada la sanción(Matrícula, Fecha y Puntos perdidos) la almacenará en los datos del Servidor, siempre y cuando la matrícula exista. Devuelve 1 si se ha puesto
    //la multa y 0 en caso contrario
    
    int QuitarMulta(String Matricula, String Fecha) throws RemoteException; 
    //Dado una Matrícula y una Fecha, la función restaurará los puntos perdidos por la sanción al usuario del vehículo y eliminando la sanción de los datos del 
    //servidor. Devuelve 1 si se ha quitado la multa y 0 en caso contrario
    
    int AltaVehiculo(int Dni, String Matricula) throws RemoteException;
    //Dado los datos de un usuario (Dni y Matrícula) se da de alta al vehículo en los datos del servidor si previamente nos existía dicha matrícula. Si se ha dado
    //de alta se devolverá 1, en caso contario 0
    
    int BajaVehiculo(int Dni, String Matricula) throws RemoteException; 
    //Dado los datos de un usuario (Dni y Matrícula) se da de baja al vehículo en los datos del servidor si previamente existe y no tiene ninguna multa. Si se ha
    //dado de baja devolverá 1, en caso contrario
    
    boolean CambioTitularidad(int DniActual, String Matricula, int NuevoDni) throws RemoteException;
    //Devuelve true si al menos se ha modificado la titularidad de un vehiculo y false en caso contrario.
}
