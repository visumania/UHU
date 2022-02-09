#include <fstream>
using namespace std;
class Cola{
	int fin, inicio;
	fstream elementos;
    char nombre[10]; //nombre del fichero. Lo manejamos como atributo para eliminar el fichero al final (destructor)    
	public:
		Cola();
		~Cola();
		bool esvacia(){return fin==inicio;}
		int longitud(){return (fin-inicio);}
		int primero();
		void encolar(int e);
		void desencolar();
		
};


