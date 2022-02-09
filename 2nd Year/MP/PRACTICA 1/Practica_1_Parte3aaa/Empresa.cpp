#include "Empresa.h"
#include "Cliente.h"
#include <typeinfo>
#include <cstdio>
#include <windows.h>
#include <iomanip>

Empresa::Empresa()
{
    //this->ncli = 0;
    this->nmaxcli = 100;
    //this->ncon = 0;
    this->nmaxcon = 10;
    contratos = new Contrato *[this->nmaxcon];
}

Empresa::~Empresa()
{
    for(int i=0 ; i<this->ncli ; i++)
        delete this->clientes[i];

    for(int i=0 ; i<ncon ; i++)
        delete this->contratos[i];

    delete contratos;
    contratos = NULL;
}

void Empresa::cargarDatos()
{
    //Aqui vamos a cargar 3 clientes :

    this->clientes[0] = new Cliente(75547001, "Peter Lee", Fecha(28, 2, 2001));
    this->clientes[1] = new Cliente(45999000, "Juan Perez" , Fecha(29 , 2 , 2000));
    this->clientes[2] = new Cliente(37000017 , "Luis Bono" ,Fecha (31 , 1 , 2002));

    //Aqui vamos a cargar los 7 Contratos:

    this->contratos[0] = new ContratoMovil(75547001 ,Fecha(28,2,2001) , 0.12 , 110 , "DANES");
    this->contratos[1] = new ContratoMovil(75547001 ,Fecha(31 , 1 , 2002) , 0.09 , 170 , "DANES");
    this->contratos[2] = new ContratoTP(37000017 ,Fecha(1,2,2002) , 250);
    this->contratos[3] = new ContratoTP(75547001 ,Fecha(28,2,2001) , 312);
    this->contratos[4] = new ContratoMovil(45999000 ,Fecha(31,1,2002) , 0.10 , 202 , "ESPAÑOL");
    this->contratos[5] = new ContratoMovil(75547001 ,Fecha(31,1,2001) , 0.15 , 80 , "DANES");
    this->contratos[6] = new ContratoTP(45999000 ,Fecha(28,2,2001) ,400);

    this->ncli = 3;
    this->ncon = 7;

}

/*void Empresa::crearContrato()
{
    long int pDni;
    bool encuentracliente;
    int i;
    int pDia , pMes , pAnio;
    int pMinutosHablados;
    int pPrecioMinuto;

    cout << "Introduzca dni: " ;
    cin >> pDni;

    encuentracliente = false;
    i = 0;

    while(i<this->ncli && !encuentracliente) // Buscamos si exite el dni del cliente cuyo dni lo introducimos por teclado
    {
        if(clientes[i]->getDni() == pDni)
            encuentracliente = true;
        else
            i++;
    }

    if(!encuentracliente)  //Si NO ENCUENTRA el cliente
    {
        if(this->ncli < this->nmaxcli) // Pregunta si hay espacio para introducir al nuevo cliente. En caso de que SI haya espacio:
        {
            char* pNombre = new char;

            cout << "Nombre del cliente: " ;
            cin.get(); cin.getline(pNombre, 20);

            cout << "dia: " ;
            cin >> pDia;

            cout << "mes: ";
            cin >> pMes;

            cout << "anio: " ;
            cin >> pAnio;

            this->clientes[ncli] = new Cliente(pDni , pNombre , Fecha(pDia , pMes , pAnio)); //Como hay espacio pues lo insertamos
            this->ncli++; //Y aumentamos el numero de clientes

            if(this->ncon < this->nmaxcon) //Preguntamos si hay espacio para introducir un nuevo contrato. En caso de que SI haya
            {
                int opcion;

                cout << "Tipo de contrato a abrir (1. Tarifa Plana , 2. Contrato Movil): "; //Comprobamos si es CTP O CM
                cin >> opcion;

                if(opcion == 1 || opcion == 2)
                {
                    cout << "Fecha del contrato" << endl;
                    cout << "dia: " ;
                    cin >> pDia;

                    cout << "mes: " ;
                    cin >> pMes;

                    cout << "anio: " ;
                    cin >> pAnio;

                    cout << "minutos hablados: " ;
                    cin >>  pMinutosHablados;

                    if(opcion==1)
                    {
                        this->contratos[ncon] = new ContratoTP(pDni , Fecha(pDia , pMes , pAnio) , pMinutosHablados);
                        this->ncon++;
                    }

                    if(opcion == 2)
                    {
                            cout << "Precio minuto: ";
                            cin >> pPrecioMinuto;

                            char* pNacionalidad;
                            cout << "Nacionalidad: " ;
                            cin.get(); cin.getline(pNacionalidad, 20);

                            this->contratos[ncon] = new ContratoMovil(pDni , Fecha(pDia, pMes , pAnio) , pPrecioMinuto , pMinutosHablados , pNacionalidad);
                            this->ncon++;
                    }
                }
                else
                {
                    cout << "Error en la opcion" << endl;
                }
            }
            else  //En el caso de que NO haya espacio en contrato
            {
                cout << "No hay espacio en contrato";
            }
        }
        else  //En caso de que no haya espacio en cliente
            cout << "\nNo hay espacio para introducir al nuevo cliente" << endl;
    }
    else //Si encuentra un cliente con ese dni que hemos introducido por teclado:
    {
        if(this->ncon < this->nmaxcon) //Preguntamos si hay espacio para introducir un nuevo contrato. En caso de que SI haya
            {
                int opcion;

                cout << "Tipo de contrato a abrir (1. Tarifa Plana , 2. Contrato Movil): "; //Comprobamos si es CTP O CM
                cin >> opcion;

                if(opcion == 1 || opcion == 2)
                {
                    cout << "Fecha del contrato" << endl;
                    cout << "dia: " ;
                    cin >> pDia;

                    cout << "mes: " ;
                    cin >> pMes;

                    cout << "anio: " ;
                    cin >> pAnio;

                    cout << "minutos hablados: " ;
                    cin >>  pMinutosHablados;

                    if(opcion==1)
                    {
                        this->contratos[ncon] = new ContratoTP(pDni , Fecha(pDia , pMes , pAnio) , pMinutosHablados);
                        this->ncon++;
                    }

                    if(opcion == 2)
                    {
                            cout << "Precio minuto: ";
                            cin >> pPrecioMinuto;

                            char* pNacionalidad;
                            cout << "Nacionalidad: " ;
                            cin >> pNacionalidad;

                            this->contratos[ncon] = new ContratoMovil(pDni , Fecha(pDia, pMes , pAnio) , pPrecioMinuto , pMinutosHablados , pNacionalidad);
                            this->ncon++;
                    }
                }
                else
                {
                    cout << "Error en la opcion" << endl;
                }
            }
            else  //En el caso de que NO haya espacio en contrato
            {
                cout << "No hay espacio en contrato";
            }
    }
}*/
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
        if(this->clientes[i]->getDni() == dni)
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

            this->clientes[this->ncli] = new Cliente(dni, nombre, Fecha(dia,mes,anio));
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
            Contrato** aux = this->contratos;

            this->contratos = new Contrato* [this->nmaxcli*2];

            for(int i=0; i<this->ncon; i++)
                this->contratos[i] = aux[i];

            delete [] aux;
            this->nmaxcon += this->nmaxcon;
        }

        // SI HAY SITIO, LO METEMOS INMEDIATAMENTE
        if(this->ncon < this->nmaxcon)
        {
            if(tipo == 1)
            {
                this->contratos[this->ncon] = new ContratoTP(dni, Fecha(dia,mes,anio), min_hab);
                this->ncon++;
            }
            else
            {
                this->contratos[this->ncon] = new ContratoMovil(dni, Fecha(dia,mes,anio), precio, min_hab, nacionalidad);
                this->ncon++;
            }
        }
    }
}
bool Empresa::cancelarContrato(int pIdContrato)
{
    bool cancelado; //True si el contrato exite , false si no existe
    int i;

    cancelado = false;
    i=0;

    while(i<this->ncon && !cancelado)
    {
        if(contratos[i]->getIdContrato()==pIdContrato)
            cancelado = true;
        else
            i++;
    }

    if(cancelado)
    {
        delete this->contratos[i];

        for(int j=i ; j<this->ncon ; j++)
        {
            this->contratos[j] = this->contratos[j+1];
        }

        this->ncon--;
    }

        return cancelado;
}

bool Empresa::bajaCliente(long int pDni)
{
    //Primero vamos a eliminar los contratos de ese cliente cuyo dni nos pasan por parámetro:

    for(int i=0 ; i<this->ncon ; i++)
    {
        if(this->contratos[i]->getDniContrato() == pDni)
        {
            delete this->contratos[i];

            for(int j=i ; j<ncon ; j++)
            {
                this->contratos[j] = this->contratos[j+1];
            }
            this->ncon--;
        }
    }

    //Seguidamente vamos a eliminar al cliente cuyo dni nos han pasado por parámetro:

    bool eliminado;
    int i;

    eliminado = false;
    i=0;

    while(i<this->ncli && !eliminado)
    {
        if(this->clientes[i]->getDni() == pDni)
            eliminado = true;
        else
            i++;
    }

    if(eliminado)
    {
        for(int j=i ; j<ncli ; j++)
        {
            this->clientes[i]=this->clientes[i+1];
        }

        this->ncli--;
    }


    return eliminado;
}

int Empresa::descuento(float porcentaje) const
{
    //El porcentaje solo se aplica a los contratos moviles

    int contador = 0;

    for(int i=0 ; i<this->ncon ; i++)
    {
        if(typeid(this->contratos[i]) == typeid(ContratoMovil))
        {
            ContratoMovil *cm = dynamic_cast<ContratoMovil*>(contratos[i]);
            cm->setPrecioMinuto(cm->getPrecioMinuto()*(1-porcentaje));
            contratos[i] = cm;
            contador++;
        }
    }

    return contador;
}

int Empresa::nContratosTP()const
{
    //Devuelve solamente el numero de contratos que hay te tipo ContratoTP

    int contadorTP=0;

    for(int i=0 ; i<ncon ; i++)
    {
        if(typeid(*contratos[i])== typeid(ContratoTP))
            contadorTP++;
    }

    return contadorTP;
}

void Empresa::ver()
{
    cout << fixed << setprecision(2);
    cout << "La empresa tiene " << this->ncli << " clientes y " << this->ncon << " contratos" << endl;

    //Primero hay que hacer un bucle for para mostrar por pantalla los clientes

    cout << "Clientes:" << endl;

    for(int i=0 ; i<this->ncli ; i++)
    {
        cout << *clientes[i] << endl;
    }

    //Lo segundo es hacer un bucle for para mostrar por pantalla los contratos
    cout << "\n\nContratos:" << endl;

    for(int i=0 ; i<this->ncon ; i++)
    {
        if(typeid(*contratos[i]) == typeid(ContratoMovil))
            {
                ContratoMovil *pContratoMovil = dynamic_cast<ContratoMovil*>(contratos[i]);
                cout << *pContratoMovil << endl;
            }
        else if(typeid(*contratos[i]) == typeid(ContratoTP))
        {
            ContratoTP *pContratoTP = dynamic_cast<ContratoTP*>(contratos[i]);
            cout << *pContratoTP << endl;
        }
    }
}
