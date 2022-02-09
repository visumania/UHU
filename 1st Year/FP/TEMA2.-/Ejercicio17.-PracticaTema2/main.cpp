#include <iostream>

using namespace std;

int main()
{
    int longitud_en_metros ;
    float precio_total_en_euros ;

    cout << "Introduzca los metros de carretera que desee arreglar: " ;
    cin >> longitud_en_metros ;

    precio_total_en_euros = 5000 * (longitud_en_metros / 5280.0);

    cout << "El precio total en euros es de:\n" << precio_total_en_euros << " euros";

    return 0;


}
// La asignacion 1 es la correcta ya que al poner 5280.0
// estas indicando que vas a usar con los decimales . En el
// otro caso como el numero es redondo , pues redondea con
// los resultados tambien .
