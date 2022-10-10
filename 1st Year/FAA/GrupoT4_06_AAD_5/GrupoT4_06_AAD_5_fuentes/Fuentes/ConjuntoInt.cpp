#include <iostream>
using namespace std;
#include <ctime>  //para time
#include <cstdlib> // for srand, rand
#include "ConjuntoInt.h"

ConjuntoInt::ConjuntoInt(int max)
{
	tamano = max;
	datos = new int[max];
}
ConjuntoInt::~ConjuntoInt()
{
	delete[] datos;
}
void ConjuntoInt::vaciar()
{
	tamano = 0;
}
int* ConjuntoInt::getDatos()
{
	int* v = datos;
	for (int i = 0; i < tamano; i++) {
		v[i] = datos[i];
	}
	return v;
}

void ConjuntoInt::GeneraVector(int tam)
{
	tamano = tam;
	srand((unsigned)time(NULL)); //srand(time(0));
	for (int i = 0; i < tamano; i++) {
		datos[i] = rand() % 1000; //genera un número aleatorio entre 1 y 999
	}
}
int ConjuntoInt::generaKey()
{
	return datos[rand() % tamano]; // devuelve el valor del  array en una posición aleatoria entre 1 y el tamaño del array
}
void ConjuntoInt::escribe()
{
	for (int i = 0; i < tamano; i++)
		cout << datos[i] << (i < tamano - 1 ? ", " : "\n");
}
int ConjuntoInt::getPrimero()
{
	return datos[0];
}
int ConjuntoInt::busquedaSecuencial(int valor)
{
	int i = 0;
	while (datos[i] != valor && i < tamano)
	{
		i = i + 1;
	}
	if (datos[i] == valor)
		return i;	 // devuelve la posición i donde se encuentra el valor en el array
	else
		return -1;  // devuelve -1, no se encuentra el valor en el array
}
void ConjuntoInt::Insercion(int v[], int size) {

	int x, j;

	for (int i = 1; i < size; i++) {
		x = v[i];
		j = i - 1;
		while (j >= 0 && x < v[j]) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = x;
	}
}


void ConjuntoInt::Shell(int v[], int size) {
	for (int h = size / 2; h > 0; h /= 2) {
		for (int i = h; i < size; i++) {
			int j = i;
			int ve = v[i];
			while (j >= h and ve < v[j - h]) {
				v[j] = v[j - h];
				j -= h;
			}
			v[j] = ve;
		}
	}
}

void ConjuntoInt::Quicksort(int v[], int talla)
{
	Quicksort(v, 0, talla - 1);
}

void ConjuntoInt::Quicksort(int v[], int e, int d)
{
	if (e < d)
	{
		int q = partition(v, e, d);
		Quicksort(v, e, q);
		Quicksort(v, q + 1, d);
	}

}

int ConjuntoInt::partition(int v[], int e, int d)
{
	int x = v[e]; int i = e - 1; int j = d + 1;
	for (;;)
	{
		while (x < v[--j]);
		while (v[++i] < x);
		if (i >= j) return j;
		swap(v[i], v[j]);
	}

}
