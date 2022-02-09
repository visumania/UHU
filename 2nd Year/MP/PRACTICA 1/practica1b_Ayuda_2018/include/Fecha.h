#ifndef FECHA_H
#define FECHA_H

#include <iostream> //cin, cout

using namespace std;
//SI FALTA ALGUN METODO O FUNCION AÑADIRLO...
class Fecha {
  int dia;
  int mes;
  int anio;
public:
  Fecha(int d, int m, int a);
//Fecha(const Fecha &f); //NO HACE FALTA: EL QUE GENERA EL COMPILADOR FUNCIONA BIEN YA QUE NO HAY PUNTEROS
  int getDia() const { return this->dia; }
  int getMes() const { return this->mes; }
  int getAnio()  const { return this->anio; }
  void setFecha(int d, int m, int a);
  void ver() const;
  bool bisiesto() const;
  Fecha operator++();   //++f
  Fecha operator++(int i);  //f++
  Fecha operator+(int i) const;

  friend Fecha operator+(int i, const Fecha &f); //const por seguridad y & por velocidad
  friend ostream& operator<<(ostream &s, const Fecha &f);
};

Fecha operator+(int i, const Fecha &f); //const por seguridad y & por velocidad
ostream& operator<<(ostream &s, const Fecha &f);

#endif // FECHA_H
