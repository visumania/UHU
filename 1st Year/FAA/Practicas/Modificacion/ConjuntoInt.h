#pragma once

#include <iostream>
using namespace std;

/////////// Declaraci�n de la clase conjuntoInt /////////////

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
	int* getDatos();
	void escribe();
	void Clonar(int* v, int tam);
	int generaKey();
};
