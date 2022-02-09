#include <iostream>
#include <math.h>

using namespace std;

class numeros
{
    int n1 , n2 ;

public:
    void cargar();
    int Num1 () ;
    int Num2 ();
    int Suma();
    int Resta();
    int Mult();
    float Div ();
};

void numeros::cargar()
{
    cout << "Introduzca 2 numeros: " ;
    cin >> n1 >> n2 ;
}

int numeros::Num1()
{
   return n1;
}

int numeros::Num2()
{
    return n2;
}

int numeros::Suma()
{
    return n1+n2 ;
}

int numeros::Resta()
{
    return n1-n2;
}

int numeros::Mult()
{
    return n1*n2 ;
}

float numeros::Div()
{
    return (float)n1/n2;
}

int main()
{
    numeros N ;

    int opcion ;

    N.cargar();

    cout << "Elija opcion : \n1.-Sumar\n2.-Restar\n3.-Multiplicar\n4.-Dividir " ;
    cin >> opcion ;

    switch(opcion)
    {
        case 1 : cout << N.Num1() << "+" << N.Num2() << "=" << N.Suma() << endl ;
            break ;
        case 2 : cout << N.Num1() << "-" << N.Num2() << "=" << N.Resta() << endl ;
            break ;
        case 3 : cout << N.Num1() << "*" << N.Num2() << "=" << N.Mult() << endl;
            break;
        case 4 : cout << N.Num1() << "/" << N.Num2() << "=" << N.Div() << endl ;
            break ;
        default: cout << "Opcion invalida :( " ;

    }
    return 0;
}
