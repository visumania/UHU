#include <iostream>
#include <windows.h>

using namespace std;

class Fibonacci
{
    int NoElementos;

public:
    void PedirNoElementos();
    float MostrarElementos();
};

void Fibonacci::PedirNoElementos()
{
    do
    {
        cout << "Introduzca el numero de elementos a mostrar en la secuencia de Fibonacci: " ;
        cin >> NoElementos ;

        if(NoElementos<1)
        {
            cout << "Error, el valor no puede ser menor que 1\n";

            system("pause");
        }
    }while(NoElementos<1);
}

float Fibonacci::MostrarElementos()
{
    float fibo = 0 ;
    int a = 0 ;
    int b = 1 ;

    for(int i=0 ; i<NoElementos ; i++)
    {
        if(i+1==1)
            cout << i+1 << " | 0" << "\n";
        else
        {
            fibo = a + b ;
            cout << i+1 << " | " << fibo << "\n";

            b=a ;
            a=fibo ;
        }
    }

    return fibo;
}

int main()
{
    Fibonacci fi;

    fi.PedirNoElementos();
    fi.MostrarElementos();

    return 0;
}
