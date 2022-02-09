#include <iostream>

using namespace std;
int main ()
{


int euros ;

    cout << "Introduzca cantidad de dinero en euros " ;
    cin >>  euros ;

    const float dolares = euros * 1.16 ;
    const float libras = euros * 0.89 ;

    cout << "La cantidad introducida corresponde a " <<  dolares << "dolares " << "\n" ;
    cout << "La cantidad introducida corresponde a " << libras << "libras " << " \n";
    return 0;
}
