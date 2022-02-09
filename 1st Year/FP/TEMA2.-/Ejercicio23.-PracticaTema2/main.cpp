#include <iostream>

using namespace std;

class Cargas
{
    float q1 , q2 , r ;
public :
    void Leer();
    double Fuerza ();
};

void Cargas::Leer()
{

    cout << "Introduzca el valor de q1:" ;
    cin >> q1 ;
    q1= q1 * 0.000001 ;

    cout << "Introduzca el valor de q2:" ;
    cin >> q2;
    q2= q2 * 0.000001 ;

    cout << "Introduzca la distancia entre las dos cargas:" ;
    cin >> r ;
}

double Cargas::Fuerza()
{
    double f ;


    f = (9000000000 * q1 * q2 )/ (r*r) ;

    cout << "F= " << f << " Newtons" ;

    return f ;

}

int main ()
{
    Cargas c ;

    c.Leer();
    c.Fuerza();

    return 0 ;
}



