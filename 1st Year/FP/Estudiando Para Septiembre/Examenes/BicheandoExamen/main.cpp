#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

typedef char cad[20];

class tprod
{
    cad nombre;
    float precio;
    int stock;

public:
    tprod();
    void cambiarnombre(cad nom);
    void cambiarprecio(float prec);
    void cambiarstock(int stoc);
    void leenombre(cad nom);
    float leeprecio();
    void leestock(int &st);
    void vender(int cantidad);
};

tprod::tprod()
{
    strcpy(nombre , "NO HAY PRODUCTO");
    precio = 0;
    stock = 0;
}

void tprod::cambiarnombre(cad nom)
{
    strcpy(nombre , nom);
}

void tprod::cambiarprecio(float prec)
{
    precio = prec;
}

void tprod::cambiarstock(int stoc)
{
    stock = stoc;
}

void tprod::leenombre(cad nom)
{
    strcpy(nom ,nombre);
}

float tprod::leeprecio()
{
    return precio;
}

void tprod::leestock(int &st)
{
    st = stock;
}

void tprod::vender(int cantidad)
{

    if(stock<cantidad)
    {
        cout << "\nNo hay articulos en stock\n";
    }
    else
    {
        cout << "\nEl precio a cobrar es de : " << cantidad * precio << endl;
        stock = stock-cantidad;
    }

    system("pause");

}

/*int main()
{
    tprod tabladeproductos;

    cad nombre;
    float precio;
    int cantidad;
    int cvender;
    int st;

    cout << "Introduzca nombre del producto: " ;
    cin >> nombre;
    tabladeproductos.cambiarnombre(nombre);

    cout << "\nIntroduzca precio del producto: " ;
    cin >> precio ;
    tabladeproductos.cambiarprecio(precio);

    cout << "\nIntroduzca cantidad de articulos que hay en stock: " ;
    cin >> cantidad;
    tabladeproductos.cambiarstock(cantidad);

    system("pause");
    system("cls");

    cout << "Introduzca cantidad a vender del producto: ";
    cin >> cvender;

    tabladeproductos.vender(cvender);

    tabladeproductos.leestock(st);

    cout << "\n\nLa nueva cantidad en stock es de " << st << endl;

    return 0;
}*/

#define MAX 5

class almacen
{
    tprod productos[MAX];
    int nprod;

public:
    almacen();
    void vaciar();
    int existe(cad nom);
    void verprod(int pos , tprod &prod);
    int insertar(tprod P);
    void vertabla();
    void vender(int pos, int cant);
};

almacen::almacen()
{
    nprod = 0;
}

void almacen::vaciar()
{
    nprod = 0;
}

int almacen::existe(cad nom)
{
    bool encontrado;
    int i;

    tprod tp;


    encontrado = false;
    i=0;

    while(i<nprod && !encontrado)
    {
        cad nombre;
        productos[i].leenombre(nombre);

        if(strcmp(nombre , nom)==0)
            encontrado = true;
        else
            i++;
    }

    if(!encontrado)
        i = -1;

    return i;
}

void almacen::verprod(int pos , tprod &prod)
{
    //prod = productos[pos];

    cad nombre;
    productos[pos].leenombre(nombre); // Copia el atributo en nombre
    prod.cambiarnombre(nombre); // Lo copia en prod que nos pasan por parametro

    float precio;
    productos[pos].leeprecio();
    prod.cambiarprecio(precio);

    int stock;
    productos[pos].leestock(stock);
    prod.cambiarstock(stock);
}

int almacen::insertar(tprod P)
{
    int devolver=0;

    if(nprod==MAX)
    {
        devolver = 2;
    }
    else
    {
        cad nombre;

        P.leenombre(nombre);

        if(existe(nombre)!=-1)
            devolver = -1;
        else
        {
            productos[nprod] = P;
            nprod++;
        }
    }

    return devolver;
}

void almacen::vertabla()
{
    if(nprod!=0)
    {
        for(int i=0 ; i<nprod ; i++)
        {
            cad nombre;
            float precio;
            int stock;

            productos[i].leenombre(nombre);
            precio = productos[i].leeprecio();
            productos[i].leestock(stock);

            cout << "\tPRODUCTO " << i+1 ;
            cout << "\nNombre : " << nombre;
            cout << "\nPrecio: " << precio << " euros";
            cout << "\nCantidad disponible: " << stock << " unidades\n\n";
        }

        system("pause");
    }
    else
    {
        cout << "\nEL ALMACEN ESTA VACIO\n\n";

        system("pause");

    }
}



void almacen::vender(int pos, int cant)
{
    productos[pos].vender(cant);
}

char menu()
{
    char i;

    system("cls");

    cout << "*************** MENU ***************";
    cout << "\n*****A.- Visualizar la tabla. ******";
    cout << "\n*****B.- Insertar un producto.******";
    cout << "\n*****C.- Vender un producto.  ******";
    cout << "\n*****D.- Vaciar el almacen.   ******";
    cout << "\n*****E.- Salir.               ******";
    cout << "\n************************************";
    cout << "\nPon la opcion que deseas: ";
    cin >> i;

    i=toupper(i);

    return i;
}

int main()
{
    almacen al;
    tprod tp;
    char i;
    cad nombre;
    float precio;
    int stock;
    int cantidad;

    do
    {
        system("cls");

        i=menu();

        switch(i)
        {
            case 'A':
                {
                    al.vertabla();

                    cout << "\n";
                }
                break;

            case 'B':
                {
                    cout << "\nIntroduzca el nombre del producto a insertar: ";
                    cin >> nombre;
                    tp.cambiarnombre(nombre);

                    cout << "\nIntroduzca el precio del producto a insertar: " ;
                    cin >> precio;
                    tp.cambiarprecio(precio);

                    cout << "\nIntroduzca la cantidad de articulos disponibles del producto a inserar: " ;
                    cin >> stock;
                    tp.cambiarstock(stock);

                    al.insertar(tp);

                    cout << "\n";
                }
                break;

            case 'C':
                {
                    cout << "\nIntroduzca el nombre del producto a vender: " ;
                    cin >> nombre;

                    int pos ;
                    pos = al.existe(nombre);

                    if(pos!=-1)
                    {
                        cout << "\nIntroduzca la cantidad a vender: ";
                        cin >> cantidad;

                        al.vender(pos, cantidad);
                    }
                    else
                    {
                        cout << "\nNo existe ningun producto con ese nombre";
                    }

                    cout << "\n";
                }
                break;

            case 'D':
                {
                   al.vaciar();

                   cout << "\n";
                }
                break;

            case 'E':
                {
                    cout << "\nSaliendo del programa...\n";
                }
                break;

            default:
                {
                    cout << "\nOpcion invalida";

                    system("pause");
                }
        }

    }while(i!='E');
}
