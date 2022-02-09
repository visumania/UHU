#include <iostream>
#include <string.h>

using namespace std;

//Ejercicio numero 1:

typedef char cad[20];

struct alumno
{
    cad nombre;
    cad asigalumno[12];
    int n;
};

struct profesor
{
    cad nombre;
    cad asigprofesor[5];
    int n;
};

class colegio
{
    cad nombre;
    cad direccion;
    alumno alumnos[200];
    int nalumn;
    profesor profesores[20];
    int nprof;

public:
    colegio();
    void cargarDatosColegio();
    alumno buscar(cad nom);
    bool mismo(colegio c);
};

colegio::colegio()
{
    nalumn = 0;
    nprof = 0;
}

void colegio::cargarDatosColegio()
{
    cout << "Introduzca nombre del colegio: " ;
    cin >> nombre ;

    cout << "\nIntroduzca la direccion del colegio: " ;
    cin >> direccion ;

    cout << "\nIntroduzca numero de alumnos que se van a inscribir: " ;
    cin >> nalumn;

    for(int i=0 ; i<nalumn ; i++)
    {
        cout << "\nIntroduzca el nombre del alumno " << i+1 << ": ";
        cin >> alumnos[i].nombre;

        cout << "\nIntroduzca el numero de asignaturas que va a cursar el alumno " << i+1 << ": " ;
        cin >> alumnos[i].n;

        for(int j=0  ; j<alumnos[i].n ; j++)
        {
            cout << "\nIntroduzca el nombre de la asignatura " << j+1 << ": " ;
            cin >> alumnos[i].asigalumno[j];
        }
    }

    cout << "\nIntroduzca numero de profesores en el centro: " ;
    cin >> nprof ;

    for(int i=0 ; i<nprof ; i++)
    {
        cout << "\nIntroduzca el nombre del profesor " << i+1 << ": " ;
        cin >> profesores[i].nombre ;

        cout << "\nIntroduzca numero de asignaturas que imparte el profesor " << i+1 << ": " ;
        cin >> profesores[i].n;

        for(int j=0 ; j<profesores[i].n ; j++)
        {
            cout << "\nIntroduzca el nombre de la asignatura " << j+1 << ": " ;
            cin >> profesores[i].asigprofesor[j];
        }
    }
}

alumno colegio::buscar(cad nom)
{
    alumno a;

    int i;
    bool encontrado;

    i=0;
    encontrado = false+;

    while(i<nalumn && !encontrado)
    {
        if(strcmp(nom , alumnos[i].nombre)==0)
            encontrado = true;
        else
            i++;
    }

    if(encontrado)
    {
        a = alumnos[i];
    }
    else
    {
        strcpy(a.nombre , "NO HAY ALUMNO");
    }

    return a;
}

bool colegio::mismo(colegio c)
{
    bool devolver=false;

    if(strcmp(nombre , c.nombre)==0)
    {
        if(strcmp(direccion , c.direccion)==0)
            devolver = true;
    }

    return devolver;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Ejercicio numero 2

typedef char Cadena[100];

class Trabajador
{
    Cadena Nombre;
    Cadena Banco;
    float Sueldo;
    int Dni;

public:
    void getNombre(Cadena pNombre);
    void getBanco(Cadena pBanco);
    float getSueldo();
    int getDni();
};

class Obra
{
    Cadena Direccion;
    int Trabajadores[100];
    int nTrabajadores;

public:
    void getDireccion(Cadena pDireccion);
    int getNTrabajadores();
    void getDniTrabajador(int Pos , int &Dni);
    int BuscarTrabajador(int Dni);
};

int LocalizarTrabajador(Trabajador pPlantilla[500] , int PTamaPlantilla , int dni);

int main()
{
    Trabajador Plantilla[500];
    int TamaPlantilla;

    Obra Trabajos[200];
    int NTrabajos;

    Cadena direccion;
    Cadena temp;
    int i;
    bool encontrado;

    cout << "Introduzca la direccion de una obra: " ;
    cin >> direccion ;

    while(i<NTrabajos && !encontrado)
    {
        Trabajos[i].getDireccion(temp);

        if(strcmp(temp , direccion)==0)
            encontrado=true;
        else
            i++;
    }

    if(encontrado)
    {
        int Nt = Trabajos[i].getNTrabajadores();
        float Suma = 0;
        int Dni , Pos , Salario;
        Cadena Nombre;

        for(int j=0 ; j<Nt ; j++)
        {
            Trabajos[i].getDniTrabajador(j , Dni);
            Pos = LocalizarTrabajador(Plantilla , TamaPlantilla , Dni);
            Plantilla[Pos].getNombre(Nombre);
            Salario = Plantilla[Pos].getSueldo();

            cout << "Nombre: " << Nombre << "\tSueldo: " << Salario "\n\n";

            Suma = Suma + Salario;
        }

        cout << "\nSalario Total: " << Suma ;
    }
}
