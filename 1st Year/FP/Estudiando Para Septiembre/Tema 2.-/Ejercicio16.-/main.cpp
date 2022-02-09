#include <iostream>

using namespace std;

int main()
{
    int cantidadsegundos ;
    int segundos , minutos , horas ;

    cout << "Introduzca un cantidad de segundos: " ;
    cin >> cantidadsegundos ;

   horas = cantidadsegundos / 3600 ;

   segundos = cantidadsegundos % 3600 ;

   minutos = segundos / 60 ;

   segundos = segundos % 60 ;

   cout << "\n" << cantidadsegundos << " segundos corresponden a " << horas << " horas " << minutos << " minutos y " << segundos << " segundos" ;

   return 0 ;
}
