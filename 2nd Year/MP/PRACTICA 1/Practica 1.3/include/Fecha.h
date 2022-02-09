#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class Fecha
{
    int dia, mes, anio;

    public:
        Fecha(int d, int m, int a);

        void setFecha(int d,int m, int a);
        const int& getDia() const{return this->dia;}
        const int& getMes() const{return this->mes;}
        const int& getAnio() const{return this->anio;}
        bool bisiesto() const {return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));};
        void ver() const;

        Fecha operator++(); // ++Fecha
        Fecha operator++(int notused); // Fecha++
        Fecha operator+(int i) const;

        friend Fecha operator+(int i, const Fecha &f); // const por seguridad y & por velocidad


};
Fecha operator+(int i, const Fecha &f);
ostream& operator<<(ostream &s, const Fecha &f);
#endif // FECHA_
