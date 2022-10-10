/*
 *Definiciones de las Constantes para la pr�ctica 2
 */
#pragma once

 /* Constantes simb�licas para indicar el metodo de ordenacion*/
enum algoritmosOrdenacion { BURBUJA, INSERCION, SELECCION };
/* Constantes para indicar el Orden del metodo de ordenacion*/
enum ordenes { CUADRADO, NLOGN, N, LOGN, LOGLOGN };
/* Constantes para indicar el Numero de repeticiones para el caso medio de cada m�todo de b�squeda */
static const int NUMREPETICIONES = 100;
/* Constantes para indicar la variacion de las tallas del vector */
enum valoresTallas { tallaIni = 100, tallaFin = 1000, incTalla = 100 };
enum valoresTallasBusqueda {tallaInicial=1000, tallaFinal=10000, incrementaTalla=1000};

/* Constantes simb�licas para indicar el metodo de busqueda*/
enum algoritmosBusqueda{SECUENCIALIT, BINARIAIT, INTERPOLACIONIT};