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
        cout << "\nIntroduce valor " << i+1 << "\n" ;
        cin >> tabla[i];
    }
}

int uno::maximo()
{
    int maxim = -999999;

    for(int i=0 ; i<M ; i++)
    {
        if(tabla[i] > maxim)
            maxim = tabla[i];
    }

    system("cls");

    cout << "el maximo es: " << maxim <<  "\n" ;

    return maxim;

}

int uno::minimo()
{
    int minim = 999999;

    for(int i=0 ; i<M ; i++)
    {
        if(tabla[i] < minim)
            minim = tabla[i];
    }

    cout << "El minimo es: " << minim ;

    return minim ;
}

int main()
{
    uno u ;

    u.cargar();
    u.maximo();
    u.minimo();

    return 0;
}
