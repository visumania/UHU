#include "Empresa.h"
#include <iomanip>
#include <cstdio>

Empresa::Empresa()
{
    this->nmaxcon = 10;
    this->nmaxcli = 100;
    this->Contratos = new Contrato *[this->nmaxcon];
}

void Empresa::cargarDatos()
{
    // Clientes
    this->Clientes[0] = new Cliente(75547001, "Peter Lee", Fecha(28,2,2001));
    this->Clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29,2,2000));
    this->Clientes[2] = new Cliente(37000017, "Luis Bono", Fecha(31,1,2002));

    // Contratos
    this->Contratos[0] = new ContratoMovil(Clientes[0]->getDni(), Clientes[0]->getFecha(), 0.12, 110, "DANES");
    this->Contratos[1] = new ContratoMovil(Clientes[0]->getDni(), Clientes[2]->getFecha(), 0.09, 170, "DANES");
    this->Contratos[2] = new ContratoTP(Clientes[2]->getDni(), Fecha(1,2,2002), 250);
    this->Contratos[3] = new ContratoTP(Clientes[0]->getDni(), Clientes[0]->getFecha(), 312);
    this->Contratos[4] = new ContratoMovil(Clientes[1]->getDni(), Clientes[2]->getFecha(), 0.10, 202, "ESPA?OL");
    this->Contratos[5] = new ContratoMovil(Clientes[0]->getDni(), Clientes[2]->getFecha(), 0.15, 80, "DANES");
    this->Contratos[6] = new ContratoTP(Clientes[1]->getDni(), Fecha(1,2,2002), 400);

    // Inicializamos los atributos privados
    this->ncli = 3;
    this->ncon = 7;
}

Empresa::~Empresa()
{
    for(int i=0; i<this->ncli; i++)
        delete this->Clientes[i];

    for(int i=0; i<this->ncon; i++)
        delete Contratos[i];

    delete Contratos;
    Contratos = NULL;
}

void Empresa::crearContrato()
{
    int tipo, dia, mes, anio, min_hab, i=0;
    float precio;
    long int dni;
    char *nacionalidad = new char;
    bool existe = false;

    cout << "Introduzca dni: "; cin >> dni;

    while(i<this->ncli && !existe)
    {
        if(this->Clientes[i]->getDni() == dni)
            existe = true;
        else
            i++;
    }

    if(existe)
    {
        cout << "Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): "; cin >> tipo;
        cout << "Fecha del contrato:" << endl;
        cout << "Dia: "; cin >> dia;
        cout << "Mes: "; cin >> mes;
        cout << "Anio: "; cin >> anio;
        cout << "Minutos hablados: "; cin >> min_hab;

        if(tipo == 2) // ContratoMovil
        {
            cout << "Precio minuto: "; cin >> precio;
            cout << "Nacionalidad: "; cin.get(); cin.getline(nacionalidad, 10);
        }

        cout << endl;
    }
    else
    {
        if(this->ncli<100)
        {
            char *nombre = new char;
            cout << "Nombre del Cliente: "; cin.get(); cin.getline(nombre, 20);
            cout << "Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): "; cin >> tipo;
            cout << "Fecha del contrato:" << endl;
            cout << "Dia: "; cin >> dia;
            cout << "Mes: "; cin >> mes;
            cout << "Anio: "; cin >> anio;
            cout << "Minutos hablados: "; cin >> min_hab;

            if(tipo == 2)
            {
                cout << "Precio minuto: "; cin >> precio;
                cout << "Nacionalidad: "; cin.get(); cin.getline(nacionalidad, 10);
            }

            cout << endl;

            this->Clientes[this->ncli] = new Cliente(dni, nombre, Fecha(dia,mes,anio));
            this->ncli++;
        }
        else
            cout << "ERROR. NUMERO MAXIMO DE CLIENTES ALCANZADO.\nACTUALICE PARA AUMENTAR LA CAPACIDAD!" << endl;
    }

    // SI EXISTE, O SI NO EXISTE PERO PODEMOS CREAR 1 CLIENTE NUEVO
    if(existe || this->ncli<100)
    {
        if(this->ncon == this->nmaxcon)
        {
            Contrato** aux = this->Contratos;

            this->Contratos = new Contrato* [this->nmaxcli*2];

            for(int i=0; i<this->ncon; i++)
                this->Contratos[i] = aux[i];

            delete [] aux;
            this->nmaxcon += this->nmaxcon;
        }

        // SI HAY SITIO, LO METEMOS INMEDIATAMENTE
        if(this->ncon < this->nmaxcon)
        {
            if(tipo == 1)
            {
                this->Contratos[this->ncon] = new ContratoTP(dni, Fecha(dia,mes,anio), min_hab);
                this->ncon++;
            }
            else
            {
                this->Contratos[this->ncon] = new ContratoMovil(dni, Fecha(dia,mes,anio), precio, min_hab, nacionalidad);
                this->ncon++;
            }
        }
    }
}

bool Empresa::cancelarContrato(int idContrato)
{
    int i=0, total=this->ncon;
    bool encontrado=false;

    while(i<this->ncon && !encontrado)
    {
        if(this->Contratos[i]->getIdContrato() == idContrato)
        {
            encontrado = true;
            delete this->Contratos[i];

            for(int k=i+1; k<total; k++)
                this->Contratos[k-1] = this->Contratos[k];

            this->ncon--;
        }
        else
            i++;
    }

    return encontrado;
}

void Empresa::ver() const
{
    cout << fixed << setprecision(2);
    cout << "La Empresa tiene " << this->ncli << " clientes y " << this->ncon << " contratos" << endl;
    cout << "Clientes: " << endl;

    for(int i=0; i<ncli; i++)
        cout << *Clientes[i]<< endl;

    cout << endl;
    cout << "Contratos: " << endl;

    for(int i=0; i<ncon; i++)
    {
        cout << *Contratos[i];

        if(ContratoTP *c = dynamic_cast<ContratoTP*>(this->Contratos[i]))
        {
            cout << c->getMinutosHablados() << "m, ";
            cout << c->getLimiteMinutos() << "(";
            cout << c->getPrecioTP() << ") - " << c->factura() << "$";
        }
        else
        {
            cout << static_cast<ContratoMovil*>(Contratos[i])->getMinutosHablados() << "m, ";
            cout << static_cast<ContratoMovil*>(Contratos[i])->getNacionalidad() << " ";
            cout << static_cast<ContratoMovil*>(Contratos[i])->getPrecioMinuto();
            cout << " - " << static_cast<ContratoMovil*>(Contratos[i])->factura() << "$";
        }
        cout << endl;
    }
}

int Empresa::nContratosTP() const
{
    int contador=0;

    for(int i=0; i<this->ncon; i++)
        if(typeid(*Contratos[i]) == typeid(ContratoTP))
            contador++;

    return contador;
}

bool Empresa::bajaCliente(long int dni)
{
    bool encontrado=false;
    int idCliente=0, total = this->ncon;

    // ELIMINAMOS LOS CONTRATOS DE ESE CLIENTE
    for(int i=total-1; i>=0; i--)
    {
        if(this->Contratos[i]->getDniContrato() == dni)
        {
            delete this->Contratos[i];

            for(int k=i+1; k<total; k++)
                this->Contratos[k-1] = this->Contratos[k];

            this->ncon--;
        }
    }

    // AHORA ELIMINAMOS AL CLIENTE
    while(idCliente<this->ncli && !encontrado)
    {
        if(this->Clientes[idCliente]->getDni() == dni)
            encontrado = true;
        else
            idCliente++;
    }

    if(encontrado)
        for(int i=idCliente+1; i<this->ncli; i++)
            this->Clientes[i-1] = this->Clientes[i];

    this->ncli--;

    return encontrado;
}

int Empresa::descuento(float porcentaje) const
{
    int contador=0;

    for(int i=0; i<this->ncon; i++)
    {
        if(ContratoMovil *c = dynamic_cast<ContratoMovil*>(this->Contratos[i]))
        {
            contador++;
            float nuevo_precio = c->getPrecioMinuto() * (1-porcentaje/100);

            c->setPrecioMinuto(nuevo_precio);
        }
    }

    return contador;
}
