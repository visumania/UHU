#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <cstdlib>
#include "grafo.h"
#include "conjunto.h"
#include <queue>
#include <sstream>
#include <map>



using namespace std;

//Ejercicio 1
template <typename T>
T verticeMaxCoste(const Grafo<T, float>& G)
{
    map<T,float> coste; //Diccionario para almacenar los costes de cada vertice
    T v, vMax;

    //Inicializamos el diccionario de costes a 0
    Conjunto<Vertice<T> > cv = G.vertices();

    while(!cv.esVacio())
    {
        v = cv.quitar().getObj();
        coste[v] = 0;
    }

    //Actualizamos los costes de salida, sumando el coste de las aristas que salen de cada vértice
    Conjunto<Arista<T,float> > A = G.aristas();

    while(!A.esVacio())
    {
        Arista<T,float> a = A.quitar();
        coste[a.getOrigen()] += a.getEtiqueta();
    }

    //Recorrer el diccionario para encontrar el vertice con mayor coste
    float costeMax = 0;

    for(typename map<T,float>::iterator it = coste.begin() ; it != coste.end() ; it++)
    {
        if(it->second >= costeMax)
        {
            costeMax = it->second;
            vMax = it->first;
        }
    }

    return vMax;
}


//Ejercicio 2
template <typename T, typename U>
void inaccesibles(const Grafo<T, U>& G)
{
    Conjunto<Vertice<T> > vertices = G.vertices();

    while(!vertices.esVacio())
    {
        Vertice<T> tmp = vertices.quitar();

        if(G.antecesores(tmp.getObj()).esVacio())
            cout << tmp.getObj() << " ";
    }
}


// Ejercicio 3 --> Resolver este ejercicio con un algoritmo NO recursivo, y haciendo uso del TAD cola proporcionado por la STL (queue)
template <typename T, typename U>
bool caminoEntreDos(const Grafo<T, U>& G, const T& vo, const T& vd)
{
    queue<T> cola;
    cola.push(vo);
    Conjunto<T> cerrados;
    T actual = vo;

    do
    {
        Conjunto<Vertice<T> > adyacentes = G.adyacentes(actual);

        while(!adyacentes.esVacio())
        {
            T tmp = adyacentes.quitar().getObj();

            if(!cerrados.pertenece(tmp))
                cola.push(tmp);
        }

        cerrados.anadir(actual);
        actual = cola.front();
        cola.pop();
    }while(actual != vd && !cola.empty());

    return actual == vd;
}


//Ejercicio 4 --> Para esta ejercicio se recomienda usar un algoritmo recursivo
template <typename T>
void caminosAcotados(const Grafo<T, float>& G, const T& u, float maxCoste)
{
    stringstream ss;
    ss << u;
    caminosAcotados(G , u , maxCoste , ss.str() , 0);
}

template <typename T>
void caminosAcotados(const Grafo<T,float> &G, const T &u, float maxCoste, string s, float costeAcum)
{
    Conjunto<Arista<T,float> > ca = G.aristas();

    cout << "(" << s << ") coste = " << costeAcum << endl;

    while(!ca.esVacio())
    {
        Arista<T,float> a = ca.quitar();

        if(a.getOrigen() == u && (costeAcum + a.getEtiqueta() <= maxCoste))
        {
            stringstream ss;
            ss << a.getDestino();
            caminosAcotados(G,a.getDestino(),maxCoste, s+ " " + ss.str(), costeAcum + a.getEtiqueta());
        }
    }
}


//Ejercicio 5
template <typename T, typename U>
T outConectado(const Grafo<T, U>& G)
{
    map<T,int> valor;
    T outConectada;

    Conjunto<Vertice<T> > vertices = G.vertices();

    while(!vertices.esVacio())
        valor[vertices.quitar().getObj()] = 0;

    Conjunto<Arista<T,float> > aristas = G.aristas();

    while(!aristas.esVacio())
    {
        Arista<T,float> tmp = aristas.quitar();
        valor[tmp.getOrigen()] += 1;
        valor[tmp.getDestino()] -= 1;
    }

    bool encontrado = false;
    typename map<T,int>::iterator it = valor.begin();

    while(it != valor.end() && !encontrado)
    {
        if(it->second > 0)
        {
            outConectada = it->first;
            encontrado = true;
        }
        it++;
    }

    return outConectada;
}


//Ejercicio 6
template <typename T, typename U>
void recorrido_profundidad(const Grafo<T, U>& G, const T& v)
{
    //Diccionario para controlar los vertices ya visitados
    map<T,bool> visitados;

    //Inicializamos el diccionario de visitados a false
    Conjunto<Vertice<T> > cv;
    cv=G.vertices();

    while(!cv.esVacio())
        visitados[cv.quitar().getObj()] = false;

    //Llamamos a la funcion recursiva auxiliar
    recorrido_profundidad(G,v, visitados);
}

template <typename T, typename U>
void recorrido_profundidad(const Grafo<T,U> &G, const T &v, map<T,bool> &visitados)
{
    visitados[v] = true;
    cout << v << " ";

    Conjunto<Vertice<T> > ady = G.adyacentes(v);

    while(!ady.esVacio())
    {
        T u = ady.quitar().getObj();

        if(!visitados[u])
            recorrido_profundidad(G,u,visitados);
    }
}


//********************************************************************//
int main()
{
    Grafo<int, float> G(7);
    for (int i = 1; i <= 7; i++) G.insertarVertice(i);
    G.insertarArista(2, 1, 4);
    G.insertarArista(1, 3, 3);
    G.insertarArista(1, 4, 2);
    G.insertarArista(1, 6, 1);
    G.insertarArista(6, 4, 5);
    G.insertarArista(4, 7, 3);
    G.insertarArista(5, 1, 6);

    Grafo<string, float> H(7);
    H.insertarVertice("Huelva"); H.insertarVertice("Lepe"); H.insertarVertice("Niebla");
    H.insertarVertice("Mazagon"); H.insertarVertice("Almonte"); H.insertarVertice("Aljaraque");
    H.insertarVertice("Matalascañas");
    H.insertarArista("Lepe", "Huelva", 4);
    H.insertarArista("Huelva", "Niebla", 3);
    H.insertarArista("Huelva", "Mazagon", 2);
    H.insertarArista("Huelva", "Aljaraque", 1);
    H.insertarArista("Mazagon", "Almonte", 3);
    H.insertarArista("Mazagon", "Matalascañas", 4);
    H.insertarArista("Aljaraque", "Mazagon", 5);
    H.insertarArista("Almonte", "Huelva", 6);


    cout << " Vertice de maximo coste en G: " << verticeMaxCoste(G) << endl;
    cout << " Vertice de maximo coste en H: " << verticeMaxCoste(H) << endl;

    cout << endl << " Vertices inaccesibles en G: ";
    inaccesibles(G);

    cout << endl << " Camino entre Dos en H de Lepe a Almonte: ";
    cout << (caminoEntreDos(H, string("Lepe"), string("Almonte")) ? " SI " : " NO ") << endl;
    cout << endl << " Camino entre Dos en H de Aljaraque a Lepe: ";
    cout << (caminoEntreDos(H, string("Aljaraque"), string("Lepe")) ? " SI " : " NO ") << endl;

    cout << endl << " Caminos acotados en G a coste 9 desde el vertice 2:" << endl;
    caminosAcotados(G, 2, 9);

    cout << endl << endl << " Vertice outConectado en G: " << outConectado(G);
    cout << endl << " Vertice outConectado en H: " << outConectado(H);

    cout << endl << endl << " Recorrido en profundidad de H desde el vertice Huelva:  " << endl;
    recorrido_profundidad(H, string("Huelva"));
    cout << endl << endl;


    system("PAUSE");
    return EXIT_SUCCESS;
}
