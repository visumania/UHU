/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de B�squeda para buscar un elemento en un vector de enteros.
 * Define las implementaciones iterativas de los siguientes m�todos de b�squeda en vectores de enteros:
 *	- Secuencial
 *	- Binaria o dicot�mica
 *  - Interpolacion
 */

#include "AlgoritmosBusqueda.h"

 /*
  * Implementaci�n de los m�todos de la clase AlgoritmosBusqueda
  */
AlgoritmosBusqueda::AlgoritmosBusqueda() {}
AlgoritmosBusqueda:: ~AlgoritmosBusqueda() {}

/*
	 * Funci�n busquedaSecuencialIt, implementa el m�todo de b�squeda secuencial Iterativo
	 * param v: el array de enteros donde buscar
	 * param size: tama�o del array
	 * param key: clave o elemento a buscar
	 * return posici�n de la clave en el array
	 */
int AlgoritmosBusqueda::busquedaSecuencialIt(int v[], int size, int key)
{
	int i = 0;

	while (v[i] != key && i < size)
		i++;

	if (v[i] != key)
		i = -1;

	return i;
}

/*
	 * Funci�n busquedaBinariaIt, implementa el m�todo de b�squeda binaria Iterativa
	 * param v: el array de enteros donde buscar
	 * param size: tama�o del array
	 * param key: clave o elemento a buscar
	 * return posici�n de la clave en el array
	 */
int AlgoritmosBusqueda::busquedaBinariaIt(int v[], int size, int key)
{
	bool encontrado = false;
	int mitad, primero, ultimo;
	primero = 0;
	ultimo = size - 1;

	while (primero <= ultimo && !encontrado)
	{
		mitad = ((ultimo + primero) / 2);

		if (key == v[mitad])
			encontrado = true;
		else
		{
			if (key < v[mitad])
				ultimo = mitad - 1;
			else
			{
				if (key > v[mitad])
					primero = mitad + 1;
			}
		}
	}

	if (!encontrado)
		mitad = -1;

	return mitad;
}

/*
 * Funci�n busquedaInterpolacionIt, implementa el m�todo de b�squeda por Interpolacion Iterativa
 * param v: el array de enteros donde buscar
 * param size: tama�o del array
 * param key: clave o elemento a buscar
 * return posici�n de la clave en el array
 */
int AlgoritmosBusqueda::busquedaInterpolacionIt(int v[], int size, int key)
{
	int p, primero, ultimo;
	primero = 0;
	ultimo = size - 1;

	while ((v[ultimo] >= key) && (v[primero] < key))
	{
		p = primero + ((ultimo - primero) * (key - v[primero]) / (v[ultimo] - v[primero]));
		if (key > v[p])
		{
			primero = p + 1;
		}
		else
		{
			primero = p;
		}
	}

	if (v[primero] != key)
		primero = -1;

	return primero;
}