#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

typedef char Cadena[50];

#define MAX_CUENTAS 100

class Cuenta
{
    float Saldo ;
    int NoCuenta ;
    bool bloqueada ;

public :
    Cuenta();
    Cuenta(int pNo , float pSal);
    bool ActualizarSaldo(int pSal);
    void ActualizarBloqueo(bool pBloq);
    float DameSaldo();
    int DameNoCuenta();
    bool EstaBloqueada();
};

Cuenta::Cuenta()
{
    Saldo=0.0;
    NoCuenta=0;
    bloqueada=false;
}

Cuenta::Cuenta(int pNo , float pSal)
{
    pNo=0;
    pSal=0.0;
    bloqueada=false;
}

bool Cuenta::ActualizarSaldo(int pSal)
{
    if(bloqueada==true)
    {
        cout<<"la cuenta esta bloqueada";
        bloqueada = false;
    }
    else
    {
        Saldo=pSal;
        bloqueada=true;
    }

    return bloqueada;
}

void Cuenta::ActualizarBloqueo(bool pBloq)
{
    bloqueada=pBloq;
}

float Cuenta::DameSaldo()
{
    return Saldo;
}

int Cuenta::DameNoCuenta()
{
    return NoCuenta;
}

bool Cuenta::EstaBloqueada()
{
    return bloqueada;
}

int BuscarCuenta(Cuenta Ctas[MAX_CUENTAS], int NCuentas , int NoCuenta)
{
    int i;
    bool encontrado=false ;

    i=0;
    while(i<NCuentas && !encontrado)
    {
        if(Ctas[i]==Ctas.NoCuenta)
            encontrado=true;
        else
            i++;
    }

    if(encontrado)
        cout << "Posicion " << i+1;
    else
        i=-1 ;


    return i;

}

int MenuCuentas()
{
    char i;

    system("cls");

    cout << "\n\tMenu de Gestion de Cuentas";
    cout << "\n\t\t1 Aniadir una cuenta a un cliente";
    cout << "\n\t\t2 Mostrar las cuentas del cliente";
    cout << "\n\t\t3 Borrar una cuenta del cliente";
    cout << "\n\t\t4 Modificar Saldo de una cuenta";
    cout << "\n\t\t5 Modificar Estado de una cuenta";
    cout << "\n\t\t6 Salir";
    cout << "\n\t\t Elige opcion:";

    cin >> i ;
    i=toupper(i);

}

int main()
{
    Cuenta DatosCuentas[MAX_CUENTAS];
    int nCuentas=0;

    int i;
    do
    {
        i=MenuCuentas();
        switch(i)
            {
                case 1:
                    {

                    }

                case 2:
                    {

                    }

                case 3:
                    {

                    }

                case 4:
                    {

                    }

                case 5:
                    {

                    }



            }
    }while(i!=6);


    return 0;
}

