#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    float euros ;

    cout << "Introduzca una cantidad monetaria en euros para hacer la conversion: ";
    cin >> euros ;

    float dolar = euros * 1.17 ;
    float libra = euros * 0.88 ;

    system("cls");

    cout << euros << " euros corresponden a " << dolar << " dolares y a " << libra << " libras \n" ;

    return 0 ;
}
