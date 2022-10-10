#ifndef _LIB_CONJUNTOINT
#define _LIB_CONJUNTOINT

#include <iostream>
using namespace std;

/////////// Declaración de la clase conjuntoInt /////////////

class ConjuntoInt
{
private:
	int tamano;
	int* datos;
public:
	ConjuntoInt(int max = 0);
	~ConjuntoInt();
	void vaciar();
	void GeneraVector(int tam);
	int generaKey();
	int* getDatos();
	void escribe();
	int getPrimero();
	/*
	 * Función busquedaSecuencial, implementa el método de búsqueda secuencial Iterativo
	 * para el array de enteros "datos"
	 * tamaño del array "tamano"
	 * param key: clave o elemento a buscar
	 * return posición de la clave en el array, si no se encuentra return -1
	 */
	int busquedaSecuencial(int key);
	void Insercion(int v[], int size);
	void Shell(int v[], int size);
	void Quicksort(int v[], int talla);
	void Quicksort(int v[], int e, int d);
	int partition(int v[], int e, int d);
};

#endif

