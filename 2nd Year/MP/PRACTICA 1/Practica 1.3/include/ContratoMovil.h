#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H
#include <Contrato.h>

class ContratoMovil:public Contrato
{
    char* Nacionalidad;
    float precioMinuto;
    int minutosHablados;

    public:
        ContratoMovil(long int dni, Fecha F, float precio, int minutos, char* origen);
        ContratoMovil(const ContratoMovil &C);
        ~ContratoMovil();   // NECESARIO PARA ELIMINAR CORRECTAMENTE LA MEMORIA

        const char* getNacionalidad() const {return this->Nacionalidad;};
        float getPrecioMinuto() const {return this->precioMinuto;};
        void setNacionalidad(const char* nueva_nacionalidad);
        void setPrecioMinuto(float nuevo_precio) {this->precioMinuto = nuevo_precio;};
        void setMinutosHablados(int nuevos_minutos) {this->minutosHablados = nuevos_minutos;};
        int getMinutosHablados() const {return this->minutosHablados;};
        void ver() const;
        float factura() const {return (precioMinuto*minutosHablados);};
};

ostream& operator<<(ostream &s, const ContratoMovil &C);

#endif // CONTRATOMOVIL_H
