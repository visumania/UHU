#include <iostream>

using namespace std;

int main()
{
    int valor1 , valor2 , valor3;

    cout << "Introduzca los dos valores a intercambiar: " ;
    cin >> valor1 >> valor2;

    cout << "El valor 1 es " << valor1 << "\n" ;
    cout << "El valor 2 es " << valor2 << "\n\n" ;

    valor3=valor1;
    valor1=valor2;
    valor2=valor3;

    cout << "El nuevo valor 1 es " << valor1 << "\n" ;
    cout << "El nuevo valor 2 es " << valor2 << "\n" ;

    return 0;

}
