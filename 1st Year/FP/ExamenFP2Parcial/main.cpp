#include <iostream>
#include <cmath>
#include <cstring>

// Autor: Fran Beltr�n

using namespace std;

//-------------------- CLASE Punto ---------------------------------------
class Punto
{
    float x;     //Coordenada x
    float y;     //Coordenada y
public:
    Punto(); // Inicializa el punto a las coordenadas (0,0)
    void CambiarCoord (float cx, float cy); // (cx, cy) ser�n las nuevas coordenadas
    float CoordX (); // Devuelve la coordenada X
    float CoordY (); // Devuelve la coordenada Y
    int Cuadrante(); // Indica el Cuadrante en el que se encuentra el punto
};

Punto::Punto()  //Inicializa el punto a las coordenadas (0,0)
{
    x=0;
    y=0;
}

void Punto::CambiarCoord(float cx, float cy) //Establece como coordenadas del punto (cx,cy)
{
    x=cx;
    y=cy;
}

float Punto::CoordX()  //Devuelve la coordenada x del punto
{
    return x;
}

float Punto::CoordY()  //Devuelve la coordenada y del punto
{
    return y;
}

int Punto::Cuadrante() //Indica el cuadrante en el que se encuentra el punto.
{
    int c;

    if (x>=0 && y>=0)
        c=1;
    else if (x<0 && y>0)
        c=2;
    else if (x<0 && y<0)
        c=3;
    else
        c=4;

    return c;

}

// --------- CLASE Figura -----------------------------------------------------
class Figura
{
    Punto Puntos[3];  //Tri�ngulo. Coordenadas de los 3 v�rtices
    char Color[10];   //Color del tri�ngulo en min�scula
public:
    Figura(); // Estable el Color a "sin color"
    void Crear(); // Crea un triangulo solicitando al usuario coordenadas y color
    void Lados (float &L1, float &L2, float &L3); // Devuelve la longitud de los 3 lados del triangulo
    int Cuadrante(); // Devuelve el cuadrante en el que se encuentra totalmente englobada la figura
    void MostrarCoord(); // Muestra las coordenadas de los 3 vertices del triangulo
    void VerColor(char C[10]); // Devuelve el color de la figura
};

Figura::Figura()
{
    strcpy(Color, "sin color");
}

void Figura::Crear()
{
    float pX, pY;

    for(int i=0; i<3; i++)
    {
        cout << "Introduzca las coordenadas del Punto " << i+1 << " (X,Y): ";
        cin >> pX >> pY;
        Puntos[i].CambiarCoord(pX, pY);
    }

    cout << "Introduzca el Color: ";
    cin >> Color;
}

void Figura::Lados (float &L1, float &L2, float &L3) //Devuelve la longitud de los 3 lados del tri�ngulo
 {
    L1 = sqrt(pow(Puntos[0].CoordX()-Puntos[1].CoordX(),2) +
              pow(Puntos[0].CoordY()-Puntos[1].CoordY(),2));

    L2 = sqrt(pow(Puntos[1].CoordX()-Puntos[2].CoordX(),2) +
              pow(Puntos[1].CoordY()-Puntos[2].CoordY(),2));

    L3 = sqrt(pow(Puntos[2].CoordX()-Puntos[0].CoordX(),2) +
              pow(Puntos[2].CoordY()-Puntos[0].CoordY(),2));
}

int Figura::Cuadrante() //Devuelve el cuadrante en el que se encuentra totalmente englobado el tri�ngulo. Si ocupa m�s de un cuadrante devolver� 0
{
    int c;

    c = Puntos[0].Cuadrante();

    if (Puntos[1].Cuadrante() != c || Puntos[2].Cuadrante() != c)
        c=0;

    return c;
}

void Figura::MostrarCoord() //Muestra las coordenadas de los 3 v�rtices del tri�ngulo
{
    int i;

    for (i=0; i<3; i++)
      cout << "(" << Puntos[i].CoordX() << ", " << Puntos[i].CoordY() << ") ";
}

void Figura::VerColor(char C[10])  //Devuelve el color de la figura
{
  strcpy(C, Color);
}

// ------------- Funci�n gen�rica A IMPLEMENTAR POR EL ALUMNO, a la que se le pasa como par�metro
// ------------- de entrada una figura y devuelve su per�metro y su �rea.
void Funcion_generica(Figura pFigura, float &pPerimetro, float &pArea)
{
    float Lado1, Lado2, Lado3, SemiP;

    pFigura.Lados(Lado1, Lado2, Lado3); // Sacamos los valores de cada Lado
    pPerimetro = Lado1 + Lado2 + Lado3; // Calculamos el Per�metro
    SemiP = pPerimetro/2.0;

    pArea = sqrt(SemiP * (SemiP-Lado1) * (SemiP-Lado2) * (SemiP-Lado3));
}

//-------- Funci�n main() -----------------------------------------------------
int main()
{   // ---------- A REALIZAR POR EL ALUMNO --------------
    Figura Figuras[10];
    int Numero_Figuras, Cuadrante_busqueda;
    float Perimetro_figura, Area_figura;
    char Color_busqueda[10];

    do
    {
        cout << "Introduzca el numero de figuras que desea crear: " << endl;
        cin >> Numero_Figuras;
    }while(Numero_Figuras<0 || Numero_Figuras>10);

    for(int i=0; i<Numero_Figuras; i++)
    {
        cout << "\nFigura " << i+1 << " :" << endl;
        Figuras[i].Crear();
    }

    cout << "\nListado de Triangulos Rojos en el Primer Cuadrante: " << endl;

    for(int j=0; j<Numero_Figuras; j++)
    {
        Figuras[j].VerColor(Color_busqueda); // Conseguimos el color de esa Figura.
        Cuadrante_busqueda = Figuras[j].Cuadrante(); // Conseguimos el cuadrante que nos interesa.

        if((Cuadrante_busqueda == 1) && (strcmp(Color_busqueda, "rojo") == 0))
        {
            Funcion_generica(Figuras[j], Perimetro_figura, Area_figura);
            cout << "Triangulo ";
            Figuras[j].MostrarCoord();
            cout << "Area = " << Area_figura << " y Perimetro = " << Perimetro_figura << endl;
        }
    }

    return 0;
}
