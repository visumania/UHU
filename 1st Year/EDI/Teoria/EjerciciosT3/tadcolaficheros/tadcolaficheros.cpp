#include "tadcolaficheros.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

Cola::Cola(){
long int i;
//char nombre[10];
inicio=0;
fin=0;
do //estamos buscando el nombre de un fichero que no exista
 {
  i=rand();
  itoa(i,nombre,10);
  strcat(nombre,".dat");
  elementos.open(nombre,ios::binary|ios::in);
  if (elementos!=NULL) elementos.close();
 }
 while (elementos!=NULL);
 elementos.clear();
 //creamos el fichero
 elementos.open(nombre,ios::binary|ios::out);
 if (elementos.fail())
 {
  cout<<"Se ha producido error inesperado en creación de fichero\n";
 }
 else
 {
  elementos.close();
  elementos.open(nombre,ios::binary|ios::out|ios::in); 
  if (elementos.fail())
   { 
     cout<<"Se ha producido error inesperado en apertura de fichero\n";
   }
 }  
}


Cola::~Cola(){
	
	elementos.close();
	char comandoborrar[50];
	strcpy(comandoborrar,"Del ");
	strcat(comandoborrar,nombre);
	system(comandoborrar);
        // lo que ejecuta es system("del " + nombre); siendo el nombre el "nombre" del fichero de la cola 
}

int Cola::primero(){
	int devolver;
	elementos.seekg(inicio*sizeof(int), ios::beg);
	elementos.read((char*)&devolver, sizeof(int));
	return devolver;
}

void Cola::encolar(int e){
	
    elementos.seekp(0, ios::end);

	elementos.write((char*)&e, sizeof(int));
	if (elementos.fail())
	{
		cout<<"Error en escritura!";
	}
	else
	{
		fin++;
	}
}

void Cola::desencolar(){
	inicio++;
	
}

