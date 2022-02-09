#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

typedef char Cadena[50];

#define MAX_CUENTAS 10

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

/*int main()
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
}*/

//Ejercicio 4

#define MAX_CLIENTES 100

class Cliente
{
    Cadena Nombre;
    Cadena Direccion;
    Cuenta Cuentas[MAX_CUENTAS];
    int NoCuentas;

public:
    Cliente();
    void ActualizarCliente(Cadena pNomb , Cadena pDir);
    void DameNombre(Cadena pNom);
    void DameDireccion(Cadena pDir);
    int BuscarCuenta(int pNoCuenta);
    bool CrearCuenta(Cuenta pCu);
    bool ActualizarCuenta(Cuenta pCu);
    bool BorrarCuenta(int pNoCuenta);
    int DameNoCuentas();
    Cuenta DameCuenta(int pos);
    void Mostrar(char Campo);
};

Cliente::Cliente()
{
    NoCuentas = 0 ;
    strcpy(Nombre , "");
    strcpy(Direccion , "");
}

void Cliente::ActualizarCliente(Cadena pNomb , Cadena pDir)
{
    strcpy(Nombre , pNomb);
    strcpy(Direccion , pDir);
    NoCuentas = 0;
}

void Cliente::DameNombre(Cadena pNom)
{
    strcpy(pNom , Nombre); // Devuelve el atributo nombre en el parametro pNom
}

void Cliente::DameDireccion(Cadena pDir)
{
    strcpy(pDir , Direccion);
}

int Cliente::BuscarCuenta(int pNoCuenta)
{
    bool encontrado;
    int i;

    while(i<NoCuentas && !encontrado)
    {
        if(Cuentas[i].DameNoCuenta()==pNoCuenta)
            encontrado=true;
        else
            i++;
    }

    if(!encontrado)
        i=-1;

    return i;
}

bool Cliente::CrearCuenta(Cuenta pCu)
{
    bool devuelve = false ;

    if(NoCuentas < MAX_CUENTAS)
    {
        int c = BuscarCuenta(pCu.DameNoCuenta());

        if(c==-1)
        {
            Cuentas[NoCuentas] = pCu;

            NoCuentas++;

            devuelve = true;
        }
    }

    return devuelve;
}

bool Cliente::ActualizarCuenta(Cuenta pCu)
{
    bool devolver = false;

    int c = BuscarCuenta(pCu.DameNoCuenta());

    if(c != -1)
    {
        Cuentas[c].ActualizarSaldo(pCu.DameSaldo());
        Cuentas[c].ActualizarBloqueo(pCu.DameNoCuenta());

        devolver = true;
    }

    return devolver;
}

bool Cliente::BorrarCuenta(int pNoCuenta)
{
    bool eliminado = false;

    int c = BuscarCuenta(pNoCuenta);

    if(c != -1)
    {
        for(int i=c ; i<NoCuentas ; i++)
        {
            Cuentas[c] = Cuentas[c+1];
        }

       NoCuentas--;

       eliminado = true;
    }

    return eliminado;
}

int Cliente::DameNoCuentas()
{
    return NoCuentas ;
}

Cuenta Cliente::DameCuenta(int pos)
{
    return Cuentas[pos];
}

void Cliente::Mostrar(char Campo)
{
    Campo = toupper(Campo);

    if(Campo == 'S' || Campo == 'T')
    {
        cout << "\nNombre: " << Nombre;
        cout << "\nDireccion: " << Direccion << "\n\n";
    }

    if(Campo=='C' || Campo == 'T')
    {
        for(int i=0 ; i<NoCuentas ; i++)
        {
            cout << "\nNumero de cuenta: " << Cuentas[i].DameNoCuenta();
            cout << "\nSaldo de la cuenta: " << Cuentas[i].DameSaldo();
            cout << "\nBloqueada: " << Cuentas[i].EstaBloqueada();
        }
    }
}

int BuscarCliente(Cliente Ctes[MAX_CLIENTES] , int NCtes , Cadena Nombre)
{
    bool encontrado;
    int i;

    encontrado = false;
    i = 0;

    while(i<NCtes && !encontrado)
    {
        Cadena nom;
        Ctes[i].DameNombre(nom);

        if(strcmp(nom , Nombre)==0)
            encontrado = true;
        else
        i++;
    }

    if(!encontrado)
        i = -1 ;

    return i ;
}

int menu()
{
    int opcion1;

    cout << "\t\tMenu Principal\n";
    cout << "\t1 Aniadir un cliente\n";
    cout << "\t2 Actualizar Direccion del Cliente\n";
    cout << "\t3 Mostrar un cliente\n";
    cout << "\t4 Mostrar todos los clientes\n";
    cout << "\t5 Submenu Gestion de Cuentas\n";
    cout << "\t6 Salir\n";
    cout << "\tElige Opcion: ";
    cin >> opcion1;

    return opcion1;
}

int MenuCuentas()
{
    int opcion2;

    cout << "\t\tMenu Gestion de Cuentas\n";
    cout << "\t1 Aniadir una cuenta a un cliente\n";
    cout << "\t2 Mostrar las cuentas de un cliente\n";
    cout << "\t3 Borrar una cuenta del cliente\n";
    cout << "\t4 Modificar Saldo de una cuenta\n";
    cout << "\t5 Modificar Estado de una cuenta\n";
    cout << "\t6 Salir\n";
    cout << "\tElige Opcion: " ;
    cin >> opcion2 ;

    return opcion2 ;
}

int main()
{
    Cliente Datos[MAX_CLIENTES];
    int nClientes=0;
    Cuenta DatosCuentas[MAX_CUENTAS];
    int nCuentas = 0;

    float Saldo;
    int noCuenta;
    bool bloq=false;

    Cadena nombre;
    Cadena direccion;


    int opc1;
    int opc2;

    do
    {
        system("cls");

        opc1 = menu();

        switch(opc1)
        {
            case 1:
                {
                    cout << "\nIntroduzca nomnbre: ";
                    cin >> nombre;

                    cout << "\nIntroduzca direccion: " ;
                    cin >> direccion ;

                    Datos[nClientes].ActualizarCliente(nombre , direccion);

                    nClientes++;
                }
                break;

            case 2:
                {
                    cout << "\nIntroduzca nombre del cliente a actualizar: ";
                    cin >> nombre;

                    int c = BuscarCliente(Datos ,nClientes , nombre);

                    if(c != -1)
                    {
                        cout << "\nIntroduzca direccion del cliente: " ;
                        cin >> direccion ;

                        Datos[c].ActualizarCliente(nombre , direccion);
                    }
                    else
                    {
                        cout << "\nNo se ha encontrado a ningun cliente con ese nombre para actualizar\n\n";
                    }

                    system("pause");
                }
                break;

            case 3:
                {
                    cout << "\nIntroduzca nombre del cliente a buscar: " ;
                    cin >> nombre ;

                    int pos = BuscarCliente(Datos , nClientes , nombre);

                    if(pos != -1)
                    {
                        Datos[pos].Mostrar('T');
                    }
                    else
                    {
                        cout << "\nNo se ha encontrado a ningun cliente con ese nombre\n\n";
                    }

                    system("pause");
                }
                break;

            case 4:
                {
                    if(nClientes==0)
                    {
                        cout << "\nNo hay clientes para mostrar\n\n";
                    }
                    else
                    {
                         for(int i=0 ; i<nClientes ; i++)
                        {
                            cout << "CLIENTE " << i+1 << "\n";

                            Datos[i].Mostrar('T');

                            cout << "\n\n";
                        }
                    }

                    system("pause");
                }
                break;

            case 5:
                {
                    cout << "Introduzca el nombre del cliente para operar en el menu de cuentas: " ;
                    cin >> nombre;

                    int pos = BuscarCliente(Datos , nClientes , nombre);

                    if(pos != -1)
                    {
                                 do
                            {
                                system("cls");

                                opc2 = MenuCuentas();

                                switch(opc2)
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
                                        cout << "\n\nSaliendo del submenu de cuentas ...gracias por utilizarlo:)\n\n";

                                    }
                                    break;

                                default:
                                    {
                                        cout << "\nError introduzca un numero comprendido entre 1 y 6\n\n";

                                        system("pause");
                                    }
                                }
                            }while(opc2!=6);
                    }
                    else
                    {
                        cout << "\nNo se ha encontrado a ningun cliente con ese nombre\n\n";
                    }

                    system("pause");
                }

                break;
            case 6:
                {
                    cout << "\n\nSaliendo del programa ... gracias por utilizarlo :)\n\n";

                    system("pause");
                }
                break;

            default:
                {
                    cout << "\nError , introduzca un numero entre 1 y 6\n\n";

                    system("pause");
                }
        }

    }while(opc1!=6);
}
