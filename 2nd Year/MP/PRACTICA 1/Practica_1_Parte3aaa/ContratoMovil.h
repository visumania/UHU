#ifndef CONTRATOMOVIL_H_INCLUDED
#define CONTRATOMOVIL_H_INCLUDED

#include <iostream>
#include "Fecha.h"
#include "Contrato.h"

using namespace std;


class ContratoMovil: public Contrato
{
  float precioMinuto;
  int minutosHablados;
  char *nacionalidad;

public:
  ContratoMovil(long int pDni, Fecha pFecha, float pPrecioMinuto, int pMinutosHablados, char *pNacionalidad); //Constructor de la clase
  virtual ~ContratoMovil(); //Destructor de la clase necesario porque hay un atributo tipo char*
  ContratoMovil(const ContratoMovil& pContratoMovil); //necesario porque hay un atributo puntero char*
  //Métodos get():
  float getPrecioMinuto() const { return this->precioMinuto; }
  int getMinutosHablados() const { return this->minutosHablados; }
  const char* getNacionalidad() const { return this->nacionalidad; } //IMPORTANTE devuelve un puntero constante
  //Métodos set():
  void setPrecioMinuto(float pPrecioMinuto) { this->precioMinuto=pPrecioMinuto; }
  void setMinutosHablados(int pMinutosHablados) { this->minutosHablados=pMinutosHablados; }
  void setNacionalidad(const char* pNacionalidad);
  //Otros métodos:
  void ver() const;
  float factura() const;
  virtual void nada()const {;}
};

ostream& operator<<(ostream &s, const ContratoMovil &pContratoMovil);

#endif // CONTRATOMOVIL_H_INCLUDED
