#include <iostream>

using namespace std;

class Fecha
{
    int agno ;

public:
    bool bisiesto();
    void leer();
};

void Fecha::leer()
{
    cout << "Introduzca el anio: ";
    cin >> agno ;
}

bool Fecha::bisiesto()
{
    bool encontrado = false ;

    if ((agno%4)==0 && (agno%100)!=0)
        encontrado = true;

    if(encontrado)
        cout << "\nEl agno es bisiesto";
    else
        cout << "\nEl agno no es bisiesto";

    return encontrado;
}

int main()
{
    Fecha f ;

    f.leer();
    f.bisiesto();

    return 0;
}
