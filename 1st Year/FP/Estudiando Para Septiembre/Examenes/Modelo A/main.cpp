#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

/********************************

DNI: 49063961Q
NOMBRE: Adrián Moreno Monterde

*********************************/


typedef char Cadena[50];
#define MAX_INGREDIENTES 100

struct Ingrediente
{
    Cadena Nombre;
    float Gramos;
    int Cantidad;
    int Calorias;
};

class Receta
{
    Cadena Titulo;
    Ingrediente Elementos[MAX_INGREDIENTES];
    int NIngredientes;
    int Dificultad;
    int NPersonas;
public:
    Receta();
    void ActualizarDatos(Cadena pNombre, int pNDificultad, int pNPersonas);
    int Buscar(Cadena pNombre);
    Ingrediente get_Ingrediente(int pPos);
    int get_NIngredientes();
    void get_DatosAdicionales(Cadena pNombre, int &pDificultad, int &pNPersonas);
    void set_Ingrediente(int pPos, Ingrediente pIng);
    bool eliminarIngrediente(Cadena pNombre);
    bool anadirIngrediente(Ingrediente pIng);
};

Receta::Receta()
{
    strcpy(Titulo,"");
    NIngredientes=Dificultad=NPersonas=0;
}

void Receta::ActualizarDatos(Cadena pNombre, int pNDificultad, int pNPersonas)
{
    strcpy(Titulo , pNombre);
    Dificultad = pNDificultad;
    NPersonas = pNPersonas;
    NIngredientes = 0;
}

int Receta::Buscar(Cadena pNombre)
{
    bool encontrado;
    int i;

    encontrado = false;
    i=0;

    while(i<NIngredientes && !encontrado)
    {
        if(strcmp(Elementos[i].Nombre , pNombre)==0)
            encontrado=true;
        else
            i++;
    }

    if(!encontrado)
        i = -1;

    return i;
}

Ingrediente Receta::get_Ingrediente(int pPos)
{
    return Elementos[pPos];
}

int Receta::get_NIngredientes()
{
    return NIngredientes;
}

void Receta::get_DatosAdicionales(Cadena pNombre, int &pDificultad, int &pNPersonas)
{
    strcpy(pNombre , Titulo);
    pDificultad = Dificultad;
    pNPersonas = NPersonas;
}

void Receta::set_Ingrediente(int pPos, Ingrediente pIng)
{
    Elementos[pPos]=pIng;
}

bool Receta::eliminarIngrediente(Cadena pNombre)
{
    bool eliminado = false ;

    int pos = Buscar(pNombre);

    if(pos != -1)
    {
        for(int i=pos ; i<NIngredientes ; i++)
        {
            Elementos[pos] = Elementos[pos+1];
        }

        eliminado = true;

        NIngredientes--;
    }

    return eliminado;
}

bool Receta::anadirIngrediente(Ingrediente pIng)
{
    bool insertado = false;

    int pos = Buscar(pIng.Nombre);

    if(pos == -1)
    {
        set_Ingrediente(NIngredientes, pIng);

        NIngredientes++;

        insertado = true ;
    }

    return insertado;
}


int Menu()
{
    int opcion;
    do
    {
        cout << "1.- Actualizar Datos de la Receta\n"
             << "2.- Añadir Ingrediente\n"
             << "3.- Borrar Ingrediente\n"
             << "4.- Mostrar Receta (datos e ingredientes)\n"
             << "5.- Salir\n\n"
             << "Eligen opción: ";
        cin>>opcion;
        if (opcion<1 || opcion>5)
            cout <<" Error debes utilizar un valor entre 1 y 5\n";
    } while (opcion<1 || opcion>5);
    return opcion;
}

int main()
{
    Receta MiReceta;
    int Opcion;
    Cadena Nombre;
    int Dificultad;
    int NPersonas;
    Ingrediente Ing;



    do
    {
        system("cls");
        Opcion=Menu();
        switch(Opcion)
        {
            case 1: cout<<"Introduce el Nombre de la receta: ";
                    cin>>Nombre;
                    cout<<"Intruduce la dificultad: ";
                    cin>>Dificultad;
                    cout<<"Introduce el Número de Personas: ";
                    cin>>NPersonas;
                    MiReceta.ActualizarDatos(Nombre,Dificultad,NPersonas);
                    break;
            case 2: cout<<"Introduce el nombre del Ingrediente: ";
                    cin>>Ing.Nombre;
                    cout<<"Introduce nº de Gramos: ";
                    cin>>Ing.Gramos;
                    cout<<"Introduce la Cantidad: ";
                    cin>>Ing.Cantidad;
                    cout<<"Introduce nº de calorias: ";
                    cin>>Ing.Calorias;
                    if (MiReceta.anadirIngrediente(Ing))
                        cout <<"El Ingrediente "<<Ing.Nombre<<" ha sido añadido.\n";
                    else
                        cout << "El Ingrediente "<<Ing.Nombre<<" ya existe.\n";
                    break;
            case 3: cout<<"Intruduce el Nombre del ingrediente a eliminar: ";
                    cin>>Nombre;
                    if (MiReceta.eliminarIngrediente(Nombre))
                        cout<<"El ingrediente "<<Nombre<<" ha sido eliminado.\n";
                    else
                        cout<<"El ingrediente "<<Nombre<<" No se encuentra.\n";
                    break;
            case 4: MiReceta.get_DatosAdicionales(Nombre , Dificultad , NPersonas);

                    cout << "\nNombre: " << Nombre ;
                    cout << "\nDificultad: " << Dificultad;
                    cout << "\nComensales: " << NPersonas;
                    cout << "\nNumero de ingredientes: " << MiReceta.get_NIngredientes();

                    int cal=0 ;

                    for(int i=0 ; i<MiReceta.get_NIngredientes() ; i++)
                    {
                        cout << "\n\nINGREDIENTE " << i+1 << ":";
                        cout << "\nNombre: " << MiReceta.get_Ingrediente(i).Nombre;
                        cout << "\nGramos: " << MiReceta.get_Ingrediente(i).Gramos;
                        cout << "\nCantidad (Unidades): " << MiReceta.get_Ingrediente(i).Cantidad;
                        cout << "\nCalorias : " << MiReceta.get_Ingrediente(i).Calorias << " kcal";

                        cal = cal + MiReceta.get_Ingrediente(i).Calorias;
                    }

                    cout << "\n\nNumero total de calorias de la receta: " << cal << " kcal\n\n";

                    system("pause");

                    break;

        }
    } while (Opcion!=5);
    return 0;
}
