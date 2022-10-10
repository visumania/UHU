#include <iostream>
#include "TestOrdenacion.h"
#include "TestBusqueda.h"
using namespace std;

int main()
{
    int opcMenuPrincipal;
    int opcMenuOrdenacion, opcSubMenuCasoMedioOrdenacion, opcM1ComparacionOrdenacion, opcM2ComparacionOrdenacion;
    int opcMenuBusqueda, opcSubMenuCasoMedioBusqueda, opcM1ComparacionBusqueda, opcM2ComparacionBusqueda;
    TestOrdenacion to = TestOrdenacion();
    TestBusqueda tb = TestBusqueda();

    do
    {
        cout << "\t\t\t\t*** FAA. Practica 3. Curso 21/22 ***" << endl << endl;
        cout << "\t\t\t\t\tAlum. Adrian Moreno Monterde" << endl << endl << endl;
        cout << "\t\t\t*** MENU PRINCIPAL ***" << endl << endl << endl;
        cout << "\t\t\t1.- MENU ORDENACION" << endl << endl;
        cout << "\t\t\t2.- MENU BUSQUEDA" << endl << endl;
        cout << "\t\t\t0.- Salir" << endl << endl;
        cout << "\t\t\t----------" << endl << endl;
        cout << "\t\t\tElige opcion: ";
        cin >> opcMenuPrincipal;

        system("cls");

        switch (opcMenuPrincipal)
        {
        case 1:
            do
            {
                cout << "\t*** ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION ***" << endl << endl << endl;
                cout << "\t\t1.- Probar los metodos de ordenacion" << endl << endl;
                cout << "\t\t2.- Obtener el caso medio de un metodo de ordenacion" << endl << endl;
                cout << "\t\t3.- Comparar dos metodos" << endl << endl;
                cout << "\t\t4.- Comparar todos los metodos" << endl << endl;
                cout << "\t\t0.- Volver al menu principal" << endl << endl;
                cout << "\t\t---------" << endl << endl;
                cout << "\t\tElige opcion: ";
                cin >> opcMenuOrdenacion;

                system("cls");

                switch (opcMenuOrdenacion)
                {
                case 1:
                    to.comprobarMetodosOrdenacion();
                    break;

                case 2:
                    cout << endl << endl << "\t\t\t*** Metodo a estudiar para el caso medio ***" << endl << endl;
                    cout << "\t\t\t0. Burbuja" << endl << endl;
                    cout << "\t\t\t1. Insercion" << endl << endl;
                    cout << "\t\t\t2. Seleccion" << endl << endl;
                    cout << "\t\t\t3. Mayo22" << endl << endl;
                    cout << "\t\t\t-------------" << endl << endl;
                    cout << "\t\t\tElige opcion: ";
                    cin >> opcSubMenuCasoMedioOrdenacion;

                    switch (opcSubMenuCasoMedioOrdenacion)
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
                    case 3:
                        to.casoMedio(3);
                        break;
                    default:
                        system("cls");
                        cout << endl << "Error, opcion invalida" << endl << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                    break;

                case 3:
                    do
                    {
                        system("cls");
                        cout << endl << endl << "\t\t\t*** COMPARACION DE DOS METODOS DE ORDENACION ***" << endl << endl;
                        cout << "\t\t\tSelecciona los dos metodos a comparar" << endl << endl;
                        cout << "\t\t\t0. Burbuja" << endl << endl;
                        cout << "\t\t\t1. Insercion" << endl << endl;
                        cout << "\t\t\t2. Seleccion" << endl << endl;
                        cout << "\t\t\t3. Mayo22" << endl << endl << endl;
                        cout << "\t\t\tElige metodo 1: ";
                        cin >> opcM1ComparacionOrdenacion;
                        cout << endl << "\t\t\tElige metodo 2: ";
                        cin >> opcM2ComparacionOrdenacion;

                        if (opcM1ComparacionOrdenacion > 3 || opcM1ComparacionOrdenacion < 0)
                        {
                            system("cls");
                            cout << endl << "Error, el metodo 1 seleccionado no corresponde a ninguna opcion del menu" << endl << endl;
                            system("pause");
                            system("cls");
                        }

                        if (opcM2ComparacionOrdenacion > 3 || opcM2ComparacionOrdenacion < 0)
                        {
                            system("cls");
                            cout << endl << "Error, el metodo 2 seleccionado no corresponde a ninguna opcion del menu" << endl << endl;
                            system("pause");
                            system("cls");
                        }

                        if (opcM1ComparacionOrdenacion == opcM2ComparacionOrdenacion)
                        {
                            system("cls");
                            cout << endl << "Error, los metodos seleccionados deben de ser diferentes" << endl << endl;
                            system("pause");
                            system("cls");
                        }

                    } while (opcM1ComparacionOrdenacion > 3 || opcM1ComparacionOrdenacion < 0 || opcM2ComparacionOrdenacion>3 || opcM2ComparacionOrdenacion < 0 || opcM1ComparacionOrdenacion == opcM2ComparacionOrdenacion);
                    to.comparar(opcM1ComparacionOrdenacion, opcM2ComparacionOrdenacion);
                    break;

                case 4:
                    to.comparaTodos();
                    break;

                case 0:
                    cout << "Volviendo al menu principal del programa..." << endl << endl;
                    system("pause");
                    system("cls");
                    break;

                default:
                    system("cls");
                    cout << endl << "Error, opcion invalida" << endl << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } while (opcMenuOrdenacion != 0);
            break;

        case 2:
            do
            {
                cout << "\t\t*** MENU BUSQUEDA ***" << endl << endl << endl;
                cout << "\t\t1.- Probar los metodos de busqueda" << endl << endl;
                cout << "\t\t2.- Obtener el caso medio de un metodo de busqueda" << endl << endl;
                cout << "\t\t3.- Comparar dos metodos" << endl << endl;
                cout << "\t\t4.- Comparar todos los metodos" << endl << endl;
                cout << "\t\t0.- Volver al menu principal" << endl << endl;
                cout << "\t\t---------" << endl << endl;
                cout << "\t\tElige opcion: ";
                cin >> opcMenuBusqueda;

                system("cls");

                switch (opcMenuBusqueda)
                {
                case 1:
                    tb.comprobarMetodosBusqueda();
                    break;

                case 2:
                    cout << endl << endl << endl << "\t\t\t*** Metodo a estudiar para el caso medio ***" << endl << endl;
                    cout << "\t\t\t0.- Busqueda Secuencial Iterativa" << endl << endl;
                    cout << "\t\t\t1.- Busqueda Binaria Iterativa" << endl << endl;
                    cout << "\t\t\t2.- Busqueda de Interpolacion Iterativa" << endl << endl;
                    cout << "\t\t\t-----------" << endl << endl;
                    cout << "\t\t\tElige opcion: ";
                    cin >> opcSubMenuCasoMedioBusqueda;

                    switch (opcSubMenuCasoMedioBusqueda)
                    {
                    case 0:
                        tb.casoMedio(0);
                        break;

                    case 1:
                        tb.casoMedio(1);
                        break;

                    case 2:
                        tb.casoMedio(2);
                        break;

                    default:
                        system("cls");
                        cout << "Error, opcion invalida" << endl << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                    break;

                case 3:
                    do
                    {
                        system("cls");
                        cout << endl << endl << endl << "\t\t*** COMPARACION DE DOS METODOS DE BUSQUEDA ***" << endl << endl;
                        cout << "\t\tSelecciona los dos metodos a comparar" << endl << endl;
                        cout << "\t\t0.- Busqueda Secuencial Iterativa" << endl << endl;
                        cout << "\t\t1.- Busqueda Binaria Iterativa" << endl << endl;
                        cout << "\t\t2.- Busqueda de Interpolacion Iterativa" << endl << endl;
                        cout << "\t\tElige metodo 1: ";
                        cin >> opcM1ComparacionBusqueda;
                        cout << "\t\tElige metodo 2: ";
                        cin >> opcM2ComparacionBusqueda;

                        if (opcM1ComparacionBusqueda > 2 || opcM1ComparacionBusqueda < 0)
                        {
                            system("cls");
                            cout << endl << "Error, el metodo 1 seleccionado no corresponde a ninguna opcion del menu" << endl << endl;
                            system("pause");
                            system("cls");
                        }

                        if (opcM2ComparacionBusqueda > 2 || opcM2ComparacionBusqueda < 0)
                        {
                            system("cls");
                            cout << endl << "Error, el metodo 2 seleccionado no corresponde a ninguna opcion del menu" << endl << endl;
                            system("pause");
                            system("cls");
                        }

                        if (opcM1ComparacionBusqueda == opcM2ComparacionBusqueda)
                        {
                            system("cls");
                            cout << endl << "Error, los metodos seleccionados deben de ser diferentes" << endl << endl;
                            system("pause");
                            system("cls");
                        }

                    } while (opcM1ComparacionBusqueda > 2 || opcM1ComparacionBusqueda < 0 || opcM2ComparacionBusqueda>2 || opcM2ComparacionBusqueda < 0 || opcM1ComparacionBusqueda == opcM2ComparacionBusqueda);

                    tb.comparar(opcM1ComparacionBusqueda, opcM2ComparacionBusqueda);
                    break;

                case 4:
                    tb.comparaTodos();
                    break;

                case 0:
                    cout << "Volviendo al menu principal del programa..." << endl << endl;
                    system("pause");
                    system("cls");
                    break;

                default:
                    system("cls");
                    cout << endl << "Error, opcion invalida" << endl << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } while (opcMenuBusqueda != 0);
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