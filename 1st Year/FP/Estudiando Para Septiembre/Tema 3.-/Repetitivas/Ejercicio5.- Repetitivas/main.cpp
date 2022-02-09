#include <iostream>

using namespace std;

class TablasMultiplicar
{
    int TablaIni , TablaFin;

public:
    void PedirNotablas();
    void MostrarTablas();
};

void TablasMultiplicar::PedirNotablas()
{
    do
    {
        cout << "Introduzca el valor de la tabla inicial: ";
        cin >> TablaIni;

        cout << "\nIntroduzca el valor de la tabla final: ";
        cin >> TablaFin;

    }while(TablaIni<1 || TablaIni>10 || TablaFin<1 || TablaFin>10);

    if(TablaIni>TablaFin)
    {
        int TablaAux; // Para intercambiar los valores de la tabla inicial y final

        TablaAux=TablaIni;
        TablaIni=TablaFin;
        TablaFin=TablaAux;

        //A partir de ahora se supone que se han intercambiado los valores de Tabla inicial y Tabla final
    }


}

void TablasMultiplicar::MostrarTablas()
{
    for(int i=0 ; i<11 ; i++)
    {
        for(int j=TablaIni ; j<=TablaFin ; j++)
        {
            cout << j << " x " << i << " = " << j*i << "\t";
        }

        cout << "\n";
    }
}

int main()
{
    TablasMultiplicar tm;

    tm.PedirNotablas();
    tm.MostrarTablas();

    return 0 ;
}
