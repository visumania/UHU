#include <iostream>

using namespace std;

class empleado
{
    int horasnormales , horasextras ;

public:
    void cargar();
    float nomina();
};

void empleado::cargar()
{
    cout << "Introduzca el numero de horas normales trabajadas: " ;
    cin >> horasnormales;

    cout << "\nIntroduzca el numero de horas extras trabajadas: " ;
    cin >> horasextras;
}

float empleado::nomina()
{
    float sueldo;

    sueldo = (horasnormales * 5) + (horasextras * 8);

    cout << "\n\nEl salario es de " << sueldo << " euros" ;

    return sueldo ;
}

int main ()
{
    empleado em ;

    em.cargar() ;
    em.nomina();

    return 0 ;
}
