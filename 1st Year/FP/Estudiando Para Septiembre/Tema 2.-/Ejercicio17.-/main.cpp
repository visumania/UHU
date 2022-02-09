#include <iostream>

using namespace std;

int main()
{
    int longitud ;

    cout << "Introduzca la longitud de la carretera que desea arreglar (metros): ";
    cin >> longitud;

    float preciocondecimal , preciosindecimal ;

    preciosindecimal = 5000 * (longitud / 5280);

    preciocondecimal = 5000 * (longitud / 5280.0);

    if (preciocondecimal == preciosindecimal)
        cout << "El resultado NO varia en nada ";
    else
    {
        cout << "El resultado SI varia\n" ;
        cout << "El precio sin decimal es " << preciosindecimal ;
        cout << "\nEl precio con decimal es " << preciocondecimal ;
    }

    return 0 ;
}
