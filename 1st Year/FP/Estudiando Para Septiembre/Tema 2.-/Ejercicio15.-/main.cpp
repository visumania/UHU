#include <iostream>

using namespace std;

int main()
{
   float a , b , c , d , e , f ;
   float x , y ;

   cout << "Introduzca el valor del termino a: " ;
   cin >> a ;

   cout << "Introduzca el valor del termino b: " ;
   cin >> b ;

   cout << "Introduzca el valor del termino c: " ;
   cin >> c ;

   cout << "Introduzca el valor del termino d: " ;
   cin >> d ;

   cout << "Introduzca el valor del termino e: " ;
   cin >> e ;

   cout << "Introduzca el valor del termino f: " ;
   cin >> f ;

   x = (c*e - b*f) / (a*e - b*d);

   y = (a*f - c*d) / (a*e - b*d);

   cout << "\nx = " << x ;

   cout << "\ny = " << y ;

   return 0 ;
}
