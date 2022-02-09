#include <iostream>
#include <windows.h>

using namespace std;

int main()
{

    int numero1 , numero2;
    float resultado ;

    cout << "Introduzca dos numeros enteros: " ;
    cin >> numero1 >> numero2 ;



    char opcion;

    do
    {
        system("pause");
        system("cls");

        cout << "\t\t\t\tMENU\n";
        cout << "\t\tA. Sumar\n";
        cout << "\t\tB. Restar\n";
        cout << "\t\tC. Multiplicar\n";
        cout << "\t\tD. Dividir\n" ;
        cout << "\t\tE. Salir\n";
        cout << "\n\tElija opcion (Letra mayuscula): ";

        cin >>  opcion;


        switch(opcion)
        {
            case 'A':
                {
                    resultado = numero1 + numero2;

                    cout << "\n";
                    cout << numero1 << " + " << numero2 << " = " << resultado << "\n";
                }
            break;

            case 'B':
                {
                    resultado = numero1 - numero2;

                    cout << "\n";
                    cout << numero1 << " - " << numero2 << " = " << resultado << "\n";
                }
            break;

            case 'C':
                {
                    resultado = numero1 * numero2;

                    cout << "\n";
                    cout << numero1 << " * " << numero2 << " = " << resultado << "\n";
                }
            break;

            case 'D':
                {
                    resultado = numero1 / numero2;

                    cout << "\n";
                    cout << numero1 << " / " << numero2 << " = " << resultado << "\n";
                }
            break;

            case 'E': cout << "\nSaliendo del programa ... \n " ; system("pause");
            break;

            default:
                {
                    cout << "\nOpcion invalida\n";
                }
        }
    }while(opcion !='E');

    system("cls");

    cout << "\nGracias por el uso :)\n " ;

    return 0;
}


