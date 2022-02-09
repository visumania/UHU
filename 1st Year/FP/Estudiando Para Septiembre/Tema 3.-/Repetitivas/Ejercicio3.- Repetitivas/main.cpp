#include <iostream>

using namespace std;

class Estadistica
{
    int susp , apr , notab , sob ;

public:
    void elaborarEstadistica();
    void resultado();
};

void Estadistica::elaborarEstadistica()
{
    int numeroalumnos ;
    float alumnon;

    susp = apr = notab = sob = 0;

    cout << "Introduzca numero de alumnos que se han examinado: ";
    cin >> numeroalumnos ;

    for(int i=0 ; i<numeroalumnos ; i++)
    {
        do
        {
            cout << "Introduzca nota del alumno " << i+1 << ": " ;
            cin >> alumnon;

        }while(alumnon<0 || alumnon>10);

        if(alumnon<5 && alumnon>0)
            {
                susp = susp + 1;
            }
            else
            {
                if(alumnon<7 && alumnon>=5)
                {
                    apr++;
                }
                else
                {
                    if(alumnon<9 && alumnon>=7)
                    {
                        notab++;
                    }
                    else
                    {
                        if(alumnon<=10 && alumnon>=9)
                        {
                            sob++;
                        }
                    }
                }
            }
    }
}

void Estadistica::resultado()
{
    cout << "\nNumero de suspensos: " << susp << "\n";
    cout << "Numero de aprobados: " << apr << "\n";
    cout << "Numero de notables: " << notab << "\n";
    cout << "Numero de sobresalientes: " << sob << "\n";

}

int main()
{
    Estadistica est;

    est.elaborarEstadistica();
    est.resultado();

    return 0;
}
