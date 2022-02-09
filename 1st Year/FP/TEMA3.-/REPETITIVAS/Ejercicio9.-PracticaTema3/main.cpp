#include <iostream>

using namespace std;

class patata
{
    int n;

public :
    void informacion();
    int suma();
};

void patata::informacion()
{
    cout << "Cuantos numeros quieres sumar? ";
    cin >> n ;
}

int patata::suma()
{
    int sumatorio ;
    sumatorio = n ;

    for (int i=n ; i>0 ; i--)
    {
        if((i%2)==0)
        {
            cout << i << "\t" ;
            sumatorio = sumatorio + i ;
        }


    }

    sumatorio = sumatorio - n ;

    cout << "\nEl sumatorio de " << n  << " exceptuando numeros primos es: " << sumatorio ;

    return sumatorio ;
}

int main()
{
    patata p;

    p.informacion();
    p.suma();

    return 0;
}
