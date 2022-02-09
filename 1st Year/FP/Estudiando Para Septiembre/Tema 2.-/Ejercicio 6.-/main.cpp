#include <iostream>

using namespace std;

int main()
{
    float teoria , practica;

    cout << "Introduzca nota teoria : " ;
    cin >> teoria ;

    cout << "Introduzca nota practica: " ;
    cin >> practica ;

    float notafinal;

    notafinal = teoria * 0.70 + practica * 0.30;

    cout << "La nota final es " << notafinal ;

    return 0 ;
}
