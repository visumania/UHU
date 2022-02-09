#include <iostream>

using namespace std;

int main()
{
    int valor1 , valor2;

    cout << "Introduzca los valores de dos numeros enteros: ";
    cin >> valor1 >> valor2;
    cout << endl;

    if(valor1<valor2)
        cout << valor2 << " es mayor que " << valor1;

    if(valor1>valor2)
        cout << valor1 << " es mayor que " << valor2;

    if (valor1==valor2)
        cout << "Ambos valores son iguales" ;

    return 0 ;
}
