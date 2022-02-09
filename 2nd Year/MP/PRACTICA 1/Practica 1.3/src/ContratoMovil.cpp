#include "ContratoMovil.h"
#include <cstring>
#include <iomanip>

ContratoMovil::ContratoMovil(long int dni, Fecha F, float precio, int minutos, char* origen):Contrato(dni, F)
{
    this->precioMinuto = precio;
    this->minutosHablados = minutos;

    this->Nacionalidad = new char[strlen(origen)+1];
    strcpy(this->Nacionalidad, origen);
}

ContratoMovil::~ContratoMovil()
{
    delete [] Nacionalidad;
    Nacionalidad = NULL;
}

ContratoMovil::ContratoMovil(const ContratoMovil &C):Contrato(C.getDniContrato(), C.getFechaContrato())
{
    this->precioMinuto = C.precioMinuto;

    this->Nacionalidad = new char[strlen(C.Nacionalidad)+1];
    strcpy(this->Nacionalidad, C.Nacionalidad);
    this->minutosHablados = C.minutosHablados;
}

void ContratoMovil::ver() const
{
    Contrato::ver();
    cout << fixed << setprecision(2) << " " << minutosHablados << "m, " << getNacionalidad() << " " << getPrecioMinuto() << "$";
}

void ContratoMovil::setNacionalidad(const char* nueva_nacionalidad)
{
    delete [] Nacionalidad;

    this->Nacionalidad = new char[strlen(nueva_nacionalidad)+1];
    strcpy(this->Nacionalidad, nueva_nacionalidad);
}

ostream& operator<<(ostream& s, const ContratoMovil &C)
{
    s << C.getDniContrato() << " (" << C.getIdContrato() << " - "; //<< C.getFechaContrato() << ") ";

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

    s << C.getMinutosHablados() << "m, ";
    s << C.getNacionalidad() << " " << C.getPrecioMinuto() << "$ - ";
    s << C.factura() << "$";

    return s;
}
