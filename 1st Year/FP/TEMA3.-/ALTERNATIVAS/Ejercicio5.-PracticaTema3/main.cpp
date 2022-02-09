#include <iostream>
#include <math.h>

using namespace std;

class Fecha
{
    int agno ;

public:
    void leer();
    bool bisiesto();
};

void Fecha::leer()
{
    cout << "Introduce un anio cualquiera: " ;
    cin >> agno ;
}

bool Fecha::bisiesto()
{

    if ((agno%400)==0 || (agno%4)==0 )

        return true ;

    else
        return false ;
}

int main ()
{
    Fecha f ;
    f.leer();
    bool bisiesto= f.bisiesto() ;

    if (bisiesto == true)
    cout << "El anio es bisiesto" ;
    else
    cout << "El anio no es bisiesto" ;


    return 0;
}



