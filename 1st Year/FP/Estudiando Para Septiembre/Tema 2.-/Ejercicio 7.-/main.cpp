#include <iostream>

using namespace std;

int main()
{
    int x1 , x2;
    int y1 , y2;

    cout << "Introduzca la coordenada del primer punto del plano : (eje x , eje y) " ;
    cin >> x1 >> y1;

    cout << "Introduzca la coordenada del segundo punto del plano : (eje x , eje y): " ;
    cin >> x2 >> y2;

    cout << "La distancia que hay entre los dos punto es : (" << x1-x2 << " , " << y1-y2 << ")\n" ;

    return 0 ;
}
