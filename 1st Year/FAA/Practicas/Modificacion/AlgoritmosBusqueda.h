/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de B�squeda para buscar un elemento en un vector de enteros.
 * Define las implementaciones iterativas de los siguientes m�todos de b�squeda en vectores de enteros:
 *	- Secuencial
 *	- Binaria o dicot�mica
 *      - Interpolacion
 */
#pragma once
 /*
  * declaraci�n de la clase AlgoritmosBusqueda
  */
class AlgoritmosBusqueda
{
public:
	AlgoritmosBusqueda();
	~AlgoritmosBusqueda();

	/*
	   * Funci�n busquedaSecuencialIt, implementa el m�todo de b�squeda secuencial Iterativo.
	   * param v: el array de enteros donde buscar
	   * param size: tama�o del array
	   * param key: clave o elemento a buscar
	   * return posici�n de la clave en el array
	   */
	int busquedaSecuencialIt(int v[], int size, int key);

	/*
	 * Funci�n busquedaBinariaIt, implementa el m�todo de b�squeda binaria Iterativa.
	 * param v: el array de enteros donde buscar
	 * param size: tama�o del array
	 * param key: clave o elemento a buscar
	 * return posici�n de la clave en el array
	 */
	int busquedaBinariaIt(int v[], int size, int key);

	/*
	 * Funci�n busquedaInterpolacionIt, implementa el m�todo por Interpolacion Iterativa.
	 * param v: el array de enteros donde buscar
	 * param size: tama�o del array
	 * param key: clave o elemento a buscar
	 * return posici�n de la clave en el array
	 */
	int busquedaInterpolacionIt(int v[], int size, int key);
};