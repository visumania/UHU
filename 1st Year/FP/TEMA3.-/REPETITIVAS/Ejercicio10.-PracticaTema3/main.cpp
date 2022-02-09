#include <iostream>

using namespace std;

class Numero
{
    int a ;
    int b ;

public:
    void informacion();
    int mcd();
};

void Numero::informacion()
{
    cout << "Introduzca dos valores enteros a , b :\n" ;
    cin >> a >> b ;
}

int Numero::mcd()
{
    int mcd=0 ;
    do
    {
        if (a>b)
            a = a-b ;
        else
            b = b-a ;


    }while(a!=b);

    cout << "El maximo comun divisor (mcd) entre a y b es : " << a << endl ;

    return mcd;

}

int main()
{
    Numero n ;

    n.informacion();
    n.mcd();

    return 0;
}
