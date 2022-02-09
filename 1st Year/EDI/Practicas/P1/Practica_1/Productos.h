#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include "Ventas.h"
#include <fstream>

/*struct Sfecha
{
    int dia;
    int mes;
    int anno;
};*/

struct producto
{
     Sfecha ultimaventa;
     int unidades;
     int producto;
     float importe;
     int tipo;
     char nombre[20];
};

class productos
{
    int numproductos; //numero de productos activos (productos != -1)
    int maxcatalogo; //el total de los productos , tanto los activos como los que no estan activos
    fstream resumen;
    cadena fichero;
    ventas ven;
public:
    productos(cadena Fichero,cadena FicheroVentas);
    ~productos();
    int getmaxcatalogo();
    void setmaxcatalogo(int num);
    int getnumproductos(){return numproductos;};
    void setnumproductos(int num){numproductos=num;};
    void mostrarproductos();
    void mostrarventas();
    bool anadirventa(); //true si lo añade , false si no lo añade
    void actualizarresumen();
    void obtenerestadisticas(int tipo,int annoini,int annofin);
};

#endif // PRODUCTOS_H_INCLUDED
