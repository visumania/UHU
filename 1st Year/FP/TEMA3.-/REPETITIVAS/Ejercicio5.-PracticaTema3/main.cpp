#include <iostream>
#include <windows.h>

using namespace std;

class TablasMultiplicar
{
    int TablaIni , TablaFin ;
public:
    void PedirNoTablas();
    void MostrarTablas();
};

void TablasMultiplicar::PedirNoTablas()
{
    int aux;
    aux =0 ;

    do
    {
        system("cls" );

        cout << "Introduzca el digito de la tabla inicial[1-10]: " ;
        cin >> TablaIni ;

        cout << "Introduzca el digito de la tabla final[1-10]: " ;
        cin >> TablaFin ;
    }while(((TablaIni<1 || TablaIni>10) || (TablaFin<1 || TablaFin>10)));

    if(TablaIni > TablaFin)
    {
        aux=TablaIni;
        TablaIni=TablaFin;
        TablaFin=aux;
    }
}

void TablasMultiplicar::MostrarTablas()
{
    for(int j=0 ; j<=10 ; j++)
    {
        cout << endl;
        for(int i=TablaIni ; i<=TablaFin ; i++)
        {
            cout<< i << " x " << j <<" = " << i*j << "\t";
        }
    }
}

int main()
{
    TablasMultiplicar tm ;

    tm.PedirNoTablas();
    tm.MostrarTablas();
    cout << endl;

    return 0 ;
}
