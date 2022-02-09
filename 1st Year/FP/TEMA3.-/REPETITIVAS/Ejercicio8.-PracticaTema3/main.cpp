#include <iostream>
#include <math.h>

using namespace std;

class numero
{
    int entero ;

public:
    void informacion();
    long factorial();
};

void numero::informacion()
{
    cout << "Introduzca un numero entero positivo menor que 20: " ;
    cin >> entero ;

    if((entero < 0) || (entero > 20) )
    {
        do
        {
            cout << "Introduzca de nuevo el numero por favor [0-20]: " ;
            cin >> entero ;
        }while((entero < 0) || (entero > 20) );

    }
}

long numero::factorial()
{
    int fact = 0;
    fact = entero ;

    for(int i=entero-1 ; i >=1 ; i--)
        {
            fact=fact*i ;
        }

    cout << "El factorial del numero introducido es: " << fact << endl ;


    return fact;

}

int main()
{
    numero n ;

    n.informacion();
    n.factorial();

    return 0;
}
