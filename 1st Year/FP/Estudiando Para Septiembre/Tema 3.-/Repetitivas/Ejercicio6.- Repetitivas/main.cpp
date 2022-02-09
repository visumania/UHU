#include <iostream>

using namespace std;

class primo
{
    int n;

public:
    void cargar();
    bool esPrimo();
};

void primo::cargar()
{
    cout << "Introduzca un numero: " ;
    cin >> n ;
}

bool primo::esPrimo()
{
    bool encontrado = false;
    int contadorprimo = 0 , contadornoprimo = 0;

        for(int i=1 ; i<=n ; i++)
        {
            if((n%i) ==0)
                contadornoprimo++;
            else
                contadorprimo++;
        }

    if(contadornoprimo>2)
    {
        cout << "\nEl numero NO es primo\n";
        encontrado=false;
    }
    else
    {
        cout << "\nEl numero SI es primo\n";
        encontrado = true;
    }

    return encontrado ;
}

int main()
{
    primo p ;

    p.cargar();
    p.esPrimo();

    return 0;
}
