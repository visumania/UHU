#include "Contrato.h"

int Contrato::contadorId=1; // Inicializamos el contadorId

Contrato::Contrato(int dni, Fecha F):idContrato(contadorId), FechaContrato(F)
{
    contadorId++;
    this->dniContrato = dni;
}

void Contrato::ver() const
{
    cout << this->dniContrato << " (" << this->idContrato << " - " << this->FechaContrato << ")";
}

ostream& operator<<(ostream &s, const Contrato &C)
{
    s << C.getDniContrato() << " (" << C.getIdContrato() << " - "; // << C.getFechaContrato() << ")";

    ////////////////////////////////
    int d=C.getFechaContrato().getDia(), m=C.getFechaContrato().getMes(), a=C.getFechaContrato().getAnio();

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

    s << a << ") ";
    ////////////////////////////////

    return s;
}
