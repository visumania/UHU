#include <iostream>
#include <string.h>

using namespace std;

typedef char  cadena[30];

struct producto
{
    cadena nomprod;
    int precio;
};

struct seccion
{
    producto prods[40];
    int nprod;
};

class empresa
{
    cadena nomempresa;
    seccion sec[5];
    int nsec;

public:
    empresa();
    bool insertar(int ns , producto prod);
    void numerosecciones(int &n);
    void listar();// no hay que implementarlo
};

empresa::empresa()
{
    cout << "Introduzca el nombre de la empresa: ";
    cin >> nomempresa;

    cout << "\nIntroduzca cuantas secciones tiene la empresa: " ;
    cin >> nsec;

    for(int i=0 ; i<nsec ; i++)
    {
        cout << "\nCuantos productos tiene la seccion " << i+1 << ": ";
        cin >> sec[i].nprod;

        for(int j=0 ; j<sec[i].nprod ; j++)
        {
            cout << "\n\nIntroduzca el nombre del producto " << j+1 << ": " ;
            cin >> sec[i].prods[j].nomprod;

            cout << "\nIntroduzca el nombre del producto " << j+1 << ": " ;
            cin >> sec[i].prods[j].precio;
        }
    }
}

bool empresa::insertar(int ns, producto prod)
{
    bool encontrado ;
    bool tablallena= false;
    bool devolver;
    int cantidad;
    int i , j ;

    i=0;
    encontrado = false;

    while(i<nsec && !encontrado)
    {
        j=0;

        while(j<sec[i].nprod && !encontrado)
        {
            if(strcmp(sec[i].prods.nomprod , prod.nomprod)==0)
                encontrado = true;
            else
                j++;
        }
        i++;
    }

    if(!encontrado)
    {
        if(sec[ns].nprod == 40)
            tablallena = true;
        else
        {
            cantidad = sec[ns].nprod;
            sec[ns].prods[cantidad] = prod;
            sec[ns].nprod++;
        }
    }

    if(encontrado)
    {
        devolver = false;
    }
    else
    {
        if(tablallena==true)
            devolver = false;
        else
            devolver = true;
    }

    return devolver;

}

void empresa::numerosecciones(int &n)
{
    n = nsec ;
}

void empresa::listar()
{
    for(int i=0 ;i<nsec ; i++)
    {
        cout << "SECCION N." << i+1 << ":\n";

        for(int j=0 ; j<sec[i].nprod ; j++)
        {
            cout << "PRODUCTO N." << j+1 << ": " << sec[i].prods[j].nomprod << "\nPrecio: " << sec[i].prods[j].precio "€\n\n";

        }
    }
}

int main()
{
    empresa emp;
    producto p;

    int numero;
    int numsec;
    bool insertado;

    cout << "\nIntroduzca el nombre de un producto: " ;
    cin >> p.nomprod;

    cout << "\nIntroduzca su precio(€): ";
    cin >> p.precio;

    emp.numerosecciones(numsec);// no entiendo el porque hace esto

    do
    {
        cout << "\nEn que seccion desea añadirlo? ";
        cin >> numero;

    }while(0>numero || numero>=numsec);

    emp.listar();

    insertado = emp.insertar(numero ,p);

    if(insertado)
        cout << "\nSe ha insertado correctamente\n";
    else
        cout << "\nError en la insercion\n";

    emp.listar();

    return 0;


}
