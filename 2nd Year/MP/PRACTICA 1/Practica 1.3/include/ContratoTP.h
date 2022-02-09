#ifndef CONTRATOTP_H
#define CONTRATOTP_H
#include <Contrato.h>

class ContratoTP:public Contrato // Hereda de Contrato
{
    static float precioTP;
    static int minutosTP;
    int minutosHablados;
    static const float precioExcesoMin = 0.15; // Fijo e invariable

    public:
        ContratoTP(long int dni, Fecha F, int minutos);
        ContratoTP(const ContratoTP &P);

        static float getPrecioTP() {return precioTP;};
        static int getLimiteMinutos() {return minutosTP;};
        static float getPrecio() {return precioExcesoMin;};
        static void setTarifaPlana(int nuevos_minutos, float nuevo_precio) {minutosTP = nuevos_minutos; precioTP = nuevo_precio;};

        int getMinutosHablados() const {return this->minutosHablados;};
        float factura() const;
        void ver() const;
        void setMinutosHablados(int nuevos_minutos) {this->minutosHablados = nuevos_minutos;};
};

ostream& operator<<(ostream &s, const ContratoTP &C);

#endif // CONTRATOTP_H
