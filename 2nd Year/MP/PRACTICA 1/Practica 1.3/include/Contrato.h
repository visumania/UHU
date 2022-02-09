#ifndef CONTRATO_H
#define CONTRATO_H
#include "Fecha.h"

class Contrato
{
    static int contadorId;
    int idContrato;
    long int dniContrato;
    Fecha FechaContrato;

    public:
        Contrato(int dni, Fecha F);
        virtual ~Contrato() {};

        int getIdContrato() const {return this->idContrato;};
        long int getDniContrato() const {return this->dniContrato;};
        Fecha getFechaContrato() const {return this->FechaContrato;};
        void setDniContrato(long int dni) {this->dniContrato = dni;};
        virtual float factura() const = 0;
        void setFechaContrato(Fecha F) {this->FechaContrato = F;};
        virtual void ver() const;
};

ostream& operator<<(ostream &s, const Contrato &C);

#endif
