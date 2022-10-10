/*
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los métodos de búsqueda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de búsqueda,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente con ajuste al Orden de complejidad.
 * 3. Comparar el coste temporal de dos métodos de búsqueda
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente.
 * 4. Comparar todos los algoritmos de búsqueda implementados permitiendo guardar los datos e imprimir la gráfica correspondiente.
 */
#include "TestBusqueda.h"
 //** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
#include "AlgoritmosBusqueda.h"
#include "AlgoritmosOrdenacion.h"
#include "Mtime.h"
#include "Graficas.h"
#include "Constantes.h"
#include "ConjuntoInt.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

TestBusqueda::TestBusqueda()
{
	nombreAlgoritmo.push_back("SecuencialIt");
	nombreAlgoritmo.push_back("BinariaIt");
	nombreAlgoritmo.push_back("InterpolacionIt");
	complejidad.push_back(N);
	complejidad.push_back(LOGN);
	complejidad.push_back(LOGLOGN);
}
TestBusqueda::~TestBusqueda() {}

double TestBusqueda::buscaEnArrayDeInt(int v[], int size, int metodo, int key, int& pos)
{
	AlgoritmosBusqueda al;
	Mtime time;
	LARGE_INTEGER t_ini, t_fin;

	QueryPerformanceCounter(&t_ini);

	switch (metodo)
	{
	case SECUENCIALIT:
		pos = al.busquedaSecuencialIt(v, size, key);
		break;

	case BINARIAIT:
		pos = al.busquedaBinariaIt(v, size, key);
		break;

	case INTERPOLACIONIT:
		pos = al.busquedaInterpolacionIt(v, size, key);
		break;

	default:
		cout << "Opcion incorrecta" << endl << endl;
		break;
	}

	QueryPerformanceCounter(&t_fin);

	return time.performancecounter_diff(&t_fin, &t_ini) * 1000000;
}

void TestBusqueda::comprobarMetodosBusqueda()
{
	system("cls");
	cout << "\t\t\t**** Comprobacion de los metodos de busqueda ****" << endl;

	int talla;
	cout << "Introduce la talla: ";
	cin >> talla;

	AlgoritmosOrdenacion ao;
	int key;

	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		int pos;
		v->GeneraVector(talla);
		ao.ordenaSeleccion(v->getDatos(), talla);

		cout << endl << "Vector para el metodo " << nombreAlgoritmo[metodo] << ": ";
		v->escribe();

		cout << "\tIntroduce la clave a buscar: ";
		cin >> key;

		buscaEnArrayDeInt(v->getDatos(), talla, metodo, key, pos);

		cout << "\t-->      posicion de " << key << " buscado con el metodo " << nombreAlgoritmo[metodo] << ": " << pos << endl;
		system("pause");

		delete v;
	}

	system("cls");
}

void TestBusqueda::casoMedio(int metodo)
{
	ofstream fichero(nombreAlgoritmo[metodo] + ".dat");
	system("cls");
	cout << endl << "Busqueda " << nombreAlgoritmo[metodo] << ". Tiempos de ejecucion promedio" << endl << endl << endl;

	double secs = 0;
	double tiempo = 0;
	Graficas gr;
	char opcion;
	int pos;
	AlgoritmosOrdenacion ao;

	cout << "\tTalla \t\tTiempo (microseg)" << endl << endl;

	for (int talla = tallaInicial; talla <= tallaFinal; talla += incrementaTalla)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		tiempo = 0;
		for (int prueba = 1; prueba <= NUMREPETICIONES; prueba++)
		{
			v->GeneraVector(talla);
			ao.ordenaSeleccion(v->getDatos(), talla);
			secs = buscaEnArrayDeInt(v->getDatos(), talla, metodo, v->generaKey(), pos);
			tiempo = tiempo + secs;
		}
		tiempo = tiempo / NUMREPETICIONES;
		fichero << talla << "\t" << tiempo << endl;
		cout << "\t" << talla << "\t\t" << setw(10) << fixed << setprecision(4) << (double)tiempo << "\t\t" << endl;
		delete v;
	}
	fichero.close();
	cout << endl << "Datos guardados en el fichero " << nombreAlgoritmo[metodo] << ".dat" << endl;

	char opc;
	Graficas q;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;

	switch (opc)
	{
	case 's':
	case'S':
		q.generarGraficaMEDIO(nombreAlgoritmo[metodo], complejidad[metodo]);
		system("CmdMedio.gpl"); system("cls");
		cout << "Grafica guardada en el fichero " << nombreAlgoritmo[metodo] << ".pdf" << endl << endl;
		cout << "Fichero de comandos guardado en el fichero CmdMedio.gpl" << endl << endl;
		system("pause");
		system("cls");
		break;
	default:
		system("cls");
		cout << endl << "Grafica no guardada en el fichero" << endl << endl;
		system("pause");
		system("cls");
		break;
	}
}

void TestBusqueda::comparar(int metodo1, int metodo2)
{
	double secs1, tiempo1, secs2, tiempo2;
	int pos;
	AlgoritmosOrdenacion ao;
	int key;

	ofstream fMetodo1((nombreAlgoritmo[metodo1] + ".dat").c_str());
	ofstream fMetodo2((nombreAlgoritmo[metodo2] + ".dat").c_str());

	system("cls");
	cout << endl << "\t" << nombreAlgoritmo[metodo1] << " y " << nombreAlgoritmo[metodo2] << ". Tiempos de ejecucion promedios" << endl << endl;
	cout << "\t\t\t" << nombreAlgoritmo[metodo1] << "\t\t\t" << nombreAlgoritmo[metodo2] << endl << endl;
	cout << "\tTalla\t\tTiempo (microseg)\tTiempo(microseg)" << endl << endl;

	for (int talla = tallaInicial; talla <= tallaFinal; talla += incrementaTalla)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		tiempo1 = 0;
		tiempo2 = 0;
		for (int prueba = 1; prueba <= NUMREPETICIONES; prueba++)
		{
			v->GeneraVector(talla);
			ao.ordenaSeleccion(v->getDatos(), talla);
			key = v->generaKey();
			secs1 = buscaEnArrayDeInt(v->getDatos(), talla, metodo1, key, pos);
			secs2 = buscaEnArrayDeInt(v->getDatos(), talla, metodo2, key, pos);
			tiempo1 = tiempo1 + secs1;
			tiempo2 = tiempo2 + secs2;
		}
		tiempo1 = tiempo1 / NUMREPETICIONES;
		tiempo2 = tiempo2 / NUMREPETICIONES;

		fMetodo1 << talla << "\t" << tiempo1 << endl;
		fMetodo2 << talla << "\t" << tiempo2 << endl;

		cout << "\t" << talla << "\t\t" << setw(10) << fixed << setprecision(4) << (double)tiempo1 << "\t\t" << setw(10) << fixed << setprecision(4) << (double)tiempo2 << "\t\t" << endl;
		delete v;
	}
	fMetodo1.close();
	fMetodo2.close();

	cout << endl << "Datos guardado en los ficheros " << nombreAlgoritmo[metodo1] + ".dat" << " y " << nombreAlgoritmo[metodo2] + ".dat" << endl;

	Graficas q;
	char opc;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;

	switch (opc)
	{
	case 's':
	case 'S':
		q.generarGrafica(nombreAlgoritmo[metodo1], nombreAlgoritmo[metodo2]);
		system("CmdComparar.gpl"); system("cls");
		cout << endl << "Grafica guardada en el fichero " << nombreAlgoritmo[metodo1] + nombreAlgoritmo[metodo2] << ".pdf" << endl << endl;
		cout << "Fichero de comandos guardados en el fichero CmdComparar.gpl" << endl << endl;
		system("pause");
		system("cls");
		break;
	default:
		system("cls");
		cout << endl << "Grafica no guardada en el fichero" << endl << endl;
		system("pause");
		system("cls");
		break;
	}
}

void TestBusqueda::comparaTodos()
{
	double secs1, tiempo1, secs2, tiempo2, secs3, tiempo3;
	int pos;
	AlgoritmosOrdenacion ao;
	int key;

	ofstream f((nombreAlgoritmo[0] + nombreAlgoritmo[1] + nombreAlgoritmo[2] + ".dat").c_str());

	system("cls");
	cout << endl << "\t\t\t*** COMPARACION DE TODOS LOS METODOS DE BUSQUEDA ***" << endl << endl;
	cout << "\t\t*** Comparacion Busquedas " << nombreAlgoritmo[0] << ", " << nombreAlgoritmo[1] << " y " << nombreAlgoritmo[2] << " ***" << endl << endl;
	cout << "\t\t\t" << nombreAlgoritmo[0] << "\t\t" << nombreAlgoritmo[1] << "\t\t" << nombreAlgoritmo[2] << endl << endl;
	cout << "\tTalla\t\tTiempo (microseg)\tTiempo(microseg)\tTiempo(microseg)" << endl << endl;

	for (int talla = tallaInicial; talla <= tallaFinal; talla += incrementaTalla)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		tiempo1 = 0;
		tiempo2 = 0;
		tiempo3 = 0;

		for (int prueba = 1; prueba <= NUMREPETICIONES; prueba++)
		{
			v->GeneraVector(talla);
			ao.ordenaSeleccion(v->getDatos(), talla);
			key = v->generaKey();
			secs1 = buscaEnArrayDeInt(v->getDatos(), talla, 0, key, pos);
			secs2 = buscaEnArrayDeInt(v->getDatos(), talla, 1, key, pos);
			secs3 = buscaEnArrayDeInt(v->getDatos(), talla, 2, key, pos);

			tiempo1 = tiempo1 + secs1;
			tiempo2 = tiempo2 + secs2;
			tiempo3 = tiempo3 + secs3;
		}
		tiempo1 = tiempo1 / NUMREPETICIONES;
		tiempo2 = tiempo2 / NUMREPETICIONES;
		tiempo3 = tiempo3 / NUMREPETICIONES;

		f << talla << "\t" << tiempo1 << "\t" << tiempo2 << "\t" << tiempo3 << endl;

		cout << "\t" << talla << "\t\t" << setw(10) << fixed << setprecision(4) << (double)tiempo1 << "\t\t" << setw(10) << fixed << setprecision(4) << (double)tiempo2 << "\t\t" << setw(10) << fixed << setprecision(4) << (double)tiempo3 << endl;
		delete v;
	}
	f.close();

	cout << endl << "Datos guardado en los ficheros " << nombreAlgoritmo[0] + nombreAlgoritmo[1] + nombreAlgoritmo[2] + ".dat" << endl;

	Graficas q;
	char opc;
	vector<string> nombreAlgoritmos;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;

	switch (opc)
	{
	case 's':
	case 'S':
		nombreAlgoritmos.push_back(nombreAlgoritmo[0]);
		nombreAlgoritmos.push_back(nombreAlgoritmo[1]);
		nombreAlgoritmos.push_back(nombreAlgoritmo[2]);

		q.generarGrafica(nombreAlgoritmos);
		system("CmdCompararTodos.gpl"); system("cls");

		cout << endl << "Grafica guardada en el fichero " << nombreAlgoritmo[0] + nombreAlgoritmo[1] + nombreAlgoritmo[2] << ".pdf" << endl << endl;
		cout << "Fichero de comandos guardados en el fichero CmdCompararTodos.gpl" << endl << endl;

		system("pause");
		system("cls");
		break;
	default:
		system("cls");
		cout << endl << "Grafica no guardada en el fichero" << endl << endl;
		system("pause");
		system("cls");
		break;
	}
}