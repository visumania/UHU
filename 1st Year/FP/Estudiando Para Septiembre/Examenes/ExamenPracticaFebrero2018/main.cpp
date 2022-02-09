#include <iostream>
#include <string.h>

using namespace std;

struct TFecha
{
    int Dia , Mes , Anio;
};

class Persona
{
    char Nombre[40];
    char Direccion[40];
    TFecha FNacimiento;

public:
    Persona();
    int Asignar(char PNombre[40] , char PDireccion[40] , TFecha PFNacimiento);
    void Get_Nombre(char PNombre[40]);
    void Set_Nombre(char PNombre[40]);
    void Get_Direccion(char PDireccion[40]);
    void Set_Direccion(char PDireccion[40]);
    TFecha Get_FechaNacimiento();
    void Set_FechaNacimiento(TFecha PFNacimiento);
    int igual(Persona PersonaBuscada);
};

Persona::Persona()
{
    FNacimiento.Anio = 0;
    FNacimiento.Mes = 0;
    FNacimiento.Dia = 0;
    strcpy(Direccion , "");
    strcpy(Nombre , "");
}

int Persona::Asignar(char PNombre[40] , char PDireccion[40], TFecha PFNacimiento)
{
    if(strcmp(PNombre , "")!=0)
    {
        if(strcmp(PDireccion , "")!=0)
        {
            strcpy(Nombre , PNombre);
            strcpy(Direccion , PDireccion);
            FNacimiento.Anio = PFNacimiento.Anio;
            FNacimiento.Mes = PFNacimiento.Mes;
            FNacimiento.Dia = PFNacimiento.Dia;
        }
    }
}

void Persona::Get_Nombre(char PNombre[40])
{
    strcpy(PNombre , Nombre);
}

void Persona::Get_Direccion(char PDireccion[40])
{
    strcpy(PDireccion , Direccion);
}

TFecha Persona::Get_FechaNacimiento()
{
   return FNacimiento;
}

void Persona::Set_Nombre(char PNombre[40])
{
    strcpy(Nombre , PNombre);
}

void Persona::Set_Direccion(char PDireccion[40])
{
    strcpy(Direccion , PDireccion);
}

void Persona::Set_FechaNacimiento(TFecha PFNacimiento)
{
    FNacimiento.Anio = PFNacimiento.Anio;
    FNacimiento.Mes = PFNacimiento.Mes;
    FNacimiento.Dia = PFNacimiento.Dia;
}

int Persona::igual(Persona PersonaBuscada)
{
    int devolver = 0;

    if(strcmp(Persona.Nombre , PersonaBuscada.Nombre)==0)
        devolver = 1;

    return devolver;
}

void MostrarPersona(Persona P)
{
    cout << "Nombre: " << P.Nombre << endl;
    cout << "Direccion: " << P.Direccion << endl;
    cout << "Fecha de nacimiento (dia/mes/anio): " << P.FNacimiento.Dia << "/" << P.FNacimiento.Mes << "/" << P.FNacimiento.Anio << endl;
}

Persona PedirDatosPersona()
{
    Persona p;

    cout << "Introduzca el Nombre: " ;
    cin >> p.Nombre;

    cout << "\nIntroduzca Direccion: " ;
    cin >> p.Direccion;

    cout << "\nIntroduzca fecha de nacimiento (dia/mes/anio): " ;
    cin >> p.FNacimiento.Dia >> p.FNacimiento.Mes >> p.FNacimiento.Anio ;

    return p ;
}

//Apartado b)

class Agenda
{
    Persona Propietario;
    Persona Amigos[100];
    int NAmigos;

public:
    Agenda();
    int AniadirContacto(Persona PAmigo);
    int BorrarContacto(int Pos);
    int BuscarContacto(Persona PAmigo);
    void MostrarContacto(int PosAmigo);
    void MostrarAgenda();
    int NContacto();
};

Agenda::Agenda()
{
    //Metodo constructor que debe inicializar los datos de la agenda. El metodo debe solicitar por teclado los datos de la persona propietaria
    // de la agenda por teclado y pondr� la tabla vac�a
}

int Agenda::AniadirContacto(Persona PAmigo)
{
    //M�todo que almacenar� la persona pasada por par�metro en el vector Amigos, siempre y cuando haya espacio. El metodo devuelve 1 si se ha a�adido
    // el nuevo contacto y 0 si no se ha podido por falta de espacio
}

int Agenda::BorrarContacto(int Pos)
{
    int devolver = 0 ;

    if(Pos<=NAmigos)
    {
        for(int i=Pos ; i<=NAmigos ; i++)
        {
            strcpy(Amigos[i].Nombre , Amigos[i+1].Nombre);
            strcpy(Amigos[i].Direccion , Amigos[i+1].Direccion);
            Amigos[i].FNacimiento.Anio = Amigos[i+1].FNacimiento.Anio;
            Amigos[i].FNacimiento.Mes = Amigos[i+1].FNacimiento.Mes;
            Amigos[i].FNacimiento.Dia = Amigos[i  +1].FNacimiento.Dia;
        }

        devolver = 1;
        NAmigos--;
    }

    return devolver;
}

int Agenda::BuscarContacto(Persona PAmigo)
{
    //M�todo que buscar� la persona pasada por par�metro en el vector Amigos. Devolver� la posicion en la tabla del elemento que coincide o bien -1
    // si nadie coincide
}

void Agenda::MostrarContacto(int PosAmigo)
{
    //M�todo que mostrar� los datos de la persona del vector Amigos siempre y cuando la posicion pasada por par�metro sea correcta. En caso contrario
    // no mostrar� nada
}

void Agenda::MostrarAgenda()
{
    //M�todo que debe mostrar por pantalla inicialmente los datos del propietario, y posteriormente los datos de cada una de las personas
    // almacenadas en la agenda
}

int Agenda::NContacto()
{
    return NAmigos;
}
