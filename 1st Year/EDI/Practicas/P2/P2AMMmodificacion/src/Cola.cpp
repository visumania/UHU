#include "Cola.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

cola::cola()
{
    elementos = new cliente[INCREMENTO];

    if(elementos == NULL)
    {
        ne = fin = inicio = -1;
        Tama = -1;
    }
    else
    {
        ne = fin = inicio = 0;
        Tama = INCREMENTO;
    }
}

cola::~cola()
{
    if(elementos != NULL)
        delete [] elementos;

    elementos = NULL;
    ne = fin = inicio = -1;
    Tama = 0;
}

void cola::encolar(cliente e)
{
    if(ne == Tama)
    {
        cliente *elementosTMP = new cliente[Tama+INCREMENTO];

        if(elementosTMP != NULL)
        {
            for(int i = 0; i < ne; i++)
            {
                elementosTMP[i] = elementos[inicio];
                inicio = (inicio+1)%Tama;
            }

            inicio = 0;
            fin = ne;
            Tama += INCREMENTO;

            if(elementos != NULL)
                delete [] elementos;

            elementos = elementosTMP;
        }
    }

    if(ne < Tama)
    {
        fin -= fin/Tama;
        elementos[fin] = e;
        fin = (fin+1)%Tama;
        ne++;
    }
}

void cola::desencolar()
{
    if(ne == 0)
        return;

    inicio = (inicio+1)%Tama;
    ne--;

    if(Tama-ne == INCREMENTO && Tama > INCREMENTO)
    {
        cliente *aux = new cliente[Tama-INCREMENTO];

        if(aux != NULL)
        {
            for(int i = 0; i < ne; i++)
            {
                aux[i] = elementos[inicio];
                inicio = (inicio+1)%Tama;
            }

            Tama -= INCREMENTO;
            inicio = 0;
            fin = ne;

            if(elementos != NULL)
                delete [] elementos;

            elementos = aux;
        }
    }
}

bool cola::esvacia()
{
    return ne==0;
}

cliente cola::primero()
{
    return elementos[inicio];
}

int cola::longitud()
{
    return ne;
}

void cola::vaciar()
{
    if(elementos != NULL)
        delete [] elementos;

    elementos = new cliente[INCREMENTO];
    ne = fin = inicio = 0;
    Tama = INCREMENTO;
}

void cola::clonar(cola &c)
{
    vaciar();
    cola aux; //Para no perder la original

    while(!c.esvacia())
    {
        encolar(c.primero());
        aux.encolar(c.primero());
        c.desencolar();
    }

    while(!aux.esvacia())
    {
        c.encolar(aux.primero());
        aux.desencolar();
    }
}

bool cola::comparar(cola &c)
{
    if(c.longitud() != longitud())
        return false;

    bool igual = true;
    cola aux;

    while(!c.esvacia())
    {
        aux.encolar(primero());

        if(igual)
            igual = compararClientes(primero(), c.primero());

        c.desencolar();
        desencolar();
    }

    while(!aux.esvacia())
    {
        encolar(aux.primero());
        aux.desencolar();
    }

    return igual;
}

bool cola::compararClientes(cliente c1, cliente c2)
{
    return strcmp(c1.Nombre, c2.Nombre) == 0 &&
            strcmp(c1.Apellidos, c2.Apellidos) == 0 &&
            c1.Edad == c2.Edad &&
            c1.HoraLlegada  == c2.HoraLlegada &&
            c1.TipoServicio == c2.TipoServicio;
}
