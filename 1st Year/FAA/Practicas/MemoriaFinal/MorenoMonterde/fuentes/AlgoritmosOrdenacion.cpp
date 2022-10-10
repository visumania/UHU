/*
 * Clase AlgoritmosOrdenacion que implementa los Algoritmos de Ordenación para ordenar un vector de enteros en orden descendente.
 * Define las implementaciones de los siguientes métodos de Ordenación en vectores:
 *	- Burbuja
 *	- Inserción
 *	- Selección.
 */
#include "AlgoritmosOrdenacion.h"

int posMaximo(int a[], int primero, int ultimo);
int posMinimo(int a[], int primero, int ultimo);
void swap(int a[], int i, int j);



AlgoritmosOrdenacion::AlgoritmosOrdenacion() {}
AlgoritmosOrdenacion :: ~AlgoritmosOrdenacion() {}

/*
 * método ordenaBurbuja, implementa el método de ordenación Burbuja.
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
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
 * método ordenaInsercion, implementa el método de ordenación por Inserción-
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
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
 * método ordenaSeleccion, implementa el método de ordenación por Selección.
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
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

//Examen modificacion
void AlgoritmosOrdenacion::mayo22(int a[], int primero, int ultimo)
{
	while (primero<ultimo)
	{
		swap(a,ultimo,posMaximo(a,primero,ultimo));
		ultimo = ultimo - 1;
		swap(a, primero, posMinimo(a, primero, ultimo));
		primero = primero + 1;
	}
}

int posMaximo(int a[], int primero, int ultimo)
{
	int pmaximo = primero;

	for (int i = primero + 1; i <= ultimo; i++)
	{
		if (a[i] > a[pmaximo])
			pmaximo = i;
	}

	return pmaximo;
}

int posMinimo(int a[], int primero, int ultimo)
{
	int pminimo = primero;

	for (int i = primero + 1; i <= ultimo; i++)
	{
		if (a[i] < a[pminimo])
			pminimo = i;
	}

	return pminimo;
}

void swap(int a[], int i, int j)
{
	int aux = a[i];
	a[i] = a[j];
	a[j] = aux;
}