/*
 * Clase AlgoritmosOrdenacion que implementa los Algoritmos de Ordenaci�n para ordenar un vector de enteros en orden descendente.
 * Define las implementaciones de los siguientes m�todos de Ordenaci�n en vectores:
 *	- Burbuja
 *	- Inserci�n
 *	- Selecci�n.
 */
#include "AlgoritmosOrdenacion.h"

AlgoritmosOrdenacion::AlgoritmosOrdenacion() {}
AlgoritmosOrdenacion :: ~AlgoritmosOrdenacion() {}

/*
 * m�todo ordenaBurbuja, implementa el m�todo de ordenaci�n Burbuja.
 * param v: el array de enteros a ordenar
 * param size: tama�o del array de enteros a ordenar
 */
void AlgoritmosOrdenacion::ordenaBurbuja(int v[], int size)
{
	int j, i, aux;

	for (i = size - 2; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			if (v[j] > v[j + 1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
}

/*
 * m�todo ordenaInsercion, implementa el m�todo de ordenaci�n por Inserci�n-
 * param v: el array de enteros a ordenar
 * param size: tama�o del array de enteros a ordenar
 */
void AlgoritmosOrdenacion::ordenaInsercion(int v[], int size)
{
	int j, i, aux;

	for (i = 1; i < size; i++) {
		aux = v[i];
		j = i - 1;
		while (j >= 0 && aux < v[j]) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = aux;
	}
}

/*
 * m�todo ordenaSeleccion, implementa el m�todo de ordenaci�n por Selecci�n.
 * param v: el array de enteros a ordenar
 * param size: tama�o del array de enteros a ordenar
 */
void AlgoritmosOrdenacion::ordenaSeleccion(int v[], int size)
{
	int j, i, aux, posminimo;

	for (i = 0; i <= size - 2; i++) {
		int posminimo = i;
		for (j = i + 1; j < size; j++) {
			if (v[j] < v[posminimo]) {
				posminimo = j;
			}
		}
		aux = v[posminimo];
		v[posminimo] = v[i];
		v[i] = aux;
	}
}
