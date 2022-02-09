#ifndef LISTA_H
#define LISTA_H

#include <cstdlib>
#include <cstring>
#include "cola.h"

#define INCREMENTO 2

struct peluquero
{
    int Codigo;
    cadena Apellidos;
    cadena Nombre;
    int TipoServicio;
    cola Col;
};
class lista
{
    peluquero *elementos; // elementos de la lista
    int n;// nº de elementos que tiene la lista
    int Tama; // tamaño de la tabla en cada momento
public:
    lista(); // constructor de la clase
    ~lista();// destructor de la clase
    lista(peluquero &e);
    void vaciar();
    bool esvacia();
    int longitud();
    bool pertenece(peluquero &e);
    void insertar(int i, peluquero &e);
    void eliminar(int i);
    void modificar(int i, peluquero &e);
    peluquero &observar(int i);
    int posicion(peluquero &e);
};

void copiarpeluquero(peluquero &destino,peluquero &origen);
bool compararpeluquero(peluquero &p1,peluquero &p2);


#endif // LISTA_H
