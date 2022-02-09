dvoid numeranodos(Tnodo **L)
{
 int numero=1;
 Tnodo *aux=*L;
 Tnodo *anterior=NULL;
 while (aux!=NULL)//mientrs no llegue al final de la lista
  {
   Tnodo *nuevo=new Tnodo;
   if (nuevo!=NULL)
    {
        nuevo->sig=aux;
        itoa(numero,nuevo->dato,10);
     if (numero==1)
         *L=nuevo;
     else
         anterior->sig=nuevo;
     anterior=aux;
     aux=aux->sig;
    }
   numero++; 
  } 
}   
                        
      
