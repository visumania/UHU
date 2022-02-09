#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

#include "Fecha.h"  //definición de la clase Fecha
#include "Cliente.h"  //definición de la clase Cliente
#include "Contrato.h"  // definición de la clase Contrato
#include "ContratoTP.h"  //definición de la clase ContratoTP
#include "ContratoMovil.h"  //definición de la clase ContratoMovil

using namespace std;

class Empresa
{
    Cliente *clientes[100]; // array estático (tamaño 100) de punteros a Clientes
    int ncli;               // para saber cuántos clientes hay en el array (al principio 0)
    int nmaxcli;            // para saber cuantos caben en el array clientes (100)
    Contrato **contratos; //array dinamico de punteros a contratos
    int ncon;               //para saber cuántos Contratos hay en el array (al principio 0)
    int nmaxcon;            //para saber cuántos caben en el array Contratos

public:
    Empresa();
    virtual ~Empresa();
    void cargarDatos();
    //EL CONSTRUCTOR DE COPIA Y EL OPERADOR DE ASGINACION NO LO IMPLEMENTAMOS
    //PORQUE EXPLICITAMENTE SE INDICA EN LA PRÁCTICA QUE NO SE HAGA
    void crearContrato();
    bool cancelarContrato(int pIdContrato); // true si el Contrato existe , false si no
    bool bajaCliente(long int pDni);       // true si el Cliente existe, false si no
    int descuento(float porcentaje) const ; //devuelve a cuantos aplcia el descuento
    int nContratosTP() const;
    void ver();

};

#endif // EMPRESA_H_INCLUDED
