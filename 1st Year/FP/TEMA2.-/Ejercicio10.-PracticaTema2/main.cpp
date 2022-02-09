#include <iostream>

using namespace std;


int main ()
{



float longitud ;
float superficie ;
float volumen ;

int radio ;

const float pi = 3.141592653589793 ;

    cout << " introduzca el radio " ;
    cin >> radio ;

    longitud = 2 * pi * radio ;
    superficie = pi * radio*radio ;
    volumen = 4 * pi * radio*radio*radio / 3 ;

    cout << " La longitud es " << longitud ;
    cout << " La superficie es " << superficie ;
    cout << " El volumen es " << volumen ;


    return 0;
}
