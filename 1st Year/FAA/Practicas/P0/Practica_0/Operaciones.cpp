#include "Operaciones.h"
#include <iostream>
using namespace std;

void Operaciones::Insertar(int n)
{
    if (tamano < MAXIMO)
        datos[tamano++] = n; // pueden estar repetidos pues no se comprueba si ya está el n
    else
        cerr << "ERROR: el conjunto esta lleno " << endl;
}

int Operaciones::Busqueda_lineal(int n)
{
    int cont_comparaciones = 0;
    int cont_asignaciones = 0;
    int cont_operacionesElementales = 0;
    int ret = 0;

    int i = 0;
    cont_operacionesElementales++;

    while (datos[i] != n && i < tamano)
    {
        cont_operacionesElementales += 3;
        cont_comparaciones++;
        i = i + 1;
        cont_asignaciones++;
        cont_operacionesElementales += 2;
    }
    cont_comparaciones++;
    cont_operacionesElementales += 3;
    if (datos[i] == n)
        ret = i;	 // se encuentra el elemento en el array
    else
        ret = -1;  // no se encuentra el elemento en el array
    cont_operacionesElementales += 3;

    cout << "Numero comparaciones: " << cont_comparaciones << endl;
    cout << "Numero asignaciones: " << cont_asignaciones << endl;
    cout << "Numero operaciones elementales: " << cont_operacionesElementales << endl;

    return ret;
}

void Operaciones::Ordena(int tam)
{
    int cont_comparaciones = 0;
    int cont_asignaciones = 0;
    int cont_operacionesElementales = 0;

    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (datos[j] < datos[i]) 
            {
                int tmp = datos[i];
                cont_asignaciones++;
                cont_operacionesElementales += 2; //Acceso a datos[i] y asignación

                datos[i] = datos[j];
                cont_operacionesElementales += 3; //Acceso a datos[i], acceso a datos[j] y asignacion
                cont_asignaciones++;

                datos[j] = tmp;
                cont_asignaciones++;
                cont_operacionesElementales += 2; //Acceso a datos[j] y asignación
            }
            cont_comparaciones++;
            cont_operacionesElementales += 4; //Acceso a datos[j], acceso a datos[i] , comparación e incremento for
        }
        cont_operacionesElementales += 4; //Asignación, suma , comparación e incremento for
    }
    cont_operacionesElementales += 3; //Asignacion, resta y comparación

    cout << "Numero comparaciones: " << cont_comparaciones << endl;
    cout << "Numero asignaciones: " << cont_asignaciones << endl;
    cout << "Numero operaciones elementales: " << cont_operacionesElementales << endl;
}

void Operaciones::Visualizar(int tam)
{
    for (int i = 0; i < tam; i++)
        cout << datos[i] << (i < tam - 1 ? ", " : "\n");
}

void Operaciones::Vaciar()
{
    tamano = 0;
}
