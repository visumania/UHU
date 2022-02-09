#ifndef COLA_H
#define COLA_H

#define INCREMENTO 2

typedef char cadena[50];

struct cliente
{
    cadena Apellidos;
    cadena Nombre;
    int Edad;
    int TipoServicio;
    int HoraLlegada; //almacenada en minutos
};

class cola
{
    cliente *elementos; //elementos de la cola
    int inicio, fin; //principio y fin de la cola
    int Tama; //Capacidad de la tabla
    int ne; //N� de elementos
    bool compararClientes(cliente c1, cliente c2);
public:
    cola(); // constructor de la clase
    ~cola();
    void encolar(cliente e);
    void desencolar();
    bool esvacia();
    cliente primero();
    int longitud();
    void vaciar();
    void clonar(cola &c);
    bool comparar(cola &c);
};


#endif // COLA_H
