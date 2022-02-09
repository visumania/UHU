#include <iostream>
#include <windows.h>

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
    double f;


    f = (9000000000 * q1 * q2 )/ (r*r) ;


    return f ;

}

int main ()
{
    char letra;
    Cargas c ;

    do
    {

        c.Leer();

        if(c.Fuerza() > 0)
            cout << "F= " << c.Fuerza() << " Newtons (Repulsion)" ;
        else
            cout << "F= " << c.Fuerza() << " Newtons (Atraccion)" ;


        cout << "\nDesea volver a operar con este maravilloso programa?(s/n): ";
        cin >> letra ;
        letra = toupper(letra) ;

        system("cls");

    }while(letra=='S');

    return 0 ;
}




