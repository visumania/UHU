/*
 * La clase TestAlgoritmo contiene los metodos para:
 * 1. Comprobar que el/los algoritmos funcionan adecuadamente.
 * 2. Calcular la eficiencia para los casos de un método de búsqueda,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente
 * 3. Comparar el coste temporal de los casos de búsqueda
 *    secuencial, permitiendo guardar los datos e imprimir la
 *    gráfica correspondiente.
 */
#include "TestAlgoritmo.h"
#include "Constantes.h"
#include "ConjuntoInt.h"
#include "Mtime.h"
#include "Graficas.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

TestAlgoritmo::TestAlgoritmo()
{
}
TestAlgoritmo::~TestAlgoritmo()
{
}

void TestAlgoritmo::ordenaInsercion() {

	ofstream f("Insercion.dat");

	cout << endl << "Tiempos medios para el algoritmo de Ordenacion por Insercion";
	cout << endl << endl << "\tTalla\t\tTiempo (ns)" << endl << endl;
	for (int talla = 1000; talla <= 10000; talla += 1000)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		v->GeneraVector(talla);
		Mtime t;
		LARGE_INTEGER t_ini, t_fin;
		double secs;
		QueryPerformanceCounter(&t_ini);
		///* ...hacer algo... */
		//// Buscar la clave en el array
		v->Insercion(v->getDatos(), talla);
		QueryPerformanceCounter(&t_fin);
		secs = t.performancecounter_diff(&t_fin, &t_ini);
		//cout << endl << "\t" << talla << "\t\t" << secs * 1000000 << endl;
		v->vaciar();

		f << talla << "\t" << secs * 1000000 << endl;
		cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)secs * 1000000 << endl;
	}
	f.close();
	cout << endl << "Datos guardados en el fichero Insercion.dat " << endl;
	/* Generar grafica */
	char opc;
	Graficas q;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		q.generarGraficaMEDIO("Insercion", CUADRADO);
		/* Ejecutar el fichero por lotes (comandos)*/
		system("Insercion.gpl"); system("cls");
		//system((gpl).c_str());
		cout << endl << "Grafica guardada en el fichero Insercion.gpl" << endl;
		cout << endl << "Grafica guardada en el fichero Insercion.pdf" << endl;
	}break;
	default:
		system("cls");
		cout << endl << endl << "Grafica no guardada" << endl << endl;
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void TestAlgoritmo::ordenaShell() {

	ofstream f("Shell.dat");

	cout << endl << "Tiempos medios para el algoritmo de Ordenacion Shell";
	cout << endl << endl << "\tTalla\t\tTiempo (ns)" << endl << endl;
	for (int talla = 1000; talla <= 10000; talla += 1000)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		v->GeneraVector(talla);
		Mtime t;
		LARGE_INTEGER t_ini, t_fin;
		double secs;
		QueryPerformanceCounter(&t_ini);
		///* ...hacer algo... */
		//// Buscar la clave en el array
		v->Shell(v->getDatos(), talla);
		QueryPerformanceCounter(&t_fin);
		secs = t.performancecounter_diff(&t_fin, &t_ini);
		//cout << endl << "\t" << talla << "\t\t" << secs * 1000000 << endl;
		v->vaciar();

		f << talla << "\t" << secs * 1000000 << endl;
		cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)secs * 1000000 << endl;
	}
	f.close();
	cout << endl << "Datos guardados en el fichero Shell.dat " << endl;
	/* Generar grafica */
	char opc;
	Graficas q;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		q.generarGraficaMEDIO("Shell", CUADRADO);
		/* Ejecutar el fichero por lotes (comandos)*/
		system("Shell.gpl"); system("cls");
		//system((gpl).c_str());
		cout << endl << "Grafica guardada en el fichero Shell.gpl" << endl;
		cout << endl << "Grafica guardada en el fichero Shell.pdf" << endl;
	}break;
	default:
		system("cls");
		cout << endl << endl << "Grafica no guardada" << endl << endl;
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void TestAlgoritmo::ordenaQuicksort() {

	ofstream f("QuickSort.dat");

	cout << endl << "Tiempos medios para el algoritmo de Ordenacion Rapida ( Quicksort )";
	cout << endl << endl << "\tTalla\t\tTiempo (ns)" << endl << endl;
	for (int talla = 1000; talla <= 10000; talla += 1000)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		v->GeneraVector(talla);
		Mtime t;
		LARGE_INTEGER t_ini, t_fin;
		double secs;
		QueryPerformanceCounter(&t_ini);
		///* ...hacer algo... */
		//// Buscar la clave en el array
		v->Quicksort(v->getDatos(), talla);
		QueryPerformanceCounter(&t_fin);
		secs = t.performancecounter_diff(&t_fin, &t_ini);
		//cout << endl << "\t" << talla << "\t\t" << secs * 1000000 << endl;
		v->vaciar();

		f << talla << "\t" << secs * 1000000 << endl;
		cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)secs * 1000000 << endl;
	}
	f.close();
	cout << endl << "Datos guardados en el fichero QuickSort.dat " << endl;
	/* Generar grafica */
	char opc;
	Graficas q;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		q.generarGraficaMEDIO("Quicksort", NLOGN);
		/* Ejecutar el fichero por lotes (comandos)*/
		system("QuickSort.gpl"); system("cls");
		//system((gpl).c_str());
		cout << endl << "Grafica guardada en el fichero QuickSort.gpl" << endl;
		cout << endl << "Grafica guardada en el fichero QuickSort.pdf" << endl;
	}break;
	default:
		system("cls");
		cout << endl << endl << "Grafica no guardada" << endl << endl;
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}