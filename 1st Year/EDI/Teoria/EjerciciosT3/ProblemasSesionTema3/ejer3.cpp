pila CopiarPila(pila p){
  
  pila aux,copia;
  while (!p.esvacia()){
   aux.apilar(p.cima());
   p.desapilar();
  }
  while (!aux.esvacia()){
   copia.apilar(aux.cima());
   p.apilar(aux.cima()); //no necesario al ser p por valor, por si deseamos dejar p en el mismo estado inicial
   aux.desapilar();
  }
  return copia;
}
