#include "Fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha(int pDia, int pMes, int pAnio)
{
    setFecha(pDia,pMes,pAnio);
}

void Fecha::setFecha(int pDia,int pMes, int pAnio)
{
   this->anio=pAnio;

   if(pMes>12) // ASIGNAMOS MES
    this->mes=12;
   else if(pMes<1)
    this->mes=1;
   else
    this->mes=pMes;

   if(pDia<1)  // ASIGNAMOS DIA
    this->dia=1;
   else if(pDia<=28)
    this->dia=pDia;

   else// Dia > 28
   {
        int DiasMax[] ={0,31,28,31,30,31,30,31,30,30,31,30,31};

        if(this->bisiesto())
        DiasMax[2] = 29; // CORREGIMOS FEBRERO

        if(pDia<=DiasMax[this->mes])// DIA MENOR QUE EL MAXIMO CORRESPONDIENTE A ESE MES
            this->dia=pDia;
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

Fecha Fecha::operator++(int n)
{
    Fecha aux(*this);
    this->dia++; // AUMENTAMOS 1 DIA
    int DiasMax[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};

        if(this->bisiesto())
        DiasMax[2] = 29; // CORREGIMOS FEBRERO

        if(dia>DiasMax[this->mes] && this->mes==12)// DIA MAYOR QUE EL MAXIMO CORRESPONDIENTE A ESE MES y
                                                // ULTIMO  MES DEL Aяс
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

    return aux;
}

Fecha Fecha::operator+(int i) const
{
    Fecha aux(*this);
    for(int j=0; j<i; j++)
        aux++;

    return aux;
}

Fecha operator+(int i, const Fecha &pFecha)
{
    Fecha aux(pFecha);
    for(int j=0; j<i; j++)
    aux++;

    return aux;
}

ostream& operator<<(ostream &s, const Fecha &pFecha)
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
        int pDia=pFecha.getDia(), pMes=pFecha.getMes(), pAnio=pFecha.getAnio();

    if(pDia<10)
        s << "0" << pDia;
    else
        s << pDia;

    switch(pMes)
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

    s << pAnio;

    return s;
}
