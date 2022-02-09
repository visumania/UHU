#include "Peluqueria.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include "peluqueria.h"

using namespace std;


void printn(char c, int n);

void peluqueria::AbrirPeluqueria(char *nombrefichero)
{
    ifstream fichero(nombrefichero, ios::binary); //porque solamente vamos a leer del fichero

    if(fichero)
    {
        L.vaciar(); //Vaciamos porque puede ser que previamente tenga elementos (peluqueros)

        int nPelu, nCli;
        peluquerof peluF;
        peluquero pelu;
        cliente cli;

        fichero.read((char *) &nPelu, sizeof(int)); //Leemos el primer numero que se corresponde al numero de peluqueros que hay

        for(int i = 0; i < nPelu; i++)
        {
            fichero.read((char *) &peluF, sizeof(peluF)); //Leemos un peluquero

            strcpy(pelu.Nombre,peluF.Nombre);
            strcpy(pelu.Apellidos,peluF.Apellidos);
            pelu.Codigo = peluF.Codigo;
            pelu.TipoServicio = peluF.TipoServicio;

            L.insertar(i+1, pelu);
        }

        fichero.read((char *) &nCli, sizeof(int)); //Leemos un numero que se corresponde al numero de clientes que hay

        for(int i = 0; i < nCli; i++)
        {
            fichero.read((char *) &cli, sizeof(cli));
            IncorporarCliente(cli);
        }

        cout << "\tFichero cargado correctamente." << endl;
    }
    else
        cout << "\tNo se pudo abrir el fichero." << endl;

    fichero.close();
}

void peluqueria::VolcarPeluqueria(char *nombrefichero)
{
    ofstream fichero(nombrefichero, ios::binary); //porque solo vamos a escribir en el fichero

    if(fichero)
    {
        int nCli = 0, nPelu = L.longitud();
        peluquerof peluF;
        peluquero *pelu;
        cliente cli;
        cola aux;

        fichero.write((char *) &nPelu, sizeof(int));

        for(int i = 0; i < nPelu; i++)
        {
            fichero.seekp(sizeof(int) + sizeof(peluquerof)*i, ios::beg); //Posicionarnos donde nos corresponde + tamaño de un entero

            pelu = &L.observar(i+1);
            strcpy(peluF.Nombre,pelu->Nombre);
            strcpy(peluF.Apellidos,pelu->Apellidos);
            peluF.Codigo = pelu->Codigo;
            peluF.TipoServicio = pelu->TipoServicio;

            fichero.write((char *) &peluF, sizeof(peluquerof));

            aux.clonar(pelu->Col);

            while(!aux.esvacia())
            {
                cli = aux.primero();

                fichero.seekp(sizeof(int) + sizeof(peluquerof)*nPelu + sizeof(int) + sizeof(cliente)*nCli, ios::beg);
                fichero.write((char *) &cli, sizeof(cliente));

                aux.desencolar();
                nCli++;
            }
        }

        fichero.seekp(sizeof(int) + sizeof(peluquerof)*L.longitud(), ios::beg);
        fichero.write((char *) &nCli, sizeof(int));

        cout << "\tFichero guardado correctamente." << endl;
    }
    else
        cout << "\tNo se pudo guardar el fichero." << endl;

    fichero.close();
}

void peluqueria::Mostrar()
{
    peluquero auxP;

    for(int i=1 ; i<=L.longitud() ; i++)
    {
        copiarpeluquero(auxP , L.observar(i));

        cout << "\nPeluquero " << auxP.Codigo << ": " << auxP.Apellidos << ", " << auxP.Nombre << " -Tipo de Servicio: " << auxP.TipoServicio << endl;
        cout << "Clientes: " << endl;
        cout << "\tApellidos\t\tNombre\t\tEdad\t\tTipo de Servicio\t\tHora de llegada" << endl;
        cout << "\t.........\t\t......\t\t....\t\t................\t\t..............." << endl;

        while(!auxP.Col.esvacia())
        {
            cout << "\t" << auxP.Col.primero().Apellidos << "\t\t" << auxP.Col.primero().Nombre << "\t\t"
            << auxP.Col.primero().Edad << "\t\t\t" <<  auxP.Col.primero().TipoServicio << "\t\t\t\t"
            << auxP.Col.primero().HoraLlegada << endl;
            auxP.Col.desencolar();
        }
    }
}

void peluqueria::IncorporarPeluquero(peluquerof t)
{
    peluquero pelu;
    int pos = posicionCorrecta(t.Codigo);
    int nCli = 0;
    int nPeluCompatibles = 0;
    int nPelu = L.longitud();
    peluquero *pNuevo = &L.observar(pos);
    peluquero *pMayor;

    pelu.Codigo = t.Codigo;
    pelu.TipoServicio = t.TipoServicio;
    strcpy(pelu.Nombre, t.Nombre);
    strcpy(pelu.Apellidos, t.Apellidos);

    L.insertar(pos, pelu);

    //Ahora hay que calcular el numero de clientes que quieran un tipo de servicio igual al peluquero que acabamos de incorporar

    for(int i = 1; i <= nPelu; i++)
    {
        if(L.observar(i).TipoServicio == t.TipoServicio)
        {
            nCli += L.observar(i).Col.longitud();
            nPeluCompatibles++;
        }
    }
    nCli /= nPeluCompatibles; // Cuanto le toca a cada uno


    while(pNuevo->Col.longitud() < nCli)
    {
        pMayor = &L.observar(peluMaxClientes(t.TipoServicio, t.Codigo));   //pMayor almacena al peluquero con mas clientes
        pNuevo->Col.encolar(pMayor->Col.primero());   //Mover el cliente
        pMayor->Col.desencolar();
    }
}

bool peluqueria::RetirarPeluquero(int codigo)
{
    int pos = buscarPorCodigo(codigo);
    bool retirado = false;

    if(pos != -1)//Primero tenemos que comprobar si el peluquero se encuentra en la lista
    {
        peluquero *pRetirar = &L.observar(pos);
        int i = 1, nPelu = L.longitud();

        while(i <= nPelu && !(L.observar(i).Codigo != codigo && L.observar(i).TipoServicio == pRetirar->TipoServicio))
            i++;

        if(i <= nPelu || pRetirar->Col.esvacia())
        {
            while(!pRetirar->Col.esvacia()) //Repartirmos la cola del peluquero a retirar entre la de los peluqueros que haya activos
            {
                L.observar(peluMinClientes(pRetirar->TipoServicio, codigo)).Col.encolar(pRetirar->Col.primero());
                pRetirar->Col.desencolar();
            }

            L.eliminar(pos);
            retirado=true;
        }
    }

    return retirado;
}

bool peluqueria::IncorporarCliente(cliente cli)
{
    bool incorporado = false;

    int pSeleccionado = peluMinClientes(cli.TipoServicio, -1);//Hallamos la posicion del peluquero con menor cola de clientes

    if(pSeleccionado != -1)
    {
        L.observar(pSeleccionado).Col.encolar(cli);
        incorporado=true;
    }

    return incorporado;
}

bool peluqueria::EliminarCliente(cadena Nombre, cadena Apelllidos)
{
    int nPelu = L.longitud();
    peluquero *pelu;
    cola aux;
    bool eliminado = false;
    int i = 1;

    while(i <= nPelu && !eliminado)
    {
        aux.vaciar();
        pelu = &L.observar(i);

        while(!pelu->Col.esvacia())
        {
            if(!eliminado && strcmp(pelu->Col.primero().Nombre, Nombre) == 0 && strcmp(pelu->Col.primero().Apellidos, Apelllidos) == 0)
                eliminado = true; //Si coincide, no lo copio
            else
                aux.encolar(pelu->Col.primero());

            pelu->Col.desencolar();
        }
        //Restauro la cola, sin el eliminado
        pelu->Col.clonar(aux);
        i++;
    }

    return eliminado;
}

bool peluqueria::AtenderCliente(int CodigoPeluquero)
{
    bool atendido = false;
    int pos = buscarPorCodigo(CodigoPeluquero);

    if(pos != -1)
    {
        peluquero *pelu = &L.observar(pos);
        if(!pelu->Col.esvacia())
        {
            pelu->Col.desencolar();

            atendido=true;
        }
    }

    return atendido;
}


int peluqueria::buscarPorCodigo(int Codigo)
{
    int nCli = L.longitud(), iPeluquero = -1;
    int i = 1;

    while(i <= nCli && iPeluquero == -1)
    {
        if(L.observar(i).Codigo == Codigo)
            iPeluquero = i;
        i++;
    }

    return iPeluquero; //Devolvemos la posicion donde se encuentra un peluquero o -1 si no lo encuentra (en base al codigo)
}

int peluqueria::posicionCorrecta(int Codigo)
{
    if(L.esvacia())
        return 1;

    int nPelu = L.longitud();
    int i = 1, iNuevo = -1;

    while(iNuevo == -1)//forma de saber que todavia no ha sido insertado
    {
        if(L.observar(i).Codigo > Codigo)
        {
            iNuevo = i;
        }
        else
            if(i == nPelu)
                iNuevo = i+1;
            else
                i++;
    }

    return iNuevo;
}

int peluqueria::peluMaxClientes(int Servicio, int codigoIgnorar)
{
    int i = 1, nPelu = L.longitud(), iMayor = -1;

    while(i <= nPelu)
    {
        if(L.observar(i).Codigo != codigoIgnorar && L.observar(i).TipoServicio == Servicio &&
           (iMayor == -1 || L.observar(i).Col.longitud() > L.observar(iMayor).Col.longitud()))
            iMayor = i;

        i++;
    }

    return iMayor;
}

int peluqueria::peluMinClientes(int Servicio, int codigoIgnorar)
{
    int i = 1, nPelu = L.longitud(), iMenor = -1;

    while(i <= nPelu)
    {
        if(L.observar(i).Codigo != codigoIgnorar && L.observar(i).TipoServicio == Servicio &&
           (iMenor == -1 || L.observar(i).Col.longitud() < L.observar(iMenor).Col.longitud()))
            iMenor = i;

        i++;
    }

    return iMenor;
}
