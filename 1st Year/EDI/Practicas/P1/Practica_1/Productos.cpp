#include "Productos.h"

productos::productos(cadena Fichero, cadena FicheroVentas)
{
    producto pro;
    strcpy(fichero,Fichero);
    resumen.open(Fichero , ios::in|ios::out|ios::binary); //Intentamos abrir el fichero resumen(productos)

    if(resumen.fail()) //Si falla o no existe:
    {
        resumen.close();
        resumen.clear();

        resumen.open(Fichero , ios::out|ios::binary); //en que caso de que no exista lo creamos
        resumen.close();

        resumen.open(Fichero , ios::in|ios::out|ios::binary);
    }

    if(resumen)
    {
        //maxcatalogo = 0;
       // numproductos = 0;

        resumen.read((char *)&pro , sizeof(pro));

        while(!resumen.eof())
        {
            maxcatalogo++;
            if(pro.tipo!=-1)
                numproductos++;
            resumen.read((char *)&pro , sizeof(pro));
        }
    }
}

productos::~productos()
{
    resumen.close();
    resumen.clear();
}

int productos::getmaxcatalogo()
{
    return this->maxcatalogo;
}

void productos::setmaxcatalogo(int num)
{
    this->maxcatalogo = num;
}

void productos::mostrarproductos()
{
    producto pro;
    resumen.close();
    resumen.clear();
    resumen.open(fichero , ios::in|ios::binary);

    resumen.read((char *)&pro , sizeof(pro));

    while(!resumen.eof())
    {
        cout << "Producto: " << pro.nombre << endl;
        cout << "Ultima venta: " << pro.ultimaventa.dia << "/" << pro.ultimaventa.mes << "/" << pro.ultimaventa.anno << endl;
        cout << "Importe: " << pro.importe << endl;
        cout << "Unidades: " << pro.unidades << endl;
        cout << "Tipo de producto: ";
        switch(pro.tipo)
        {
            case 1: cout << "Electronica" << endl;
            break;

            case 2: cout << "Papeleria" << endl;
            break;

            case 3: cout << "Otro" << endl;
            break;
        }
        cout << "__________________________________" << endl;

        resumen.read((char *)&pro ,sizeof(pro));
    }

    resumen.close();
}

void productos::mostrarventas()
{
    ven.mostrarventas();
}

bool productos::anadirventa()
{

}

void productos::actualizarresumen()
{
    ven.resumirfichero();
}

void productos::obtenerestadisticas(int tipo , int annoini , int annofin)
{
    ven.estadisticas(tipo,annoini,annofin);
}

