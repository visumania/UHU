#include <iostream>

using namespace std;

int main()
{
   float bytes ;
   float kilobytes;

   cout << "Introduzca un numero de bytes para hacer la conversion a kilobytes: \n";
   cin >> bytes;

   kilobytes = bytes / 1000;

   cout << bytes << " bytes son " << kilobytes << " kilobytes " ;

   return 0;


}
