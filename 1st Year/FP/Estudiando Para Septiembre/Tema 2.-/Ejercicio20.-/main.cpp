#include <iostream>

using namespace std;

class movimiento
{
    float vinicial , sinicial , aceleracion , tiempo;

public:
    void cargar();
    float velocidad();
    float superficie();
};

void movimiento::cargar()
{
    cout << "Introduzca velocidad inicial (m/s): " ;
    cin >> vinicial;

    cout << "\nIntroduzca superficie inicial: " ;
    cin >> sinicial;

    cout << "\nIntroduzca aceleracion del cuerpo: " ;
    cin >> aceleracion;

    cout << "\nIntroduzca tiempo transcurrido (s): ";
    cin >> tiempo;
}

float movimiento::velocidad()
{
    float vfinal;

    vfinal = vinicial + (aceleracion * tiempo);

    cout << "\n\nLa velocidad es de " << vfinal << " m/s\n\n ";

    return vfinal ;
}

float movimiento::superficie()
{
    float sfinal;

    sfinal = sinicial + (vinicial * tiempo) + (0.5 * aceleracion * tiempo * tiempo) ;

    cout << "\nLa superficie recorrida es de "  << sfinal << " metros \n\n";

    return sfinal;
}

int main ()
{
    movimiento m;

    m.cargar();
    m.velocidad();
    m.superficie();

    return 0 ;
}
