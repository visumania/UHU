#include <iostream>

using namespace std;

#define M 10

class uno
{
    int tabla [M] ;

public:
    void cargar();
    int maximo ();
    int minimo ();
};

void uno::cargar()
{
    int valores ;



    for (int i=0 ; i<M ; i++)
        {
        cout << "Introduzca valor entero " << i+1 << " : " ;
        cin >> valores ;
        }
}

int uno::maximo()
{
    maximo() == tabla[M];

    for (int i=0 ; i < M ; i++)
    {
        if (maximo()< tabla[M])
            maximo()==tabla[M] ;
    }
    cout << "El maximo es:" <<  maximo() ;


}

//int uno::minimo()
//{
  //  return minimo();
//}

int main()
{
    uno numero ;

    numero.cargar();
    numero.maximo();
   // numero.minimo();

    return 0;
}
