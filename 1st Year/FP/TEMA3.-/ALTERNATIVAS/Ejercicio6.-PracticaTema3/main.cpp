#include <iostream>
#include <math.h>

using namespace std;

class clase
{
    int a , b ;


public :
    void informacion();
    void operacion();
    int resultado ;
};

void clase::informacion()
{
    cout << "Introduzca dos numeros enteros: " ;
    cin >> a >> b ;
}

void clase::operacion()
{
    char i;

    cout << "Introduzca por teclado la operacion a realizar:\n 1.-Sumar(+ , S , s) \n2.-Restar (- , R , r)" ;
    cin >> i;

    if (i=='+' || i=='S' || i=='s')
        cout << a+b ;
    else if (i=='-' || i=='R' || i=='r')
            cout << a-b ;
         else
            cout << "La operacion solicitada no es valida :(" ;


}

int main ()
{
    clase c ;

    c.informacion();
    c.operacion();

    return 0;
}

