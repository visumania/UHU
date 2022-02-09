#include <iostream>

using namespace std;

int main()
{
float examen1 , examen2 , examen3 , examen4 , examen5 ;
float notamedia ;

cout << "Introduzca la nota del examen 1: " ;
cin >> examen1 ;

cout << "Introduzca la nota del examen 2: " ;
cin >> examen2 ;

cout << "Introduzca la nota del examen 3: " ;
cin >> examen3 ;

cout << "Introduzca la nota del examen 4: " ;
cin >> examen4 ;

cout << "Introduzca la nota del examen 5: " ;
cin >> examen5 ;

notamedia = ((examen1 + examen2 + examen3 + examen4 + examen5 )/5) ;

cout << "\nLa nota media de los 5 examenes es : " << notamedia;

return 0;



}
