#include <iostream>
#include <windows.h>

using namespace std;

class primo
{
    int n ;
public:
    void cargar();
    bool esPrimo();
    void ListaPrimos();
};

void primo::cargar()
{
    cout << "Introduzca un numero entero: " ;
    cin >> n ;
}

bool primo::esPrimo()
{
    bool encontrado ;
    encontrado=false ;


        if((n%2)==0)
        {
            encontrado=false;
            cout << "No es primo\n" ;
        }
        else
        {
            encontrado=true ;
            cout << "Es primo\n" ;
        }

        system("pause");
}

void primo::ListaPrimos()
{
    system("cls");

    cout << "Lista de primos del 1 al 100\n" ;

    for(int i=1 ; i<101 ; i++)
    {
        if((i%2)!=0)
        {
            cout << i << "\t" ;
        }
    }
}

int main()
{
    primo p ;

    p.cargar();
    p.esPrimo();
    p.ListaPrimos();

    return 0 ;
}
