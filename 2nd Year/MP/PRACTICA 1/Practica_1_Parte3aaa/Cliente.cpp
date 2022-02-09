#include "Cliente.h"
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string.h>

Cliente::Cliente(long int pDni, char *pNombre, Fecha pFecha):fechaAlta(pFecha)
{
    this->dni = pDni;
    this->nombre = new char[strlen(pNombre)+1];
    strcpy(this->nombre , pNombre);
}

Cliente::~Cliente()
{
    delete[]this->nombre;
    nombre = NULL;
}

void Cliente::setNombre(char *pNombre)
{
    strcpy(this->nombre , pNombre );
}

void Cliente::setFecha(Fecha pFechaAlta)
{
    this->fechaAlta.setFecha(pFechaAlta.getDia() , pFechaAlta.getMes(), pFechaAlta.getAnio());
}

bool Cliente::operator==(const Cliente &pCliente) const
{
    bool iguales = true;

    if (this->dni!=pCliente.dni)
        iguales = false;

    if (strcmp(this->nombre, pCliente.nombre)!=0)
        iguales = false;

    if (this->fechaAlta.getDia()!=pCliente.fechaAlta.getDia() || this->fechaAlta.getMes()!=pCliente.fechaAlta.getMes() || this->fechaAlta.getAnio()!=pCliente.fechaAlta.getAnio())
        iguales = false;

        return iguales;
}

ostream& operator<<(ostream &s, const Cliente &pCliente)
{
    s << pCliente.getNombre();
    s << " (" << pCliente.getDni() ;
    s << " - " << pCliente.getFecha() << ")";

    return s;
}

Cliente& Cliente::operator=(const Cliente &pCliente)
{
    this->dni = pCliente.getDni();
    strcpy(this->nombre , pCliente.nombre);
    fechaAlta.setFecha(pCliente.fechaAlta.getDia() , pCliente.fechaAlta.getMes() , pCliente.fechaAlta.getAnio());

    return *this;
}

//Funciones genéricas:

/*ostream& operator<<(ostream &s, const Fecha &f)
{
     int d=f.getDia(), m=f.getMes(), a=f.getAnio();

    if(d<10)
        s << "0" << d;
    else
        s << d;

    switch(m)
    {
        case 1:
            {
                s << " ene ";
                break;
            }
        case 2:
            {
                s << " feb ";
                break;
            }
        case 3:
            {
                s << " mar ";
                break;
            }
        case 4:
            {
                s << " abr ";
                break;
            }
        case 5:
            {
                s << " may ";
                break;
            }
        case 6:
            {
                s << " jun ";
                break;
            }
        case 7:
            {
                s << " jul ";
                break;
            }
        case 8:
            {
                s << " ago ";
                break;
            }
        case 9:
            {
                s << " sep ";
                break;
            }
        case 10:
            {
                s << " oct ";
                break;
            }
        case 11:
            {
                s << " nov ";
                break;
            }
        case 12:
            {
                s << " dic ";
                break;
            }
    }

    s << a;

    return s;
}*/

ostream& operator<<(ostream &s, Cliente &pCliente)
{
    s << pCliente.getNombre() << " (" << pCliente.getDni();
    s << " - " << pCliente.getFecha() << ")";

    return s;
}
