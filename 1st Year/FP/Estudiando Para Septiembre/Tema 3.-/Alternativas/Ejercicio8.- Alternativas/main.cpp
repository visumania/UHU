#include <iostream>
#include <windows.h>

using namespace std;

#define E0 0.00000000000885
#define pi 3.141592

class CampoElec
{
    float carga , distancia;

public:
    void Leer();
    double Intensidad();
};

void CampoElec::Leer()
{
    cout << "Introduzca el valor de la carga: " ;
    cin >> carga;

    int opcioncarga;

    cout << "1.- Miliculombios (mC)";
    cout << "\n2.- Microculombios (uC)";
    cout << "\n3.- Nanoculombios (nC)";
    cout << "\nElija unidad en la que desea introducir la carga: ";
    cin >> opcioncarga;

    switch (opcioncarga) // pasar a culombio
    {
    case 1:
        {
             carga = carga * 0.001;
        }
        break;

    case 2:
        {
            carga = carga * 0.000001;
        }
        break;

    case 3:
        {
            carga = carga * 0.000000001;
        }

        break;

    default:
        {

            carga = carga * 0.000001;

            system("pause");

        }
    }

    system("cls");

    cout << "\nIntroduzca el valor de la distancia: " ;
    cin >> distancia;

    int opciondistancia;//  pasar a metros

    cout << "1.-Decimetros (dm)\n";
    cout << "2.-Centimetros (cm)\n";
    cout << "3.-Milimetros (mm)\n";
    cout << "\nElija unidad en la que quiere intoducir la distancia: ";
    cin >> opciondistancia;

    switch(opciondistancia)
    {
    case 1:
        {
            distancia = distancia * 0.1 ;
        }
        break;

    case 2:
        {
            distancia = distancia * 0.01;
        }
        break;

    case 3:
        {
            distancia = distancia * 0.001;
        }
        break;

    default:
        {
            distancia = distancia * 1 ;
        }
    }



}

double CampoElec::Intensidad()
{

    double intensidadcampo;

    intensidadcampo = carga / (4 * pi * E0 * distancia * distancia);

    cout << "\n\nE = " << intensidadcampo << " N/C \n";

    return intensidadcampo;
}

int main()
{
    CampoElec ce ;

    ce.Leer();
    ce.Intensidad();
}
