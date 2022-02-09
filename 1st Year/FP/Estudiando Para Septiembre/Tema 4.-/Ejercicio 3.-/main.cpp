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
    void visualizar();
};

void tres::cargar()
{
    for(int i=0 ; i<M ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            tabla[i][j] = (i+1)*(j+1);
        }
    }
}

int tres::encontrar()
{
    int numero;

    cout << "Introduzca numero a encontrar en la tabla: ";
    cin >> numero;

    int a ;
    bool encontrado ;

    a = 0;
    encontrado = false;

    while(a<M && !encontrado)
    {
        int b;
        b=0;

        while(b<N && !encontrado)
        {
            if(tabla[a][b]==numero)
                encontrado = true;
            else
                b++;
        }

        if(!encontrado)
            a++;
    }

    if(encontrado)
    {
        cout << "\n1\n";

        return 1;
    }
    else
    {
        cout << "\n0\n";

        return 0;

    }
}

void tres::visualizar()
{
    system("pause");
    system("cls");

    char caracter ;

    cout << "¿Desea visualizar la tabla de productos de indices ?(s/n) ";
    cin >> caracter;

    if(caracter=='s')
    {
        for(int i=0 ; i<M ; i++)
        {
            for(int j=0 ; j<N ; j++)
            {
                cout << tabla[i][j] << "\t";
            }
        }
    }

    if(caracter=='n')
        cout << "\nNo se mostrara la tabla , gracias por usar el programa \n";
}

int main()
{
    tres tr ;

    tr.cargar();
    tr.encontrar();
    tr.visualizar();

    return 0;
}
