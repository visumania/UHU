#include <iostream>

using namespace std;

class rectangulo
{
    int largo ;
    int ancho ;

public:
    void iniciar();
    void cargar();
    int area ();
    void cambiar();
};

void rectangulo::iniciar()
{
    ancho = 2 ;
    largo = 4 ;
}

void rectangulo::cargar()
{
    cout << "Introduzca el ancho del rectangulo:" ;
    cin >> ancho ;

    cout << "Introduzca el largo del rectangulo:" ;
    cin >> largo ;
}

int rectangulo::area()
{
    int  ar ;

    ar = ancho * largo  ;

    cout << "El area del rectangulo es " << ar ;
    return ar ;
}

void rectangulo::cambiar()
{
    int v3 ;


    v3=ancho;
    ancho=largo ;
    largo=v3 ;
    cout << "\nSi intercambiamos los valores el ancho seria " << ancho << " y el largo seria " << largo ;
}

int main()
{
    rectangulo r;

    r.iniciar();
    r.cargar();
    r.area();
    r.cambiar();

    return 0;
}
