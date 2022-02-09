#include <iostream>

using namespace std;

int main()
{
    float centigrados ;

    cout << "Introduzca la temperatura en grado centrigrados: \n" ;
    cin >> centigrados ;

    float farenheit;

    farenheit = 1.8 * centigrados + 32 ;

    cout << "\n" << centigrados << " grados centigrados corresponden a " << farenheit << " grados farenheit\n" ;

    return 0 ;
}
