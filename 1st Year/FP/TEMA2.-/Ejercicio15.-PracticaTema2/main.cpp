#include <iostream>

using namespace std;

int main()
{
    float a , b , c , d , e , f ;
    float x , y ;

    cout << "Vamos a resolver un sistema de ecuacion lineal. " << "Para ello , introduzca los terminos a , b , c de la primera ecuacion:\n " ;
    cout << "Termino a:\n " ;
    cin >> a ;
    cout << "Termino b:\n " ;
    cin >> b ;
    cout << "Termino c:\n " ;
    cin >> c;

    cout << "Ahora introduzca los terminos d , e , f pertenecientes a la segunda ecuacion:\n " ;
    cout << "Termino d: \n" ;
    cin >> d ;
    cout << "Termino e:\n" ;
    cin >> e ;
    cout << "Termino f:\n" ;
    cin >> f ;

    x = ((c*e)-(b*f))/((a*e)-(b*d)) ;
    y = ((a*f)-(c*d))/((a*e)-(b*d));

    cout << "El valor del termino x es: " << x ;
    cout << " El valor del termino y es: " << y ;

    return 0;

}
