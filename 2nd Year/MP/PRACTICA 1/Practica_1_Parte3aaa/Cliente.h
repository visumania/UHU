#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Fecha.h"

using namespace std;

class Cliente
{
    long int dni;
    char *nombre;
    Fecha fechaAlta;

public:
    Cliente(long int pDni, char *pNombre, Fecha pFechaAlta); // Constructor de la clase
    virtual ~Cliente(); // Destructor de la clase
    //Los metodos get:
    long int getDni() const{return this->dni;}
    const char* getNombre()const {return this->nombre;}
    Fecha getFecha() const{return this->fechaAlta;}
    //Los metodos set:
    void setFecha(Fecha pFecha);
    void setNombre(char *pNombre);
    //Sobrecargas de operadores:
    bool operator==(const Cliente &pCliente) const;
    Cliente& operator=(const Cliente &pCliente);
};

//Funciones genéricas: (no es una función amiga de la clase)
ostream& operator<<(ostream &s , const Cliente &pCliente);
ostream& operator<<(ostream &s , const Fecha &pFecha);

#endif // CLIENTE_H_INCLUDED
