#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

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
    void salir();
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

void numeros::salir()
{
}

int main()
{
    numeros N ;

    char i ;
    N.cargar();
    do {
        system("cls");
        cout << "\nA. Sumar\nB. Restar\nC. Multiplicar\nD. Dividir\nE. Salir \n\nElija una opcion: " ;
        cin >> i; //a
        i=toupper(i); //a --> A

        switch(i)
        {
            case 'A':
                {
                    cout << N.Num1() << "+" << N.Num2() << "=" << N.Suma() << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            case 'B':
                {
                    cout << N.Num1() << "-" << N.Num2() << "=" << N.Resta() << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            case 'C':
                {
                    cout << N.Num1() << "*" << N.Num2() << "=" << N.Mult() << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            case 'D':
                {
                    cout << N.Num1() << "/" << N.Num2() << "=" << N.Div() << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            case 'E':
                {
                    cout << "\nPrograma finalizado :)" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
        }
    }while(i!='E');

        return 0 ;

}
