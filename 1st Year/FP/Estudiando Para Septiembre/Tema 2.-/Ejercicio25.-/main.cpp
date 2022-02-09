#include <iostream>

using namespace std;

#define g 9.8

class Energia
{
    float masa , velocidad , altura; // m (kg) v (m/s) h (m)
    float potencial , cinetica;

public:
    void Leer();
    float ECinetica();
    float EPotencial();
};

void Energia::Leer()
{
    cout << "Introduzca el valor de la masa (Kg): " ;
    cin >> masa ;

    cout << "\nIntroduzca el valor de la velocidad (Km/h): " ;
    cin >> velocidad ;

    cout << "\nIntroduzca el valor de la altura (Km): " ;
    cin >> altura ;
}

float Energia::ECinetica()
{
    float v ;

    v = velocidad * 0.277778  ; // Porque 1 km/h = 0.277778 m/s

    cinetica = 0.5 * masa * v * v ;

    cout << "\n\nLa energia cinetica es de " << cinetica << " J \n" ;

    return cinetica ;
}

float Energia::EPotencial()
{
    float h ;

    h = altura * 1000;

    potencial = masa * g * h ;

    cout << "\nLa energia potencial es de " << potencial << " J\n" ;

    float mecanica ;

    mecanica = potencial + cinetica ;

    cout << "\nLa energia mecanica es " << mecanica << " J\n" ;

    return potencial ;
}

int main ()
{
    Energia e ;

    e.Leer();
    e.ECinetica();
    e.EPotencial();



    return 0 ;
}
