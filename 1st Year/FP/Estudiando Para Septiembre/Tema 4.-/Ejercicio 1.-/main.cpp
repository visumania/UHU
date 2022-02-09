#include <iostream>
#include <windows.h>

using namespace std;

#define M 10

class uno
{
    int tabla[M];

public:
    void cargar();
    int maximo();
    int minimo();
};
void uno::cargar()
{
    for(int i=0 ; i<M ; i++)
    {
        cout << "Introduzca valor " << i+1 << ": " ;
        cin >> tabla[i];
    }
}

int uno::maximo()
{
    int numeromaximo = -9999999;

    for(int i=0 ; i<M ; i++)
    {
        if(tabla[i] > numeromaximo)
            numeromaximo = tabla[i];
    }

    cout << "El numero maximo es el " << numeromaximo << "\n" ;

    return numeromaximo;
}

int uno::minimo()
{
    int numerominimo = 9999999;

    for(int i=0 ; i<M ; i++)
    {
        if(tabla[i] < numerominimo)
            numerominimo = tabla[i];
    }

    cout << "El numero minimo es el " << numerominimo << "\n";

    return numerominimo;
}

int main()
{
    uno u ;

    u.cargar();

    system("cls");

    u.maximo();
    u.minimo();

    return 0;
}
