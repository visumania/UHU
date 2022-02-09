#include <iostream>

using namespace std;

int main ()
{
   float bytes ;
   float Kbytes  ;

    cout << "Introduzca una cantidad de bytes" ;
    cin >> bytes ;

    Kbytes= bytes/1000 ;
    cout << Kbytes ;

    return 0;
}
