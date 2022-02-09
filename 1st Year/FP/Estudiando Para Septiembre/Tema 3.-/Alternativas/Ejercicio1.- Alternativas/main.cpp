#include <iostream>

using namespace std;

int main()
{
    float nota ;

    cout << "Introduzca calificacion: " ;
    cin >> nota ;

    if (nota < 0)
        cout << "\nError en la nota";
    else
    {
        if(0<nota && nota<5)
            cout << "\nSuspenso";
        else
        {
            if(5<=nota && nota<7)
                cout << "\nAprobado";
            else
            {
                if(7<=nota && nota<9)
                    cout << "\nNotable";
                else
                {
                    if(9<=nota && nota<=10)
                        cout << "\nSobresaliente" ;
                    else
                    {
                        if(nota>10)
                            cout << "\nError en la nota" ;
                    }
                }
            }
        }
    }
}
