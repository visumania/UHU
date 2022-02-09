#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a , b , c ;

    cout << "Vamos a resolver una ecuacion de segundo grado, para ello ...\n ";

    cout << "Introduzca el valor a: " ;
    cin >> a ;

    cout << "\nIntroduzca el valor b:" ;
    cin >> b ;

    cout << "\nIntroduzca el valor c:" ;
    cin >> c ;

    double dentroraiz , raizcuadrada;

    dentroraiz = (b*b - 4*a*c);

    raizcuadrada = sqrt(dentroraiz);

    float raiz1 , raiz2;

    raiz1 = (-b + raizcuadrada)/(2*a);
    raiz2 = (-b - raizcuadrada)/(2*a);

    cout << "\n\nSolucion 1: " << raiz1 ;
    cout << "\nSolucion 2: " << raiz2 << endl ;


}
