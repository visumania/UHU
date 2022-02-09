#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int numero1 , numero2;
    float resultado ;

    cout << "Introduzca dos numeros enteros: " ;
    cin >> numero1 >> numero2 ;

    system("cls");

    int opcion;

    cout << "\t\t\t\tMENU\n";
    cout << "\t\t1.-Sumar\n";
    cout << "\t\t2.-Restar\n";
    cout << "\t\t3.-Multiplicar\n";
    cout << "\t\t4.-Dividir\n" ;
    cout << "\n\t\tElija opcion: ";

    cin >> opcion;

    switch(opcion)
    {
        case 1: resultado = numero1 + numero2;
        break;

        case 2: resultado = numero1 - numero2;
        break;

        case 3: resultado = numero1 * numero2;
        break;

        case 4: resultado = numero1 / numero2;
        break;

        default:
            {
                cout << "\nOpcion invalida\n";

                resultado = 0;
            }
    }

    cout << "El resultado es " << resultado ;

    return 0;
}
