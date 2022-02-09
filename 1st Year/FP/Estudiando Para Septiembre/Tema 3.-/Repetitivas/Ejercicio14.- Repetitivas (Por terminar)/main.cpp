#include <iostream>
#include <windows.h>

using namespace std;

class Reloj
{
    int Hi , Mi , Si; // Hora de inicio , minuto de inicio y segundo de inicio
    int TiempoSimulacion;

public:
    void Iniciar();
    void Simular();
};

void Reloj::Iniciar()
{
    cout << "Introduzca la hora de inicio de simulacion: " ;
    cin >> Hi;

    cout << "Introduzca el minuto de inicio de simulacion: " ;
    cin >> Mi;

    Si = 0; // Inicializamos los segundos de inicio a 0

    do
    {
        system("cls");

        cout << "Introduzca el tiempo de simulacion (minutos): ";
        cin >> TiempoSimulacion;

        if(TiempoSimulacion<0)
            cout << "error , el tiempo de simulacion tiene que ser positivo\n";

    }while(TiempoSimulacion<0);


    TiempoSimulacion = TiempoSimulacion * 60 ; // Ya que la variable de tiemposimulacion lo almacena en segundos , hacemos la conversion

}

void Reloj::Simular()
{
    for(int i=0 ; i<TiempoSimulacion ; i++)
    {
       // Si = Si + i;

        cout << Hi << ":" << Mi << ":" << i << "\n";

        if(i==60)
        {
            Si = 0;
            Mi ++ ;
        }

        if((Mi%60)==0)
        {
            Mi = 0 ;
            Hi++;
        }

        Sleep(500);
    }


}

int main()
{
    Reloj rl ;

    rl.Iniciar();
    rl.Simular();

    return 0;
}
