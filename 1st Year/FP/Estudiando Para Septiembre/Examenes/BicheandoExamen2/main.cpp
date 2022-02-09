#include <iostream>
#include <string.h>
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
    Bloqueada = false;
}

Cuenta::Cuenta(int pNo , float pSal)
{
    Saldo = pSal;
    NoCuenta = pNo;
    Bloqueada = false ;
}

bool Cuenta::ActualizarSaldo(int pSal)
{
    bool devolver = false;

    if(!Bloqueada)
    {
        Saldo = pSal;

        devolver = true;
    }

    return devolver;
}

void Cuenta::ActualizarBloqueo(bool pBloq)
{
    Bloqueada = pBloq;
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
    return Bloqueada ;
}

int BuscarCuenta(Cuenta Ctas[MAX_CUENTAS] , int NCuentas , int NoCuenta)
{
    bool encontrado;
    int i;

    encontrado = false;
    i=0;

    while(i<NCuentas && !encontrado)
    {
        if(Ctas[i].DameNoCuenta()==NoCuenta)
        {
            encontrado = true;
        }
        else
            i++;
    }

    if(!encontrado)
        i=-1;

    return i;
}

int MenuCuentas()
{
    int opcion;

    cout << "\t\tMenu Gestion de Cuentas\n";
    cout << "\t1 Aniadir una cuenta a un cliente\n";
    cout << "\t2 Mostrar las cuentas de un cliente\n";
    cout << "\t3 Borrar una cuenta del cliente\n";
    cout << "\t4 Modificar Saldo de una cuenta\n";
    cout << "\t5 Modificar Estado de una cuenta\n";
    cout << "\t6 Salir\n";
    cout << "\tElige Opcion: " ;
    cin >> opcion ;

    return opcion ;
}

int main()
{
    Cuenta DatosCuentas[MAX_CUENTAS];
    int nCuentas = 0;

    float Saldo;
    int noCuenta;
    bool bloq=false;

    int opc;

    do
    {
        system("cls");

        opc = MenuCuentas();

        switch(opc)
        {
        case 1:
            {
                if(nCuentas<MAX_CUENTAS)
                {
                    cout << "Introduzca el numero de la nueva cuenta: " ;
                    cin >> noCuenta;

                    if(BuscarCuenta(DatosCuentas , nCuentas , noCuenta)== -1)
                    {
                        cout << "\nIntroduzca el saldo de la cuenta: " ;
                        cin >> Saldo ;

                        Cuenta c(noCuenta , Saldo);

                        DatosCuentas[nCuentas] = c ;

                        nCuentas++;
                    }
                    else
                    {
                        cout << "\nError , ya existe ese numero de cuenta\n";
                    }
                }
                else
                {
                    cout << "\nError , no caben mas cuentas en nuestra lista\n";
                }

                system("pause");
            }
            break;

        case 2:
            {
                if(nCuentas>0)
                {
                    for(int i=0 ; i<nCuentas ; i++)
                    {
                        cout << "CUENTA " << i+1 << "\n";
                        cout << "Numero de cuenta :" << DatosCuentas[i].DameNoCuenta();
                        cout << "\nSaldo: " << DatosCuentas[i].DameSaldo();
                        cout << "\nBloqueo: " << DatosCuentas[i].EstaBloqueada() << "\n\n";
                    }
                }
                else
                    cout << "\nEL LISTADO DE CUENTAS ESTA VACIO , NO HAY CUENTAS PARA MOSTRAR\n";


                system("pause");
            }
            break;

        case 3:
            {
                cout << "\nIntroduzca numero de cuenta a eliminar: " ;
                cin >> noCuenta ;

                int pos = BuscarCuenta(DatosCuentas , nCuentas , noCuenta);

                if(pos != -1)
                {
                    for(int i=pos ; i<nCuentas ; i++)
                    {
                        DatosCuentas[i]=DatosCuentas[i+1];
                    }
                    nCuentas--;
                }
                else
                {
                    cout << "\nNo se ha encontrado ninguna cuenta con ese numero de cuenta de eliminar\n";
                }

                system("pause");
            }
            break;

        case 4:
            {
                cout << "\nIntroduzca numero de cuenta para actualizar: ";
                cin >> noCuenta ;

                int pos = BuscarCuenta(DatosCuentas , nCuentas , noCuenta);

                if(pos!= -1)
                {
                    cout << "\nIntroduzca nuevo saldo de la cuenta: " ;
                    cin >> Saldo;

                    if(DatosCuentas[pos].ActualizarSaldo(Saldo)==true)
                    {
                        cout << "\nLa cuenta ha sido actualizada correctamente\n";
                    }
                    else
                    {
                        cout << "\nError, la cuenta no se ha podido actualizar porque esta bloqueada\n";
                    }
                }
                else
                {
                    cout << "\nError no se ha encontrado ningun numero de cuenta que coincida con el introducido \n";
                }

                system("pause");
            }
            break;

        case 5:
            {
                cout << "\nIntroduzca numero de cuenta para actualizarla: " ;
                cin >> noCuenta ;

                int pos = BuscarCuenta(DatosCuentas , nCuentas, noCuenta);
                char a;

                if(pos != -1)
                {
                    cout << "\nDesea bloquear la cuenta?(s/n): ";
                    cin >> a ;

                    a = toupper(a);

                    if(a=='S')
                    {
                        bloq = true ;

                        DatosCuentas[pos].ActualizarBloqueo(bloq);

                        cout << "\nLa cuenta ha sido bloqueada\n";
                    }

                    if(a=='N')
                    {
                        bloq = false ;

                        DatosCuentas[pos].ActualizarBloqueo(bloq);

                        cout << "\nNO se bloqueara la cuenta\n";
                    }

                }
                else
                {
                    cout << "Error , no se ha encontrado ningun numero de cuenta que coincida\n";
                }

                system("pause");
            }
            break;

        case 6:
            {
                cout << "\n\nSaliendo del programa ...gracias por utilizarlo:)\n\n";

            }
            break;

        default:
            {
                cout << "\nError introduzca un numero comprendido entre 1 y 6\n\n";

                system("pause");
            }
        }
    }while(opc!=6);
}
