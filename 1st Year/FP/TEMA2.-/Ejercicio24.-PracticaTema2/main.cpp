#include <iostream>
#include <math.h>

using namespace std;

class CampoElec
{
    float q , r ;//La q tiene que ser en microculomnios y la r en metros

public:
    void Leer();
    double Intensidad();
};

void CampoElec::Leer()
{
    cout << "Introduzca el valor de la carga en microculombios: " ;
    cin >> q ;


    cout << "Introduzca el valor de la distancia en metros: " ;
    cin >> r;
}

double CampoElec::Intensidad()
{
    float pi=3.14159265359 ;
    float Epsilon = 0.00000000000885 ;
    float E ;
    q = q * 0.000001;
    E = q /(4* pi * Epsilon * r * r);

    cout << "La intensidad del campo es: " << E ;
}

int main ()
{
    CampoElec e ;

    e.Leer ();
    e.Intensidad();

    return 0;
}
