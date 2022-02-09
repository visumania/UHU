#include <iostream>
#include <cstring>

// Nombre: Francisco Jes�s Beltr�n Moreno

using namespace std;

typedef char cadena[50];

class Taxi
{
    cadena Conductor;  //Nombre Conductor
    float Kilometros;  //Kilometros del Coche
    float KmHechos;     //Kilometros recorridos en el d�a
    float Ganancia;    //Ganancia del d�a
    float Deposito;    //Litros en el Dep�sito
public:
    Taxi();
    void Inicializar(cadena pConductor, float pKilometros);
    void getConductor(cadena pNombre);
    float getKilometros();
    float getKmHechos();
    float getGanancia();
    float getDeposito();
    bool Carrera(float pDistancia, float &pPrecio);
    void Mostrar();
};

Taxi::Taxi()
{
    strcpy(Conductor, ""); // Cadena Conductor Vac�a
    Kilometros=0.0;
    KmHechos=0.0;
    Ganancia=0.0;
    Deposito=0.0;
}

void Taxi::Inicializar(cadena pConductor, float pKilometros)
{
    strcpy(Conductor, pConductor);
    Kilometros = pKilometros;
    KmHechos=0.0;
    Ganancia=0.0;
    Deposito=80.0; // Inicializamos el desp�sito a 80 Litros.
}

void Taxi::getConductor(cadena pNombre)
{
    strcpy(pNombre, Conductor);
}

float Taxi::getKilometros()
{
    return Kilometros;
}

float Taxi::getKmHechos()
{
    return KmHechos;
}

float Taxi::getGanancia()
{
    return Ganancia;
}

float Taxi::getDeposito()
{
    return Deposito;
}

bool Taxi::Carrera(float pDistancia, float &pPrecio)
{
    bool resultado=false;
    float Consumo_Taxi, Consumo_Medio=7.8; // Consumo medio, 7.8 L/100
    float Deposito_sin_reserva=Deposito-9.0; // Deposito - Reserva (9 Litros)

    Consumo_Taxi = (pDistancia*Consumo_Medio)/100; // El Resultado nos dir� cuanto Combustible gastar�a en el viaje.

    if(Consumo_Taxi < Deposito_sin_reserva)
        if(pDistancia+Kilometros<100000)
            resultado = true;

    if(resultado)
    {
        Kilometros = Kilometros + pDistancia; // Kms del coche + Kms recorridos en el viaje
        KmHechos = KmHechos + pDistancia; // Kms hechos anteriores al viaje + Kms hechos de este viaje
        Ganancia = Ganancia + (pDistancia*0.75); // Ganancia anterior + Ganancia de este viaje
        Deposito = Deposito - Consumo_Taxi; // Deposito anterior + Deposito despu�s del viaje
        pPrecio = pDistancia*0.75;
    }

    return resultado;
}

void Taxi::Mostrar()
{
    cout <<Conductor<<" "<<Kilometros<<"Km "<<KmHechos<<"Km hechos "<<Ganancia<<" euros ganados "<<Deposito<<"L"<<endl;
}


int BuscarTaxi(Taxi pFlota[50], int NTaxis)
{
    float Minimo;
    int posicion;
    int i=0;

    // Establezco como minimo, el primer taxi
    Minimo = pFlota[i].getKmHechos();
    posicion = i;

    // Despu�s realizo el recorrido de toda la flota menos el primero
    for(i=1; i<NTaxis; i++)
    {
        float Taxi_siguiente=pFlota[i].getKmHechos();

        if(Taxi_siguiente<Minimo)
        {
            Minimo = Taxi_siguiente;
            posicion = i;
        }
    }

    return posicion;
}

int main()
{
    Taxi Flota[50];
    int NTaxi=0;
    int Pos;
    int opcion;
    float Gana, Dista;
    do
    {
        cout<<"\n1.- A�adir un Taxi a la flota."
            <<"\n2.- Tomar un Taxi."
            <<"\n3.- Listado de Taxis."
            <<"\n0.- Salir."
            <<"\n\nElige Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
            case 1: if (NTaxi<50)
                    {
                        cadena Cond;
                        int Kilo;
                        cout<<"Introduce Nombre: ";
                        cin >>Cond;
                        cout<<"Kil�metros iniciales del coche: ";
                        cin >>Kilo;
                        Flota[NTaxi].Inicializar(Cond,Kilo);
                        NTaxi++;
                        cout << "Taxi a�adido correctamente.";
                    }
                    else cout<<"La Flota est� completa.";
                    break;
            case 2:
                    {
                        bool Viaje;
                        float Precio_viaje;
                        Pos = BuscarTaxi(Flota, NTaxi);

                        cout << "Introduzca la distancia a realizar: ";
                        cin >> Dista;

                        Viaje=Flota[Pos].Carrera(Dista, Precio_viaje);

                        if(Viaje)
                        {
                            cadena Nombre_conductor;
                            Flota[Pos].getConductor(Nombre_conductor);

                            cout << "Nombre del conductor: " << Nombre_conductor
                                 << "\nPrecio del viaje: " << Precio_viaje << endl;
                        }
                        else
                            cout << "ERROR. No es posible realizar el viaje." << endl;
                    }
                    break;
            case 3:
                    {
                        float Kms_totales=0;
                        Gana=0;

                        cout << "\nLista de Taxis: " << endl;
                        for(int i=0; i<NTaxi; i++)
                        {
                            Flota[i].Mostrar();
                            Kms_totales += Flota[i].getKmHechos();
                            Gana += Flota[i].getGanancia();
                        }

                        cout << "Kilometros Totales: " << Kms_totales
                             << "\nGanancia Total: " << Gana << endl;
                    }
                    break;

        }
    } while (opcion!=0);

    return 0;
}
