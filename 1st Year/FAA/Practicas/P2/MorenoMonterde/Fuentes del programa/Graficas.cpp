/*
 * Clase Graficas, contiene métodos para guardar las gráficas de los resultados, es decir, crea
 * los ficheros por lo lotes (comandos) para generar los ficheros gráficos que corresponda.
 */
#include "Graficas.h"
#include "TestOrdenacion.h"
#include <fstream>

 /*
  * Método generarGraficaMEDIO, genera el fichero de comandos para GNUPlot y dibuja la gráfica
  * del caso medio de un método de ordenación y su ajuste a la función correspondiente.
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
    f << "Cuadrado(x) = a*x**2 +b*x + c" << endl;
    f << "fit Cuadrado(x) \"" << nombre_metodo << ".dat\" using 1:2 via a,b,c" << endl;
    f << "plot \"" << nombre_metodo << ".dat\" using 1:2 title \"" << nombre_metodo << "\", Cuadrado (x)" << endl;
    f << "set terminal pdf" << endl;
    f << "set output\"" << nombre_metodo << ".pdf\"" << endl;
    f << "replot" << endl;
    f << "pause-1 \"Pulsa Enter para continuar...\"" << endl;
    f.close();
}

/*
 * Método generarGrafica, genera el fichero de comandos para GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer método de ordenación
 * param nombre2: es el nombre del fichero de datos del segundo método de ordenación
 */
void  Graficas::generarGrafica/*CMP*/(string nombre1, string nombre2)
{
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    ofstream f("CmdComparar.gpl");
    f << "\t#ESTE ES UN SCRIP DE GNUPLOT PARA ESTUDIO DE 2 METODO" << endl;
    f << "set title \" Comparacion tiempos " << nombre1 << " y " << nombre2 << "\"" << endl;
    f << "set key top left vertical inside" << endl;
    f << "set grid" << endl;
    f << "set xlabel \"Talla (n)\"" << endl;
    f << "set ylabel \"Tiempo (ms)\"" << endl;
    f << "plot \"" << nombre1+nombre2 << ".dat\" using 1:2 with lines title \"" << nombre1 << "\",\"" << nombre1+nombre2 << ".dat\" using 1:3 with lines title \"" << nombre2 << "\"" << endl;
    f << "set terminal pdf" << endl;
    f << "set output \"" << nombre1 + nombre2 << ".pdf\"" << endl;
    f << "replot" << endl;
    f << "pause -1 \"Pulsa Enter para continuar...\"" << endl;
    f.close();
}

/*
 * Dibuja la gráfica de todos los métodos de ordenación.
 */
void Graficas::generarGrafica(vector<string> nombreAlgoritmo)
{
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    
    ofstream f("CmdCompararTodos.gpl");
    f << "\t#ESTE ES UN SCRIP DE GNUPLOT PARA ESTUDIO DE 2 METODO" << endl;
    f << "set title \" Comparacion tiempos " << nombreAlgoritmo[0] << ", " << nombreAlgoritmo[1] << " y " << nombreAlgoritmo[2] << "\"" << endl;
    f << "set key top left vertical inside" << endl;
    f << "set grid" << endl;
    f << "set xlabel \"Talla (n)\"" << endl;
    f << "set ylabel \"Tiempo (ms)\"" << endl;
    //f << "plot \"" << nombreAlgoritmo[0]+nombreAlgoritmo[1]+nombreAlgoritmo[2] << ".dat\" using 1:2 with lines title \"" << nombreAlgoritmo[0] << "\",\"" << nombreAlgoritmo[0]+nombreAlgoritmo[1]+nombreAlgoritmo[2] << ".dat\" using 1:3 with lines title \"" << nombreAlgoritmo[1] << "\",\"" << nombreAlgoritmo[0]+nombreAlgoritmo[1]+nombreAlgoritmo[2] << ".dat\" using 1:4 with lines title \"" << nombreAlgoritmo[2] << "\"" << endl;
    f << "plot \"" << "CompararTodos.dat\" using 1:2 with lines title \"" << nombreAlgoritmo[0] << "\",\"" << "CompararTodos.dat\" using 1:3 with lines title \"" << nombreAlgoritmo[1] << "\",\"" <<  "CompararTodos.dat\" using 1:4 with lines title \"" << nombreAlgoritmo[2] << "\"" << endl;
    f << "set terminal pdf" << endl;
    f << "set output \"" << nombreAlgoritmo[0] + nombreAlgoritmo[1] + nombreAlgoritmo[2] << ".pdf\"" << endl;
    f << "replot" << endl;
    f << "pause -1 \"Pulsa Enter para continuar...\"" << endl;
    f.close();
}