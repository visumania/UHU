#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream> //cin, cout
#include "Fecha.h"

using namespace std;
//SI FALTA ALGUN METODO O FUNCION AÑADIRLO...
class Cliente {
  long int dni;
  char *nombre;
  Fecha fechaAlta;
public:
  Cliente(long int d, char *nom, Fecha f);
  virtual ~Cliente();
  Cliente& operator=(const Cliente& c);
  long int getDni() const { return this->dni; }
//const char* para evitar que desde el main() se puede modificar el nombre
  const char* getNombre() const { return this->nombre; } //VIP devolver un puntero constante
  Fecha getFecha() const { return this->fechaAlta; }
  void setNombre(char *nom);
  void setFecha(Fecha f);
  bool operator==(Cliente c) const;

};

ostream& operator<<(ostream &s, const Cliente &c); //funcion no amiga de la clase
#endif // CLIENTE_H
