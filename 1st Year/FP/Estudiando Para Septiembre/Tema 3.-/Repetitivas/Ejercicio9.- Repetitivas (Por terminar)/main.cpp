#include <iostream>

using namespace std;

class llamada
{
    int numero;

public:
    void informacion();
    int suma();
};

void llamada::informacion()
{
    cout << "\nIntroduzca la cantidad de numeros que desea sumar: " ;
    cin >> numero;
    cout << endl;
}

int llamada::suma()
{
    int operacion = 0;

    for(int i=0 ; i<=numero ; i++)
    {
        if((i%2==0) ||(i%3==0)||(i%4==0)||(i%5==0)||(i%6==0)||(i%7==0))
            operacion = operacion + i;
    }

    cout << "La suma de los " << numero << " primeros numeros consecutivos es " << operacion << "\n";

    return operacion ;
}

int main()
{
    llamada llmd;

    llmd.informacion();
    llmd.suma();

    return 0;
}
