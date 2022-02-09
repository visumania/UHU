#include <iostream>

using namespace std;

class fracciones
{
    float  a , b , c , d ;

public:
    void pedirdatos();
    void calculardatosymostrarlos();
};

void fracciones::pedirdatos()
{
    cout << "Introduzca el valor de a: " ;
    cin >> a ;

    cout << "Introduzca el valor de b: " ;
    cin >> b ;

    cout << "Introduzca el valor de c: " ;
    cin >> c ;

    cout << "Introduzca el valor de d: " ;
    cin >> d ;
}

void fracciones::calculardatosymostrarlos()
{
    float suma1 , suma2 ;
    float resta1 , resta2 ;
    float multiplicacion1 , multiplicacion2 ;
    float division1 , division2 ;

    suma1 = (a*d + b*c);
    suma2 =(b*d);

    resta1 = (a*d - b*c);
    resta2 =(b*d);

    multiplicacion1 = (a*c);
    multiplicacion2 =(b*d) ;

    division1 = (a*d);
    division2= (b*c) ;


    cout << "La suma es " << suma1 << "/" << suma2 ;
    cout << "La resta es " << resta1 << "/" << resta2 ;
    cout << "El producto es " << multiplicacion1 << "/" << multiplicacion2  ;
    cout << "La division es " << division1 << "/" << division2 ;
}

int main()
{
    fracciones f ;

    f.pedirdatos();
    f.calculardatosymostrarlos();

    return 0 ;
}
