/*
 * La clase TestAlgoritmo contiene los metodos para:
 * 1. Comprobar que el algoritmo funciona adecuadamente.
 * 2. Calcular la eficiencia teórica y experimental para los casos de un método de búsqueda,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente
 * 3. Comparar el coste temporal de los casos del método de búsqueda
 *    secuencial teórico y experimental, permitiendo guardar los datos e imprimir la
 *    gráfica correspondiente.
 */
#ifndef _TEST_ALGORITMO
#define _TEST_TESTALGORITMO

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class TestAlgoritmo
{
	vector<string> nombreAlgoritmoCaso;
public:
	TestAlgoritmo();
	~TestAlgoritmo();
	void ordenaInsercion();
	void ordenaShell();
	void ordenaQuicksort();
};

#endif