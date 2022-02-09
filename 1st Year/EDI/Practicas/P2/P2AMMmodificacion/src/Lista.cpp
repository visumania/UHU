#include "Lista.h"

#include <iostream>
lista::lista()
{
    elementos = NULL;
    vaciar();
}

lista::~lista()
{
    if(elementos != NULL)
        delete [] elementos;

    elementos = NULL;
    Tama = n = 0;
}

lista::lista(peluquero &e)
{
    vaciar();
    insertar(1, e);
}

void lista::vaciar()
{
    if(elementos != NULL)
        delete [] elementos;

    elementos = new peluquero[INCREMENTO];

    if(elementos == NULL)
        Tama = n = -1;
    else
    {
        Tama = INCREMENTO;
        n = 0;
    }
}

bool lista::esvacia()
{
    return n == 0;
}

int lista::longitud()
{
    return n;
}

bool lista::pertenece(peluquero &e)
{
    return posicion(e)!=-1;
}

void lista::insertar(int i, peluquero &e)
{
    if(n == Tama)//En caso de que la tabla este llena y tengamos que agrandarla
    {
       peluquero *aux = new peluquero[Tama+INCREMENTO];

        if(aux != NULL)
        {
            for(int j = 0; j < n; j++)
                copiarpeluquero(aux[j], elementos[j]);

            Tama += INCREMENTO;
            delete [] elementos;
            elementos = aux;
        }
    }

    if(n < Tama)//Agregamos el elemento implicando un posible desplazamiento del resto de elementos de la tabla
    {
        for(int pos = n-1; pos >= i-1; pos--)
            copiarpeluquero(elementos[pos+1], elementos[pos]);

        copiarpeluquero(elementos[i-1], e);
        n++;
    }
}

void lista::eliminar(int i)
{
    while(i < n)
    {
        copiarpeluquero(elementos[i-1], elementos[i]);
        i++;
    }

    n--;

    if(Tama-n >= INCREMENTO && Tama > INCREMENTO)
    {
        peluquero *aux = new peluquero[Tama-INCREMENTO];

        if(aux != NULL)
        {
            for(int pos = 0; pos < Tama-INCREMENTO; pos++)
                copiarpeluquero(aux[pos], elementos[pos]);

            Tama -= INCREMENTO;
            delete [] elementos;
            elementos = aux;
        }
    }
}

void lista::modificar(int i, peluquero &e)
{
    copiarpeluquero(elementos[i-1], e);
}

peluquero& lista::observar(int i)
{
    return elementos[i-1];
}

int lista::posicion(peluquero &e)
{
    int i = 0;

    while(!compararpeluquero(e, elementos[i++]));

    return (i==n?-1:i+1);
}

void copiarpeluquero(peluquero &destino,peluquero &origen)
{
    destino.Codigo = origen.Codigo;
    destino.TipoServicio = origen.TipoServicio;
    strcpy(destino.Nombre, origen.Nombre);
    strcpy(destino.Apellidos, origen.Apellidos);
    destino.Col.clonar(origen.Col);
}

bool compararpeluquero(peluquero &p1,peluquero &p2)
{
    return  p1.TipoServicio == p2.TipoServicio &&
            p1.Codigo == p2.Codigo &&
            strcmp(p1.Nombre, p2.Nombre) == 0 &&
            strcmp(p1.Apellidos, p2.Apellidos) == 0 &&
            p1.Col.comparar(p2.Col);
}
