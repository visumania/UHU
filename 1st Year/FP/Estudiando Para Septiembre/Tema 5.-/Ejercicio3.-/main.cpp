#include <iostream>
#include <windows.h>

using namespace std;

typedef char Cadena[50];

#define MAX_CUENTAS 100

class Cuenta
{
    float Saldo;
    int NoCuenta;
    bool Bloqueada;

public:
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
    Saldo = 0 ;
    NoCuenta = 0 ;
    Bloqueada = false ;
}

Cuenta::Cuenta(int pNo , float pSal)
{
    NoCuenta = pNo ;
    Saldo = pSal;
    Bloqueada = false ;
}

bool Cuenta::ActualizarSaldo(int pSal)
{
    bool actualizado = false ;

    if(!Bloqueada) // La cuenta no este bloqueada
    {
        Saldo = pSal;
        actualizado = true;
    }

    return actualizado ;
}

void Cuenta::ActualizarBloqueo(bool pBloq)
{
    Bloqueada = pBloq ;
}

float Cuenta::DameSaldo()
{
    return Saldo ;
}

int Cuenta::DameNoCuenta()
{
    return NoCuenta ;
}

bool Cuenta::EstaBloqueada()
{
    return Bloqueada ;
}

int BuscarCuenta(Cuenta Ctas[MAX_CUENTAS] , int NCuentas , int NoCuenta)
{
    int n ;
    bool encontrado  ;

    n = 0 ;
    encontrado = false ;

    while(n<NCuentas && !encontrado)
    {
        if(NoCuenta == Ctas[n].DameNoCuenta())
        {
            encontrado = true;
        }
        else
            n++;
    }

    if(encontrado)
    {
        return n ;
    }
    else
    {
        return -1 ;
    }
}

int Menucuentas()
{
    int opcion ;

    cout << "\t\tMenu Gestion de Cuentas\n";
    cout << "\t1 Anadir una cuenta al cliente\n";
    cout << "\t2 Mostrar las cuentas del cliente\n";
    cout << "\t3 Borrar una cuenta del cliente\n";
    cout << "\t4 Modificar Saldo de una cuenta\n";
    cout << "\t5 Modificar Estado de una cuenta\n";
    cout << "\t6 Salir\n";
    cout << "\tElige opcion: ";

    cin >> opcion ;

    return opcion;
}

int main()
{
    Cuenta DatosCuentas[MAX_CUENTAS];

    int nCuentas = 0;
    int numerocuenta;
    float saldo ;
    int eliminado;
    int opcion ;
    int posicion;
  //  bool encontrado;
    //int n;
    int pos;
    char caracter ;
    bool bloqueado = false;
    //int Saldo;

    do
    {
        system("cls");

        opcion = Menucuentas();

        switch(opcion)
        {
        case 1:

                if(nCuentas < MAX_CUENTAS)
                {
                    cout << "\nIntroduzca el numero de la cuenta nueva: " ;
                    cin >> numerocuenta;

                        if(BuscarCuenta(DatosCuentas , nCuentas , numerocuenta) == -1)
                        {
                            cout << "\nIntroduzca saldo: " ;
                            cin >> saldo;

                            Cuenta c(numerocuenta , saldo);

                            DatosCuentas[nCuentas] = c;

                            nCuentas ++ ;
                        }
                        else
                        {
                            cout << "\nYa existe una cuenta con esos datos\n";
                        }



                }

            break;

        case 2:
                for(int i=0; i<nCuentas ; i++)
                {
                    cout << "\nCuenta " << i+1;
                    cout << "\nNumero de cuenta: " << DatosCuentas[i].DameNoCuenta();
                    cout << "\nSaldo de la cuenta: " << DatosCuentas[i].DameSaldo();
                    cout << "\nBloqueada: " << DatosCuentas[i].EstaBloqueada() << "\n\n";
                }

                system("pause");

            break;

        case 3:
            cout << "\nIntroduzca numero de cuenta a eliminar: " ;
            cin >> eliminado ; // Esto es un numero de cuenta

            pos = BuscarCuenta(DatosCuentas , nCuentas  , eliminado) ;
            if(pos != -1)
            {
                  for (int i = pos; i<nCuentas; i++)
                    {
                        DatosCuentas[i] = DatosCuentas[i+1];
                    }

                    nCuentas--;
            }
            else
                {
                    cout << "\nNo se ha encontrado ninguna cuenta con esos datos para eliminarla\n";
                }

            break;

        case 4:
            cout << "\nIntroduzca numero de cuenta a actualizar: " ;
            cin >> numerocuenta ;


            posicion = BuscarCuenta(DatosCuentas , nCuentas , numerocuenta);

            if(posicion != -1)
            {
                cout << "\nIntroduzca nuevo saldo: " ;
                cin >> saldo;
                if(DatosCuentas[posicion].ActualizarSaldo(saldo)==true)
                {
                     cout << "\nLa cuenta ha sido actualizada correctamente\n" ;
                     system("pause");
                }
                else
                    cout << "\nError , la cuenta esta bloqueada y no se ha podido actualizar\n"; system("pause");
            }
            else
            {
                cout << "\nError , no se ha encontrado ninguna cuenta para actualizar\n";
                system("pause");
            }
            break;

        case 5:
            cout << "\nIntroduzca numero de cuenta que desea actualizar: " ;
            cin >> numerocuenta;


            posicion = BuscarCuenta(DatosCuentas , nCuentas , numerocuenta);
            bloqueado = false;

            if(posicion !=-1)
            {
                cout << "\nDesea bloquear la cuenta (s/n): " ;
                cin >> caracter ;

                if(caracter == 's')
                {
                    bloqueado = true;
                }

                DatosCuentas[posicion].ActualizarBloqueo(bloqueado);
            }
            else
            {
                cout << "Error , no se ha encontrado ninguna cuenta con esos datos\n";
            }


            break;

        case 6:

                cout << "\nSaliendo del programa ... gracias por usarlo\n";
                system("pause");

            break;

        default:
            {
                if(1>opcion || opcion > 6)
                {
                    cout << "Error , vuelva a introducir numero\n";
                    system("pause");
                }
            }
        }

    }while(opcion!=6);
}
