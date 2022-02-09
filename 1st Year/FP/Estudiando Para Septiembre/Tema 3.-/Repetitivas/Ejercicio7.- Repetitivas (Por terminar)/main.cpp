#include <iostream>
#include <windows.h>

using namespace std;

class primo
{
    int n;

public:
    void cargar();
    bool esPrimo(int n);
    void ListaPrimo();
};

void primo::cargar()
{
    cout << "Introduzca un numero: " ;
    cin >> n ;
}

bool primo::esPrimo(int n)
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

void primo::ListaPrimo()
{
    int intervalomenor , intervalomayor;

   // bool encontrado = esPrimo();
//    encontrado=false;

    cout << "Introduzca intervalo (menor y mayor respectivamente) para hacer la lista de numeros primos [ , ]: " << "\n";
    cin >> intervalomenor >> intervalomayor ;

    for(int i = intervalomenor ; i<=intervalomayor ; i++)
    {
        if(esPrimo(i) == true)
            cout << i << "\t";
    }
}

int main()
{
    primo p ;

    p.cargar();

  //  p.esPrimo(int n);

    system("pause");
    system("cls");

    p.ListaPrimo();

    return 0;
}
