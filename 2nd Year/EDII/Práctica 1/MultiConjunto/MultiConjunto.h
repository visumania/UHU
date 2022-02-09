#ifndef MULTICONJUNTO_H_INCLUDED
#define MULTICONJUNTO_H_INCLUDED

#include "../Persona/Persona.h"

template <typename T>

class MultiConjunto
{
    T c [100]; //Vector de almacenamiento de elementos
    int num; //Indica el n�mero de elementos en el multiconjunto
public:
    MultiConjunto(); //Constructor
    bool esVacio() const; //Comprueba si el multiconjunto es o no vacio
    int cardinalidad() const; //Devuelve el n�mero de elementos
    void anade(const T &objeto); //A�ade un objeto de tipo T al multiconjunto (se permiten objetos repetidos)
    void elimina(const T &objeto); //Elimina todas las concurrencias del objeto pasado como par�metro
    bool pertenece(const T &objeto) const; //Comprueba si el objeto pasado como par�metro existe en el multiconjunto
};

#endif // MULTICONJUNTO_H_INCLUDED
