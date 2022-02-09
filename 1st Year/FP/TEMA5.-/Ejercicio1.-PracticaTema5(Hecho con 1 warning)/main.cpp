#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

typedef char cad[20];

class tprod
{
    cad nombre ;//Almacenara el nombre del producto

    float precio ; //Almacenara el precio del producto
    int stock; // Almacenara la cantidad de stock del producto

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
    precio = 0.0;
    stock = 0 ;
}

void tprod::cambiarnombre(cad nom)
{
    strcpy(nombre , nom);
}

void tprod::cambiarprecio(float prec)
{
   precio = prec ;
}

void tprod::cambiarstock(int stoc)
{
   stock=stoc;
}

void tprod::leenombre(cad nom)
{
    strcpy(nom, nombre);
}

float tprod::leeprecio()
{
    return precio ;
}

void tprod::leestock(int &st)
{
    st = stock ;
}

void tprod::vender(int cantidad)
{
    if(stock<cantidad || cantidad<0)
         cout << "No hay en stock suficiente cantidad :(";
    else
    {
        precio=precio*cantidad;
        cout << "\nEl precio de su compra seria: " << precio;
        stock = stock - cantidad;
    }
}

/*int main()
{
    tprod prod ;

    cad producto ;

    cout << "Introduce el nombre del producto: ";
    cin >> producto;
    prod.cambiarnombre(producto);

    float precio ;
    do
    {
        cout << "Introduzca el precio del producto: ";
        cin >> precio ;

    }while(precio<0);
    prod.cambiarprecio(precio);

    int stock ;
    do
    {
        cout << "Introduzca cantidad de productos en stock: ";
        cin >> stock;

    }while(stock<0);
    prod.cambiarstock(stock);

    system("cls");

    cout << "***Resumen :**** \nNombre del producto : " << producto;
    cout << "\nPrecio del producto: " << precio ;
    cout << "\nCantidad disponible (en stock): " << stock << "\n";

    system("pause");
    system("cls");

    int cantidadacomprar;
    do
    {
        cout << "\nIntroduzca las unidades que usted desea obtener: ";
        cin >> cantidadacomprar;

    }while(cantidadacomprar<0);
    prod.vender(cantidadacomprar);

    return 0;

}*/

#define MAX 5

class almacen
{
    tprod productos[MAX];
    int nprod ;

public:
    almacen();
    void vaciar();
    int existe(cad nom);
    void verprod(int pos , tprod &prod);
    int insertar(tprod P);
    void vertabla();
    void vender(int pos , int cant);
    char menu();
    //Lo siguiente es borrar el main de la clase tprod ,
    // que se hara mas abajo
};

almacen::almacen()
{
    nprod=0;
}

void almacen::vaciar()
{
    nprod=0;
}

int almacen::existe(cad nom)
{
    int i;
    bool encontrado = false ;
    cad nombre;

    i=0;
    while(i<MAX && !encontrado)
    {
        productos[i].leenombre(nombre);
        if(strcmp(nombre , nom)==0)
            encontrado=true;
        else
            i++;
    }

    if(encontrado==true)
        cout << "Se encuentra en la posicion " << i+1 << " y su nombre es " << nombre ;
    else
        cout << "-1";

        return i;
}

void almacen::verprod(int pos , tprod &prod)
{
    prod=productos[pos];
}

int almacen::insertar(tprod P)
{
    int i;
    bool encontrado = false;
    cad nombre;
    cad p;
    if(nprod == MAX)
        i = 2;
    else
    {
        i=0;
        while(i<MAX && !encontrado)
        {
            productos[i].leenombre(nombre);
            P.leenombre(p);
            if (strcmp(nombre, p)==0)
                encontrado = true;
           else
            i++;
        }
        if(encontrado)
            i=1;
        else
        {
            productos[nprod]=P;
            nprod++;
            i=0;
        }
    }
    return i;
}

void almacen::vertabla()
{
    cad nombre ;
    float precio ;
    int stock ;

    if(nprod==0)
    {
        cout << "El almacen se encuentra vacio ";
    }
    else
    {
         for(int i=0 ; i<nprod ; i++)
            {
                productos[i].leenombre(nombre);
                cout << "Nombre del producto: " << nombre ;

                precio = productos[i].leeprecio();
                cout << "\nPrecio: " << precio ;

                productos[i].leestock(stock);
                cout << "\nStock del producto: " << stock;
                cout << endl;
            }
    }
}

void almacen::vender(int pos , int cant)
{
    productos[pos].vender(cant);
}

char almacen::menu()
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
        i=alm.menu();
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
                        int posicion ;
                        int cantidad;

                        alm.vender(cantidad,posicion);

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
