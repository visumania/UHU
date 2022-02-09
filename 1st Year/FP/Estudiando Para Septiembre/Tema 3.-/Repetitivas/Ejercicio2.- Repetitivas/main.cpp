#include <iostream>

using namespace std;

class valores
{
    int maximo , minimo ;
    float media ;

public:
    void estadistica();
    int mostrarmax();
    int mostrarmin();
    float mostrarmedia();
};

void valores::estadistica()
{
    int numero , numeros;


    cout << "Introduzca cuantos numeros desea introducir: " ;
    cin >> numero ;

    for(int i=0 ; i<numero ; i++)
    {
        cout << "Introduzca numero " << i << ":" ;
        cin >> numeros;

        if (i==0)
        {
            media = numeros;
            maximo = numeros;
            minimo = numeros;
        }
        else
        {
            media = numeros + media ;

            if(numeros>maximo)
            {
                maximo = numeros;
            }

            if(numeros<minimo)
            {
                minimo = numeros;
            }
        }
    }

    media = media / numero;
}

int valores::mostrarmax()
{
    cout << "\nEl maximo valor es " << maximo << "\n";

    return maximo ;
}

int valores::mostrarmin()
{
    cout << "El minimo valor es " << minimo << "\n";

    return minimo ;
}

float valores::mostrarmedia()
{
    cout << "La media es " << media ;

    return media ;
}

int main ()
{
    valores v ;

    v.estadistica();
    v.mostrarmax();
    v.mostrarmin();
    v.mostrarmedia();

    return 0 ;
}
