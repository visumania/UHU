#pragma once
// Clase conjunto de enteros con tama�o m�ximo limitado.
#define MAXIMO 5  // TAMA�O M�XIMO 5
class Operaciones
{
private:
    int tamano;
    int datos[MAXIMO];
public:
    void Insertar(int n);
    int Busqueda_lineal(int n);
    void Ordena(int tam);
    void Visualizar(int tam);
    void Vaciar();
};