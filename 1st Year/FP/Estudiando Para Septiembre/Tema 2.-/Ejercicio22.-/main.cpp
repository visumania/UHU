#include <iostream>

using namespace std;

class complejo
{
    int a , b , c , d ;

public:
    void cargar();
    void sumar();
    void restar();
    void multiplicar();
    void dividir();
};

void complejo::cargar()
{
    cout << "Introduzca la parte REAL del complejo 1: " ;
    cin >> a ;

    cout << "Introduzca la parte IMAGINARIA del complejo 1: ";
    cin >> b ;

    cout << "Introduzca la parte REAL del complejo 2: " ;
    cin >> c;

    cout << "Introduzcla la parte IMAGINARIA del complejo 2: " ;
    cin >> d;
}

void complejo::sumar()
{
    int suma1 , suma2;

    suma1 = a + c; //real
    suma2 = b + d; //imaginaria

    cout << "\n\nLa suma es (" << suma1 << " , " << suma2 << "i )" ;

}

void complejo::restar()
{
    int resta1 , resta2;

    resta1 = a - c; //real
    resta2 = b - d; //imaginaria

    cout << "\nLa resta es (" << resta1 << " , " << resta2 << "i )" ;
}

void complejo::multiplicar()
{
    int multiplicacion1 , multiplicacion2;

    multiplicacion1 = (a*c) - (b*d); //real
    multiplicacion2 = (a*d) + (b*c); //imaginaria

    cout << "\nLa multiplicacion es (" << multiplicacion1 << " , " << multiplicacion2 << "i )" ;

}

void complejo::dividir()
{
    float division1 , division2 , division3;
    float division4 , division5;

    division1 = (a*c)+(b*d);
    division2 = (b*c)-(a*d);
    division3 = (c*c)+(d*d);

    division4 = division1 / division3; //real
    division5 = division2 / division3; // imaginaria

    cout << "\nLa division es (" << division4 << " , " << division5 << "i )" ;
}

int main ()
{
    complejo cm;

    cm.cargar();
    cm.sumar();
    cm.restar();
    cm.multiplicar();
    cm.dividir();

    return 0;
}
