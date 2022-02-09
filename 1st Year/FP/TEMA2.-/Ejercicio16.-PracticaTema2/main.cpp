#include <iostream>

using namespace std;

//Este ejercicio se hace con el resto (módulo) [%] entre 2 números

int main()
{
    int horas , minutos , segundos ;
    int seg ;
    int cocienteminutos , cocientehoras ;
    cout << "Introduzca una cantidad de segundos:\n" ;
    cin >> seg ;

    segundos = seg % 60 ;
    cocienteminutos = seg / 60 ;

    minutos = cocienteminutos % 60 ;
    horas = cocienteminutos / 60 ;
    cout << "La cantidad introducida de segundos equivale a: "
         << horas << " horas, "
         << minutos << " minutos y "
         << segundos << "  segundos " ;


    return 0 ;




}
