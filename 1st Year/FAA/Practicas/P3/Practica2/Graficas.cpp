/*
 * Clase Graficas, contiene m�todos para guardar las gr�ficas de los resultados, es decir, crea
 * los ficheros por lo lotes (comandos) para generar los ficheros gr�ficos que corresponda.
 */
#include "Graficas.h"
#include "TestOrdenacion.h"
#include "Constantes.h"
#include <fstream>

 /*
  * M�todo generarGraficaMEDIO, genera el fichero de comandos para GNUPlot y dibuja la gr�fica
  * del caso medio de un m�todo de ordenaci�n y su ajuste a la funci�n correspondiente.
  * param metodo: metodo de ordenacion.
  * param orden: Orden del metodo de ordenacion.
  */
void Graficas::generarGraficaMEDIO(string nombre_metodo, int orden)
{
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
	ofstream f("CmdMedio.gpl");
    f << "\t#ESTE ES UN SCRIP DE GNUPLOT PARA ESTUDIO DE 1 METODO" << endl;
    f << "set title \"" << nombre_metodo << "\"" << endl;
    f << "set key top left vertical inside" << endl;
    f << "set grid" << endl;
    f << "set xlabel \"Talla (n)\"" << endl;
    f << "set ylabel \"Tiempo (ms)\"" << endl;
    if (orden == CUADRADO) {
        f << "Cuadrado(x) = a*x*x + b*x + c" << endl;
        f << "fit Cuadrado(x) \"" << nombre_metodo << +".dat" << "\" using 1:2 via a,b,c" << endl;
        f << "plot \"" << nombre_metodo << +".dat" << "\" using 1:2  title \"" << nombre_metodo << "\", Cuadrado(x)" << endl;
    }
    else if (orden == N)
    {
        f << "N(x) = a*x + b" << endl;
        f << "fit N(x) \"" << nombre_metodo << +".dat" << "\" using 1:2 via a,b" << endl;
        f << "plot \"" << nombre_metodo << +".dat" << "\" using 1:2  title \"" << nombre_metodo << "\", N(x)" << endl;
    }
    else if (orden == LOGLOGN)
    {
        f << "Logaritmo(x) = a*log(log(x))" << endl;
        f << "fit Logaritmo(x) \"" << nombre_metodo << +".dat" << "\" using 1:2 via a" << endl;
        f << "plot \"" << nombre_metodo << +".dat" << "\" using 1:2  title \"" << nombre_metodo << "\", Logaritmo(x)" << endl;
    }
    else if (orden == LOGN)
    {
        f << "Logaritmo(x) = a*log(x)" << endl;
        f << "fit Logaritmo(x) \"" << nombre_metodo << +".dat" << "\" using 1:2 via a" << endl;
        f << "plot \"" << nombre_metodo << +".dat" << "\" using 1:2  title \"" << nombre_metodo << "\", Logaritmo(x)" << endl;
    }
    f << "set terminal pdf" << endl;
    f << "set output\"" << nombre_metodo << ".pdf\"" << endl;
    f << "replot" << endl;
    f << "pause-1 \"Pulsa Enter para continuar...\"" << endl;
    f.close();
}

/*
 * M�todo generarGrafica, genera el fichero de comandos para GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer m�todo de ordenaci�n
 * param nombre2: es el nombre del fichero de datos del segundo m�todo de ordenaci�n
 */
void  Graficas::generarGrafica/*CMP*/(string nombre1, string nombre2)
{
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    ofstream f("CmdComparar.gpl");
    f << "\t#ESTE ES UN SCRIP DE GNUPLOT PARA ESTUDIO DE 2 METODOS" << endl;
    f << "set title \" Comparacion tiempos " << nombre1 << " y " << nombre2 << "\"" << endl;
    f << "set key top left vertical inside" << endl;
    f << "set grid" << endl;
    f << "set xlabel \"Talla (n)\"" << endl;
    f << "set ylabel \"Tiempo (ms)\"" << endl;
    f << "plot \"" << nombre1 <<".dat\" using 1:2 with lines title\"" << nombre1 << "\",\"" << nombre2 << ".dat\" using 1:2 with lines title\"" << nombre2 << "\"" << endl;
    f << "set terminal pdf" << endl;
    f << "set output \"" << nombre1 + nombre2 << ".pdf\"" << endl;
    f << "replot" << endl;
    f << "pause -1 \"Pulsa Enter para continuar...\"" << endl;
    f.close();
}

/*
 * Dibuja la gr�fica de todos los m�todos de ordenaci�n.
 */
void Graficas::generarGrafica(vector<string> nombreAlgoritmo)
{
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    
    ofstream f("CmdCompararTodos.gpl");
    f << "\t#ESTE ES UN SCRIP DE GNUPLOT PARA COMPARACION DE TODOS LOS METODOS" << endl;
    f << "set title \" Comparacion tiempos " << nombreAlgoritmo[0] << "-" << nombreAlgoritmo[1] << "-" << nombreAlgoritmo[2] << "\"" << endl;
    f << "set key top left vertical inside" << endl;
    f << "set grid" << endl;
    f << "set xlabel \"Talla (n)\"" << endl;
    f << "set ylabel \"Tiempo (ms)\"" << endl;
    f << "plot \"" << nombreAlgoritmo[0] << ".dat\" using 1:2 with lines title \"" << nombreAlgoritmo[0] << "\",\"" << nombreAlgoritmo[1] << ".dat\" using 1:2 with lines title \"" << nombreAlgoritmo[1] << "\",\"" << nombreAlgoritmo[2] << ".dat\" using 1:2 with lines title \"" << nombreAlgoritmo[2] << "\"" << endl;
    f << "set terminal pdf" << endl;
    f << "set output \"" << nombreAlgoritmo[0] + nombreAlgoritmo[1] + nombreAlgoritmo[2] << ".pdf\"" << endl;
    f << "replot" << endl;
    f << "pause -1 \"Pulsa Enter para continuar...\"" << endl;
    f.close();
}