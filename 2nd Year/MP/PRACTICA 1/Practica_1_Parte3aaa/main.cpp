#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <iomanip> // std:: setprecision
#include "Fecha.h" // definici�n de la clase Fecha
#include "Cliente.h" // definici�n de la clase Cliente
#include "Contrato.h" // definici�n de la clase Contrato
#include "ContratoTP.h" //definici�n de la clase ContratoTP
#include "ContratoMovil.h" //definici�n de la clase ContratoMovil
#include "Empresa.h" //definicion de la clase Empresa

using namespace std;

int main(int argc , char *argv[])
{
    //MAIN DE LA PARTE 1:

   /* Fecha f1(29,2,2001) , f3(29,2,2004) , f4(29,2,1900);
      const Fecha f2=f1; //Aqui se esta utilizando el operator= de fecha

      f1.setFecha(f3.getDia()-3 , f3.getMes()-2 , 2007);

      cout << "Fechas: "; f1.ver(); cout << ", "; f2.ver(); cout << ", ";
                          f3.ver(); cout << ", "; f4.ver(); cout << endl;

      if(f3.bisiesto() && !f2.bisiesto() && f4.bisiesto()==false)
        cout << f3.getAnio() << " es bisiesto, " << f2.getAnio() << " y " << f4.getAnio() << " no\n";

      f4.setFecha(31,12,2000);
      f3=f4++; //Aqui se est� ejecutando la sobrecarga del operador++ de fecha
      ++f4;
      f1=2+f2+3;

      cout << "Fechas: "; f1.ver(); cout << ", "; f2.ver(); cout << ", ";
                          f3.ver(); cout << ", "; f4.ver(); cout << endl;

      Cliente *p = new Cliente(75547001 , "Susana Diaz" , f1);
      f1.setFecha(7,10,2015);
      Cliente c(75547999 , "Juan Sin Miedo" , Fecha(29,2,2000));
      const Cliente j(44228547 , "Luis" , f1);
      c.setNombre("Juan Palomo");

      if(j==c)
        cout << "\nj y c son iguales\n";
      else
        cout << "\nj y c no son iguales\n";

      cout << p->getDni() << " - " << c.getNombre() << ": " << j.getFecha() << endl;
      cout << *p << "\n" << c << "\n" << j << "\n";
      c = *p;
      p->setNombre("Susanita"); p->setFecha(p->getFecha()+10);

      cout << "\nDatos de los clientes: \n";
      cout << *p << "\n" << c << "\n" << j << "\n";

      delete p;
      p = NULL;

      system("PAUSE");

      return 0;*/

    //MAIN DE LA PARTE 2:

    /*Fecha f1(29,2,2001) , f2(f1), f3(29,2,2004);
    cout << "Fechas: ";
    f1.ver(); cout << ", "; f2.ver(); cout << ", "; f3.ver(); cout << endl;

    Contrato *p = new Contrato(75547111,f1) , c(23000111 , Fecha(2,2,2002));
    cout << ContratoTP::getLimiteMinutos() << " - " <<ContratoTP::getPrecio() << endl << endl;
    ContratoTP ct1(17333256,f1,250); //habla 250 minutos
    ContratoTP ct2(12555100,f3,320);//habla 320 minutos
    ContratoTP ct3(ct1);
    ContratoMovil cm1(17333256,f1,0.12,100,"ESPA�OL"); //habla 100 minutos
    ContratoMovil cm2(17000000,Fecha(3,3,2003),0.10,180,"FRANCES"); //habla 180 minutos
    ContratoMovil cm3(cm2);

    p->ver(); cout << "\n"; c.ver(); cout << endl;
    ct1.ver(); cout << endl; ct2.ver(); cout << "\n"; ct3.ver(); cout << "\n\n";
    cm1.ver(); cout << endl; cm2.ver(); cout << "\n"; cm3.ver(); cout << "\n\n";

    cout << p->getIdContrato() << ct2.getIdContrato() << cm2.getIdContrato() << endl;
    cout << setprecision(2) << fixed;
    cout << "Facturas: " << ct1.factura() << "-" << ct2.factura() << "-" << cm1.factura() << endl << endl;

    ContratoTP::setTarifaPlana(350,12); //350 minutos por 12 euros
    p->setDniContrato(cm1.getDniContrato());
    ct3.setFechaContrato(p->getFechaContrato()+1);
    cm3.setNacionalidad(cm1.getNacionalidad());
    cm2.setPrecioMinuto(cm1.getPrecioMinuto()+0.02);
    cm1.setMinutosHablados(ct2.getMinutosHablados()/2);
    ct1.setMinutosHablados(cm3.getMinutosHablados()*2);

    cout << *p << "\n" << c << endl;
    cout << ct1 << endl << ct2 << "\n" << ct3 << "\n\n" << cm1 << "\n" << cm2 << endl << cm3 << endl;

    Contrato *t[4];
    t[0]=p; t[1]=&c; t[2]=&ct2; t[3]=&cm1;

    cout << "\n-- Datos de los contratos: --  \n";

    t[3]->setDniContrato(75547111);

    for(int i=0 ; i<4 ; i++)
    {
        t[i]->setFechaContrato(t[i]->getFechaContrato()+2);
        t[i]->ver(); cout << endl;
    }

    system("PAUSE");
    return 0;*/


    //MAIN DE LA PARTE 3:

    bool ok;
    Empresa Yoigo;

    cout << setprecision(2) << fixed; //Con esto haremos que los float se muestren con 2 decimales
    cout << endl; cout << "APLICACION DE GESTION TELEFONICA\n" << endl;
    Yoigo.cargarDatos(); //Crea 3 clientes y 7 contratos al ejecutarse el cargarDatos de manera que no tenga que meter datos cada vez que pruebo el programa
    Yoigo.ver();
    cout << "Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n\n";

    Yoigo.crearContrato(); // ContratoMovil a 37000017 el 01/01/2017 con 100m a 0.25
    Yoigo.crearContrato(); // ContratoTP a 22330014 (pepe luis) el 2/2/2017 con 305m

    ok = Yoigo.cancelarContrato(28); // este contrato no existe
    if(ok)
        cout << "Contrato 28 cancelado\n";
    else
        cout << "El Contrato 28 no existe\n";

    ok = Yoigo.cancelarContrato(4); // estre contrato si existe
    if(ok)
        cout << "El Contrato 4 ha sido cancelado\n";
    else
        cout << "El Contrato 4 no existe\n";

    ok = Yoigo.bajaCliente(75547001); //debe eliminar al cliente y sus 3 contratos
    if(ok)
        cout << "El cliente 75547001 y sus Contratos han sido cancelados\n";
    else
        cout << "El cliente 75547001 no existe\n";

    Yoigo.ver();

    Yoigo.descuento(20);
    cout << "\nTras rebajar un 20% la tarifa de los ContratosMovil...";
    Yoigo.ver();
    cout << "Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n";

    system("PAUSE");

    return 0;
}
