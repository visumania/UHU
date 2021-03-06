#include "Fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha(int d, int m, int a)
{
    setFecha(d,m,a);
}

void Fecha::setFecha(int d,int m, int a)
{
   this->anio=a;

   if(m>12) // ASIGNAMOS MES
    this->mes=12;
   else if(m<1)
    this->mes=1;
   else
    this->mes=m;

   if(d<1)  // ASIGNAMOS DIA
    this->dia=1;
   else if(d<=28)
    this->dia=d;

   else// Dia > 28
   {
        int DiasMax[] ={0,31,28,31,30,31,30,31,30,30,31,30,31};

        if(this->bisiesto())
        DiasMax[2] = 29; // CORREGIMOS FEBRERO

        if(d<=DiasMax[this->mes])// DIA MENOR QUE EL MAXIMO CORRESPONDIENTE A ESE MES
            this->dia=d;
        else // DIA MAYOR QUE EL MAXIMO CORRESPONDIENTE
            this->dia=DiasMax[this->mes];

   }
}

void Fecha::ver() const
{
    if(this->dia<10)
    cout << '0';
    cout << this->dia << '/';
    if(this->mes<10)
    cout << '0';
    cout << this->mes << '/' << this->anio;
}

Fecha Fecha::operator++()
{
    this->dia++; // AUMENTAMOS 1 DIA
    int DiasMax[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};

        if(this->bisiesto())
        DiasMax[2] = 29; // CORREGIMOS FEBRERO

        if(dia>DiasMax[this->mes] && this->mes==12)// DIA MAYOR QUE EL MAXIMO CORRESPONDIENTE A ESE MES y
                                                // DIA MAYOR QUE EL MAXIMO CORRESPONDIENTE Y ULTIMO MES
            {
                this->dia=1;
                this->mes=1;
                this->anio++;
            }
        else // DIA MAYOR QUE EL MAXIMO CORRESPONDIENTE
        {
            this->dia=1;
            this->mes++;
        }

    return *this;
}

Fecha Fecha::operator++(int notused)
{
    Fecha copia(*this);
    this->dia++; // AUMENTAMOS 1 DIA
    int DiasMax[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};

        if(this->bisiesto())
        DiasMax[2] = 29; // CORREGIMOS FEBRERO

        if(dia>DiasMax[this->mes] && this->mes==12)// DIA MAYOR QUE EL MAXIMO CORRESPONDIENTE A ESE MES y
                                                // ULTIMO  MES DEL A??
            {
                this->dia=1;
                this->mes=1;
                this->anio++;
            }
        else if(dia>DiasMax[this->mes]) // DIA MAYOR QUE EL MAXIMO CORRESPONDIENTE
        {
            this->dia=1;
            this->mes++;
        }

    return copia;
}

Fecha Fecha::operator+(int i) const
{
    Fecha res(*this);
    for(int j=0; j<i; j++)
        res++;
    return res;
}

Fecha operator+(int i, const Fecha &f)
{
    Fecha res(f);
    for(int j=0; j<i; j++)
    res++;

    return res;
}

ostream& operator<<(ostream &s, const Fecha &f)
{
    /*int d=f.getDia(), m=f.getMes(), a=f.getAnio();

    if(d<10)
        s << "0" << d;
    else
        s << d;

    s << "/";

    if(m<10)
        s << "0" << m;
    else
        s << m;

    s << "/" << a;

    return s;*/
        int d=f.getDia(), m=f.getMes(), a=f.getAnio();

    if(d<10)
        s << "0" << d;
    else
        s << d;

    switch(m)
    {
        case 1:
            {
                s << " ene ";
                break;
            }
        case 2:
            {
                s << " feb ";
                break;
            }
        case 3:
            {
                s << " mar ";
                break;
            }
        case 4:
            {
                s << " abr ";
                break;
            }
        case 5:
            {
                s << " may ";
                break;
            }
        case 6:
            {
                s << " jun ";
                break;
            }
        case 7:
            {
                s << " jul ";
                break;
            }
        case 8:
            {
                s << " ago ";
                break;
            }
        case 9:
            {
                s << " sep ";
                break;
            }
        case 10:
            {
                s << " oct ";
                break;
            }
        case 11:
            {
                s << " nov ";
                break;
            }
        case 12:
            {
                s << " dic ";
                break;
            }
    }

    s << a;

    return s;
}
