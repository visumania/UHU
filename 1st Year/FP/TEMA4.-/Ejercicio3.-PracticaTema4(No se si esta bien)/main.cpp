#include <iostream>
#include <windows.h>

using namespace std;

#define M 10
#define N 15

class tres
{
    int tabla[M][N];

public:
    void cargar();
    int encontrar();
};

void tres::cargar()
{
    for(int i=0 ; i<M ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            tabla[i][j] = i*j;
        }
    }
}

int tres::encontrar()
{
    bool encontrado = false ;

    int leida ;

    cout << "Introduzca un numero entero para buscar en la tabla: " ;
    cin >> leida ;

    int i=0 ;
    while((i<M) && !encontrado)
    {
        int j=0 ;
        while((j<N) && !encontrado)
        {
            if(tabla[i][j]== leida)
                encontrado=true ;
            else
                j++;
        }
        if(!encontrado)
        i++;
    }

    system("cls");

    if(encontrado==true)
    {
        cout << "1\n" ;
    }
    else
    {
        cout << "0\n" ;
    }

    for(int i=0 ; i<M ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cout << tabla[i][j] << "\t" ;
        }
    }


    return encontrado ;
}

int main()
{
    tres t ;

    t.cargar();
    t.encontrar();

    return 0 ;
}
