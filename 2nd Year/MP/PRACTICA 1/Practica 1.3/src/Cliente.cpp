#include "Cliente.h"
#include "Fecha.h"
#include <cstring>

using namespace std;

Cliente::~Cliente()
{
    delete [] nombre;
    nombre = NULL;
}

Cliente::Cliente(long int d, char* nom, Fecha f):fechaAlta(f.getDia(),f.getMes(),f.getAnio())
{
    this->dni = d;

    this->nombre = new char[strlen(nom+1)];
    strcpy(this->nombre, nom);
}

Cliente& Cliente::operator=(const Cliente& c)
{
    if(this != &c)
    {
        this->dni = c.getDni();
        this->fechaAlta = c.getFecha();

        delete [] this->nombre;
        this->nombre = new char[strlen(c.getNombre())+1];
        strcpy(this->nombre, c.getNombre());
    }

    return *this;
}

void Cliente::setNombre(char *nom)
{
    delete [] this->nombre;

    this->nombre = new char[strlen(nom)+1];
    strcpy(this->nombre, nom);
}

bool Cliente::operator==(Cliente c) const
{
    if(this!=&c)
    {
        int d1=this->fechaAlta.getDia(), m1=this->fechaAlta.getMes(), a1=this->fechaAlta.getAnio();
        int d2=c.getFecha().getDia(), m2=c.getFecha().getMes(), a2=c.getFecha().getAnio();

        if(strcmp(this->nombre,c.getNombre())!=0 || this->dni!=c.getDni() || (d1!=d2 || m1!=m2 || a1!=a2))
            return false;
        else
            return true;
    }
    else
        return true;
}
/*ostream& operator<<(ostream &s, const Fecha &f)
{
    int d=f.getDia(), m=f.getMes(), a=f.getAnio();

    if(d<10)
        s << "0" << d;
    else
        s << d;

    s << "/";

    if(m<10)
        s << "0" << m;
    else
        s << m;

    s << "/" << a;
//////////////////////////////////////////////////////////////////
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

ostream& operator<<(ostream &s, const Cliente &c)
{
    s << c.getNombre() << " (" << c.getDni() << " - " << c.getFecha() << ")";
    return s;
}
