#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a , b , c ;
    float raizcuadrada , dentroraiz , raiz1 , raiz2;

    cout << "Introduzca el valor del termino a:\n";
    cin >> a ;

    cout << "Introduzca el valor del termino b:\n";
    cin >> b ;

    cout << "Introduzca el valor del termino c:\n";
    cin >> c;

    dentroraiz = ((b*b)-(4*a*c));

    if(dentroraiz < 0)
    {
        cout << "No existe solucion\n";
    }
    else
    {
        raizcuadrada = sqrt(dentroraiz);

        raiz1 = (-b + raizcuadrada) / (2*a);
        raiz2 = (-b - raizcuadrada) / (2*a);
    }

    cout << "Solucion 1: " << raiz1 << "\n" ;
    cout << "Solucion 2: " << raiz2 << "\n" ;

    return 0 ;
}
