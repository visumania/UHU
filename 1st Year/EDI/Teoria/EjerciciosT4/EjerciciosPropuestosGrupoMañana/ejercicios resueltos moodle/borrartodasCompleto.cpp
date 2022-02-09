#ianclude <iostream>
using namespace std;

struct Tnodo
 {
  float dato;
  Tnodo *sig;};

void Borrartodas (Tnodo **L,float x)
 {
  Tnodo *aux=*L;
  Tnodo *primero=aux;
  Tnodo *anterior=NULL;
  Tnodo *borr;
  while (aux!=NULL)
   {
    if (aux->dato==x)
     {
      borr=aux;
      if (anterior==NULL)
        {

         primero=aux->sig;
        }
      else //ya hay nodos buenos que me he saltado y no borrado, debo hacer que el anterior apunte al siguiente
      //del que estoy y que voy a borrar
      {
       anterior->sig=aux->sig;

      }
      delete borr;
     }
    else
     {
      anterior=aux;

     }
    aux=aux->sig;
   }
  *L=primero;
}

int main()
 {
  Tnodo *elementos;

  Borrartodas (&elementos,3);
}

