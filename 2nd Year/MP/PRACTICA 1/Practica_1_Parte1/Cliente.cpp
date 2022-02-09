#include "Cliente.h"
#include "Fecha.h"
#include <cstring>

using namespace std;

Cliente::Cliente(long int pDni, char* pNombre, Fecha pFecha):fechaAlta(pFecha.getDia(),pFecha.getMes(),pFecha.getAnio())
{
    this->dni = pDni;

    this->nombre = new char[strlen(pNombre+1)];
    strcpy(this->nombre, pNombre);
}

Cliente::~Cliente()
{
    delete [] nombre;
    nombre = NULL;
}

void Cliente::setNombre(char *pNombre)
{
    delete [] this->nombre;

    this->nombre = new char[strlen(pNombre)+1];
    strcpy(this->nombre, pNombre);
}

bool Cliente::operator==(Cliente pCliente) const
{
    if(this!=&pCliente)
    {
        int d1=this->fechaAlta.getDia(), m1=this->fechaAlta.getMes(), a1=this->fechaAlta.getAnio();
        int d2=pCliente.getFecha().getDia(), m2=pCliente.getFecha().getMes(), a2=pCliente.getFecha().getAnio();

        if(strcmp(this->nombre,pCliente.getNombre())!=0 || this->dni!=pCliente.getDni() || (d1!=d2 || m1!=m2 || a1!=a2))
            return false;
        else
            return true;
    }
    else
        return true;
}

Cliente& Cliente::operator=(const Cliente& pCliente)
{
    if(this != &pCliente)
    {
        this->dni = pCliente.getDni();
        this->fechaAlta = pCliente.getFecha();

        delete [] this->nombre;
        this->nombre = new char[strlen(pCliente.getNombre())+1];
        strcpy(this->nombre, pCliente.getNombre());
    }

    return *this;
}


ostream& operator<<(ostream &s, const Fecha &f)
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
}

ostream& operator<<(ostream &s, const Cliente &pCliente)
{
    s << pCliente.getNombre() << " (" << pCliente.getDni() << " - " << pCliente.getFecha() << ")";

    return s;
}



