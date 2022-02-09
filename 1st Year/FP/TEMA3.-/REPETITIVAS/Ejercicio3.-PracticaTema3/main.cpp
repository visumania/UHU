#include <iostream>
#include <math.h>

using namespace std;

class Estadisitica
{
    int susp , apro , notab , sob ;

public :
    void elaborarEstadisitica();
    void resultado();
};

void Estadisitica::elaborarEstadisitica()
{
    int nalumnos ;
    float notas ;

    susp = 0 , apro = 0 , notab = 0 , sob = 0 ;

    cout << "Introduzca el numero de alumnos que se han examinado: " ;
    cin >> nalumnos ;



    for (int i=0 ; i < nalumnos ; i++)
        {
            cout << "Introduzca la nota del alumno " << i + 1 << ":"  ;
            cin >>  notas ;

            if (notas<0 || notas>10)
            {


                do
            {
                cout << "Introduzca la nota del alumno " << i + 1 << " de nuevo por favor: " ;
                cin >> notas ;

            }while ((notas < 0) || (notas > 10));
            }


            if ((notas >= 0) && (notas < 5))
                susp++ ;
            if ((notas >= 5) && (notas < 7))
                apro++ ;
            if ((notas >= 7) && (notas <9))
                notab++ ;
            if ((notas >= 9) && (notas < 10))
                sob++ ;
        }


    }



void Estadisitica::resultado()
{
    cout << "\n" << "\t" << susp << " SUSPENSOS" << endl ;
    cout << "\t" << apro << " APROBADOS" << endl ;
    cout << "\t" << notab << " NOTABLES" << endl ;
    cout << "\t" <<sob << "SOBRESALIENTES" << endl ;
}

int main ()
{
    Estadisitica est ;

    est.elaborarEstadisitica();
    est.resultado();

    return 0 ;
}
