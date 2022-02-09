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

public:
    void cargar();//Pondrá en cada elemento de la tabla una palabra leída desde teclado
    void encontrar();//Pedirá una palabra por teclado y mostrará por pantalla si esa palabra está o no en la tabla y en qué fila y columna se encuentra
};

void cuatro::cargar()
{
    for(int i=0 ; i<M ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cout << "Introduzca palabra de la posicion " << i+1 << "." << j+1 << ":\n";
            cin >> tabla[i][j];
        }
    }
}

void cuatro::encontrar()
{
    int i , j ;
    char palabra[30];

    system("cls");

    cout << "Introduzca la palabra que desea buscar: " ;
    cin >> palabra ;

    bool encontrado=false ;

    i=0 ;

    while(i<M && !encontrado)
    {
        j=0;
        while(j<N && !encontrado)
        {
            if(strcmp(tabla[i][j] , palabra)==0)
            {
                encontrado = true ;
            }
            else
                j++;
        }
        if(!encontrado)
            i++;
    }
    if(encontrado)
        cout << "\nSe encontro la palabra en la posicion " << i+1 << "." << j+1 ;
    else
        cout << "\nNo se encontro la palabra en ninguna posicion" ;
}

int main()
{
    cuatro c ;

    c.cargar();
    c.encontrar();

    return 0;
}
