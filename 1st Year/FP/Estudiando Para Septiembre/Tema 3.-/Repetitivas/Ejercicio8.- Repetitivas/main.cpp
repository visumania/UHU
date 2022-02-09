#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

class ejercicio
{
    int numero ;

public:
    void informacion();
    long factorial();
};

void ejercicio::informacion()
{
    do
    {
        system("cls");

        cout << "Introduzca un numero positivo menor que 20: " ;
        cin >> numero ;

        if(0<numero && numero<20)
        {
            cout << "\nCalculando el factorial...\n" ;
            system("pause");
        }
        else
        {
            cout << "\nError\n";
            system("pause");
        }

    }while(0>=numero ||numero>=20);
}

long ejercicio::factorial()
{
    long entero = numero ;

    for(int i=numero-1 ; i>0 ; i--)
    {
        entero = entero * i ;
    }

    cout << "\nEl factorial de " << numero << " es " << entero;

    return entero ;
}

int main()
{
    ejercicio ft ;

    ft.informacion() ;
    system("cls");
    ft.factorial();

    return 0;
}
