#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include<iostream>

using namespace std;

class Fecha
{
    int dia;
    int mes;
    int anio;

public:
    Fecha(int pDia , int pMes , int pAnio);//Constructor parametrizado de la clase
    //Los metodos get
    int getDia() const {return this->dia;}
    int getMes() const {return this->mes;}
    int getAnio() const {return this->anio;}
    //los metodos set
    void setFecha(int pDia, int pMes , int pAnio);
    //Otros métodos
    void ver() const;
    bool bisiesto() const;
    //Sobrecargas de operadores
    Fecha operator=(Fecha pFecha);
    Fecha operator+(int n) const;
    Fecha operator++();
    Fecha operator++(int n);

    friend Fecha operator+(int n , const Fecha &pFecha);

};

Fecha operator+(int n, const Fecha &pFecha);

#endif // FECHA_H_INCLUDED
