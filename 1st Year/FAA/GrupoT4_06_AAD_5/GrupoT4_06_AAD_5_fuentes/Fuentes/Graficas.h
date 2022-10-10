/*
 * Clase Graficas, contiene m�todos para guardar las gr�ficas de los resultados, es decir, crea
 * los ficheros por lo lotes (comandos) para generar los ficheros gr�ficos que corresponda.
 */
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Graficas
{
public:
	/*
	 * M�todo generarGraficaMEDIO, genera el fichero de comandos para GNUPlot y dibuja la gr�fica
	 * del caso medio de un m�todo de ordenaci�n y su ajuste a la funci�n correspondiente.
	 * param metodo: metodo de ordenacion.
	 * param orden: Orden del metodo de ordenacion.
	 */
	void generarGraficaMEDIO(string metodo, int orden);
};

