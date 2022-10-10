#include "TestAlgoritmo.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main();

int subMenu(char c);
int subMenuCasos();

/* Programa principal */
int main()
{
	int opcion = 0;
	int opcionSubmenuTeorico = 0;
	int opcionSubmenuEmpirico = 0;
	int opcionSubmenuCasos = 0;
	TestAlgoritmo ta = TestAlgoritmo();
	do
	{
		cout << "\t*** FAA. Practica 1. Curso 21/22 ***" << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tAlum. Adrian Moreno Monterde" << endl << endl;
		cout << "\t*** ESTUDIO DE LA COMPLEJIDAD DEL ALGORITMO BUSUQEDA SECUENCIAL ***" << endl << endl;
		cout << "\t\t\t\t1.- ESTUDIO TEORICO" << endl << endl;
		cout << "\t\t\t\t2.- ESTUDIO EMPIRICO" << endl << endl;
		cout << "\t\t\t\t0.- Salir" << endl << endl;
		cout << "\t\t\t\t---------" << endl << endl;
		cout << "Elige opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			do
			{
				system("cls");
				opcionSubmenuTeorico = subMenu('t');

				switch (opcionSubmenuTeorico)
				{
				case 1:
					ta.comprobarAlgoritmo();
					break;

				case 2:
					do
					{
						system("cls");
						opcionSubmenuCasos = subMenuCasos();

						switch (opcionSubmenuCasos)
						{
						case 0:
							ta.costeCasoTeorico(0);
							break;

						case 1:
							ta.costeCasoTeorico(1);
							break;

						case 2:
							ta.costeCasoTeorico(2);
							break;

						default:
							cout << "Error, opcion incorrecta" << endl;
							system("pause");
							break;
						}
					} while (opcionSubmenuCasos < 0 || opcionSubmenuCasos > 2);
					break;

				case 3:
					ta.compararTeorico(0, 1, 2);
					break;

				case 0:
					cout << "Volviendo al menu principal" << endl;
					break;

				default:
					cout << "Error, opcion incorrecta" << endl;
					break;
				}
				system("pause");
				system("cls");
			} while (opcionSubmenuTeorico != 0);
			break;

		case 2:
			do
			{
				system("cls");
				opcionSubmenuEmpirico = subMenu('e');

				switch (opcionSubmenuEmpirico)
				{
				case 1:
					ta.comprobarAlgoritmo();
					break;

				case 2:
					do
					{
						system("cls");
						opcionSubmenuCasos = subMenuCasos();

						switch (opcionSubmenuCasos)
						{
						case 0:
							ta.costeCasoEmpirico(0);
							break;

						case 1:
							ta.costeCasoEmpirico(1);
							break;

						case 2:
							ta.costeCasoEmpirico(2);
							break;

						default:
							cout << "Error, opcion incorrecta" << endl;
							system("pause");
							break;
						}
					} while (opcionSubmenuCasos < 0 || opcionSubmenuCasos > 2);
					break;

				case 3:
					ta.compararEmpirico(0, 1, 2);
					break;

				case 0:
					cout << "Volviendo al menu principal" << endl;
					break;

				default:
					cout << "Error, opcion incorrecta" << endl;
					break;
				}
				system("pause");
				system("cls");
			} while (opcionSubmenuEmpirico != 0);
			break;

		case 0:
			cout << "Saliendo del programa..." << endl;
			break;

		default:
			cout << "Error, opcion invalida" << endl;
			break;
		}
		system("cls");
	} while (opcion != 0);
	return 0;
}

int subMenu(char c)
{
	int opcion;

	cout << "\n\n\t*** MENU";

	if (c == 't')
		cout << " TEORICO ";
	if (c == 'e')
		cout << " EMPIRICO ";

	cout << "DEL ALGORITMO DE BUSQUEDA SECUENCIAL ***" << endl << endl;
	cout << "\t1.- Probar el algoritmo busqueda secuencial" << endl << endl;
	cout << "\t2.- Obtener los casos del metodo de busuqeda secuencial" << endl << endl;
	cout << "\t3.- Comparar los casos" << endl << endl;
	cout << "\t0.- Volver al menu principal" << endl << endl;
	cout << "\t---------" << endl << endl;
	cout << "\tElige opcion: ";
	cin >> opcion;

	return opcion;
}

int subMenuCasos()
{
	int opcion = 0;

	cout << "\n\n\n\t*** Caso a estudiar para la busqueda secuencial ***" << endl << endl;
	cout << "\t0: Caso peor" << endl << endl;
	cout << "\t1: Caso medio" << endl << endl;
	cout << "\t2: Caso mejor" << endl << endl;
	cout << "\t\t\t\t----------" << endl << endl;
	cout << "Elige opcion: ";
	cin >> opcion;

	return opcion;
}