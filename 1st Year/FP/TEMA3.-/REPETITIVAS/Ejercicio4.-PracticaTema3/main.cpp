#include <iostream>

using namespace std;

class TablaMultiplicar
{
    int Tabla ;

public:
    void PedirNoTabla();
    void MostrarTabla();
};

void TablaMultiplicar::PedirNoTabla()
{
    Tabla = 0;
    cout << " De que numero hacemos la tabla de multiplicar guapo ? : " ;
    cin >> Tabla;
    if(((Tabla<0) || (Tabla > 10)))
    {
        do
        {
            cout << " Error en la tabla , introduzca un numero que oscile entre 0 y 10: " ;
            cin >> Tabla;
        }while(Tabla<0 || Tabla > 10);
    }
}

void TablaMultiplicar::MostrarTabla()
{
    cout << "\t" << Tabla << " * 0= "<< Tabla * 0 << "\n" ;
    cout << "\t" << Tabla << " * 1= "<< Tabla * 1 << "\n" ;
    cout << "\t" << Tabla << " * 2= "<< Tabla * 2 << "\n" ;
    cout << "\t" << Tabla << " * 3= "<< Tabla * 3 << "\n" ;
    cout << "\t" << Tabla << " * 4= "<< Tabla * 4 << "\n" ;
    cout << "\t" << Tabla << " * 5= "<< Tabla * 5 << "\n" ;
    cout << "\t" << Tabla << " * 6= "<< Tabla * 6 << "\n" ;
    cout << "\t" << Tabla << " * 7= "<< Tabla * 7 << "\n" ;
    cout << "\t" << Tabla << " * 8= "<< Tabla * 8 << "\n" ;
    cout << "\t" << Tabla << " * 9= "<< Tabla * 9 << "\n" ;
    cout << "\t" << Tabla << " * 10= "<< Tabla * 10 << "\n" ;

}

int main ()
{
    TablaMultiplicar tm ;

    tm.PedirNoTabla();
    tm.MostrarTabla();

    return 0 ;
}
