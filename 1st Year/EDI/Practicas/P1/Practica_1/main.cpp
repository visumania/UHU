#include <iostream>
#include <windows.h>
#include "Ventas.h"
#include "Ventas.cpp"
#include "Productos.h"
#include "Productos.cpp"

using namespace std;

int main()
{
    int opcion;
    ventas ve;
    ve.asignar("ventas.dat","resumen.dat");
    productos pro("resumen.dat","ventas.dat");

    do
    {
        system("cls");

        cout << "Practica 1" << endl << endl;
        cout << "\t1 Ver fichero detalle ventas" << endl;
        cout << "\t2 Ver fichero productos" << endl;
        cout << "\t3 Aniadir venta" << endl;
        cout << "\t4 Crear resumen ventas" << endl;
        cout << "\t5 Obtener estadisticas (tipo producto y periodo)" << endl;
        cout << "\t0 Salir" << endl << endl;
        cout << "Elija opcion: " ;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            {
                cout << "\nAqui se ejecuta la opcion 1" << endl <<endl;
                ve.mostrarventas();

                system("pause");
            }
            break;

        case 2:
            {
                cout << "\nAqui se ejecuta la opcion 2" << endl << endl;
                pro.mostrarproductos();
                system("pause");
            }
            break;

        case 3:
            {
                cout << "\nAqui se ejecuta la opcion 3" << endl << endl;
                ve.anadirventa(3);
                system("pause");
            }
            break;

        case 4:
            {
                cout << "\nAqui se ejecuta la opcion 4" << endl;
                ve.resumirfichero();
                system("pause");
            }
            break;

        case 5:
            {
                cout << "\nAqui se ejecuta la opcion 5" << endl;

                int tipo ,annoini , annofin;

                cout << "Introduzca el tipo del producto (1.-Electronica|2.-Papeleria|3.-Otros): " ;
                cin >>tipo;

                cout << "Introduzca el anio de inicio: " ;
                cin >> annoini;

                cout << "Introduzca el anio de finalizacion: " ;
                cin >> annofin;

                ve.estadisticas( tipo ,  annoini, annofin);
                system("pause");
            }
            break;

        case 0:
            {
                cout << "\nSaliendo del programa..." << endl;

                system("pause");
            }
            break;

        default:
            {
                    cout << "\nError, introduzca de nuevo la opcion...\n";
                    system("pause");
            }
        }

    }while(opcion!=0);

}
