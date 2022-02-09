#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct reg1
{
    int codigo;
    int cantidad;
    int precio;
};

struct reg2
{
    int codigo;
    int cantidad;
    int peso;
};

struct reg3
{
    int codigo;
    int cantidad;
    int datos[2];
};

void crearPesos();
void crearPrecios();


//main del ejercicio 3:
/*int main()
{
    char opcion;

    do
    {
        system("cls");

        cout << "\t\tEste programa crea los ficheros con los codigos ordenados" << endl;
        cout << "1.- Crear fichero de pesos" << endl;
        cout << "2.- Crear fichero de precios" << endl;
        cout << "3.- Salir" << endl;
        opcion=getch();

        switch(opcion)
        {
            case '1': crearPesos();
            break;

            case '2': crearPrecios();
            break;

            case '3': cout << "Saliendo del programa..." << endl;
            break;

            default: cout << "Opcion incorrecta " << endl;

        }

        system("pause");

    }while(opcion!='3');

    return 0;
}
*/

void crearPesos()
{
    reg1 r1;
    int ultimo = -1;
    ofstream f1("precios.dat" , ios::binary);
    char seguir;

    if(f1)
    {
        cout << "Se crea el fichero de precios" << endl;

        do
        {
            do
            {
                cout << "Introduzca codigo: ";
                cin >> r1.codigo;
            }while(r1.codigo<=ultimo);

            ultimo = r1.codigo;

            cout << "Introduzca cantidad: " ;
            cin >> r1.cantidad;

            cout << "Introduzca precio: ";
            cin >> r1.precio;

            f1.write((char *)&r1 , sizeof(reg1));

            cout << "Desea seguir introduciendo datos?(s/n)";
            seguir=toupper(getch());

        }while(seguir!='N');

        f1.close();
    }
    else
        cout << "Error en la apertura del fichero" << endl;
}

void crearPrecios()
{
    reg2 r2;
    int ultimo = -1;
    ofstream f2("pesos.dat" , ios::binary);
    char seguir;

    if(f2)
    {
        do
        {
            do
            {
                cout << "Introduzca codigo: " ;
                cin >> r2.codigo;

            }while(r2.codigo<=ultimo);

            ultimo = r2.codigo;

            cout << "Introduzca cantidad: " ;
            cin >> r2.cantidad;

            cout << "Introduzca peso: " ;
            cin >> r2.peso;

            cout << "Desea seguir introduciendo datos?(s/n): " ;
            seguir=toupper(getch());

        }while(seguir!='N');

        f2.close();

    }
    else
        cout << "Error en la apertura del fichero" << endl;
}
