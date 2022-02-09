#include <iostream>
#include <windows.h>

using namespace std;

class merges
{
    int uno[15] , dos[15] , fus[30];
    int numuno;
    int numdos;

public:
    void cargar();
    void mezclar();
    void ver();
    void verfusion();
};

void merges::cargar()
{
    cout << "Cuantos elementos desea introducir en la tabla 1 ? ";
    cin >> numuno;

    for(int i=0 ; i<numuno ; i++)
    {
        cout << "Introduzca elemento " << i+1 << " #: " ;
        cin >> uno[i];
    }

    for (int i = 0; i < numuno; i++) {
        cout << "Num " << i << " = " << uno[i];
    }

    system("pause");
    system("cls");

    cout << "Cuantos elementos desea introducir en la tabla 2 ? ";
    cin >> numdos;

    for(int j=0 ; j<numdos ; j++)
    {
        cout << "Introduzca elemento " << j+1 << " #: " ;
        cin >> dos[j];
    }
}

void merges::mezclar()
{
    int fusion ;
    int fusion2;

    fusion = numuno + numdos;

   for(int i=0 ; i<fusion ; i++)
   {
       fus[i]=uno[i];
   }

   for(int j=0 ; j<fusion ; j++)
   {
        fus[j+numuno]=dos[j];
   }
}

void merges::ver()
{

}

void merges::verfusion()
{

}

int main()
{
    merges mr ;

    mr.cargar();
    mr.mezclar();
    mr.ver();
    mr.verfusion();

    return 0;
}
