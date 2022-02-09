#include <iostream>

using namespace std;

class movimiento
{
    float v0 , a , t ,s0;
    float vf , sf;

public:
    void solicitardatos();
    float calculardatos();
    void mostrardatos();

};

void movimiento::solicitardatos()
{
    cout << "Introduzca v0 , a , t , s0 " ;
    cin >> v0 ;
    cin >> a ;
    cin >> t ;
    cin >> s0 ;
}

float movimiento::calculardatos()
{
    vf = v0 + a*t;
    sf = s0 + v0*t + (a*t*t)/2 ;
}

void movimiento::mostrardatos()
{
    cout << "velocidad final = " << vf << "\n" ;
    cout << "superficie final = " << sf ;
}

int main()
{
    movimiento m ;

    m.solicitardatos();
    m.calculardatos();
    m.mostrardatos();


    return 0;
}
