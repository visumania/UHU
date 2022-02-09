/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.rmi.Naming;
import java.rmi.RMISecurityManager;
import java.util.Random; 
import java.util.Scanner;

/**
 *
 * @author adrianmorenomonterde
 */
public class RMI_Multas_Cliente 
{
    public static void main(String[] args)
    {
        try
        {
             int Puerto = 0; 
             String Host; 
             Scanner Teclado = new Scanner(System.in);

             System.out.println("Introduce el numero de puerto para comunicarse: "); 
             Puerto = Teclado.nextInt();

             System.out.println("Introduce el nombre del host: ");
             Host = Teclado.next();

             //Random rnd = new Random(System.nanoTime());
             MultasIntf multasStub = (MultasIntf) Naming.lookup("rmi://" + Host + ":" + Puerto + "/Multas");
             int opcionMC;
             int opcionMG;
             String iden, mat,fech;
             int pts , dni , dniNv;
             
             do
             {
                 System.out.println("\n\nMenú Consultas");
                 System.out.println("**************************\n");
                 System.out.println("1.- Identificacion");
                 System.out.println("2.- Consultar Puntos"); 
                 System.out.println("3.- Consultar Multas"); 
                 System.out.println("4.- Salir\n");
                 System.out.println("Elige opcion: ");
                 opcionMC = Teclado.nextInt();
                 
                 switch(opcionMC)
                 {
                     case 1: 
                     {
                         System.out.println("\nIntroduzca contraseña de identificacion: ");
                         iden = Teclado.next();
                         
                         if(multasStub.Identificacion(iden) == 1)
                         {
                             do
                            {
                                System.out.println("\n\nMenu Gestion");
                                System.out.println("*************************\n");
                                System.out.println("1.- Poner Multa");
                                System.out.println("2.- Quitar Multa");
                                System.out.println("3.- Alta de un Vehiculo");
                                System.out.println("4.- Baja de un Vehiculo"); 
                                System.out.println("5.- Cambiar de Titularidad un vehiculo");
                                System.out.println("6.- Salir\n");
                                System.out.println("Elige una opcion: ");
                                opcionMG = Teclado.nextInt();

                                switch(opcionMG)
                                {
                                    case 1:
                                    {
                                        System.out.println("\nIntroduzca matricula del coche a multar(1111AAA): ");
                                        mat = Teclado.next();
                                        
                                        System.out.println("Introduzca fecha de la multa(dd/mm/aaaa)");
                                        fech = Teclado.next();
                                        
                                        System.out.println("Introduzca la cantidad puntos perdidos: ");
                                        pts = Teclado.nextInt();
                                        
                                        if(multasStub.PonerMulta(mat, fech, pts) == 1)
                                            System.out.println("Multa puesta correctamente");
                                        else
                                            System.out.println(("Error: no se ha podido poner la multa"));
                                    }
                                    break;

                                    case 2:
                                    {
                                        System.out.println("\nIntroduzca matricula del coche a quitar la multar(1111AAA): ");
                                        mat = Teclado.next();
                                        
                                        System.out.println("Introduzca fecha de la multa(dd/mm/aaaa)");
                                        fech = Teclado.next();
                                        
                                        if(multasStub.QuitarMulta(mat, fech) == 1)
                                            System.out.println("Multa quitada correctamente");
                                        else
                                            System.out.println("Error: no se ha podido quitar la multa");
                                    }
                                    break;

                                    case 3:
                                    {
                                        System.out.println("\nIntroduzca DNI (Solo numeros): ");
                                        dni = Teclado.nextInt();
                                        
                                        System.out.println("Introduzca matricula del coche a registrar(1111AAA): ");
                                        mat = Teclado.next();
                                        
                                        if(multasStub.AltaVehiculo(dni, mat) == 1)
                                            System.out.println("Vehiculo dado de alta correctamente");
                                        else
                                            System.out.println("Error: el vehiculo ya se encuentra registrado en el servidor");
                                    }
                                    break;

                                    case 4:
                                    {
                                        System.out.println("\nIntroduzca DNI (Solo numeros): ");
                                        dni = Teclado.nextInt();
                                        
                                        System.out.println("Introduzca matricula del coche a registrar(1111AAA): ");
                                        mat = Teclado.next();
                                        
                                        if(multasStub.BajaVehiculo(dni, mat) == 1)
                                            System.out.println("Vehiculo dado de baja correctamente");
                                        else
                                            System.out.println("Error: el vehiculo no se ha podido dar de baja porque no existe en el servidor o tiene multas");
                                    }
                                    break;
                                    
                                    case 5:
                                    {
                                        System.out.println("\nIntroduzca el DNI del actual Titular (solo numeros): ");
                                        dni = Teclado.nextInt();
                                        
                                        System.out.println("Introduzca matricula del coche a realizar el camio (1111AAA): ");
                                        mat = Teclado.next();
                                        
                                        System.out.println("Introduzca el DNI del nuevo titular (solo numeros): ");
                                        dniNv = Teclado.nextInt();
                                        
                                        if(multasStub.CambioTitularidad(dni, mat, dniNv))
                                            System.out.println("El cambio de titularidad se ha hecho correctamente");
                                        else
                                            System.out.println("Error: el cambio de titularidad no se ha podido efectuar con exito");
                                    }
                                    break; 

                                    case 6: System.out.println("\nSaliendo del menú de gestion. Volviendo al menú de consultas...");
                                    break;

                                    default: System.out.println("Opcion incorrecta");
                                }

                            }while(opcionMG != 6);
                         }
                         else
                             System.out.println("\nPassword de agente incorrecto");
                     }
                     break;
                     
                     case 2:
                     {
                         System.out.println("\nIntroduzca DNI de la persona a consultar (Solo numeros): ");
                         dni = Teclado.nextInt();
                                        
                         System.out.println("Introduzca matricula del coche(1111AAA): ");
                         mat = Teclado.next();
                         
                         pts = multasStub.ComprobarPuntos(dni, mat);
                         
                         if(pts != -1)
                             System.out.println("\nEl usuario con Dni: " + dni + " y matricula " + mat + " tiene " + pts + " puntos");
                         else
                             System.out.println("\nError: no se ha encontrado al usuario");
                     }
                     break;
                     
                     case 3: 
                     {                      
                         System.out.println("\nIntroduzca DNI de la persona a consultar (Solo numeros): ");
                         dni = Teclado.nextInt();
                                        
                         System.out.println("Introduzca matricula del coche(1111AAA): ");
                         mat = Teclado.next();

			 //multasStub.ComprobarMultas(dni,mat); LO DEJO COMENTADO PORQUE SI LO EJECUTO SE LANZA UNA EXCEPCION
                         
                         //System.out.println("\nLa persona con dni " + dni + " tiene un total de " + multasStub.ComprobarMultas(dni, mat).size() + " multas");
                          
                         /*if(!(multasStub.ComprobarMultas(dni, mat).isEmpty()))
                         {
                             for(int i=0 ; i<multasStub.ComprobarMultas(dni, mat).size() ; i++)
                                multasStub.ComprobarMultas(dni, mat).get(i).toString();
                         }  */                      
                     }
                     break;
                     
                     case 4: System.out.println("\nSaliendo del programa ...");
                     break;
                     
                     default: System.out.println("\nOpcion incorrecta...");
                 }
                 
                 
             }while(opcionMC != 4);
             
             
        } catch(Exception e)
        {
            System.out.println("Error: " + e);
        }
    }
}


