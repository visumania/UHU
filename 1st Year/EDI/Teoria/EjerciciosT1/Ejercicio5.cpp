#include <iostream>
#include <fstream>
using namespace std;
int main()
{
 char c;
 int num;
 
 ifstream in("datos1.txt", ios::binary); //apertura en modo binario y para lectura de datos1
 if (!in.fail())
 { //si no hay fallo
 	ofstream out("datos2.txt", ios::binary); //apertura binaria para escritura de datos2. Se situa al principio
 	in.seekg(0, ios::end);  //posicionamiento al final del fichero datos1 
 	num=in.tellg(); //obtenemos cuantos bytes tiene datos1
 	while(num!=0) //mientras haya "bytes" que recorrer
 	{   
 	in.seekg(sizeof(char)*(num-1),ios::beg); //nos situamos en el �ltimo byte (num-1), siguiente vuelta num vale uno menos..pen�ltimo, luego antepen�ltimo...
    in.read((char*)&c,sizeof(char)); //leeemos el byte (char) existente en la posici�n en cuesti�n
    out.write((char*)&c,sizeof(char)); //escribimos dicho byte (char) en el fichero datos2 
    num--; //ya queda un byte menos que recorrer
    }
	out.close(); //cerramos el fichero datos2
 }
 else
 {
 	cout<<"Error al abrir el fichero";
 	in.clear();
 }
 in.close();   //cierre de datos1

 system("pause");
 return 0;
}
