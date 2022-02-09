#include <iostream>

using namespace std;

class rectangulo
{
    int largo ;
    int ancho;

public:
    void iniciar();
    void cargar();
    int area();
    void cambiar();
};

void rectangulo::iniciar()
{
    ancho = 2;
    largo = 4;
}

void rectangulo::cargar()
{
    cout << "Introduzca el largo del rectangulo: " ;
    cin >> largo ;

    cout << "Introduzca el ancho del rectangulo: ";
    cin >> ancho ;
}

int rectangulo::area()
{
    int arearectangulo;

    arearectangulo = largo * ancho ;

    cout << "El area del rectangulo es " << arearectangulo ;

    return arearectangulo;
}

void rectangulo::cambiar()
{
    int aux ;

    aux = largo ;
    largo = ancho ;
    ancho = aux ;

    cout << "\nUna vez intercambiados los valores, ahora el ancho es " << ancho << " y el largo es " << largo ;
}

int main()
{
    rectangulo rect ;

    rect.iniciar();
    rect.cargar();
    rect.area();
    rect.cambiar();

    return 0;
}
