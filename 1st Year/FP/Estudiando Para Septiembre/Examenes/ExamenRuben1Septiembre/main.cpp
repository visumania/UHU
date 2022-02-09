#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

typedef char cad[30];

struct DatosPersonales
{
    cad name , lastName , email;
    int phone;
};

class Usuario
{
    char username[15];
    char password[30];
    char bio[50];
    bool reportado;
    DatosPersonales misDatos;

public:
    Usuario(char usr[15] , char pass[30]);
    Usuario(Usuario u);
    void Get_Username(char usr[15]);
    void Set_Username(char usr[15]);
    void Get_Password(char pass[15]);
    void Set_Password(char pass[15]);
    void Get_Bio(char bi[15]);
    void Set_Bio(char bi[15]);
    bool Get_Reported();
    void Set_Reportado(bool rpt);
    DatosPersonales Get_DatosPersonales();
    void Set_DatosPersonales(DatosPersonales dp);
};

Usuario::Usuario(char usr[15] , char pass[30])
{
    if(strcmp(usr , "")!=0){
        if(strcmp(pass , "")!=0)
        {
            strcpy(username , usr);
            strcpy(password ,pass);
            reportado=false;
        }
    }
}

Usuario::Usuario(Usuario u) {
    char usr[30];
    u.Get_Username(usr);
    strcpy(username, u);


}

void Usuario::Get_Username(char usr[15])
{
    strcpy(usr , username);
}

void Usuario::Set_Username(char usr[15])
{
    strcpy(username , usr);
}

void Usuario::Get_Password(char pass[15])
{
    strcpy(pass , password);
}

void Usuario::Set_Password(char pass[15])
{
    strcpy(password, pass);
}

void Usuario::Get_Bio(char bi[15])
{
    strcpy(bi , bio);
}

void Usuario::Set_Bio(char bi[15])
{
    strcpy(bio , bi);
}

bool Usuario::Get_Reported()
{
    return reportado;
}

void Usuario::Set_Reportado(bool rpt)
{
    reportado = rpt;
}

DatosPersonales Usuario::Get_DatosPersonales()
{
    return DatosPersonales;
}

void Usuario::Set_DatosPersonales(DatosPersonales dp)
{
    strcpy(misDatos.email , dp.email);
    strcpy(misDatos.lastName , dp.lastName);
    strcpy(misDatos.name , dp.name);
    misDatos.phone = dp.phone;
}

void MostrarUsuario(Usuario U)
{
    char pass[15];
    char usr[15];
    char bi[50];

   U.Get_Password(pass);
   cout << pass;

   U.Get_Username(usr);
   cout << usr;

   U.Get_Bio(bi);
   cout << bi;

   cout << U.Get_Reported();

   cout << U.Get_DatosPersonales().email;
   cout << U.Get_DatosPersonales().lastName;
   cout << U.Get_DatosPersonales().name;
   cout << U.Get_DatosPersonales().phone;
}

Usuario crearPerfil()
{

    char usr[15];
    char pass[15];
    char bio[50];

    DatosPersonales dp;

    cout << "\nUsuario: " ;
    cin >> usr;

    cout << "\nContrasenia: " ;
    cin >> pass;

    Usuario u(usr , pass);

    cout << "\nBiografia: ";
    cin >> bio;

    u.Set_Bio(bio);

    cout << "\nNombre: ";
    cin >> dp.name;

    cout << "\nApellidos: ";
    cin >> dp.lastName;

    cout << "\nEmail: " ;
    cin >> dp.email;

    cout << "\nNumero de telefono: " ;
    cin >> dp.phone;

    u.Set_DatosPersonales(dp);
}

class Instagram
{
    Usuario influencer;
    Usuario followers[50];
    int NFollowers;

public:
    Instagram(Usuario u);
    bool AddFollower(Usuario follower);
    bool RemoveFollower(Usuario follower);
    int SearchFollower(Usuario follower);
    void MostrarFollower(Usuario follower);
    void MostrarListaFollowers();
    int NumFollowers();
};

Instagram::Instagram(Usuario u)
{
    NFollowers = 0;
    //influencer = u;
    influencer(u);
}

bool Instagram::AddFollower(Usuario follower)
{
    bool aniadido = false;

    int pos;

    int i = SearchFollower(follower);

    if(NFollowers<50 && i==-1 && !influencer.Get_Reported())
    {
        pos = NFollowers;

        char pass[15];
        follower.Get_Password(pass);
        followers[pos].Set_Password(pass);

        char usr[15];
        follower.Get_Username(usr);
        followers[pos].Set_Username(usr);

        char bi[50];
        follower.Get_Bio(bi);
        followers[pos].Set_Bio(bi);

        followers[pos].Set_Reportado(follower.Get_Reported());

        followers[pos].Set_DatosPersonales(follower.Get_DatosPersonales());

        /*
        followers[pos] = follower;
        */

        aniadido = true;
    }

    return aniadido;
}

bool Instagram::RemoveFollower(Usuario follower)
{
    bool eliminado = false;
    if(NFollowers > 0){
        int i = SearchFollower(follower);
        if(i != -1)
        {
            for(int j=i ; j<NFollowers ; j++)
            {
                followers[j] = followers[j+1];
            }

            NFollowers--;
            eliminado = true;
        }

        if(NFollowers == 0) influencer.Set_Reportado(false);
    }

    return eliminado;
}

int Instagram::SearchFollower(Usuario follower)
{
    bool encontrado;
    int i;
    encontrado = false;
    i=0;

    while(i<NFollowers && !encontrado)
    {
            char usu[15];
            char usuaux[15];

            followers[i].Get_Username(usu);
            follower.Get_Username(usuaux);

            if(strcmp(usu , usuaux)==0)
                encontrado = true;
            else
                i++;
    }

    if(!encontrado)
        i = -1;

    return i;
}

void Instagram::MostrarFollower(Usuario follower)
{
    int i = SearchFollower(follower);

    if(i!=-1)
    {
        char usu[15];
        followers[i].Get_Username(usu);
        cout << "\nUsuario: " << usu;

        char bi[50];
        followers[i].Get_Bio(bi);
        cout << "\nBiografia: " << bi;

        char resultado[3];

        if(followers[i].Get_Reported()) resultado = "Si";
        else resultado = "No";
        cout << "\nReportado: " << resultado;


        cout << "\nNombre: " << followers[i].Get_DatosPersonales().name;
        cout << "\nApellidos: " << followers[i].Get_DatosPersonales().lastName;
        cout << "\nEmail: " << followers[i].Get_DatosPersonales().email;
        cout << "\nNumero de telefono: " << followers[i].Get_DatosPersonales().phone;
    }
    else
        cout << "\nNo se ha encontrado a ningun follower con ese nombre de usuario";
}

void Instagram::MostrarListaFollowers()
{
    MostrarFollower(influencer);

    cout << "\n\n";

    if(NFollowers != 0)
    {
        for(int i=0 ; i<NFollowers ; i++)
            {
                MostrarFollower(followers[i]);
                cout << "\n\n";
            }
    }

}

int Instagram::NumFollowers()
{
    return NFollowers;
}

int menuprincipal()
{

}

int submenu()
{

}

int main()
{

    Usuario u = crearPerfil();
    Instragram i(u);

}
