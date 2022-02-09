#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    float numero1 , numero2;

    cout << "Introduzca los numeros con los que quieras realizar los calculos: \n" ;
    cin >> numero1 >> numero2 ;

    system("cls") ;

    cout << "Suma: " << numero1 << " + " << numero2 << " = " << numero1 + numero2;

    cout << "\nResta: " << numero1 << " - " << numero2 << " = " << numero1 - numero2 ;

    cout << "\nMultiplicacion: " << numero1 << " * " << numero2 << " = " << numero1 * numero2 ;

    cout << "\nDivision: " << numero1 << " / " << numero2 << " = " << numero1 / numero2 << "\n" ;

    return 0 ;
}
