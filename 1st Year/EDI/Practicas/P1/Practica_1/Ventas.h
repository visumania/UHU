#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

typedef char cadena[101];

struct Sfecha
{
    int dia;
    int mes;
    int anno;
};

struct venta
{
     Sfecha fecha; //Fecha de la venta
     int unidades; //numero de unidades vendidas
     int producto;  //codigo del producto vendido
     float importe; //importe de las unidades vendidas
};

class ventas
{
    fstream detalle; //nombre lógico del fichero asociado a las ventas
    cadena fichero; //cadena de caracteres asociado al fichero ventas
    cadena ficheroresumen; //cadena d caracteres asociado al maestro de productos (fichero de productos)
    void posicionar(int i , char tipo);
public:
    bool asignar(cadena Fichero,cadena FicheroResumen);
    void mostrarventas();
    void anadirventa(int num);
    void resumirfichero();
    void estadisticas(int tipo,int annoini,int annofin);

};

#endif // VENTAS_H_INCLUDED
