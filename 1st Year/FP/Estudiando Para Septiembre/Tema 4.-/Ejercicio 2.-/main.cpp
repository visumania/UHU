#include <iostream>
#include<windows.h>

using namespace std;

#define M 10

class matrices
{
    int tabla[M];

public:
    void cargar();
    bool encontrar();
};

void matrices::cargar()
{
    for(int i=0 ; i<M ; i++)
    {
        tabla[i] = i+1;
    }
}

bool matrices::encontrar()
{
    int numero ;

    system("cls");

    cout << "Introduzca un numero a buscar en la tabla(ha de tener en cuenta de que la tabla va desde 1 hasta 10): " ;
    cin >> numero ;

    int n ;
    bool encontrado ;

    n = 0 ;
    encontrado = false ;

    while(n<M && !encontrado)
    {
        if(tabla[n]==numero)
        {
            encontrado = true ;
        }
        else
            n++;
    }

    system("cls");

    if (encontrado)
        cout << "Se ha encontrado en la posicion " << n+1 << "\n";
    else
        cout << "No se ha encontrado el numero en ninguna de las posiciones \n" ;

        return encontrado ;
}

int main()
{
    matrices matri;

    matri.cargar();
    matri.encontrar();

    return 0 ;
}
