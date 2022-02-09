#include <iostream>

using namespace std;

class primo
{
    int n ;
public:
    void cargar();
    bool esPrimo();
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
            cout << "No es primo" ;
        }
        else
        {
            encontrado=true ;
            cout << "Es primo" ;
        }
}

int main()
{
    primo p ;

    p.cargar();
    p.esPrimo();

    return 0 ;
}
