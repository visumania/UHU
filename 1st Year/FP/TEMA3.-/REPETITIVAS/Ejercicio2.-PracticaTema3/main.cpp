#include <iostream>

using namespace std;

class clase
{
    float maximo , minimo , media ;

public:
    void estadistica();
    int mostrarmax();
    int mostarmin();
    float mostrarmedia();
};

void clase::estadistica()
{
    int numero , numeros ;

    cout << "Introduzca el numero de numeros que desee introducir: " ;
    cin >> numero ;

    for (int i=0 ; i<numero ; i++)
    {
        cout << "Introduce numero " << i + 1 << ":" ;
        cin >> numeros ;

        if(i==0)
        {
            maximo = numeros ;
            minimo = numeros ;
            media = numeros ;
        }
        else
        {
            media = numeros + media ;

            if(numeros>maximo)
            {
                maximo=numeros ;
            }

            if(numeros<minimo)
            {
                minimo=numeros;
            }
        }
    }
    media = media/numero;
}

int clase::mostrarmax()
{
    cout << "\nEl maximo es: " << maximo << "\n" ;

    return maximo;
}

int clase::mostarmin()
{
    cout << "El minimo es: " << minimo << "\n" ;

    return minimo;
}

float clase::mostrarmedia()
{
    cout << "La media es: "  << media ;

    return media;
}

int main()
{
    clase c ;

    c.estadistica();
    c.mostrarmax();
    c.mostarmin();
    c.mostrarmedia();

    return 0 ;
}
