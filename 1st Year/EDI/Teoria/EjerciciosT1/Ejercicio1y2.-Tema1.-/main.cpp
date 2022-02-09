#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    float **datos = new float*[100]; // Creamos Datos que apunta a un array de float de tamaño 100 que al mismo tiempo este último apunta a otro array de floats
    int fila , col;
    float suma=0;
    char respuesta;

    for(int i=0 ; i<100 ; i++)
    {
        datos[i]=new float[100-i];

        for(int j ; j<100-i ; j++)
            datos[i][j]=0.0;
    }

    //Para hacer la suma de los valores primeros habra que meterlos por teclado , ya que inicialmente estan a 0.0
    do
    {
        cout << "Introduzca fila: ";
        cin >> fila;

        cout << "Introduzca columna: ";
        cin >> col;

        cout << "Introduzca valor de la fila " << fila << " y de la columna " << col << ": ";
        cin >> datos[fila-1][col-1];

        cout << "Desea continuar introduciendo datos?(s/n): ";
        respuesta=toupper(getch());

    }while(respuesta!='N');

    //Una vez hayamos salido de este bucle que sirve para rellenar datos, ahora tendremos que hacer la suma de los valores:

    for(int i=0 ; i<100 ; i++)
    {
        for(int j=0 ; j<100-i ; j++)
            suma += datos[i][j];

        delete datos[i];
    }

    delete [] datos;

    cout << "La suma de los valores de la tabla es: " << suma;

    return 0;
}
