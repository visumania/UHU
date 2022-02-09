#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

#define M 3
#define N 4

typedef char cadena[30];

class cuatro
{
    cadena tabla[M][N];

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
            cout << "Introduzca palabra [" << i+1 << " , " << j+1 << "]: ";
            cin >> tabla[i][j];
        }
    }
}

void cuatro::encontrar()
{
    system("cls");

    cadena leida ;

    cout << "Introduzca la palabra a buscar en la tabla de elementos: " ;
    cin >> leida ;

    int i ;
    int j;
    bool encontrado ;

    i = 0 ;
    encontrado = false ;

    while(i<M && !encontrado)
    {
        j=0 ;

        while(j<N && !encontrado)
        {
            if(strcmp(leida , tabla[i][j])==0)
                encontrado = true ;
            else
                j++;
        }

        if(!encontrado)
            i++;
    }

    if(encontrado)
    {
        cout << "\nSe ha encontrado la palabra en la posicion [" << i+1 << " , " << j+1 << "]";
    }
    else
        cout << "\nNo se ha encontrado la palabra en niguna posicion\n";
}

int main()
{
    cuatro ctr ;

    ctr.cargar();
    ctr.encontrar();

    return 0;
}
