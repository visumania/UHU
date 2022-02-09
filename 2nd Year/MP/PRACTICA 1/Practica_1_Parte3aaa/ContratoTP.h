#ifndef CONTRATOTP_H_INCLUDED
#define CONTRATOTP_H_INCLUDED

#include <iostream>
#include "Fecha.h"
#include "Contrato.h"

using namespace std;

class ContratoTP: public Contrato
{
  static int minutosTP;
  static float precioTP;
  int minutosHablados;
  static const float precioExcesoMinutos ;

public:
  ContratoTP(long int pDniContrato, Fecha pFecha, int pMinutosHablados); //Constructor de la clase:
  ContratoTP(const ContratoTP& pContratoTP);  //¿es necesario? pensar y reflexionad --> SI , es un constructor en lo que me pasan por parámetro es un objeto tipo contratotp y en el main está la evidencia de que lo necesitamos .
  //Métodos get():
  static int getLimiteMinutos() { return ContratoTP::minutosTP; }
  static float getPrecio() { return ContratoTP::precioTP; }
  int getMinutosHablados()const{return this->minutosHablados;}
  //Métodos set():
  static void setTarifaPlana(int pMinutosTP, float pPrecioTP); //el el .cpp se pone la cabecera sin la palabra static
  void setFechaContrato(Fecha pFecha);
  void setMinutosHablados(int pMinutosHablados){this->minutosHablados = pMinutosHablados;}
  //Otros métodos:
  void ver() const;
  float factura() const;
  virtual void nada() const {;}
};

ostream& operator<<(ostream &s, const ContratoTP &pContratoTP);

#endif // CONTRATOTP_H_INCLUDED
