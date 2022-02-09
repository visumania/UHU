#include <iostream>

using namespace std;

#define M 10

class uno
{
    int tabla [M] ;

public :
    void cargar();
    bool encontrar ();
};

void uno::cargar()
{
    int valores ;

    for(int i=0 ; i<M ; i++)
       {
        cout << "Introduzca una valor entero para almacenarlo en la tabla , posicion: " << i+1 << " : " ;
        cin >> valores ;
       }
}

bool uno::encontrar()
{
    int j ;
    bool encontrado ;

    encontrado==false ;

    if (j == tabla[M])
        encontrado = true ;
}   else encontrado ;

int main()
{
    uno numero;

    numero.cargar();
    numero.encontrar();

    return 0;
}
