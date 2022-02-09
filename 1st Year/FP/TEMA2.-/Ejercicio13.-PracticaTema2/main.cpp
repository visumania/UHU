#include <iostream>
#include <math.h>

using namespace std;

int main ()
{


float a , b , c ;
float dentroraiz , raizcuadrada , raiz1 , raiz2 ;

cout << "Introduzca el valor de la variable a:\n" ;
cin >> a ;

cout << "Introduzca el valor de la variable b:\n" ;
cin >> b ;

cout << "Introduzca el valor de la variable c:\n" ;
cin >> c ;

dentroraiz = ((b*b)- 4*a*c) ;

if (dentroraiz <0)
    cout << "\nNo existen raices reales para esta ecuacion " ;
else
{
    raizcuadrada = sqrt(dentroraiz) ;
    raiz1 = ((-b + raizcuadrada)/2*a) ;
    raiz2 = ((-b - raizcuadrada)/2*a);

    if (raiz1 == raiz2)
        cout << raiz1;

    cout << "Solucion 1: " << raiz1 << "\n" ;
    cout << "Solucion 2: " << raiz2 << "\n" ;
}
return 0;
}
