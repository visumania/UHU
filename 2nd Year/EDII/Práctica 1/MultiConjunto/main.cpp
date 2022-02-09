#include <iostream>

#include "MultiConjunto.h"

using namespace std;

int main()
{
    MultiConjunto<char> mc;
    MultiConjunto<Persona> mc1;

    if(mc.esVacio())
        cout << "El multiconjunto mc esta vacio" << endl;
    else
        cout << "El multiconjunto mc no esta vacio" << endl;

    cout << "Cardinalidad: " << mc.cardinalidad() << endl;

    mc.anade('a');
    mc.anade('b');
    mc.anade('a');

    if(mc.esVacio())
        cout << "El multiconjunto mc esta vacio" << endl;
    else
        cout << "El multiconjunto mc no esta vacio" << endl;

    cout << "Cardinalidad: " << mc.cardinalidad() << endl;

    mc.elimina('b');

    cout << "Cardinalidad: " << mc.cardinalidad() << endl;

    if(mc.pertenece('b'))
        cout << "La letra b pertenece al multiconjunto mc" << endl;
    else
        cout << "La letra b NO pertenece al multiconjunto mc " << endl;

    if(mc.pertenece('a'))
        cout << "La letra a pertenece al multiconjunto mc" << endl;
    else
        cout << "La letra a NO pertenece al multiconjunto mc" << endl;

    return 0;
}
