#include "MultiConjunto.h"

template <typename T>
MultiConjunto<T>::MultiConjunto()
{
    num = 0;
}

template <typename T>
bool MultiConjunto<T>::esVacio() const
{
    return num==0;
}

template <typename T>
int MultiConjunto<T>::cardinalidad() const
{
    return num;
}

template <typename T>
void MultiConjunto<T>::anade(const T &objeto)
{
    if(num<100)
    {
        c[num] = objeto;
        num++;
    }
}

template <typename T>
void MultiConjunto<T>::elimina(const T &objeto)
{
    int i=0;

    while(i<num)
    {
        if(c[i]==objeto)
        {
            c[i]=c[num-1];
            num--;
        }
        else
            i++;
    }
}

template <typename T>
bool MultiConjunto<T>::pertenece(const T &objeto) const
{
    bool encontrado;
    int i;

    encontrado=false;
    i=0;

    while(i<num && !encontrado)
    {
        if(c[i] == objeto)
            encontrado = true;
        else
            i++;
    }

    return encontrado;
}

template class MultiConjunto<int>;
template class MultiConjunto<char>;
template class MultiConjunto<Persona>;
