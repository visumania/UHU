#ifndef CLIENTE_H
#define CLIENTE_H
#include "Fecha.h"
#include <iostream>

using namespace std;

class Cliente
{
    char* nombre;
    long int dni;
    Fecha fechaAlta;

    public:
        Cliente(long int d, char* nom,Fecha f);
        ~Cliente();

        Fecha getFecha() const {return this->fechaAlta;};
        long int getDni() const {return this->dni;};
        const char* getNombre() const {return this->nombre;};/// OJO SEGURIDAD {return this->nombre;}
        void setNombre(char* nom);
        void setFecha(Fecha f) {this->fechaAlta=f;};

        bool operator==(Cliente c)const;
        Cliente& operator=(const Cliente& c);


};
//ostream& operator<<(ostream &s, const Fecha &f);
ostream& operator<<(ostream &s, const Cliente &c);
#endif
