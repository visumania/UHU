#include <cstdlib>
#include <iostream>
#include "Fecha.h" //definicion de la clase Fecha
#include "Contrato.h" // definicion de la clase Contrato
#include "ContratoTP.h" // definicion de la clase ContratoTP
#include "ContratoMovil.h" // definicion de la clase ContratoMovil
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    Fecha f1(29,2,2001), f2(f1), f3(29,2,2004);
    cout << "Fechas:" << f1 << ", " << f2 << ", " << f3 << endl;

    //Contrato *p = new Contrato(75547111, f1), c(23000111, Fecha(2,2,2002));
    cout << ContratoTP::getLimiteMinutos() << " - " << ContratoTP::getPrecioTP() << endl; cout << endl; // ORIGINAL getPrecio()
    ContratoTP ct1(17333256, f1, 250); //habla 250 minutos
    ContratoTP ct2(12555100, f3, 320); //habla 320 minutos
    ContratoTP ct3(ct1);
    ContratoMovil cm1(17333256, f1, 0.12, 100, "ESPA�OL"); //habla 100 minutos
    ContratoMovil cm2(17000000, Fecha(3,3,2003), 0.10, 180, "FRANCES"); //habla 180 minutos
    ContratoMovil cm3(cm2);

    //p->ver(); cout << "\n"; c.ver(); cout << endl;
    ct1.ver(); cout << endl; ct2.ver(); cout << "\n"; ct3.ver(); cout << "\n"; cout << endl;
    cm1.ver(); cout << endl; cm2.ver(); cout << "\n"; cm3.ver(); cout << "\n"; cout << endl;
    //cout << fixed << setprecision(2) << p->getIdContrato() << ct2.getIdContrato() << cm2.getIdContrato() << endl;
    cout << "Facturas: " << ct1.factura() <<"-"<< ct2.factura() <<"-"<< cm1.factura() << endl; cout << endl;

    ContratoTP::setTarifaPlana(350, 12); //350 minutos por 12 euros
    //p->setDniContrato(cm1.getDniContrato());
    //ct3.setFechaContrato(p->getFechaContrato()++);
    cm3.setNacionalidad(cm1.getNacionalidad());
    cm2.setPrecioMinuto(cm1.getPrecioMinuto()+0.02); // +2 C�NTIMOS
    cm1.setMinutosHablados(ct2.getMinutosHablados()/2);
    ct1.setMinutosHablados(cm3.getMinutosHablados()*2);

    //cout << *p <<"\n"<< c << endl;
    cout << ct1 << endl << ct2 <<"\n"<< ct3 <<"\n\n"<< cm1 <<"\n"<< cm2 <<endl<< cm3 << endl;

    Contrato *t[4];
    //t[0]=p;
    //t[1]=&c;
    t[2]=&ct2; t[3]=&cm1;

    cout << "\n-- Datos de los contratos: -- \n";
    t[3]->setDniContrato(75547111);
    for(int i=0; i<4; i++)
    {
        t[i]->setFechaContrato(t[i]->getFechaContrato()+2);
        t[i]->ver(); cout << endl;
    }

    system("PAUSE");
    return 0;
}
