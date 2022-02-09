#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class Fecha
{
    int dia, mes, anio;

    public:
        Fecha(int pDia, int pMes, int pAnio); //Constructor de la clase
        //Metodos set():
        void setFecha(int pDia,int pMes, int pAnio);
        //Metodos get();
        const int& getDia() const{return this->dia;}
        const int& getMes() const{return this->mes;}
        const int& getAnio() const{return this->anio;}
        //Otros métodos:
        bool bisiesto() const {return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));};
        void ver() const;
        //Sobrecarga de operadores:
        Fecha operator++(); // ++Fecha
        Fecha operator++(int n); // Fecha++
        Fecha operator+(int i) const;
        //Función amiga de la clase:
        friend Fecha operator+(int i, const Fecha &pFecha); // const por seguridad y & por velocidad


};
Fecha operator+(int i, const Fecha &f);
ostream& operator<<(ostream &s, const Fecha &pFecha);
#endif // FECHA_
