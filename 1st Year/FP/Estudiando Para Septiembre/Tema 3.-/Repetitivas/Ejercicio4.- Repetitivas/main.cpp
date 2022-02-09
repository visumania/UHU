#include <iostream>

using namespace std;

class TablaMultiplicar
{
    int Tabla;

public:
    void PedirNoTabla();
    void MostrarTabla();
};

void TablaMultiplicar::PedirNoTabla()
{
    do
    {
        cout << "Introduzca el numero de la tabla que desea visualizar [1-10]: ";
        cin >> Tabla ;

    }while(Tabla<0 || Tabla>10);
}

void TablaMultiplicar::MostrarTabla()
{
    for(int i=0 ; i<11 ; i++)
    {
        cout << "\n\t\t\t" << Tabla << " x " << i << "= " << Tabla * i ;
    }
}

int main()
{
    TablaMultiplicar tm;

    tm.PedirNoTabla();
    tm.MostrarTabla();

    cout << "\n";

    return 0 ;
}
