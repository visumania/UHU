/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.rmi.*;
import java.util.Scanner;

/**
 *
 * @author adrianmorenomonterde
 */
public class RMI_Multas_Servidor 
{
    public static void main(String[] args)
    {
        try
        {
            MultasIntf multasStub = new MultasImpl();
            int Puerto = 0;
            Scanner Teclado = new Scanner(System.in); 
            
            System.out.println("Introduce el numero de puerto para comunicarse: ");
            Puerto = Teclado.nextInt();
            
            Naming.rebind("rmi://localhost:" + Puerto + "/Multas", multasStub);
            
            System.out.println("Servidor Multas esperando peticiones ...");
        }catch(Exception e)
        {
            System.out.println("Error en servidor Multas:" + e);
        }
    }
}
