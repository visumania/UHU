#include <iostream>

using namespace std;

int main()
{
    int x , y , j , k ;
    int distanciaxj ;
    int distanciayk ;

    cout << "introduce coordenada x :" ;
    cin >> x ;

    cout << "introduce coordenada y : " ;
    cin >> y ;

    cout << "introduce coordenada j :" ;
    cin >> j ;

    cout << "introduce coordenada k :" ;
    cin >> k ;

    distanciaxj = x-j ;
    distanciayk = y-k ;

    cout << distanciaxj   << distanciayk ;

    return 0;
}
