#include "Contrato.h"
#include "ContratoTP.h"

int ContratoTP::minutosTP=300;
float ContratoTP::precioTP=10;
const float ContratoTP::precioExcesoMinutos=0.15;

ContratoTP::ContratoTP(long int pDniContrato , Fecha pFecha , int pMinutosHablados): Contrato(pDniContrato ,  pFecha)
{
    minutosHablados = pMinutosHablados ;
}

ContratoTP::ContratoTP(const ContratoTP &pContratoTP):Contrato(pContratoTP.getDniContrato(), pContratoTP.getFechaContrato())
{
    this->minutosHablados = pContratoTP.minutosHablados;
}

//static se pone en el .h (no se pone en el .cpp)
void ContratoTP::setTarifaPlana(int pMinutosTP, float pPrecioTP)
{
  ContratoTP::minutosTP=pMinutosTP; //pongo ContratoTP::minutosTP para recordar que es estatico
  ContratoTP::precioTP=pPrecioTP;  //pongo ContratoTP::precioTP para recordar que es estatico
}

void ContratoTP::setFechaContrato(Fecha pFecha)
{
    Contrato::setFechaContrato(pFecha);
}

void ContratoTP::ver()const
{
    Contrato::ver();

    cout << minutosHablados << "m, " << ContratoTP::minutosTP << "(" << ContratoTP::precioTP << ")";
}

float ContratoTP::factura()const
{
    int LimiteMinutos = ContratoTP::getLimiteMinutos();

    if(minutosHablados>LimiteMinutos)
        return(ContratoTP::precioTP + ((minutosHablados-LimiteMinutos) * ContratoTP::precioExcesoMinutos));
    else
        return precioTP;
}

ostream& operator<<(ostream &s, const ContratoTP &pContratoTP)
{
    s << (Contrato &)pContratoTP;
    s << " " << pContratoTP.getMinutosHablados() ;
    s <<  "m, " << ContratoTP::getLimiteMinutos();
    s << "(" <<  ContratoTP::getPrecio() << ")";
    s << " - " << pContratoTP.factura() << "€";


    return s;
}
