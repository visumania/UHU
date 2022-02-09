#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class pila
{
    fstream fichero;
    int elemento;
    int tope;
public:
    pila();
    ~pila();
    void apilar(int e);
    void desapilar();
    int cima();
    bool esvacia();
    int longitud();
};

pila::pila()
{
    fichero.open("pila.dat" , ios::in|ios::out|ios::binary); //Intentamos abrir el fichero para lectura y escritura

    if(fichero.fail()) //Si falla en la apertura o no existe
    {
        fichero.close();
        fichero.clear();
        fichero.open("pila.dat",ios::out|ios::binary); //Lo crea
        fichero.close();
        fichero.open("pila.dat",ios::in|ios::out|ios::binary); //Lo abre tanto para lectura como para escritura
    }

    if(fichero)
    {
        tope = -1;
    }
}

pila::~pila()
{
    fichero.close();
}

void pila::apilar(int e)
{
    //fichero.open("pila.dat" , ios::in|ios::out | ios::binary);
    tope++;
    fichero.seekp(tope*sizeof(int), ios::beg);
    elemento = e;
    fichero.write((char *) &elemento , sizeof(int));
}

void pila::desapilar()
{
    tope--;
}

int pila::cima()
{
    fichero.seekg(tope*sizeof(int),ios::beg);
    fichero.read((char *)&elemento, sizeof(int));
    return elemento;
}

bool pila::esvacia()
{
    return(tope==-1);
}

int pila::longitud()
{
    return tope+1;
}

int main()
{
    int opcion;
    pila p;

    do
    {
        system("cls");

        cout << "\tPILA IMPLEMENTADA CON FICHERO:" << endl;
        cout << "1.- Apilar" << endl;
        cout << "2.- Longitud" << endl;
        cout << "3.- Desapilar" << endl;
        cout << "4.- Ver Cima" << endl;
        cout << "5.- Esta vacia?" << endl;
        cout << "6.- Salir" << endl;
        cout << "Elija opcion: " ;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            {
                int elemento;

                cout << "Introduzca el elemento que desea apilar: " ;
                cin >> elemento;

                p.apilar(elemento);
            }
            break;

        case 2:
            {
                cout << p.longitud() << endl;
            }
            break;

        case 3:
            {
                p.desapilar();
            }
            break;

        case 4:
            {
                cout << p.cima() << endl;
            }
            break;

        case 5:
            {
                if(p.esvacia())
                    cout << "La pila esta vacia" << endl;
                else
                    cout << "La pila no esta vacia" << endl;
            }
            break;

        case 6:
            {
                cout << "Saliendo del programa ... " << endl;
            }
            break;

        default: cout << "Error , opcion incorrecta" << endl;

        }

        system("pause");

    }while(opcion!=6);

    return 0;
}
