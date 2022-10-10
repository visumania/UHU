#include "TestAlgoritmo.h"
#include <iostream>
using namespace std;

/* Programa principal */
int main()
{
	TestAlgoritmo test;
	int opc = 1;

	do
	{
		system("cls");
		cout << "*** FAA. AMPLIACION ADD_5 - PRACTICA 1. CURSO 21/22 ***" << endl << endl;
		cout << "\t\t\t\tAlum. Adri" << char(160) <<"n Moreno Monterde" << endl;
		cout << "\t\t\t\tAlum. Antonio Jose Morano Mori" << char(164) <<"a" << endl;
		cout << "\t\t\t\tAlum. Antonio Brimes Romero";
		cout << "\n\n\t\t*** ESTUDIO DE LA COMPLEJIDAD DEL ALGORITMO BUSQUEDA SECUENCIAL ***" << endl;
		cout << "\n\t\t\t1.- Insercion" << endl;
		cout << "\n\t\t\t2.- Shell" << endl;
		cout << "\n\t\t\t3.- Quicksort" << endl;
		cout << "\n\t\t\t0.- Salir" << endl;
		cout << "\n\t\t\t------------" << endl;
		cout << "\n\t\t\tElige opcion : ";
		cin >> opc;

		system("cls");

		switch (opc)
		{
		case 0:
			cout << endl << endl << "Saliendo del programa..." << endl << endl; 
			break;

		case 1:
			test.ordenaInsercion();
			break;

		case 2:
			test.ordenaShell();
			break;

		case 3:
			test.ordenaQuicksort();
			break;

		default:
			system("cls");
			cout << endl << endl << "Error, la opcion introducida no es correcta" << endl << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (opc != 0);

	return 0;
}

