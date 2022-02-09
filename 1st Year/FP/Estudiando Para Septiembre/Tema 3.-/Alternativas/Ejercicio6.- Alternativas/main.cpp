#include <iostream>

using namespace std;

class valores
{
    int valor1 , valor2;

public:
    void informacion();
    void operacion();
};

void valores::informacion()
{
    cout << "Introduzca el valor de dos numeros enteros: " ;
    cin >> valor1 >> valor2;
}

void valores::operacion()
{
    char operando ;

    cout << "Para realizar suma introduzca + S s\n" ;
    cout << "Para realizar resta introduzca - R r\n" ;
    cout << "Elija opcion: " ;
    cin >> operando ;

    if (operando == '+' || operando == 'S' || operando == 's')
        cout << "\nLa suma es " << valor1 + valor2 ;
    else
    {
        if (operando == '-' || operando == 'R' || operando == 'r')
            cout << "\nLa resta es " << valor1 - valor2 ;
    }


}

int main ()
{
    valores v ;

    v.informacion();
    v.operacion();

    return 0 ;
}
