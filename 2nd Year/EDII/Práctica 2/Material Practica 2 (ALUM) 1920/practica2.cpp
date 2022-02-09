#include <iostream>
#include <cstdlib>
#include <queue>
#include "arbin.h"
#include "abb.h"

// Recorridos

template <typename T>
void inorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        inorden(a, a.subIzq(r));
        cout << r.observar() << " ";
        inorden(a, a.subDer(r));
    }
}

template <typename T>
void preorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        cout << r.observar() << " ";
        preorden(a, a.subIzq(r));
        preorden(a, a.subDer(r));
    }
}

template <typename T>
void postorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        postorden(a, a.subIzq(r));
        postorden(a, a.subDer(r));
        cout << r.observar() << " ";
    }
}

template <typename T>
void anchura(const Arbin<T>& a) {
    if (!a.esVacio()) {
        queue<typename Arbin<T>::Iterador> c;
        typename Arbin<T>::Iterador ic = a.getRaiz();
        c.push(ic);
        while (!c.empty()) {
             ic = c.front();
             c.pop();
             cout << ic.observar() << " ";
             if (!a.subIzq(ic).arbolVacio())
                c.push(a.subIzq(ic));
             if (!a.subDer(ic).arbolVacio())
                c.push(a.subDer(ic));
        }
    }
}


/***************************************************************************/
/****************************** EJERCICIOS *********************************/
/***************************************************************************/
//Ejercicio 1

template <typename T>
int numHojas(const Arbin<T> &a)
{
    return numHojas(a,a.getRaiz());
}

template <typename T>
int numHojas(const Arbin<T> &a , const typename Arbin<T>::Iterador &r)
{
    if(r.arbolVacio()) //Caso de árbol vacío
        return 0;
    else
        if(a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio()) //Caso de un arbol no vacio con un solo nodo (árbol raiz y hoja al mismo tiempo)
            return 1;
        else
            return numHojas(a,a.subIzq(r)) + numHojas(a,a.subDer(r));

}

/****************************************************************************/
//Ejercicio 2

template <typename T>
const Arbin<T> &simetrico(const Arbin<T> &a)
{
    return *simetrico<T>(a,a.getRaiz());
}

template <typename T>
const Arbin<T> *simetrico(const Arbin<T> &a , const typename Arbin<T>::Iterador &r)
{
    if(r.arbolVacio())
        return new Arbin<T>();
    else
        return new Arbin<T>(r.observar(), *simetrico(a, a.subDer(r)) , *simetrico(a,a.subIzq(r)));
}

/****************************************************************************/
//Ejercicio 3

template <typename T>
void recorridoZigzag(const Arbin<T> &a, char sentido)
{
    recorridoZigzag(a,a.getRaiz(),sentido);
}

template <typename T>
void recorridoZigzag(const Arbin<T> &a , const typename Arbin<T>::Iterador &i , char sentido)
{
    if(!i.arbolVacio()) //Si el arbol que nos pasan por parámetro no esta vacio
    {
        cout << i.observar() << " ";

        if(sentido == 'I')
            recorridoZigzag(a,a.subIzq(i),'D');
        if(sentido == 'D')
            recorridoZigzag(a,a.subDer(i),'I');
    }
}

/******************************************************************************/
//Ejercicio 4

template <typename T>
bool compensado(const Arbin<T> &a)
{
     return compensado(a,a.getRaiz());
}

template <typename T>
bool compensado(const Arbin<T> &a , const typename Arbin<T>::Iterador &r)
{
    if(r.arbolVacio() || (a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio()))//Si el arbol esta vacio o tiene un solo nodo
        return true;
    else
        if(!(compensado(a,a.subIzq(r)) && compensado(a,a.subDer(r))))
            return false;
        else
            return abs(hijos(a,a.subIzq(r)) - hijos(a,a.subDer(r))) <=1;
}

template <typename T>
int hijos(const Arbin<T> &a , const typename Arbin<T>::Iterador &r)
{
    if(r.arbolVacio())
        return 0;
    else
    {
        int n=0;

        if(!a.subIzq(r).arbolVacio())
            n++;
        if(!a.subDer(r).arbolVacio())
            n++;

        return n;
    }
}

/*****************************************************************************/
//Ejercicio 5

template <typename T>
void palabras(const Arbin<T> &a)
{
    palabras(a,a.getRaiz(), "");
}

template <typename T>
void palabras(const Arbin<T> &a , const typename Arbin<T>::Iterador &r , string palabra)
{
    if(!r.arbolVacio()) //Si el árbol no está vacío
        if(a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio())
            cout << palabra + r.observar() << endl;
        else
        {
            palabras(a,a.subIzq(r) , palabra+r.observar());
            palabras(a,a.subDer(r) , palabra+r.observar());
        }
}

/******************************************************************************/
//Ejercicio 6
//Resuelto como vienen en las diapositivas de la práctica 2 --> No funciona

/*int minimo(const ABB<int> &a , const ABB<int>::Iterador &r) //Función auxiliar llamada minimo: dado un abb te devuelve el valor minimo elemento que se encuentra en el árbol
{
    if(a.subIzq(r).arbolVacio())
        return (r.observar());
    else
        return(minimo(a,a.subIzq(r)));
}

void siguienteMayor(const ABB<int> &a , const ABB<int>::Iterador &r , int x , int &sm)
{
    int eRaiz;

    if(!r.arbolVacio())
    {
        eRaiz = r.observar(); //elemento que se encuentra en la raíz del árbol

        if(eRaiz == x) //elemento x coincide con la raiz del árbol (o subárbol) que se estas analizando
            if(!a.subDer(r).arbolVacio())
                sm = minimo(a,a.subDer(r));
        else
            if(eRaiz < x)
                siguienteMayor(a,a.subDer(r),x,sm);
            else
            {
                sm = eRaiz;
                siguienteMayor(a,a.subIzq(r),x,sm);
            }
    }
}

int siguienteMayor(const ABB<int> &a, int x) throw(NoHaySiguienteMayor)
{
    int sm=0; //Variable donde almacenaremos el siguiente mayor (la inicializamos a 0)

    siguienteMayor(a,a.getRaiz(),x,sm);

    if(sm == 0)
        throw(NoHaySiguienteMayor());
    else
        return sm;
}*/


//Resuelto como tiene BorjaLive -->si funciona (REVISAR BIEN EL CODIGO PARA VER EXACTAMENTE QUE ES LO QUE ESTA HACIENDO)

int siguienteMayor(const ABB<int> &a , const typename ABB<int>::Iterador &r , int x) throw (NoHaySiguienteMayor)
{
    if(r.arbolVacio())
        throw NoHaySiguienteMayor();
    else
    {
        if(r.observar() <= x)
            return siguienteMayor(a,a.subDer(r),x);
        else
        {
            try
            {
                return siguienteMayor(a,a.subIzq(r),x);
            }catch(NoHaySiguienteMayor)
                {
                    return r.observar();
                }
        }
    }
}

int siguienteMayor(const ABB<int> &a, int x) throw (NoHaySiguienteMayor)
{
    return siguienteMayor(a,a.getRaiz(),x);
}

/******************************************************************************/
//Ejercicio 7

int posicionInorden(const ABB<int> &a , const typename Arbin<int>::Iterador &r , int x , int &n)
{
    int pos=0;

    if(!r.arbolVacio())
    {
        pos = posicionInorden(a,a.subIzq(r),x,n);

        if(pos==0)
        {
            n++;

            if(r.observar() == x)
                pos = n;
            else
                pos = posicionInorden(a,a.subDer(r),x,n);
        }
    }

    return pos;
}

int posicionInorden(const ABB<int> &a , int x)
{
    int n=0;

    return posicionInorden(a,a.getRaiz(),x,n);
}

/******************************************************************************/
//Ejercicio 8

bool haySumaCamino(const Arbin<int> &a , const typename Arbin<int>::Iterador &r , int suma)
{
    if(r.arbolVacio()) //Si el árbol está vacío
        return false;
    else
        if(a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio()) //Si solamente hay un nodo en todo el árbol
            return suma-r.observar() == 0;
        else
            return haySumaCamino(a,a.subIzq(r),suma-r.observar()) || haySumaCamino(a,a.subDer(r),suma-r.observar());
}
bool haySumaCamino(const Arbin<int> &a, int suma)
{
    haySumaCamino(a, a.getRaiz(),suma);
}

/****************************************************************************/
/****************************************************************************/
int main(int argc, char *argv[])
{
    Arbin<char> A('t', Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()));

    Arbin<char> B('t', Arbin<char>('n', Arbin<char>(),
                                        Arbin<char>('d', Arbin<char>('e', Arbin<char>(), Arbin<char>()),
                                                         Arbin<char>())),
                       Arbin<char>('m', Arbin<char>('f', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('n', Arbin<char>(), Arbin<char>())));

    Arbin<char> D('t', Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()),
                       Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())));

    Arbin<char> E('o', Arbin<char>('r', Arbin<char>(),
                                        Arbin<char>('o', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('l', Arbin<char>('a', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('e', Arbin<char>(), Arbin<char>())));

    Arbin<int> F(2, Arbin<int>(7, Arbin<int>(2, Arbin<int>(), Arbin<int>()),
                                  Arbin<int>(6, Arbin<int>(5, Arbin<int>(), Arbin<int>()),
                                                Arbin<int>(11, Arbin<int>(), Arbin<int>()))),
                    Arbin<int>(5, Arbin<int>(),
                                  Arbin<int>(9, Arbin<int>(),
                                                  Arbin<int>(4, Arbin<int>(), Arbin<int>()))));

    ABB<int> BB6, BB7;


    // NUMERO HOJAS //
    cout << "Num. hojas del arbol B: " << numHojas(B) << endl;
    cout << "Num. hojas del arbol E: " << numHojas(E) << endl << endl;

    // COPIA SIMETRICA //
    Arbin<char> C = simetrico(B);
    cout << "Recorrido en inorden del arbol B: " << endl;
    inorden(B, B.getRaiz());
    cout << endl << "Recorrido en inorden del arbol C: " << endl;
    inorden(C, C.getRaiz());
    cout << endl << endl;


    // RECORRIDO EN ZIG-ZAG //
    cout << "Recorrido en zigzag I de B:\n";
    recorridoZigzag(B, 'I');
    cout << endl;
    cout << "Recorrido en zigzag D de C:\n";
    recorridoZigzag(C, 'D');
    cout << endl << endl;


    // COMPENSADO //
    cout << "Esta A compensado?:";
    cout << (compensado(A) ? " SI" : " NO") << endl;
    cout << "Esta B compensado?:";
    cout << (compensado(B) ? " SI" : " NO") << endl << endl;


    // PALABRAS DE UN ARBOL //
    cout << "PALABRAS DE E:\n";
    palabras(E);
    cout << "PALABRAS DE B:\n";
    palabras(B);


    // SIGUIENTE MAYOR
    BB6.insertar(8); BB6.insertar(3); BB6.insertar(10); BB6.insertar(1); BB6.insertar(6);
    BB6.insertar(14); BB6.insertar(4); BB6.insertar(7); BB6.insertar(13);
    try
    {
        cout << "Siguiente mayor en BB6 de 5: " << siguienteMayor(BB6, 5) << endl;
        cout << "Siguiente mayor en BB6 de 8: " << siguienteMayor(BB6, 8) << endl;
        cout << "Siguiente mayor en BB6 de 13: " << siguienteMayor(BB6, 13) << endl;
        cout << "Siguiente mayor en BB6 de 14: " << siguienteMayor(BB6, 14) << endl;
    }
    catch(const NoHaySiguienteMayor& e)
    {
        cout << e.Mensaje() << endl << endl;
    }

    // POSICION INORDEN //
    BB7.insertar(5); BB7.insertar(1); BB7.insertar(3); BB7.insertar(8); BB7.insertar(6);
    cout << "Posicion Inorden en BB7 de 3: ";
    cout << posicionInorden(BB7, 3);
    cout << endl << "Posicion Inorden en BB7 de 8: ";
    cout << posicionInorden(BB7, 8);
    cout << endl << "Posicion Inorden en BB7 de 7: ";
    cout << posicionInorden(BB7, 7);
    cout << endl << endl;


    // SUMA CAMINO
    cout << "Hay un camino de suma 26 en F?:";
    cout << (haySumaCamino(F, 26) ? " SI" : " NO") << endl;
    cout << "Hay un camino de suma 9 en F?:";
    cout << (haySumaCamino(F, 9) ? " SI" : " NO") << endl;


    system("PAUSE");
    return 0;
}
