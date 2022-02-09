#include <iostream>

using namespace std;

#define K 9000000000

class cargas
{
    float carga1 , carga2 , distancia; //q1 , q2 , r --> respectivamente (microculombios y metros)

public:
    void Leer();
    double Fuerza();
};

void cargas::Leer()
{
    cout << "Introduzca el valor de la carga 1 (microculombios): " ;
    cin >> carga1;

    cout << "\nIntroduzca el valor de la carga 2 (microculombios): " ;
    cin >> carga2;

    cout << "\nIntroduzca la distancia a la que se encuentran las cargas (m): " ;
    cin >> distancia;
}

double cargas::Fuerza()
{
    float q1 , q2;

    q1 = carga1 * 0.000001; //Las pasamos de microculombios a culombios
    q2 = carga2 * 0.000001;

    double fuerzacargas;

    fuerzacargas = (K * q1 * q2) / (distancia * distancia);


    cout << "La fuerza es de " << fuerzacargas << " N por lo que la fuerza es  ";

    return fuerzacargas;
}

int main()
{
    cargas crgs;

    crgs.Leer();

    if(crgs.Fuerza() == 0)
        cout << " Neutral \n\n";
    else
    {
        if(crgs.Fuerza()<0)
        cout <<  " Atraccion \n\n";
        else
        {
            if(crgs.Fuerza()>0)
            cout <<  " Repulsion \n\n";
        }
    }


    return 0;
}

