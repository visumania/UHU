#ifndef CONTRATO_H_INCLUDED
#define CONTRATO_H_INCLUDED

#include <iostream>
#include "Fecha.h"

using namespace std;

class Contrato
{
  static int contador;
  const int idContrato;
  long int dniContrato;
  Fecha fechaContrato;
public:
  Contrato(long int pDniContrato, Fecha pFecha); //Constructor de la clase
  virtual ~Contrato(); //Destructor de la clase
  //Métodos get():
  int getIdContrato() const { return this->idContrato; }
  long int getDniContrato() const { return this->dniContrato; }
  Fecha getFechaContrato() const { return this->fechaContrato; }
  //Métodos set():
  void setFechaContrato(Fecha pFecha) { this->fechaContrato=pFecha; }
  void setDniContrato(long int pDni) { this->dniContrato=pDni; }
  //Otros métodos:
  virtual void ver() const;
  virtual void nada()const =0;
};

ostream& operator<<(ostream &s, const Contrato &pContrato);
ostream& operator<<(ostream &s , const Fecha &pFecha);

#endif // CONTRATO_H_INCLUDED
