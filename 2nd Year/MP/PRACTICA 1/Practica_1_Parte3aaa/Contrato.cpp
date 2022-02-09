#include "Contrato.h"

int Contrato::contador=1;

Contrato::Contrato(long int pDniContrato, Fecha pFecha): idContrato(contador), fechaContrato(pFecha)
{
  Contrato::contador++;
  this->dniContrato=pDniContrato;
}

Contrato::~Contrato()
{
    Contrato::contador--; //Hecho como he visto en los ejemplos de los apuntes
}


void Contrato::ver() const
{
  cout << this->dniContrato << " (" << this->idContrato << " - ";
  this->fechaContrato.ver(); //llamo al ver del objeto fecha
  cout << ")";
}

ostream& operator<<(ostream &s, const Contrato &pContrato)
{
  s << pContrato.getDniContrato() << " (" << pContrato.getIdContrato() << " - " << pContrato.getFechaContrato() << " )";

  return s;
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
