#include <iostream>
#include <math.h>

using namespace std;

int main()
{float nota ;

   cout << "Introduzca calificacion obtenida : " ;
   cin >> nota ;

   if (nota < 0)
    cout << " error en la nota" ;
   else
    if (nota>0 && nota<5 )
        cout << "SUSPENSO" ;
    else if (nota>5 && nota<7)
            cout << "Aprobado" ;
        else if (nota>7 && nota<9)
                cout << "Notable" ;
            else if (nota>=9 && nota<=10 )
                    cout << "Sobresaliente jeje" ;
                else if (nota > 10)
                        cout << "Error en la nota" ;



    return 0;
}
