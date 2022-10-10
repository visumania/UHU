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
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const int REPETICIONES = 1e4;

void visualizarResultados(int caso[], int nCasos, bool medicion);

TestAlgoritmo::TestAlgoritmo()
{
	nombreAlgoritmoCaso.push_back("SecuencialPeor");
	nombreAlgoritmoCaso.push_back("SecuencialMedio");
	nombreAlgoritmoCaso.push_back("SecuencialMejor");
}
TestAlgoritmo::~TestAlgoritmo()
{
}

/* Comprueba que el algoritmo funciona */
void TestAlgoritmo::comprobarAlgoritmo()
{
	int talla;
	cout << endl << endl << "Introduce la talla: ";
	cin >> talla;
	ConjuntoInt* v = new ConjuntoInt(talla);
	v->GeneraVector(talla);
	cout << endl << endl << "vector para el algoritmo " << ":" << endl << endl;
	v->escribe();
	int key;
	cout << endl << endl << "Introduce la clave a buscar: ";
	cin >> key;
	int posicion;
	Mtime t;
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	QueryPerformanceCounter(&t_ini);
	/* ...hacer algo... */
	// Buscar la clave en el array
	posicion = v->busquedaSecuencial(key);
	QueryPerformanceCounter(&t_fin);
	secs = t.performancecounter_diff(&t_fin, &t_ini);
	cout << endl << endl << "posicion de " << key << " buscado con el algoritmo de busqueda secuencial: " << posicion << endl << endl;
	cout << "tiempo de ejecucion= " << secs * 1000000000 << "ns" << endl;
	v->vaciar();
	system("pause");
	system("cls");
}
/*
 * Calcula el coste TEORICO de los casos de un Algoritmo,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo: caso del algoritmo a estudiar.
 */
void TestAlgoritmo::costeCasoTeorico(int numerocaso)
{
	ofstream f(nombreAlgoritmoCaso[numerocaso] + "Teorico.dat");
	system("cls");
	cout << endl << "Busqueda " << nombreAlgoritmoCaso[numerocaso] + " Teorico";
	cout << "Tiempos de ejecucion " << endl << endl;
	cout << endl;;
	cout << "\tTalla\t\tTiempo (oe)" << endl << endl;
	double tiempo = 0;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{

		switch (numerocaso) {
		case SECUENCIALPEOR: /*Caso peor (T(n)= 7n+9)*/
		{
			tiempo = 6 * talla + 8;
		}
		break;
		case SECUENCIALMEDIO:/*Caso medio (T(n)= (7/2)n+9)*/
		{
			tiempo = ((3 / 2.0) * talla) + 8;
		}
		break;
		case SECUENCIALMEJOR:/*Caso mejor (T(n)= 9)*/
		{
			tiempo = 8;
		}
		break;
		}
		f << talla << "\t" << tiempo << endl;
		cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)tiempo << " \t\t" << endl;
		cout << endl;
	}
	f.close();
	cout << endl << "Datos guardados en el fichero " << nombreAlgoritmoCaso[numerocaso] << "Teorico.dat " << endl;

	/* Generar grafica */
	char opc;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {

		int casos[1] = { numerocaso };
		visualizarResultados(casos, 1, true);

		system("start tmp.gpl"); system("cls");

	}
	}
	cout << endl;
	system("pause");
	system("cls");
}

string generarNombre(int caso[], int nCasos, bool medicion) {
	string cadena = "";

	for (int i = 0; i < nCasos; i++) {
		cadena += "Secuencial";
		switch (caso[i]) {
		case SECUENCIALPEOR:
			cadena += "Peor";
			break;
		case SECUENCIALMEDIO:
			cadena += "Medio";
			break;
		case SECUENCIALMEJOR:
			cadena += "Mejor";
			break;
		}
	}
	if (medicion)
		cadena += "Teorico";
	else
		cadena += "Empirico";

	return cadena;
}

string generarNombre(int caso, bool medicion) {
	int casos[1] = { caso };

	return generarNombre(casos, 1, medicion);
}


/*
 * Compara los casos TEORICOS de un algoritmo.
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo1: Primer algoritmo a comparar
 * param metodo2: Segundo algoritmo a comparar
 * param metodo3: Segundo algoritmo a comparar
 */
void TestAlgoritmo::compararTeorico(int metodo1, int metodo2, int metodo3)
{
	ofstream f(nombreAlgoritmoCaso[metodo1] + nombreAlgoritmoCaso[metodo2] + nombreAlgoritmoCaso[metodo3] + "Teorico.dat");
	system("cls");
	cout << endl << "Busqueda Secuencial" << " Teorico";
	cout << ". Tiempos de ejecucion " << endl << endl;
	cout << endl;;
	cout << "\tTalla\t\tTiempo (oe)" << endl << endl;
	double tiempoPeor = 0; int tiempoMedio = 0; int tiempoMejor = 0;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{
		/* Caso peor (T(n)= 6n+8) */
		tiempoPeor = 6 * talla + 8;
		/*Caso medio (T(n)= 3n+8)*/
		tiempoMedio = (3 * talla) + 8;
		/*Caso mejor (T(n)= 8)*/
		tiempoMejor = 8;
		/*escribir en el fichero*/
		f << talla << "\t" << tiempoPeor << "\t" << tiempoMedio << "\t" << tiempoMejor << endl;
		/*Visualizar en pantalla*/
		cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)tiempoPeor << " \t" << setw(10) << setprecision(2) << (double)tiempoMedio << " \t" << setw(10) << setprecision(2) << (double)tiempoMejor << " \t\t" << endl;
		cout << endl;
	}
	f.close();
	cout << endl << "Datos guardados en el fichero " << nombreAlgoritmoCaso[metodo1] + nombreAlgoritmoCaso[metodo2] + nombreAlgoritmoCaso[metodo3] << "Teorico.dat " << endl;
	/* Generar grafica */
	char opc;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		int casos[3] = { metodo1, metodo2, metodo3 }; //Lo hacemos asi para poder generar nuevas graficas
		visualizarResultados(casos, 3, true);

		system("start tmp.gpl"); system("cls");
	}break;
	default: {cout << "Grafica no guardada en fichero " << endl;
	}break;
	}
	cout << endl;
	system("pause");
	system("cls");
}
/*
 * Calcula el coste EMPÍRICO de los casos de un Algoritmo,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo: caso del algoritmo a estudiar.
 */
void TestAlgoritmo::costeCasoEmpirico(int numerocaso)
{
	ofstream f(nombreAlgoritmoCaso[numerocaso] + "Empirico.dat");
	system("cls");
	cout << endl << "Busqueda " << nombreAlgoritmoCaso[numerocaso] + " Empirico";
	cout << "Tiempos de ejecucion " << endl << endl;
	cout << endl;;
	cout << "\tTalla\t\tTiempo (ms)" << endl << endl;
	double tiempo = 0;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{
		LARGE_INTEGER t_inicio, t_final;
		Mtime t;

		ConjuntoInt* conjunto = new ConjuntoInt(talla);

		switch (numerocaso)
		{
		case SECUENCIALPEOR:
		{
			conjunto->GeneraVector(talla);
			QueryPerformanceCounter(&t_inicio);
			conjunto->busquedaSecuencial(-1);
			QueryPerformanceCounter(&t_final);
			tiempo += t.performancecounter_diff(&t_final, &t_inicio);
		}
		break;
		case SECUENCIALMEDIO:
		{
			for (int i = 0; i < NUMREPETICIONES; i++)
			{
				conjunto->GeneraVector(talla);
				QueryPerformanceCounter(&t_inicio);
				conjunto->busquedaSecuencial(conjunto->generaKey());
				QueryPerformanceCounter(&t_final);
				tiempo += t.performancecounter_diff(&t_final, &t_inicio);
			}
			tiempo /= NUMREPETICIONES;
		}
		break;
		case SECUENCIALMEJOR:
		{
			conjunto->GeneraVector(talla);
			QueryPerformanceCounter(&t_inicio);
			conjunto->busquedaSecuencial(conjunto->getPrimero());
			QueryPerformanceCounter(&t_final);
			tiempo += t.performancecounter_diff(&t_final, &t_inicio);

		}
		break;
		}
		delete conjunto;
		tiempo *= 1000.0;

		f << talla << "\t" << tiempo << endl;
		cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)tiempo << "\t\t" << endl;
		cout << endl;
	}
	f.close();
	cout << endl << "Datos guardados en el fichero " << nombreAlgoritmoCaso[numerocaso] << "Empirico.dat" << endl;

	/*generamos la grafica*/
	char opc;
	cout << endl << "generar grafica de resultados? (s/n)";
	cin >> opc;
	switch (opc)
	{
	case 's':
	case 'S':
	{
		int casos[1] = { numerocaso };
		visualizarResultados(casos, 1, false);
		system("start tmp.gpl"); system("cls");
	}
	}
	cout << endl;
	system("pause");
	system("cls");
}

/*
  * Compara los casos EMPÍRICOS de un algoritmo.
  * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
  * param metodo1: Primer algoritmo a comparar
  * param metodo2: Segundo algoritmo a comparar
  * param metodo3: Segundo algoritmo a comparar
  */

void TestAlgoritmo::compararEmpirico(int metodo1, int metodo2, int metodo3)
{

	//Graficas g;
	ofstream f(nombreAlgoritmoCaso[metodo1] + nombreAlgoritmoCaso[metodo2] + nombreAlgoritmoCaso[metodo3] + "Empirico.dat");
	system("cls");
	cout << endl << "Busqueda Secuencial" << " Empirico";
	cout << ". Tiempos de ejecucion " << endl << endl;
	cout << endl;;
	cout << "\tTalla\t\tTiempo (oe)" << endl << endl;
	double tiempoPeor = 0; double tiempoMedio = 0; double tiempoMejor = 0;

	LARGE_INTEGER t_ini, t_fin;
	Mtime t;


	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{

		tiempoPeor = 0;
		tiempoMedio = 0;
		tiempoMejor = 0;

		ConjuntoInt* conjunto = new ConjuntoInt(talla);
		for (int i = 0; i < NUMREPETICIONES; i++) {
			conjunto->GeneraVector(talla);

			QueryPerformanceCounter(&t_ini);
			conjunto->busquedaSecuencial(-1);
			QueryPerformanceCounter(&t_fin);
			tiempoPeor += t.performancecounter_diff(&t_fin, &t_ini);

			QueryPerformanceCounter(&t_ini);
			conjunto->busquedaSecuencial(conjunto->generaKey());
			QueryPerformanceCounter(&t_fin);
			tiempoMedio += t.performancecounter_diff(&t_fin, &t_ini);

			QueryPerformanceCounter(&t_ini);
			conjunto->busquedaSecuencial(conjunto->getPrimero());
			QueryPerformanceCounter(&t_fin);
			tiempoMejor += t.performancecounter_diff(&t_fin, &t_ini);
		}
		delete conjunto;

		tiempoPeor *= 1000.0 / NUMREPETICIONES;
		tiempoMedio *= 1000.0 / NUMREPETICIONES;
		tiempoMejor *= 1000.0 / NUMREPETICIONES;


		/*escribir en el fichero*/
		f << talla << "\t" << tiempoPeor << "\t" << tiempoMedio << "\t" << tiempoMejor << endl;
		/*Visualizar en pantalla*/
		cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)tiempoPeor << " \t" << setw(10) << setprecision(2) << (double)tiempoMedio << " \t" << setw(10) << setprecision(2) << (double)tiempoMejor << " \t\t" << endl;
		cout << endl;

	}
	f.close();
	cout << endl << "Datos guardados en el fichero " << nombreAlgoritmoCaso[metodo1] + nombreAlgoritmoCaso[metodo2] + nombreAlgoritmoCaso[metodo3] << "Empirico.dat " << endl;
	/* Generar grafica */
	char opc;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		int casos[3] = { metodo1, metodo2, metodo3 };
		visualizarResultados(casos, 3, false);

		system("start tmp.gpl"); system("cls");
	}
			break;
	default: cout << "Grafica no guardada en fichero " << endl;
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void visualizarResultados(int caso[], int nCasos, bool medicion) {
	/*	MEDICION
		False: empirico
		True:  teorico
	*/

	ofstream file("tmp.gpl");

	file << "set title \"Secuencial" << generarNombre(caso, nCasos, medicion) << "\"\n"
		<< "set key top left vertical inside\n"
		<< "set grid\n"
		<< "set xlabel \"Talla (n)\"\n"
		<< "set ylabel \"Tiempo (" << (medicion ? "OE" : "ms") << ")\"\n";

	if (nCasos == 1) {
		for (int i = 0; i < nCasos; i++) {
			switch (caso[i]) {
			case SECUENCIALPEOR:
				file << "N(x) = a*x + b\n"
					<< "fit N(x) \"" << generarNombre(caso, nCasos, medicion) << ".dat\" using 1:" << (i + 2) << " via a,b";
				break;
			case SECUENCIALMEDIO:
				file << "M(x) = t*x + u\n"
					<< "fit M(x) \"" << generarNombre(caso, nCasos, medicion) << ".dat\" using 1:" << (i + 2) << " via t,u";
				break;
			case SECUENCIALMEJOR:
				file << "C(x) = w\n"
					<< "fit C(x) \"" << generarNombre(caso, nCasos, medicion) << ".dat\" using 1:" << (i + 2) << " via w";
				break;
			}
		}
	}


	file << "\nplot ";
	for (int i = 0; i < nCasos; i++) {
		file << "\"" << generarNombre(caso, nCasos, medicion) << ".dat\" using 1:" << (i + 2) << " with lines title \"" << generarNombre(caso[i], medicion) << "\"";
		if (nCasos == 1) {
			switch (caso[i]) {
			case SECUENCIALPEOR:
				file << ", N(x)";
				break;
			case SECUENCIALMEDIO:
				file << ", M(x)";
				break;
			case SECUENCIALMEJOR:
				file << ", C(x)";
				break;
			}
		}
		else if (medicion && caso[i] == SECUENCIALMEJOR) {
			file << ", \"" << generarNombre(caso, nCasos, medicion) << ".dat\" using 1:" << (i + 2) << " title \"" << generarNombre(caso[i], medicion) << "\"";
		}

		if (i != nCasos - 1)
			file << ", ";
	}

	file << "\nset terminal pdf\n"
		<< "set output \"" << generarNombre(caso, nCasos, medicion) << ".pdf\"\n"
		<< "replot\n"
		<< "pause 5 \"Pulsa Enter para continuar...\"";


	file.close();
}