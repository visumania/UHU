#include <iostream>

using namespace std;

class Numero
{
    int a;
    int b;

public:
    void informacion();
    int mcd();
};

void Numero::informacion()
{
    cout << "Introduzca dos valores por teclado para calcula el mcd: ";
    cin >> a >> b ;
}

int Numero::mcd()
{

            if(a>b)
            {
                a=a-b;

                cout << "\nEl maximo comun divisor es " << a << endl;

                return a;
            }

            if(b>a)
            {
                b=b-a;

                cout << "\nEl maximo comun divisor es " << b << endl;

                return b;
            }

            if(a==b || b==a)
            {
                cout << "\nEl maximo comun divisor es " << a << endl;

                return a;
            }
}

int main()
{
    Numero n ;

    n.informacion();
    n.mcd();

    return 0;
}
