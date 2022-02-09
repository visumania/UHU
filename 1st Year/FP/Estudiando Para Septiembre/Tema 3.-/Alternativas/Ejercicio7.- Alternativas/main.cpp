#include <iostream>

using namespace std;

class billete
{
    int distancia , dias , edad;

public:
    void informacion();
    void operacion();
};

void billete::informacion()
{
    cout << "Introduzca la distancia del viaje(Km): ";
    cin >> distancia;

    cout << "\nIntroduzca la duracion del viaje (numero de dias): " ;
    cin >> dias ;

    cout << "\nIntroduzca la edad del turista: " ;
    cin >> edad ;
}

void billete::operacion()
{
    float precio ;

    precio = distancia * 0.50;

    if(distancia>800 && dias>7)
        precio = precio * 0.75;

    if(edad>55)
        precio = precio * 0.75;

    cout << "\nEl precio del viaje es " << precio << " euros\n" ;
}

int main()
{
    billete b ;

    b.informacion();
    b.operacion();

    return 0 ;
}
