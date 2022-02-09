#include <iostream>
#include <windows.h>

using namespace std;

class vectors
{
    int tab1[10] , tab2[10];

public:
    void cargar();
    int comparar();
};

void vectors::cargar()
{
    for(int i=0 ; i<10 ; i++)
        {
            cout << "Introduzca valor de la tabla 1 de la posicion " << i+1 << "#: "  ;
            cin >> tab1[i];
        }

    system("cls");

    for(int i=0 ; i<10 ; i++)
         {
             cout << "Introduzca valor de la tabla 2 de la posicion " << i+1 << "#: " ;
             cin >> tab2[i];
         }

    // Aqui dudo si el recorrido para rellenar la segunda tabla
    // va dentro del recorrido de la primera tabla o va
    // independiente


}

int vectors::comparar()
{
    bool encontrado=true;
    int i;

    i=0;
    while((i<10) && encontrado==true)
    {
        if(tab1[i] != tab2[i])
            encontrado = false ;
        else
            i++;
    }

    system("cls");

    if(encontrado==true)
    {
        cout << "0 , por lo tanto son iguales " ;
    }
    else
    {
        cout << "1 , por lo tanto NO son iguales" ;
    }

    return encontrado ;

}

int main()
{
    vectors v ;

    v.cargar();
    v.comparar();

    return 0 ;
}
