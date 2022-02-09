#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

typedef char cad[20];

#define M 40
#define M2 5
#define MAlum 200
#define MProf 20

struct Asignatura
{
    cad nombre;
    int numCreditos;
};

struct Alumno
{
    cad nombre;
    cad ciudad;
    cad carrera;
    Asignatura asigalumno[M];
    int nAsig;
};

struct Profesor
{
    cad nombre;
    Asignatura asigprofesor[M2];
    int nAsig;
};

class Universidad
{
    cad nombre;
    cad ciudad;
    Alumno alumnos[MAlum];
    int nalumn;
    Profesor profesores[MProf];
    int nprof;

public:
    Universidad();
    void cargarDatosUniversidad();
    Asignatura buscar(cad nom);
};

Universidad::Universidad()
{
    nalumn = 0 ;
    nprof = 0;
}

void Universidad::cargarDatosUniversidad()
{
    cout << "Introduzca nombre de la Universidad: " ;
    cin >> nombre;

    cout << "\nIntroduzca ciudad a la que pertenece la Universidad: " ;
    cin >> ciudad;

    cout << "\nIntroduzca numero de alumnos inscritos: " ;
    cin >> nalumn;

    for(int i=0 ; i<nalumn ; i++)
    {
        cout << "ALUMNO " << i+1 << ":\n";

        cout << "Introduzca nombre: " ;
        cin >> alumnos[i].nombre;

        cout << "\nIntroduzca numero de asignaturas en las que se va a matricular: " ;
        cin >> alumnos[i].nAsig;

        for(int j=0 ; j<alumnos[i].nAsig ; j++)
        {
            cout << "\nIntroduzca nombre de la asignatura " << j+1 << ": " ;
            cin >> alumnos[i].asigalumno[j].nombre;

            cout << "\nIntroduzca numero de creditos que tiene la asignatura: " ;
            cin >> alumnos[i].asigalumno[j].numCreditos;
        }
    }

    system("cls");

    cout << "Alumnos cargados correctamente\n";

    system("pause");

    cout << "\nIntroduzca numero de profesores que hay en el centro: " ;
    cin >> nprof;

    for(int i=0 ; i<nprof ; i++)
    {
        cout << "PROFESOR " << i+1 << ":\n";

        cout << "Introduzca nombre: " ;
        cin >> profesores[i].nombre;

        cout << "\nIntroduzca numero de asignaturas que imparte: ";
        cin >> profesores[i].nAsig;

        for(int j=0 ; j<profesores[i].nAsig ; j++)
        {
            cout << "\nIntroduzca nombre de la asignatura " << j+1 << ": " ;
            cin >> profesores[i].asigprofesor[j].nombre;

            cout << "\nIntroduzca numero de creditos que abarca la asignatura: " ;
            cin >> profesores[i].asigprofesor[j].numCreditos;
        }
    }
}

Asignatura Universidad::buscar(cad nom)
{
    Asignatura Asig;

    bool encontradoalumno;
    bool encontradoprofesor;
    int i , j , z , x;

    encontradoalumno = false;
    i=0;

    while(i<nalumn && !encontradoalumno)
    {
        j=0;

        while(j<alumnos[i].nAsig && !encontradoalumno)
        {
            if(strcmp(alumnos[i].asigalumno[j].nombre , nom)==0)
                encontradoalumno = true;
            else
                j++;
        }

        if(!encontradoalumno)
            i++;
    }

    encontradoprofesor=false;
    z=0;

    while(z<nprof && !encontradoprofesor)
    {
        x=0;

        while(x<profesores[z].nAsig && !encontradoprofesor)
        {
            if(strcmp(profesores[z].asigprofesor[x].nombre , nom)==0)
                encontradoprofesor = true;
            else
                x++;
        }

        if(!encontradoprofesor)
            z++;
    }

    if((encontradoalumno && encontradoprofesor) || (encontradoalumno && !encontradoprofesor))
    {
        strcpy(Asig.nombre , alumnos[i].asigalumno[j].nombre);
        Asig.numCreditos = alumnos[i].asigalumno[j].numCreditos;
    }

    if(!encontradoalumno && encontradoprofesor)
    {
        strcpy(Asig.nombre , profesores[z].asigprofesor[x].nombre);
        Asig.numCreditos = profesores[z].asigprofesor[x].numCreditos;
    }

    return Asig;
}

#define NUnv 5

class Comunidad
{
    Universidad universidades[NUnv];
    int nUnv;

public:
    Universidad mayorNumAsignaturas();
    void buscarAlumnos(cad nom);
};

Universidad Comunidad::mayorNumAsignaturas()
{
    int maximo = 0;
    int contador = 0;
    int pos;

    for(int i=0 ; i<nUnv ; i++)
    {
        for(int j=0 ; j<universidades[i].nalumn ; j++)
        {
            contador = contador + universidades[i].alumnos[j].nAsig;
        }

        if(contador > maximo)
        {
            maximo = contador;
            pos = i ;
        }
    }

    return universidades[pos];
}

void Comunidad::buscarAlumnos(cad nom)
{
    cout << "\t\t**BUSCAR ALUMNOS**";

    for(int i=0 ; i<nUnv ; i++)
    {
        for(int j=0 ; j<universidades[i].nalumn ; j++)
        {
            if(strcmp(universidades[i].alumnos[j].nombre , nom)==0)
            {
                cout << "\n\nNombre: " << universidades[i].alumnos[j].nombre;
                cout << "\nCiudad: " << universidades[i].alumnos[j].ciudad;
                cout << "\nUniversidad: " << universidades[i].nombre;
                cout << "\nCarrera: " << universidades[i].alumnos[j].carrera;
                cout < "\nNumero de asignaturas matriculadas: " << universidades[i].alumnos[j].nAsig;
                cout << "\nAsignaturas: " ;

                for(int z=0 ; z<universidades[i].alumnos[j].nAsig ; z++)
                {
                    cout << universidades[i].alumnos[j].asigalumno[z].nombre << " , " ;
                }
            }
        }
    }
}

int main()
{
    int opcion;

    do
    {
        system("cls");

        cout << "\tt**MENU UNIVERSITARIO ANDALUZ**";
        cout << "\n1.- Registrar Universidad Andaluza";
        cout << "\n2.- Buscar Universidad Andaluza";
        cout << "\n3.- Buscar mayor Universidad Andaluza";
        cout << "\n4.- Buscar alumno en Andalucia";
        cout << "\n5.- Salir";
        cout << "\n\nElija opcion: " ;
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                {

                }
                break;

            case 2:
                {

                }
                break;

            case 3:
                {

                }
                break;

            case 4:
                {

                }
                break;

            case 5:
                {
                    cout << "\nSaliendo del programa...\n\n";

                    system("pause");
                }
                break;

            default:
                {
                    if((opcion<1) || (opcion>5))
                    {
                        cout << "\nError, introduzca numero comprendido entre 1 y 5";

                    }
                }
        }
    }while(opcion!=5);
}



