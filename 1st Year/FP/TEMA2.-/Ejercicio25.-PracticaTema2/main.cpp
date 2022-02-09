#include <iostream>

using namespace std;

class Energia
{
    int m ;
    float v , h ;
public :
    void Leer();
    float ECinetica();
    float EPotencial();
};

void Energia::Leer()
{
    cout << "Introduzca el valor de la masa: " ;
    cin >> m ;

    cout << "Introduzca el valor de la velocidad: " ;
    cin >> v ;
    v= v * 0.27778 ;


    cout << "Introduzca el valor de la altura: " ;
    cin >> h ;
    h = h *1000 ;
}

float Energia::ECinetica()
{
    float ec ;

    ec = 0.5 * m * v * v ;

    return ec ;
}

float Energia::EPotencial()
{
    float ep ;

    ep = m * 9.8 * h ;

    return ep ;
}

int main ()
{
    Energia e ;

    e.Leer();
    e.ECinetica();
    e.EPotencial();

    cout << "Energia cinetica: " << e.ECinetica() << "\n" ;
    cout << "Energia potencial: " << e.EPotencial() << "\n" ;

    float em = e.ECinetica() + e.EPotencial() ;

    cout << "Energia mecanica: " << em ;



    return 0 ;
}
