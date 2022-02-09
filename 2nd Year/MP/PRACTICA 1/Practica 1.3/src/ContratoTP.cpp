#include "ContratoTP.h"
#include <iostream>
#include <iomanip>

using namespace std;

float ContratoTP::precioTP = 10;
int ContratoTP::minutosTP = 300;

ContratoTP::ContratoTP(long int dni, Fecha F, int minutos):Contrato(dni, F)
{
    this->minutosHablados = minutos;
}

void ContratoTP::ver() const
{
    Contrato::ver();
    cout << fixed << setprecision(2) << " " << minutosHablados << "m, " << getLimiteMinutos() << "(" << getPrecioTP() << ")";
}

ContratoTP::ContratoTP(const ContratoTP &P):Contrato(P.getDniContrato(), P.getFechaContrato())
{
    //this->minutosTP = P.getLimiteMinutos();
    this->minutosHablados = P.getMinutosHablados();
}

float ContratoTP::factura() const
{
    if(minutosHablados > minutosTP)
    {
        int min_a_pagar = minutosHablados-minutosTP;

        return (precioTP + (min_a_pagar*precioExcesoMin));
    }
    else
        return precioTP;
}

ostream& operator<<(ostream &s, const ContratoTP &C)
{
    s << C.getDniContrato() << " (" << C.getIdContrato() << " - "; //<< C.getFechaContrato() << ") ";

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

    s << C.getMinutosHablados() << "m, ";
    s << C.getLimiteMinutos() << "(" << C.getPrecioTP() << ")" << " - ";
    s << C.factura() << "$";

    return s;
}
