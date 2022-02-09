#include <iostream>

using namespace std;

int main()
{
   int numero1 , numero2 ;

   cout << "Introduzca dos numeros enteros: \n" ;
   cin >> numero1 >> numero2 ;

   if (numero1 > numero2)
    cout << "El mayor es:" << numero1 ;
    else if (numero1 < numero2)
    cout << "El mayor es: " << numero2 ;
         else
            cout << "Los numeros introducidos son iguales cabezabuque" ;

         return 0;
}
