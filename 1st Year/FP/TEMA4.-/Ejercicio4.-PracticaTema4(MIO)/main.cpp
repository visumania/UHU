#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

#define M 3
#define N 4

typedef char cadena[30];

class cuatro
{
    cadena tabla[M][N];
    cadena leida ;

public:
    void cargar();
    void encontrar();
};

void cuatro::cargar()
{
    for(int i=0 ; i<M ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cout << "Introduzca la palabra de la posicion " << i+1 << "." << j+1 << ".-" ;
            cin >> tabla[i][j];
        }
    }
}

void cuatro::encontrar()
{

    bool encontrado = false;
    int i ;
    int j ;
    cout << "Introduzca la palabra a buscar: " ;
    cin >> leida ;

    i=0;
    while(i<M && !encontrado)
    {
        j=0;
        while(j<N && !encontrado)
        {
            if (strcmp(tabla[i][j] , leida)==0)
            {
                 encontrado=true ;
            }
            else j++ ;
        }

        if(!encontrado)
            i++;
    }

    system("cls");

    if(encontrado)
    {
        cout << "Se encontro en la posicion " << i+1 << "." << j+1 ;
    }
    else
    {
        cout << "No se encontro en ninguna posicion";
    }
}

int main()
{
    cuatro c ;

    c.cargar();
    c.encontrar();

    return 0 ;
}
