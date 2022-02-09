#include <iostream>
#include <windows.h>

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
        tabla[i]= i+1;
    }
}

bool matrices::encontrar()
{
    int leida ;
    bool encontrado =false ;

    cout << "Introduzca el numero a buscar: " ;
    cin >> leida ;

    int i=0 ;

    while((i<M) && (!encontrado))
    {

        if(tabla[i]==leida)
        {
            encontrado=true ;
        }
        else i++;
    }

    if(encontrado)
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }

    return encontrado;


}

int main()
{
    matrices m ;

    m.cargar();
    m.encontrar();

    return 0 ;
}
