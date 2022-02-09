#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) {
    this->setFecha(d, m, a); //el cogido es el mismo que el del metodo setFecha
}

void Fecha::setFecha(int d, int m, int a) {
/*
  if ((m == 1) || (m == 3) || (m == 5) ....
      dmax=31;
  else if ((m == 4) || (m == 6) || (m == 9) ....
      dmax=30;
  else if (m == 2)
      dmax=28;

  switch (m) {
    case 1:
    case 3:
    case 5:
       ...
            dmax=31;
            break;
    case 4:
    case 6:
    case 9:
       ...
            dmax=30;
            break;
    default:
            dmax=28;
            break;
  }
*/
//ES MAS RAPIDO Y COMODO USAR UN ARRAY QUE GUARDE LOS DIAS DE CADA MES...
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    this->anio=a; //VIP debo asignar año para al llamar a bisiesto() tengo el año bien
    if (this->bisiesto())
        diaMes[2]=29;

    if (m<1)  //si el mes es incorrecto
      m=1;
    else if (m>12) //si el mes es incorrecto
      m=12;
    this->mes=m;
    dmax=diaMes[m]; //una vez fijado el mes veo cuantos dias tiene ese mes como maximo

    if (d>dmax) //si d es superior al numero de dias de dicho mes
      d=dmax;
    else if (d<1) //si d es inferior a 1
      d=1;

    this->dia=d;
}

bool Fecha::bisiesto() const {
    if (this->anio%4==0) //esto no es exacto... corregidlo ustedes
        return true;
    else
        return false;
}

void Fecha::ver() const {
  if (this->dia < 10)
    cout << "0";
  cout << this->dia << "/";
  if (this->mes < 10)
    cout << "0";
  cout << this->mes << "/" << this->anio;
}

Fecha Fecha::operator++() {   //++f
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (this->bisiesto()) //si el año es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    dmax=diaMes[this->mes];
    this->dia++;
    if (this->dia>dmax) { //si al incrementar dia superamos el numero de dias de dicho mes
        this->dia=1;      //pasamos a 1
        this->mes++;      //del mes siguiente
        if (this->mes>12) { //si al incrementar mes pasamos de 12 meses
            this->mes=1;    //pasamos al mes 1
            this->anio++;   //del año siguiente
        }
    }
    return *this; //devolvemos el objeto fecha ya incrementado
}

//RESTO DE METODOS Y FUNCIONES A RELLENAR POR EL ALUMNO...

