

bool lista::operator==(lista l)
 {
     bool igualdad=true;
     int i;
     int j=longitud();
     if(j!=l.longitud())
      {
       igualdad=false;
      }
     else
      {
       i=1;                                
       while ((i<=j)&&(igualdad))
        {
         if (observar(i)!=l.observar(i))
          igualdad=false
         else
          i++;
        }
      }          
      return igualdad;
 }

