#include <iostream>

using namespace std;

class Billete
{
    int distancia , dias , edad ;

public:
    void informacion();
    float operacion();
};

void Billete::informacion()
{
    cout << "Introduzca la distancia del viaje a realizar:\n ";
    cin >> distancia ;

    cout << "Introduzca el numero de dias que dura dicho viaje:\n";
    cin >> dias ;

    cout << "Introduzca la edad del turista:\n " ;
    cin >> edad ;


}

float Billete::operacion()
{
    float precio ;

    if (dias > 7 && distancia > 800)
        precio= (distancia*0.50)* 0.75 ;
    else if (edad >55)
            precio= (distancia*0.50)* 0.75 ;
         else
            precio= (distancia*0.50);

cout << "El precio es: " << precio << " euros" ;



}

int main()
{
    Billete b ;

    b.informacion();
    b.operacion();

    return 0;
}

