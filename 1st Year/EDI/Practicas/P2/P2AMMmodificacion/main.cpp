#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include "peluqueria.h"

using namespace std;

int main()
{
    peluqueria p;
    char opc;

    do
    {
        system("cls");

        cout << "\t\t\tAdrian Moreno Monterde" << endl << endl;
        cout << "Peluqueria Corte 2.0 Huelva" << endl;
        cout << "_____________________________________________________________________" << endl;
        cout << "1 - Leer fichero (rescatar copia)" << endl;
        cout << "2 - Insertar peluquero" << endl;
        cout << "3 - Insertar cliente" << endl;
        cout << "4 - Retirar peluquero" << endl;
        cout << "5 - Atender cliente" << endl;
        cout << "6 - Mostrar peluqueria" << endl;
        cout << "7 - Eliminar un cliente" << endl;
        cout << "8 - Volcar a fichero (crear copia)" << endl;
        cout << "9 - Peluqueros X tipo" << endl;
        cout << "a - Tiempos Medios de Espera" << endl;
        cout << "0 - Salir" << endl;
        cout << "\n\nPulse la opcion deseada: ";
        opc = getch();
        system("cls");

        switch(opc)
        {
            case '1':
                cout << "1 - Leer fichero (rescatar copia)" << endl;

                cadena archivo;

                cout << "Nombre del fichero a cargar (sin extension): ";
                cin >> archivo;

                strcat(archivo, ".dat"); //Concatenamos el nombre recogido en arhivo con .dat

                cin.ignore();

                p.AbrirPeluqueria(archivo);

            break;

            case '2':
                cin.ignore();

                cout << "2 - Insertar peluquero" << endl;

                peluquerof peluF;


                cout << "Nombre del peluquero: ";
                gets(peluF.Nombre);

                cout << "Apellidos del peluquero: ";
                gets(peluF.Apellidos);

                cout << "Codigo del peluquero: ";
                cin >> peluF.Codigo;

                cout << "Tipo de servicio del peluquero: ";
                cin >> peluF.TipoServicio;

                cin.ignore();

                p.IncorporarPeluquero(peluF);

                cout << endl <<"Peluquero agregado correctamente." << endl;
            break;

            case '3':
                cout << "3 - Insertar cliente" << endl;

                cliente cli;

                cin.ignore();

                cout << "Nombre del cliente: ";
                gets(cli.Nombre);

                cout << "Apellidos del cliente: ";
                gets(cli.Apellidos);

                cout << "Edad del cliente: ";
                cin >> cli.Edad;

                cout << "Tipo de servicio solicitado: ";
                cin >> cli.TipoServicio;

                cout << "Hora de llegada (minutos): ";
                cin >> cli.HoraLlegada;

                cin.ignore();

                cout << "\n\t" << (p.IncorporarCliente(cli)?"Cliente agregado correctamente.":"No se pudo agregar el cliente.") << "\n";
            break;

            case '4':
                cout << "4 - Retirar peluquero" << endl;

                int codigo;

                cout << "Codigo del peluquero a retirar: ";
                cin >> codigo;

                cin.ignore();

                if(p.RetirarPeluquero(codigo))
                    cout << "Peluquero retirado correctamente " << endl;
                else
                    cout << "No se pudo retirar al peluquero " << endl;
            break;

            case '5':
                cout << "5 - Atender cliente" << endl;

                int cod;

                cout << "Codigo del peluquero que atiende: ";
                cin >> cod;

                cin.ignore();

                if(p.AtenderCliente(cod))
                    cout << "El peluquero atendio a un cliente nuevo " << endl;
                else
                    cout << "El peluquero no pudo atender a un nuevo cliente " << endl;
            break;

            case '6':
                cout << "6 - Mostrar peluqueria" << endl;

                p.Mostrar();

                cin.ignore();
            break;

            case '7':
                cout << "7 - Eliminar un cliente" << endl;

                cadena nombre, apellidos;

                cin.ignore();

                cout << "Nombre del cliente: ";
                cin.getline(nombre, sizeof(cadena));

                cout << "Apellidos del cliente: ";
                cin.getline(apellidos, sizeof(cadena));

                if(p.EliminarCliente(nombre,apellidos))
                    cout << "Cliente eliminado con exito " << endl;
                else
                    cout << "No se pudo eliminar al cliente " << endl;
            break;

            case '8':
                cout << "8 - Volcar a fichero (crear copia)" << endl;

                cadena fichero;

                cout << "Nombre del fichero a guardar: ";
                cin >> fichero;

                cin.ignore();

                strcat(fichero, ".dat"); //concatenamos la extension .dat

                p.VolcarPeluqueria(fichero);
            break;

            case '9':
                p.peluquerosxtipo();
                break;
            case 'a':
                int h , m;

                cout << "Introduzca hora del sistema: " << endl;
                cout << "Hora: ";
                cin >> h;

                cout << "Minutos: " ;
                cin >> m;

                p.tiempoMedioEspera(h,m);
                break;

            case '0': cout << endl << "Saliendo del programa ..." << endl;
            break;

            default: cout << "Error, opcion incorrecta ..." << endl;
        }

        if(opc != '0')
        {
            cout << "\n\n\n\tPulse una tecla para regresar al menu.";
            system("pause");
        }

    }while(opc != '0');

    return 0;
}
