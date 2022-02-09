#include <iostream>
#include <math.h>

using namespace std;

int main()
{
   int a , b , c ;

   cout << "Introduzca los terminos de la ecuacion de segundo grado:\n ";

   cout << "Termino a: ";
   cin >> a ;

   cout << "Termino b: " ;
   cin >> b ;

   cout << "Termino c: " ;
   cin >> c ;

   float raiz1 , raiz2 ;

   raiz1 = (-b + sqrt(b*b - 4*a*c))/2*a ;
   raiz2= (-b - sqrt(b*b - 4*a*c))/2*a ;

   cout << "Solucion 1: " << raiz1 << "\n" ;
   cout << "Solucion 2 : " << raiz2 << "\n" ;
}
