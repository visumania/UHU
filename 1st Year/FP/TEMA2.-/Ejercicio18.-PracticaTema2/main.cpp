#include <iostream>

using namespace std;

class empleado {
    int horasnormales , horasextras;

public:
    void cargar();
    float nomina();
};
void empleado::cargar()
{
    cout << "Introduzca las horas normales trabajadas: ";
    cin >> horasnormales;

    cout << "Introduzca las horas extras trabajadas: " ;
    cin >> horasextras ;
}

float empleado::nomina()
{
    float dinero ;

    dinero = ((horasnormales * 5 + horasextras*8 )* 0.85);

    cout << "La nomina del trabajador es: " << dinero << " euros" << endl ;
}


int main()
{
    empleado e ;
    e.cargar();
    e.nomina();

    return 0 ;
}









