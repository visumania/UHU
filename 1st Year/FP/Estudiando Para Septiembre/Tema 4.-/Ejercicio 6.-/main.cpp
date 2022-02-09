#include <iostream>
#include <windows.h>

using namespace std;

class vector
{
    int tab1[10] , tab2[10];

public:
    void cargar();
    int comparar();
};

void vector::cargar()
{
    cout << "Tabla 1:\n";

    for(int i=0 ; i<10 ; i++)
    {
        cout << "Elemento " << i+1 << "#:";
        cin >> tab1[i];
    }

    system("pause");
    system("cls");

    cout << "Tabla 2:\n";

    for(int j=0 ; j<10 ; j++)
    {
        cout << "Elemento " << j+1 << "#:";
        cin >> tab2[j];
    }
}

int vector::comparar()
{
    int devuelve;

    int i ;
    bool encontrado;

    i=0;
    encontrado=true;

    while(i<10 && encontrado)
    {
            if(tab1[i]!=tab2[i])
                encontrado=false;
            else
                i++;
    }

    if(encontrado)
    {
        devuelve=0;
        cout << "\n0, por lo tanto son iguales\n";
    }
    else
    {
        devuelve=1;
        cout << "\n1 , por lo tanto son diferentes\n";
    }

    return devuelve;

}

int main()
{
    vector vc ;

    vc.cargar();
    vc.comparar();

    return 0;
}
