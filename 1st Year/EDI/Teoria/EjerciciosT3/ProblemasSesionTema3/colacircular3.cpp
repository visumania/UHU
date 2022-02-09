cola::cola
{
 inicio=0;
 fin=-1;
}

void cola::encolar(int e)
 {
  if (longitud()!=MAX)   
   {
    fin++;
    if (fin==MAX)
     fin=0;
    //fin=(fin+1)%MAX;
    elementos[fin]=e;
   }
 }
 
int cola::longitud()
 {
  int l;                  
  if (fin==-1) l=0;
  if (inicio<=fin)
   l=fin-inicio+1;
  else
   l=MAX-inicio + fin + 1;
 }
 void cola::desencolar()
  {
   if (longitud()!=1)
    {   
     inicio++;
     if (inicio==MAX) inicio=0;
     //inicio=(inicio+1)%MAX;   
    }
   else
    {
     inicio=0;
     fin=-1;
    }
  }                               
  
int cola::primero()
 {
  return elementos[inicio];
 }
 
                      
bool cola::esvacia()
 {
  return (fin==-1);
 }
       
                       
               
