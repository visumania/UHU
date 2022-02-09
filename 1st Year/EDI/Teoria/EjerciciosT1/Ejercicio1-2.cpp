#include <iostream>
#include <conio.h>
using namespace std;
int main()
 {
  float **datos=new float*[100];
  char respuesta;
  float suma=0;
  int fila,col;
  for (int i=0;i<100;i++)
   {
    datos[i]=new float[100-i]; 
    for (int j=0;j<100-i;j++)
      datos[i][j]=0;
   }
  do
   {
    cout<<"Deme fila (1 a 100)\n";
    cin>>fila;
    cout<<"Deme columna (1 a "<<100-fila+1<<")\n";
    cin>>col;
    cout<<"Deme valor\n";
    cin>>datos[fila-1][col-1];
    cout<<"Desea continuar (S/N)\n";
    respuesta=toupper(getch());
   } while (respuesta!='N');                    
  
  for (int i=0;i<100;i++) //para las filas
   {
    for (int j=0;j<100-i;j++) //recorrido de las columnas
      suma+=datos[i][j]; //suma=suma + datos[i][j];
    delete []datos[i];
   }   
  delete []datos;
  cout<<"La suma vale "<<suma<<endl;
  system("pause");
  return 0;
} 
  
  
  
  
  
