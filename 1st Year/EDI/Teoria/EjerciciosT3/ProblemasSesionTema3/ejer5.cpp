bool pilasiguales(pila p1,pila p2)
 {
  bool igualdad=true;
  if (p1.longitud()!=p2.longitud())
   iguales=false;
  else
   {
    while ((!p1.esvacia())&&(igualdad))
     {
      if (p1.cima()!=p2.cima())
       igualdad=false;
      else      
       {
        p1.desapilar();
        p2.desapilar();
       } 
     }
   }
  return igualdad;
}                                                   
                     
