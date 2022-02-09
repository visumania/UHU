//SOLUCION AL EJERCICIO 1 HACIENDO USO DE PUNTEROS AUXILIARES
#include <iostream>
#include <conio.h>
using namespace std;
int main()
 {
  char respuesta;
  float suma=0;
  int fila,col;
  float **Datos=new float*[100];
  if (Datos!=NULL)
  {
  	  float *Tabla;
	  for (int i=0;i<100;i++)
	   {
	    Datos[i]=new float[100-i];
	    Tabla=Datos[i];
	    for (int j=0;j<100-i;j++)
	      //Datos[i][j]=0.0;
	      Tabla[j]=0.0;
	   }
  }
  do
   {
    cout<<"Deme fila (1 a 100)\n";
    cin>>fila;
    Tabla=Datos[fila-1];
    cout<<"Deme columna (1 a "<<100-fila+1<<")\n";
    cin>>col;
    cout<<"Deme valor\n";
    cin>>Tabla[col-1];
    cout<<"Desea continuar (S/N)\n";
    respuesta=toupper(getch());
   } while (respuesta!='N');                    
  
  for (int i=0;i<100;i++) //para las filas
   {
   	Tabla=Datos[i];
    for (int j=0;j<100-i;j++) //recorrido de las columnas
      //suma+=Datos[i][j]; //suma=suma + datos[i][j];
      suma+=Tabla[j];
    //delete [] Datos[i];
    delete [] Tabla;
   }   
  delete [] Datos;
  Datos=NULL;
  cout<<"La suma vale "<<suma<<endl;
  system("pause");
  return 0;
} 
  
  
  
  
  
