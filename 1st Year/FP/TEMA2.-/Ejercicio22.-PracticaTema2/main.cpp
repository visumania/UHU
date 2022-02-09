#include <iostream>

using namespace std;

class complejo
{
    float a, b , c ,d ;
public:
    void pedirdatos();
    void calculardatosymostrarlos();
};

void complejo::pedirdatos()
{
    cout << "Vamos a hacer una serie de operaciones con numeros complejos :)\n " ;

    cout << "Introduzca la parte real del primer complejo: " ;
    cin >> a ;
    cout << "Introduzca la parte imaginaria del primer complejo: " ;
    cin >> b; cout << "\n" ;

    cout << "Introduzca la parte real del segundo complejo: " ;
    cin >> c ;
    cout << "Introduzca la parte imaginaria del segundo complejo: " ;
    cin >> d ;
}

void complejo::calculardatosymostrarlos()
{
    int suma1 , suma2 ;
    int resta1 , resta2 ;
    int multiplicacion1 ,  multiplicacion2 ;
    float division1 , division2 ;

    suma1 = a + c ;
    suma2 = b + d ;

    resta1 = a - c ;
    resta2 = b - d ;

    multiplicacion1 = a*c-b*d ;
    multiplicacion2 = a*d + b*c ;

    division1 = (a*c + b*d) / (c*c + d*d) ;
    division2 = (b*c - a*d) / (c*c + d*d) ;

    cout << "Suma:(" << suma1 << " , i " << suma2 << ")" << "\n" ;
    cout << "Resta:(" << resta1 << " ,i " << resta2 << ")" << "\n" ;
    cout << "Multiplicacion:(" << multiplicacion1 << " ,i " << multiplicacion2 << ")" << "\n" ;
    cout << "Division:(" << division1 << " ,i " << division2 << ")" << "\n" ;
}

int main()
{
    complejo c ;

    c.pedirdatos();
    c.calculardatosymostrarlos();

    return 0 ;
}
