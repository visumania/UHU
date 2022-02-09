#include <iostream>
#include <cstdlib>
#include <cstring> //strlen, strcpy
#include <iomanip> //std::setprecision
#include "Contrato.h"
#include "ContratoMovil.h"

ContratoMovil::ContratoMovil(long int pDni, Fecha pFecha, float pPrecioMinuto, int pMinutosHablados, char *pNacionalidad): Contrato(pDni, pFecha)
{
  this->precioMinuto=pPrecioMinuto;
  this->minutosHablados=pMinutosHablados;
  this->nacionalidad=new char [strlen(pNacionalidad)+1];
  strcpy(this->nacionalidad, pNacionalidad);
}

ContratoMovil::~ContratoMovil()
{
  delete this->nacionalidad;
}

ContratoMovil::ContratoMovil(const ContratoMovil& pContratoMovil): Contrato(pContratoMovil.getDniContrato(), pContratoMovil.getFechaContrato())
{
    this->precioMinuto = pContratoMovil.precioMinuto;
    this->minutosHablados=pContratoMovil.minutosHablados;
    this->nacionalidad=new char [strlen(pContratoMovil.nacionalidad)+1];
    strcpy(this->nacionalidad, pContratoMovil.nacionalidad);
}

void ContratoMovil::setNacionalidad(const char* pNacionalidad)
{
    this->nacionalidad = new char[strlen(pNacionalidad)+1];
    strcpy(this->nacionalidad, pNacionalidad);
}

void ContratoMovil::ver() const
{
  Contrato::ver();
  cout << " " << this->minutosHablados << "m, " ;

  char a;
  if(strcmp(this->nacionalidad , "ESPAÑOL")==0)
  {
        a= 165;
        cout << "ESPA" << a << "OL";
  }
  else
  {
      a = 144;
      cout << "FRANC" << a << "S";
  }

  cout << " " << this->precioMinuto;
}

float ContratoMovil::factura() const
{
    return(precioMinuto*minutosHablados);
}

ostream& operator<<(ostream &s, const ContratoMovil &pContratoMovil)
{
  s << (Contrato &)pContratoMovil;
  s << " " << pContratoMovil.getMinutosHablados() << "m, " ;

  s << pContratoMovil.getNacionalidad();


  s << " " << pContratoMovil.getPrecioMinuto() << " - ";
  s << pContratoMovil.factura() << "€";

  return s;
}
