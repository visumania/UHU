#include "Fecha.h"


Fecha::Fecha(int pDia , int pMes , int pAnio)
{
    this->setFecha(pDia , pMes , pAnio);
}

Fecha Fecha::operator=(Fecha pFecha)
{
    setFecha(pFecha.dia, pFecha.mes, pFecha.anio);

    return pFecha;
}

Fecha Fecha::operator+(int n) const
{
    Fecha aux(this->dia , this->mes , this->anio);

    for(int i=0 ; i<n ; i++)
    {
        aux.operator++();
    }

    return aux;
}

Fecha Fecha::operator++() //f++;
{
    int diasMax, diasMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (this->bisiesto()) //si el año es bisiesto asignamos a febrero 29 dias
      diasMes[2]=29;

    diasMax=diasMes[this->mes];
    this->dia++;

    if (this->dia>diasMax) //si al incrementar dia superamos el numero de dias de dicho mes
    {
        this->dia=1;      //pasamos a dia 1
        this->mes++;      //del mes siguiente

        if (this->mes>12)//si al incrementar mes pasamos de 12 meses
        {
            this->mes=1;    //pasamos al mes 1
            this->anio++;   //del año siguiente
        }
    }
    return *this; //devolvemos el objeto fecha ya incrementado
}

Fecha Fecha::operator++(int n) //++f;
{
    Fecha aux(*this);
    this->dia++; // AUMENTAMOS 1 DIA
    int DiasMax[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};

        if(this->bisiesto())
        DiasMax[2] = 29; // CORREGIMOS FEBRERO

        if(dia>DiasMax[this->mes] && this->mes==12)// DIA MAYOR QUE EL MAXIMO CORRESPONDIENTE A ESE MES y
                                                // ULTIMO  MES DEL AÑÓ
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


void Fecha::setFecha(int pDia , int pMes , int pAnio)
{
    int diasMax, diasMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    this->anio=pAnio; //VIP debo asignar año para al llamar a bisiesto() tengo el año bien

    if (this->bisiesto())
        diasMes[2]=29;

    if (pMes<1)  //si el mes es negativo o igual a 0
      pMes=1;
    else if (pMes>12) //si el mes es mayor que 12
      pMes=12;

    this->mes=pMes;
    diasMax=diasMes[pMes]; //una vez fijado el mes veo cuantos dias tiene ese mes como maximo

    if (pDia>diasMax) //si pDia es superior al numero de dias de dicho mes
      pDia=diasMax;
    else if (pDia<1) //si pDia es inferior a 1
      pDia=1;

    this->dia=pDia;
}

void Fecha::ver() const
{
    if (this->dia < 10) //para que el dia siempre tenga dos digitos
    cout << "0";

    cout << this->dia << "/";

    if (this->mes < 10) //para que el mes siempre tenga dos digitos
        cout << "0";

    cout << this->mes << "/" << this->anio;
}

bool Fecha::bisiesto() const
{
    bool bisiesto = false ;

    if((anio%4 == 0 && anio%100 != 0) || anio%400 == 0)
        bisiesto = true ;

    return bisiesto;
}

Fecha operator+(int n , const Fecha &pFecha)
{
     Fecha aux(pFecha.dia , pFecha.mes , pFecha.anio);

    for(int i=0 ; i<n ; i++)
    {
        aux.operator++();
    }

    return aux;
}
