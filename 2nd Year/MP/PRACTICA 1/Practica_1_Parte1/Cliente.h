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
        Cliente(long int pDni, char* pNombre,Fecha pFecha); //Constructor de la clase
        ~Cliente(); //Destructor de la clase
        //Métodos get():
        Fecha getFecha() const {return this->fechaAlta;};
        long int getDni() const {return this->dni;};
        const char* getNombre() const {return this->nombre;};
        //Métodos set();
        void setNombre(char* pNombre);
        void setFecha(Fecha pFecha) {this->fechaAlta=pFecha;};
        //Sobrecarga de operadores:
        bool operator==(Cliente pCliente)const;
        Cliente& operator=(const Cliente& pCliente);


};
//ostream& operator<<(ostream &s, const Fecha &f);
ostream& operator<<(ostream &s, const Cliente &pCliente);

#endif
