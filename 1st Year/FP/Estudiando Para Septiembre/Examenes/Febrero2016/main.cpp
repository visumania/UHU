#include <iostream>
#include <string.h>

using namespace std;

typedef char cadena[30];

struct datospersonales
{
    cadena nom , domicilio;
    int codimpuesto;
    int tasa;
};

class contribuyentes
{
    datospersonales datos[100];

public:
    //Diseñar metodos (solo cabecera) de la clase y genericas (si lo hay)

    contribuyentes(int n);
    bool leer(cadena nombre);

};

void localizarcontribuyente(contribuyentes con , cadena nombre , int &numerocontribuyentes);
float calcular(contribuyentes c , int numcontribuyentes);
void almacenar(contribuyentes &c , int i , int tasa);

int main()
{
    contribuyentes c(500);

    bool valor;
    cadena nom;
    int i, tasa;

    valor= c.leer(nom);

    cout << "Dame el nombre del contribuyente: ";
    cin >> nom;

    localizarcontribuyente(c , nom , i);
    cout << "El contribuyente con nombre " << nom << " esta en la posicion " << i+1;

    //...

    tasa = calcular(c , i);
    almacenar(c , i , tasa);

    //...
}

//Apartado b)

void ver(float t[12][31] , int &n)
{
    float total , maximo;
    int n;

    for(int i=0 ; i<31 ; i++)
        maximo = t[0][i];

    n=1 ;

    for(int i=1 ; i<12 ; i++)
    {
        total = 0;

        for(int j=0 ; j<31 ; j++)
        {
            if(total > maximo)
            {
                maximo = total ;
                n = i+1;
            }
        }
    }

}

//Ejercicio 2)

typedef char Cadena[100];

struct
{
    int NumCuenta;
    float Saldo;
};

class Cliente
{
    Cadena Nombre;
    CC Cuentas[100];
    int Ncuentas;

public:
    void GetNombre(Cadena PNom);
    int NumCuentas();
    CC getCuenta(int Pos);
    int BuscarCuenta(int Numero);
};

void Cliente::GetNombre(Cadena PNom)
{
    strcpy(PNom , Nombre);
}

int Cliente::NumCuentas()
{
    return Ncuentas;
}

CC Cliente::getCuenta(int Pos)
{
    return Cuentas[Pos];
}

int Cliente::BuscarCuenta(int Numero)
{
    bool encontrado ;
    int i;

    Numero = -1;

    encontrado = false;
    i = 0;

    while(i<Ncuentas && !encontrado)
    {
        if(Cuentas[i].NumCuenta==Numero)
            encontrado = true;
        else
            i++;
    }

    if(encontrado)
        Numero = i;

    return Numero;

}

class Banco
{
    Cadena Nombre;
    Cliente Clientes[100];
    int NClientes;

public:
    void MostrarClientes(float SaldoMin , float SaldoMax);
};

void Banco::MostrarClientes(float SaldoMin , floar SaldoMax)
{
    int orden = 0;

    for(int i=0 ; i<Ncuentas ; i++)
    {

    }
}

