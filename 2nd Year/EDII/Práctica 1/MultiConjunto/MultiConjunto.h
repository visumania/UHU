#ifndef MULTICONJUNTO_H_INCLUDED
#define MULTICONJUNTO_H_INCLUDED

#include "../Persona/Persona.h"

template <typename T>

class MultiConjunto
{
    T c [100]; //Vector de almacenamiento de elementos
    int num; //Indica el número de elementos en el multiconjunto
public:
    MultiConjunto(); //Constructor
    bool esVacio() const; //Comprueba si el multiconjunto es o no vacio
    int cardinalidad() const; //Devuelve el número de elementos
    void anade(const T &objeto); //Añade un objeto de tipo T al multiconjunto (se permiten objetos repetidos)
    void elimina(const T &objeto); //Elimina todas las concurrencias del objeto pasado como parámetro
    bool pertenece(const T &objeto) const; //Comprueba si el objeto pasado como parámetro existe en el multiconjunto
};

#endif // MULTICONJUNTO_H_INCLUDED
