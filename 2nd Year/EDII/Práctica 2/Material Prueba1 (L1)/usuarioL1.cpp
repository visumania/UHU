#include <iostream>
#include <cstdlib>
#include "arbin.h"

using namespace std;


//Ejercicio 1

template <typename T>
bool cargaPar(const Arbin<T>& a)
{
    return cargaPar(a,a.getRaiz());
};

template <typename T>
bool cargaPar(const Arbin<T> &a , const typename Arbin<T>::Iterador &r)
{
    int valor1, valor2;

    if(!r.arbolVacio())
        if(a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio()) //Caso en el que tenemos un único nodo en el árbol
            return true;
        else
        {
            valor1=hijos(a,a.subIzq(r));
            valor2=hijos(a,a.subDer(r));

            if((valor1-valor2 == 0) || (valor1-valor2 == 2) || (valor1-valor2 == -2))
               return true;
        }

    return false;
}

template <typename T>
int hijos(const Arbin<T>& a, const typename Arbin<T>::Iterador& r){
    if(r.arbolVacio())
        return 0;
    else
        return hijos(a, a.subIzq(r)) + hijos(a, a.subDer(r)) + 1;
}

//Ejercicio 2

void hojasCota(const Arbin<int> &a , const typename Arbin<int>::Iterador &r , int cota , int sum)
{
    if(!r.arbolVacio())
        if(a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio())
            //if(sum+r.observar() < cota)
                cout << "Hoja (" << r.observar() << ")--> pesoHoja: " << sum+r.observar() << endl;
        else
        {
            sum += r.observar();
            hojasCota(a,a.subIzq(r),cota,sum);
            hojasCota(a,a.subDer(r) ,cota,sum);
        }
}

void hojasCota (const Arbin<int>& a, int cota)
{
    int sum = 0;
    hojasCota(a,a.getRaiz(),cota , sum);
};

/* ******************************************************************* */
/* ******************************************************************* */
int main() {
    Arbin<char> a('m', Arbin<char>('q', Arbin<char>('s', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('t', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('d', Arbin<char>('k', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()));

    Arbin<char> b('m', Arbin<char>('q', Arbin<char>('s', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('t', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('d', Arbin<char>('k', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('x', Arbin<char>(), Arbin<char>())));


    Arbin<int> d (3, Arbin<int>(8, Arbin<int>(9, Arbin<int>(), Arbin<int>()),
                                 Arbin<int>(7, Arbin<int>(), Arbin<int>())),
                     Arbin<int>(5, Arbin<int>(4, Arbin<int>(), Arbin<int>()),
                                 Arbin<int>()));

// Ejercicio 1
   cout << "cargaPar el arbol A?:";
    if(cargaPar(a)) cout<<"SI";
      else cout << "NO";
   cout << endl;

   cout << "cargaPar el arbol B?:";
    if(cargaPar(b)) cout<<"SI";
      else cout << "NO";

   cout << endl<<endl;


// Ejercicio 2
   cout << "Hojas Cota 19 en Arbol D: "<<endl;
   hojasCota(d,19);
   cout << endl<<endl;


    system("PAUSE");
    return 1;
}

