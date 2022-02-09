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
    strcpy(nom , nombre);
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
    if(stock>0)
    {
        stock = stock - cantidad;
        cout << "Precio a cobrar: " << precio * cantidad ;
    }
    else
        cout << "No hay suficientes articulo en stock";
}

//int main()
//{
//    tprod producto ;
//
//    cad nombre ;
//    float precio ;
//    int cantidad;
//
//
//    cout << "Introduzca nombre del producto: " ;
//    cin >> nombre;
//
//    producto.cambiarnombre(nombre);
//    cad n;
//    producto.leenombre(n);
//
//    cout << "\nIntroduzca precio del producto: " ;
//    cin >> precio;
//
//    producto.cambiarprecio(precio);
//    producto.leeprecio();
//
//    cout << "\nIntroduzca cantidad del producto: " ;
//    cin >> cantidad ;
//
//    producto.cambiarstock(cantidad) ;
//    int stock;
//    producto.leestock(stock);
//
//    system("cls");
//
//    cout << "Nombre del producto: " << n;
//    cout << "\nPrecio del producto: " << precio ;
//    cout << "\nNumero de articulos en stock: " << stock;
//}

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

    i=0 ;
    encontrado = false;

    while (i<nprod && !encontrado)
    {
        cad nomb;
         productos[i].leenombre(nomb);
        if(strcmp(nom , nomb) == 0)
            encontrado = true;
        else
            i++;
    }

    if(!encontrado)
        i = -1 ;

    return i;

}

void almacen::verprod(int pos , tprod &prod)
{
    cad nom;
    productos[pos].leenombre(nom);
    prod.cambiarnombre(nom);

    float prec;
    prec = productos[pos].leeprecio();
    prod.cambiarprecio(prec);

    int sto ;
    productos[pos].leestock(sto);
    prod.cambiarstock(sto);
}

int almacen::insertar(tprod P)
{
    int devolver=0; // Variable comodin para el return

    if(nprod == MAX)
    {
        devolver = 2;
    }
    else
    {
        cad nom;
        P.leenombre(nom);
        if(existe(nom) != -1)
            devolver = 1 ;
        else
        {
            productos[nprod] = P;
            nprod ++;
        }
    }

    return devolver;
}

void almacen::vertabla()
{
    if (nprod==0)
        cout << "El almacen se encuentra vacio\n";
    else
    {
        for(int i=0 ; i<nprod ; i++)
        {
            cad nom ;
            float prec ;
            int sto ;

            productos[i].leenombre(nom);
            prec = productos[i].leeprecio();
            productos[i].leestock(sto);

           cout << "Nombre: " << nom;
           cout << "Precio: " << prec;
           cout << "Cantidad en stock:" <<sto << "\n";
        }
    }
}

void almacen::vender(int pos, int cant)
{
    if(pos>-1 && pos<MAX)
    {
        productos[pos].vender(cant);
    }
}

char menu()
{
     char i;

    system("cls");

    cout << "************* MENU ****************\n";
    cout << "***** A.- Visualizar la tabla.*****\n";
    cout << "***** B.- Insertar un producto.****\n";
    cout << "***** C.- Vender un producto.******\n";
    cout << "***** D.- Vaciar el almacen.*******\n";
    cout << "***** E.- Salir.*******************\n";
    cout << "***********************************\n";
    cout << "\nPon la opcion que deseas: " ;
    cin >> i;// a
    i=toupper(i); //Transforma a en A

    return i;
}

int main()
{
    tprod t ;
    almacen alm;
    char i ;
    cad nombre ;
    float precio ;
    int stock;

    do
    {
        i=menu();
        switch(i)
            {
                case 'A':
                    {
                        alm.vertabla();

                        cout <<"\n";

                        system("pause");
                        system("cls");

                        break;
                    }

                case 'B':
                    {


                        cout << "Introduzca el nombre del producto:";
                        cin >> nombre;
                        t.cambiarnombre(nombre);

                        cout << "Introduzca el precio del producto: ";
                        cin >>precio;
                        t.cambiarprecio(precio);

                        cout << "Introduzca la cantidad en stock del producto: ";
                        cin >> stock;
                        t.cambiarstock(stock);

                        alm.insertar(t);

                        cout <<"\n";

                        system("pause");
                        system("cls");

                        break ;
                    }
                case 'C':
                    {
                        int posicion  ;
                        int cantidad ;

                        cout << "Dame la posicion del producto a vender: " ;
                        cin >> posicion ;

                        cout <<  "Introduzca numero de articulos a vender del producto: ";
                        cin >> cantidad ;

                        alm.vender(posicion,cantidad);

                        cout <<"\n";

                        system("pause");
                        system("cls");

                        break;
                    }
                case 'D':
                    {
                        alm.vaciar();

                        cout <<"\n";

                        system("pause");
                        system("cls");

                        break;
                    }
            }

    }while(i!='E');

    return 0;
}

