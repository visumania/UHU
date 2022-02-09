#include <iostream>

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
        cout << "Introduzca el numero de elementos de la secuencia de Fibonacci: " ;
        cin >> NoElementos ;

    }while(NoElementos<0);


}

float Fibonacci::MostrarElementos()
{
    int fibo = 0 ;
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
}

int main()
{
    Fibonacci f ;

    f.PedirNoElementos();
    f.MostrarElementos();

    return 0;
}
