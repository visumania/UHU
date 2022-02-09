#include <iostream>
#include <windows.h>

using namespace std;

#define pi 3.1415926

int main()
{
    float radio ;

    cout << "Introduce el radio (en metro/s) para hallar la longitud , superficie y volumen: \n" ;
    cin >> radio ;

    system("cls") ;

    float longitud , superficie , volumen ;

    longitud = 2 * pi * radio ;
    superficie = pi * radio * radio ;
    volumen = (4 * pi * radio * radio * radio) / 3 ;

    cout << "La longitud de la circunferencia es " << longitud << " metros\n" ;
    cout << "la superficie es " << superficie << " metros cuadrados\n" ;
    cout << "y el valor del volumen es " << volumen << " metros cubicos \n" ;

    return 0;

}
