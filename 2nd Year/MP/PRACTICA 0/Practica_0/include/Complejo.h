#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

using namespace std;

class Complejo
{
    int real;
    int imaginario;

    public:
        Complejo(int r , int i);

        int getr()const { return real; }
        void set(int r , int i) {real = r; imaginario = i;}
        int geti()const { return imaginario; }
        void set();
        void ver()const;

        Complejo operator+(Complejo c)const;
        Complejo operator+(int i)const;
        Complejo operator-()const;

        Complejo operator++();//No se pone la coletilla const porque altera el valor de i
        Complejo operator++(int i); // No se pone la coletilla const porque altera el valor de i

};

Complejo operator+(int i , Complejo c);

ostream& operator <<(ostream& s, const Complejo &o);


#endif // COMPLEJO_H
