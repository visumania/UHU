#include <iostream>

using namespace std;

int main()
{
    float nota1 , nota2 , nota3 , nota4 , nota5;
    float media;

    cout << "Introduzca nota 1: " ;
    cin >> nota1;

    cout << "Introduzca nota 2: " ;
    cin >> nota2;

    cout << "Introduzca nota 3: " ;
    cin >> nota3;

    cout << "Introduzca nota 4: " ;
    cin >> nota4;

    cout << "Introduzca nota 5: " ;
    cin >> nota5;

    media = (nota1 + nota2 + nota3 + nota4 + nota5) / 5 ;

    cout << "\nLa media de las cinco notas es de " << media << "\n" ;

    return 0 ;
}
