#include <iostream>
#include "Complejo.h"

using namespace std;

Complejo::Complejo(int real, int imaginario)
{
    this->real = real ;
    this->imaginario = imaginario ;
}

void Complejo::set()
{
    cout << "Introduzca la parte real: ";
    cin >> this->real;

    cout << "\nIntroduzca parte imaginaria: ";
    cin >> this->imaginario;
}

void Complejo::ver()const
{
    if(this->imaginario >= 0)
    {
        cout << this->real << "+" << this->imaginario << "i";
    }
    else
    {
        cout << this->real << this->imaginario << "i";
    }
}

Complejo Complejo::operator+(Complejo c)const
{

    //Forma 1:

    Complejo suma(0,0);

    suma.real = this->real + c.real;
    suma.imaginario = this->imaginario + c.imaginario;

    return suma;

/*     //Forma 2:
 *
 *     Complejo suma(this->real + c.real , this->imaginario + c.imaginario);
 *     return suma;
 *
 *     //Forma 3:
 *
 *     return suma(this->real + c.real , this->imaginario + c.imaginario);
 */
}

Complejo Complejo::operator+(int i)const
{
    Complejo suma(this->real + i , this->imaginario);

    return suma;
}

Complejo Complejo::operator-()const
{
    // Esta forma es directa: Complejo aux(-this->real , -this->imaginario);

    //Pero usamos esta de aqui abajo porque lo entendemos mejor:
    Complejo aux(0,0);

    aux.real = -this->real;
    aux.imaginario = -this->imaginario;

    return aux;

}

Complejo operator+(int i , Complejo c)
{
    //Forma1:
    /*Complejo suma(0,0);

    suma.set(i + c.getr() , c.geti());

    return suma ;*/

    //Forma 2:

   /* Complejo suma(0,0);

    suma = c+i;

    return suma ;*/

    //Forma 3:

    return c+i ;
}

ostream& operator<<(ostream& s,const Complejo &o) //Hacemos como si quiesieramos mostrar por pantalla informacion pero cambiando los cout por s  , solo tiene un ligero cambio en el final (return s)
{
    if(o.geti() >= 0)
        {
            s << o.getr() << "+" << o.geti() << "i";
        }
        else
        {
            s << o.getr() << o.geti() << "i";
        }

        return s;
}

Complejo Complejo::operator++()
{
    this->real = this->real+1;

    return *this; // Para desreferencia el puntero porque queremos devolver el objeto , no el puntero que apunta al puntero // Estamos devolviendo una copia , para devolver el original deberiamos usar &

    //Otra forma de hacerlo:
    /*Complejo copia(this->real . this ->imaginario);

    return copia; */
}

Complejo Complejo::operator++(int i)
{
    //Forma 1:
    Complejo copia(this->real , this->imaginario);

    this->real = this->real+1;

    return copia;

   /* Forma 2:

    return copia(this->real-1 , this->imaginario);*/
}

