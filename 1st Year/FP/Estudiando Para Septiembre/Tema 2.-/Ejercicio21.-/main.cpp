#include <iostream>

using namespace std;

class fracciones
{
    int a , b , c , d ;

public :
    void cargar();
    void sumar();
    void restar();
    void multiplicar();
    void dividir();
};

void fracciones::cargar()
{
    cout << "De la expresion a/b y c/d ...\n";

    cout << "\nIntroduzca el valor de a: " ;
    cin >> a;

    cout << "\nIntroduzca el varlo de b: " ;
    cin >> b;

    cout << "\nIntroduzca el valor de c: " ;
    cin >> c;

    cout << "\nIntroduzca el valor de d: " ;
    cin >> d;
}

void fracciones::sumar()
{
    int suma1 , suma2 ;

    suma1 = (a*d + b*c);

    suma2 = (b*d);

    cout << "\n\nLa suma es " << suma1 << "/" << suma2 ;

}

void fracciones::restar()
{
    int resta1 , resta2 ;

    resta1 = (a*d - b*c);

    resta2 = (b*d);

    cout << "\nLa resta es " << resta1 << "/" << resta2;

}

void fracciones::multiplicar()
{
    int multiplicacion1 , multiplicacion2;

    multiplicacion1 = (a*c);

    multiplicacion2 = (b*d);

    cout << "\nLa multiplicacion es " << multiplicacion1 << "/" << multiplicacion2;

}

void fracciones::dividir()
{
    int division1 , division2;

    division1 = (a*d);

    division2 = (b*c);

    cout << "\nLa division es " << division1 << "/" << division2;

}

int main()
{
    fracciones fr;

    fr.cargar();
    fr.sumar();
    fr.restar();
    fr.multiplicar();
    fr.dividir();

    return 0;
}
