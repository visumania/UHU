/*
 * Clase Graficas, contiene m�todos para guardar las gr�ficas de los resultados, es decir, crea
 * los ficheros por lo lotes (comandos) para generar los ficheros gr�ficos que corresponda.
 */
#include "Graficas.h"
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
    ofstream f(nombre_metodo + ".gpl");
    f << "\t#ESTE ES UN SCRIP DE GNUPLOT PARA ESTUDIO DE 1 METODO" << endl;
    f << "set title \"" << nombre_metodo << "\"" << endl;
    f << "set key top left vertical inside" << endl;
    f << "set grid" << endl;
    f << "set xlabel \"Talla (n)\"" << endl;
    f << "set ylabel \"Tiempo (ms)\"" << endl;

    if (orden == 2)
    {
        f << "Cuadrado(x) = a*x**2 +b*x + c" << endl;
        f << "fit Cuadrado(x) \"" << nombre_metodo << ".dat\" using 1:2 via a,b,c" << endl;
        f << "plot \"" << nombre_metodo << ".dat\" using 1:2 title \"" << nombre_metodo << "\", Cuadrado (x)" << endl;
    }

    if (orden == 3)
    {
        f << "Logaritmica(x) = a*log(x) + b" << endl;
        f << "fit Logaritmica(x) \"" << nombre_metodo << ".dat\" using 1:2 via a,b" << endl;
        f << "plot \"" << nombre_metodo << ".dat\" using 1:2 title \"" << nombre_metodo << "\", Logaritmica (x)" << endl;
    }
    
    f << "set terminal pdf" << endl;
    f << "set output\"" << nombre_metodo << ".pdf\"" << endl;
    f << "replot" << endl;
    f << "pause-1 \"Pulsa Enter para continuar...\"" << endl;
    f.close();
}
