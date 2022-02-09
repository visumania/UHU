#include <iostream>
//#include <windows.h>

using namespace std;

class CampoElec
{
     float q , Q;
    int unidad ;

    float r , R;
    int unidad1 ;


public:
    void Leer();
    double Intensidad();
};

void CampoElec::Leer()
{
   float s , S;
    int unidad ;

    cout << "Introduce el valor de la carga q: " ;
    cin >> s ;

    cout << "Seleccione la unidad de la carga introducida:\n1.- Miliculombios\n2.- Microculombios\n3.- Nanoculombios: ";
    cin >> unidad ;

    switch (unidad)
    {
        case 1: S = s * 0.001;
               break ;
        case 2: S = s * 0.000001;
               break ;
        case 3: S = s * 0.000000001;
               break ;
        default : cout << " error de conversion " ;
                  S = 0 ;
    }

    cout << "q = " << S << " culombios\n" ;

    //cout << system("pause") << "\n" ;


    // Mismo menu pero con la distancia

     float t , T;
    int unidad1 ;

    cout << "Introduce el valor de la distancia r: " ;
    cin >> t ;

    cout << "Seleccione la unidad de la distancia introducida:\n1.- Decimetros\n2.- Centimetros\n3.- Milimetros :";
    cin >> unidad1 ;

    switch (unidad1)
    {
        case 1: T = t * 0.1;
               break ;
        case 2: T = t * 0.01;
               break ;
        case 3: T = t * 0.001;
               break ;
        default : cout << " error de conversion " ;
                 T = 0 ;
    }

    cout << "r = " << T << " metros\n" ;

}

double CampoElec::Intensidad()
{
    float pi = 3.1415 ;
    float Epsilon = 0.00000000000885 ;
    float E ;

    E = S /(4* pi * Epsilon * T * T);

    cout << "La intensidad del campo es: " << E << " N/C" ;

    return 0;
}

int main ()
{
    CampoElec e ;

    e.Leer ();
    e.Intensidad();

    return 0;
}
