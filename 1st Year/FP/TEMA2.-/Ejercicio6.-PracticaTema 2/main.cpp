#include <iostream>

using namespace std;

int main()
{
    float Teoria , Practica , Final ;

    cout << " Nota Teoria " ;
    cin >> Teoria ;
    cout << " Nota Practica ";
    cin >> Practica ;
    Final = Teoria * 0.7 + Practica * 0.3 ;
    cout << Final ;
    return 0;
}
