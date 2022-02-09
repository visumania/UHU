#include <iostream>

using namespace std;

#define E0 0.00000000000885
#define pi 3.141592

class CampoElec
{
    float carga , distancia; //q (microculombios) r (metros)

public:
    void Leer();
    double Intensidad();
};

void CampoElec::Leer()
{
    cout << "Introduzca el valor de la carga (microculombios): " ;
    cin >> carga;

    cout << "\nIntroduzca el valor de la distancia (metros): " ;
    cin >> distancia;
}

double CampoElec::Intensidad()
{
    float q ; //Conversion de la carga de microculombio a culombio

    q = carga * 0.000001;

    double intensidadcampo;

    intensidadcampo = q / (4 * pi * E0 * distancia * distancia);

    cout << "\n\nE = " << intensidadcampo << " N/C \n";

    return intensidadcampo;
}

int main()
{
    CampoElec ce ;

    ce.Leer();
    ce.Intensidad();
}
