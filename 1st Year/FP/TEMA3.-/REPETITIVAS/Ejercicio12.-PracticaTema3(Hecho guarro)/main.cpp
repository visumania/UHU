#include <iostream>
#include <windows.h>

using namespace std;

class Fibonacci
{
    int NoElementos;

public:
    void PedirNoElementos();
    bool ComprobarElemento();
    float MostrarElementos();
};

void Fibonacci::PedirNoElementos()
{
    do
    {
        cout << "Introduzca el numero de elementos de la secuencia de Fibonacci: " ;
        cin >> NoElementos ;

    }while(NoElementos<0);


}

float Fibonacci::MostrarElementos()
{
    int fibo = 0 ;
    int a = 0 ;
    int b = 1 ;

    for(int i=0 ; i<NoElementos ; i++)
    {
        if(i+1==1)
            cout << i+1 << " | 0" << "\n";
        else
        {
            fibo = a + b ;
            cout << i+1 << " | " << fibo << "\n";

            b=a ;
            a=fibo ;
        }
    }
}

bool Fibonacci::ComprobarElemento()
{
    system("pause");
    system("cls");

    int numero ;
    bool encontrado=false ;

    cout << "Introduzca un numero para comprobar si se encuentra en la sucesion de fibonacci(Solo los 16 primeros): ";
    cin >> numero ;

    if(numero==0)
        {
            encontrado=true ;
            cout << "Se ha encontrado en la posicion 1 ";
        }
    else
        {
           if (numero==1)
               {
                   encontrado=true;
                   cout << "Se ha encontrado en las posiciones 2 y 3";
               }
          else
               {
                    if (numero==2)
                        {
                            encontrado=true;
                            cout << "Se ha encontrado en la posicion 4";
                        }
                    else
                    {
                         if (numero==3)
                        {
                            encontrado=true;
                            cout << "Se ha encontrado en la posicion 5";
                        }
                         else
                         {
                            if (numero==5)
                                {
                                    encontrado=true;
                                    cout << "Se ha encontrado en la posicion 6";
                                }
                            else
                            {
                                 if (numero==8)
                                    {
                                        encontrado=true;
                                        cout << "Se ha encontrado en la posicion 7";
                                    }
                                 else
                                 {
                                      if (numero==13)
                                            {
                                                encontrado=true;
                                                cout << "Se ha encontrado en la posicion 8";
                                            }
                                      else
                                      {
                                           if (numero==21)
                                                {
                                                    encontrado=true;
                                                    cout << "Se ha encontrado en la posicion 9";
                                                }
                                           else
                                           {
                                                if (numero==34)
                                                    {
                                                        encontrado=true;
                                                        cout << "Se ha encontrado en la posicion 10";
                                                    }
                                                else
                                                {
                                                     if (numero==55)
                                                            {
                                                                encontrado=true;
                                                                cout << "Se ha encontrado en la posicion 11";
                                                            }
                                                     else
                                                     {
                                                          if (numero==89)
                                                                {
                                                                    encontrado=true;
                                                                    cout << "Se ha encontrado en la posicion 12";
                                                                }
                                                          else
                                                          {
                                                               if (numero==144)
                                                                    {
                                                                        encontrado=true;
                                                                        cout << "Se ha encontrado en la posicion 13";
                                                                    }
                                                                else
                                                                {
                                                                     if (numero==233)
                                                                            {
                                                                                encontrado=true;
                                                                                cout << "Se ha encontrado en la posicion 14";
                                                                            }
                                                                     else
                                                                     {
                                                                          if (numero==377)
                                                                                {
                                                                                    encontrado=true;
                                                                                    cout << "Se ha encontrado en la posicion 15";
                                                                                }
                                                                          else
                                                                          {
                                                                               if (numero==610)
                                                                                    {
                                                                                        encontrado=true;
                                                                                        cout << "Se ha encontrado en la posicion 16";
                                                                                    }
                                                                               else
                                                                                cout << "-1" ;
                                                                          }
                                                                     }
                                                                }

                                                          }
                                                     }
                                                }
                                           }
                                      }
                                 }
                            }
                         }
                    }
               }
        }



    return encontrado ;
}

int main()
{
    Fibonacci f ;

    f.PedirNoElementos();
    f.MostrarElementos();
    f.ComprobarElemento();

    return 0;
}
