#include <iostream>
#include <windows.h>

using namespace std;

class Reloj
{
    int Hi , Mi , Si ;
    int TiempoSimulacion;

public:
    void Iniciar();
    void Simular();
};

void Reloj::Iniciar()
{
    Si = 00 ;

    cout << "Introduzca la hora: " ;
    cin >> Hi ;

    cout << "Introduzca los minutos: " ;
    cin >> Mi ;

    system("cls");

    do
    {
        cout << "Hora ==> " << Hi << ":" << Mi << ":" << Si << "\n" ;

        cout << "Introduzca el tiempo de simulacion(en segundos): " ;
        cin >> TiempoSimulacion ;

        system("cls");

    }while(TiempoSimulacion < 0);

    cout << TiempoSimulacion << " minutos corresponden a " << TiempoSimulacion << " segundos";

}

void Reloj::Simular()
{
    int horas , minutos , segundos ;
    int cocienteminutos  ;

    segundos = TiempoSimulacion % 60 ;
    cocienteminutos = TiempoSimulacion / 60 ;
    minutos = (cocienteminutos % 60) + Mi ;
    horas = (cocienteminutos / 60) + Hi ;

    Sleep(500);

    cout << "La nueva hora es --> " << horas << ":"<< minutos << ":"<< segundos  ;
}

int main()
{
    Reloj r ;

    r.Iniciar();
    r.Simular();

    return 0;
}
