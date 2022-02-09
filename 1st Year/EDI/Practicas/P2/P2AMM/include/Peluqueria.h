#ifndef PELUQUERIA_H
#define PELUQUERIA_H

#include "Lista.h" //Cambiar para otra implementacion
#include "Cola.h"

struct peluquerof
{
    int Codigo;
    cadena Apellidos;
    cadena Nombre;
    int TipoServicio;
};

class peluqueria
{
    lista L; //lista de los peluqueros que están atendiendo
    int buscarPorCodigo(int Codigo);
    int posicionCorrecta(int Codigo);
    int peluMaxClientes(int Servicio, int codigoIgnorar);
    int peluMinClientes(int Servicio, int codigoIgnorar);
public:
    void AbrirPeluqueria(char *nombrefichero);
    void IncorporarPeluquero(peluquerof t);
    bool RetirarPeluquero(int codigo);
    bool EliminarCliente(cadena Nombre, cadena Apelllidos);
    bool IncorporarCliente(cliente cli);
    void Mostrar();
    bool AtenderCliente(int CodigoPeluquero);
    void VolcarPeluqueria(char *nombrefichero);
};

#endif // PELUQUERIA_H
