#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

typedef char Cadena[50];

#define MAX_CUENTAS 100
#define MAX_CLIENTES 100

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

/*int Menucuentas()
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
}*/

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
    void Mostrar (char Campo);
};

Cliente::Cliente()
{
    strcpy(Nombre , "");
    strcpy(Direccion , "");
    NoCuentas = 0;
}

void Cliente::ActualizarCliente(Cadena pNomb , Cadena pDir)
{
    strcpy(Nombre , pNomb);
    strcpy(Direccion , pDir);
    NoCuentas = 0;
}

void Cliente::DameNombre(Cadena pNom)
{
    strcpy(pNom, Nombre);
}

void Cliente::DameDireccion(Cadena pDir)
{
    strcpy(Direccion , pDir);
}

int Cliente::BuscarCuenta(int pNoCuenta)
{
    /*int busqueda = BuscarCuenta(Cuentas, NoCuentas , pNoCuenta);
    int devolver = -1;

   if(busqueda == -1)
   {
       cout << "No se ha encontrado ningun cliente asociado a ese numero de cuenta\n  ";
   }

   else
    {
        devolver = Cuentas[busqueda].DameNoCuenta();
    }

   return devolver;*/

   int n ;
    bool encontrado  ;

    n = 0 ;
    encontrado = false ;

    while(n<NoCuentas && !encontrado)
    {
        if(NoCuentas == Cuentas[n].DameNoCuenta())
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

bool Cliente::CrearCuenta(Cuenta pCu)
{
    if(NoCuentas < MAX_CUENTAS)
    {
        int c = BuscarCuenta(pCu.DameNoCuenta());

        if(c == -1)
        {
            Cuentas[NoCuentas] = pCu;

            NoCuentas++;

        }

        return true;

    }
    else
        return false;

}

bool Cliente::ActualizarCuenta(Cuenta pCu)
{
  int c = BuscarCuenta(pCu.DameNoCuenta());

  if(c==-1)
    return false;
  else
  {
      Cuentas[c].ActualizarSaldo(pCu.DameSaldo());
      Cuentas[c].ActualizarBloqueo(pCu.EstaBloqueada());

      return true;
  }
}

bool Cliente::BorrarCuenta(int pNoCuenta)
{
    int c = BuscarCuenta(pNoCuenta);

    if(c==-1)
    {
        return false;
    }
    else
    {
          for (int i = c; i<NoCuentas; i++)
            {
                Cuentas[i] = Cuentas[i+1];
            }

            NoCuentas--;

            return true ;
    }


}

int Cliente::DameNoCuentas()
{
    return NoCuentas;
}

Cuenta Cliente::DameCuenta(int pos)
{
    return Cuentas[pos];
}

void Cliente::Mostrar(char Campo)
{
    if(Campo == 's' || Campo == 't')
    {
        cout << "Nombre: " <<Nombre << endl;
        cout << "Direccion: " << Direccion << endl;
    }

    if(Campo == 'c' || Campo == 't')
    {
        for(int i=0 ; i<NoCuentas ; i++)
        {
            cout << "Saldo: " << Cuentas[i].DameSaldo() << endl;
            cout << "Numero de cuenta: " << Cuentas[i].DameNoCuenta() << endl;
            cout << "Bloqueada: " << Cuentas[i].EstaBloqueada() <<endl;
        }
    }
}

int BuscarCliente(Cliente Ctes[MAX_CLIENTES] , int NCtes , Cadena Nombre)
{
    int n ;
    bool encontrado  ;
    Cadena nombrebuscado ;


    n = 0 ;
    encontrado = false ;

    while(n<NCtes && !encontrado)
    {

        Ctes[n].DameNombre(nombrebuscado);
        if(strcmp(Nombre, nombrebuscado)==0)
        {
            encontrado = true;
        }
        else n++;
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

int Menu()
{
    int opcion ;

    cout << "\t\t Menu principal \n";
    cout << "\t1 Añadir un cliente\n";
    cout << "\t2 Actualizar direccion del cliente\n";
    cout << "\t3 Mostrar un cliente\n";
    cout << "\t4 Mostrar todos los clientes\n";
    cout << "\t5 Submenu de gestion de cuentas\n";
    cout << "\t6 Salir\n";
    cout << "\tElige opcion: ";

    cin >> opcion ;

    return opcion;
}

int MenuCuentas()
{
    int opcion ;

    cout << "\t\t Menu de gestion de cuentas\n";
    cout << "\t1 Añadir una cuenta a un cliente\n";
    cout << "\t2 Mostrar las cuentas de un cliente\n";
    cout << "\t3 Borrar cuenta de un cliente\n";
    cout << "\t4 Modificar el saldo de un cliente\n";
    cout << "\t5 Modificar estado de una cuenta\n";
    cout << "\t6 Salir\n";
    cout << "\tElige opcion: ";

    cin >> opcion ;

    return opcion;
}

int main()
{
    Cliente Datos[MAX_CLIENTES];
    int NClientes=0;

    Cadena nombre;
    Cadena direccion;
    int opcion;
    int submenu;
    int posicioncliente;
    Cuenta DatosCuentas[MAX_CUENTAS];
    int nCuentas = 0;
    int numerocuenta;
    float saldo;
    int eliminado;
    int pos;
    int posicion ;
    bool bloqueado;
    char caracter;

    do
    {
        system("cls");

        opcion = Menu();

        switch(opcion)
        {
        case 1:

            cout << "Introduzca nombre del Cliente: " ;
            cin >> nombre ;

            cout << "Introduzca dirrecion del Cliente: Calle ";
            cin >> direccion;

            Datos[NClientes].ActualizarCliente(nombre , direccion);

            NClientes++;

            break;

        case 2:

            cout << "Introduzca nombre del cliente a modoficar: " ;
            cin >> nombre ;

            posicioncliente = BuscarCliente(Datos , NClientes , nombre);

            if(posicioncliente!=-1)
            {
                cout << "\nIntroduzca la direccion del cliente: " ;
                cin >> direccion ;

                Datos[posicioncliente].ActualizarCliente(nombre , direccion);
            }
            else
            {
                cout << "Error , no hemos encontrado a ningun cliente con ese nombre\n";
            }

            break;

        case 3:

            cout << "Introduzca el nombre del cliente: " ;
            cin >> nombre ;

            posicioncliente = BuscarCliente(Datos , NClientes , nombre) ;

            if(posicioncliente!=-1)
            {
                Datos[posicioncliente].Mostrar('t');

                system("pause");
            }
            else
            {
                cout << "Error , no hemos encontrado a ningun cliente con ese nombre\n" ;
            }

            break;

        case 4:

            if(NClientes==0)
            {
                cout << "No hay clientes para mostrar en este momento\n";

                system("pause");
            }
            else
            {
                for(int i = 0; i < NClientes; i++)
                    {
                        Datos[i].Mostrar('t');

                        cout << "\n";
                    }

                system("pause");
            }

            break;

        case 5:

            cout << "Introduzca nombre del cliente para operar en el menu de subcuentas: ";
            cin >> nombre ;

            posicioncliente = BuscarCliente(Datos , NClientes , nombre) ;

            if(posicioncliente!=-1)
            {
                Datos[posicioncliente].Mostrar('c');

                cout << "\n";

                do
                {
                    //system("cls");

                    submenu = MenuCuentas();

                    switch(submenu)
                    {
                    case 1:

                        if(Datos[posicioncliente].DameNoCuentas() < MAX_CUENTAS)
                            {
                                cout << "\nIntroduzca el numero de la cuenta nueva: " ;
                                cin >> numerocuenta;


                                    if(BuscarCuenta(DatosCuentas, Datos[posicioncliente].DameNoCuentas() , numerocuenta) == -1)
                                    {
                                        cout << "\nIntroduzca saldo: " ;
                                        cin >> saldo;

                                        Cuenta c(numerocuenta , saldo);
                                        DatosCuentas[nCuentas] = c;
                                        nCuentas++;
                                        Datos[posicioncliente].CrearCuenta(c);
                                    }
                                    else
                                    {
                                        cout << "\nYa existe una cuenta con esos datos\n";
                                    }
                            }

                        break;

                    case 2:

                        for (int i = 0; i < Datos[posicioncliente].DameNoCuentas(); i++){
                            cout << "\nCuenta " << posicioncliente+1;
                            cout << "\nNumero de cuenta: " << Datos[posicioncliente].DameCuenta(i).DameNoCuenta();
                            cout << "\nSaldo de la cuenta: " << Datos[posicioncliente].DameCuenta(i).DameSaldo();
                            cout << "\nBloqueada: " << Datos[posicioncliente].DameCuenta(i).EstaBloqueada() << "\n\n";
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
                        {
                            cout << "Volviendo al menu principal de cuentas ... \n" ;

                            system("pause");
                        }
                        break;
                    }

                    if(submenu<1 || submenu >6)
                    {
                        cout << "Error el numero introducido no se encuentra dentro del intervalo que abarca el menu\n";

                        system("pause");
                    }

                }while(submenu!=6);

            }
            else
            {
                cout << "No se ha encontrado a ningun cliente con ese nombre\n";

                system("pause");
            }

            break;

        case 6:
            cout << "Saliendo del programa... gracias por usarlo\n";

            break;

        }

        if(opcion<1)
        {
            cout << "Error\n";

            system("pause");
        }

        if(opcion>6)
        {
            cout << "Error\n";

            system("pause");
        }



    }while(opcion!=6);
}

/*int main()
{
    Cuenta DatosCuentas[MAX_CUENTAS];

    Cliente Datos[MAX_CLIENTES];
    int nClientes;
    Cadena nombre ;

    int nCuentas = 0;
    int numerocuenta;
    float saldo ;
    int eliminado;
    int opcion ;
    int posicion;
    //int n;
    int pos;
    char caracter ;
    bool bloqueado = false;
    //int Saldo;

    do
    {
        system("cls");

        opcion = Menu();

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

                cout << "Introduzca el nombre de un cliente para buscarlo: " ;
                cin >> nombre ;

                posicion = BuscarCliente(Datos, nClientes, nombre);

                if(posicion != -1)
                    cout << "Se ha encontrado el cliente en la posicion " << posicion+1 << "\n";
                else
                    cout << "No se ha encontrado el cliente en ninguna posicion\n";

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
}*/
