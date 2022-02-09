#ifndef EMPRESA_H
#define EMPRESA_H

#include "Fecha.h"
#include "Cliente.h"
#include "Contrato.h"
#include "ContratoTP.h"
#include "ContratoMovil.h"

#include <typeinfo>

using namespace std;

class Empresa
{
    Cliente *Clientes[100]; // Array estático (n=100) de punteros a Clientes
    int ncli;
    int nmaxcli;
    Contrato **Contratos; // Puntero de Punteros a Contratos
    int ncon;
    int nmaxcon;

    public:
        Empresa();
        virtual ~Empresa();

        //EL CONTRUCTOR DE COPIA Y EL OPERADOR DE ASIGNACION NO LO IMPLEMENTAMOS
        //PORQUE EXPLICITAMENTE SE INDICA EN LA PRACTICA QUE NO SE HAGA

        bool cancelarContrato(int idContrato);
        bool bajaCliente(long int dni);
        int descuento (float porcentaje) const;
        int nContratosTP() const;
        void cargarDatos();
        void crearContrato();
        void ver() const;
};

#endif // EMPRESA_H
