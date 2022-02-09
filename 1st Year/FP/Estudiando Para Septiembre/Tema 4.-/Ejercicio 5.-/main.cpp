#include <iostream>
#include <windows.h>

using namespace std;

#define M 2
#define N 4

typedef char cadena[30];

struct persona
{
    int dni ;
    cadena nombres ;
};

class matrices
{
    persona tabla[M][N];

public:
    void cargar();
    void encontrar();
    void visualizar();
};

void matrices::cargar()
{
    for(int i=0 ; i<M ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cout << "\nIntroduzca dni sin letra: " ;
            cin >> tabla[i][j].dni;

            cout << "Introduzca nombre de la persona: " ;
            cin >> tabla[i][j].nombres;
        }
    }
}

void matrices::encontrar()
{
    int dniencontrar;

    system("cls");

    cout << "Introduzca dni a buscar: " ;
    cin >> dniencontrar ;

    int i ;
    int j ;
    bool encontrado ;

    i=0;
    encontrado = false;

    while(i<M && !encontrado)
    {
        j=0;

        while(j<N && !encontrado)
        {
            if(dniencontrar==tabla[i][j].dni)
                encontrado=true;
            else
                j++;
        }

        if(!encontrado)
            i++;
    }

    if(encontrado)
        cout << "\nSe ha encontrado el dni introducido por teclado y pertene a " << tabla[i][j].nombres << "\n";
    else
        cout << "\nNo se ha encontrado ningun dni en la lista de personas \n";
}

void matrices::visualizar()
{
    system("pause");
    system("cls");
    char opcion ;

    cout << "Desea visualizar tabla de elementos?(s/n): ";
    cin >> opcion;

    if(opcion=='s')
    {
        for(int i=0 ; i<M ; i++)
        {
            for(int j=0 ; j<N ; j++)
            {
                cout << "Nombre: " << tabla[i][j].nombres << "\n";
                cout << "Dni: " << tabla[i][j].dni << "\n\n";
            }
        }
    }

    if(opcion=='n')
        cout << "\nLa lista de elementos nos sera mostrada , gracias por usar el programa\n";
}

int main()
{
    matrices mat;

    mat.cargar();
    mat.encontrar();
    mat.visualizar();

    return 0;
}
