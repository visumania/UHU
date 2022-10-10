#include <iostream>
#include "TestOrdenacion.h"
using namespace std;

int main()
{
    int opcMenuPrincipal, opcSubMenuCasoMedio, opcM1Comparacion, opcM2Comparacion; 
    TestOrdenacion to = TestOrdenacion();

	do
	{
        cout << "\t\t\t\t*** FAA. Practica 2. Curso 21/22 ***" << endl << endl;
        cout << "\t\t\t\t\tAlum. Adrian Moreno Monterde" << endl << endl << endl;
        cout << "\t\t\t*** MENU PRINCIPAL ***" << endl << endl;
        cout << "\t*** ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION ***" << endl << endl << endl;
        cout << "\t\t1.- Probar los metodos de ordenacion" << endl << endl;
        cout << "\t\t2.- Obtener el caso medio de un metodo de ordenacion" << endl << endl;
        cout << "\t\t3.- Comparar los metodos" << endl << endl;
        cout << "\t\t4.- Comparar todos los metodos" << endl << endl;
        cout << "\t\t0.- Salir" << endl << endl;
        cout << "\t\t---------" << endl << endl;
        cout << "\t\tElige opcion: ";
        cin >> opcMenuPrincipal;
        system("cls");

        switch (opcMenuPrincipal)
        {
        case 1:
            to.comprobarMetodosOrdenacion();
            break;

        case 2:
            cout << endl << endl << "\t\t\t*** Metodo a estudiar para el caso medio ***" << endl << endl;
            cout << "\t\t\t0. Burbuja" << endl << endl;
            cout << "\t\t\t1. Insercion" << endl << endl;
            cout << "\t\t\t2. Seleccion" << endl << endl;
            cout << "\t\t\t-------------" << endl << endl;
            cout << "\t\t\tElige opcion: ";
            cin >> opcSubMenuCasoMedio;

            switch (opcSubMenuCasoMedio)
            {
            case 0:
                to.casoMedio(0);
                break;

            case 1:
                to.casoMedio(1);
                break;

            case 2:
                to.casoMedio(2);
                break;
            default:
                system("cls");
                cout << endl << "Error, opcion invalida" << endl << endl;
                system("pause");
                system("cls");
                break;
            }
            break;

        case 3: //Hacerlo do while para controlar posible entrada incorrecta 
            do
            {
                system("cls");
                cout << endl << endl << "\t\t\t*** COMPARACION DE DOS METODOS DE ORDENACION ***" << endl << endl;
                cout << "\t\t\tSelecciona los dos metodos a comparar" << endl << endl;
                cout << "\t\t\t0. Burbuja" << endl << endl;
                cout << "\t\t\t1. Insercion" << endl << endl;
                cout << "\t\t\t2. Seleccion" << endl << endl << endl;
                cout << "\t\t\tElige metodo 1: ";
                cin >> opcM1Comparacion;
                cout << endl << "\t\t\tElige metodo 2: ";
                cin >> opcM2Comparacion;

                if (opcM1Comparacion > 2 || opcM1Comparacion < 0)
                {
                    system("cls");
                    cout << endl << "Error, el metodo 1 seleccionado no corresponde a ninguna opcion del menu" << endl << endl;
                    system("pause");
                    system("cls");
                }

                if (opcM2Comparacion > 2 || opcM2Comparacion < 0)
                {
                    system("cls");
                    cout << endl << "Error, el metodo 2 seleccionado no corresponde a ninguna opcion del menu" << endl << endl;
                    system("pause");
                    system("cls");
                }

                if (opcM1Comparacion == opcM2Comparacion)
                {
                    system("cls");
                    cout << endl << "Error, los metodos seleccionados deben de ser diferentes" << endl << endl;
                    system("pause");
                    system("cls");
                }

            } while (opcM1Comparacion > 2 || opcM1Comparacion < 0 || opcM2Comparacion>2 || opcM2Comparacion < 0 || opcM1Comparacion==opcM2Comparacion);
            to.comparar(opcM1Comparacion, opcM2Comparacion); //Hay que controlar que opcM1Comparacion != opcM2Comparacion
            break;

        case 4:
            to.comparaTodos();
            break;

        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            system("cls");
            cout << endl << "Error, opcion invalida" << endl << endl; 
            system("pause");
            system("cls");
            break;
        }
        /*system("pause");
        system("cls");*/
	} while (opcMenuPrincipal != 0);

    return 0;
}