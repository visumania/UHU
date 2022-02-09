#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

#define M 2
#define N 4

typedef char cadena[30];

struct persona
{
    int dni;
    cadena nombre ;
};

class matrices
{
    persona tabla[M][N];

public:
    void cargar();
    void encontrar();
};

void matrices::cargar()
{
    for(int i=0 ; i<M ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cout << "Introduzca el dni sin letra " << i+1 << "." << j+1 << "#:" ;
            cin >> tabla[i][j].dni ;

            cout << "Ahora introduzca el nombre de la persona del dni anterior(" << i+1 << "." << j+1 << "): " ;
            cin >> tabla[i][j].nombre;
        }
    }
}

void matrices::encontrar()
{
    cout << "Introduzca DNI a buscar: " ;
    cin >> tabla[M][N].dni ;

    int j ;
    bool encontrado = false ;

    int i=0 ;
    while((i<M) && !encontrado)
    {
        j=0 ;
        while((j<N) && !encontrado)
        {
            if(tabla[M][N].dni == tabla[i][j].dni)
                encontrado = true ;
            else
                j++ ;
        }
        if(!encontrado)
            i++ ;
    }

    system("cls");


    if(encontrado == true)
    {
        cout << "Se encontro en la tabla en la posicion " << i+1 << "." << j+1 << " y pertenece a " << tabla[i][j].nombre;
    }
    else
    {
        cout << "No se encontro en ninguna posicion de la tabla" ;
    }
}

int main()
{
    matrices m ;

    m.cargar();
    m.encontrar();

    return 0 ;
}
