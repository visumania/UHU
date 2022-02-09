using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace ServicioCalculadora2
{
    // NOTA: puede usar el comando "Rename" del menú "Refactorizar" para cambiar el nombre de clase "Service1" en el código y en el archivo de configuración a la vez.
    [ServiceBehavior(ConcurrencyMode = ConcurrencyMode.Single, InstanceContextMode = InstanceContextMode.Single)]
    public class SCalculadora : ISCalculadora
    {
        private List<Persona> listaPersonas;

        public SCalculadora()
        {
            listaPersonas = new List<Persona>();
        }

        public int ComprobarPuntos(int Dni, String Matricula)
        {
            int puntos = -1;
            int i = 0;
            bool encontradoPersona = false;

            while (i < listaPersonas.Count && !encontradoPersona) //Busqueda por la lista de personas
            {
                if (listaPersonas[i].getDni() == Dni) //Si coincide el dni de una persona con el que me pasan por parámetro
                {
                    encontradoPersona = true;
                    int j = 0;
                    bool encontradoVehiculo = false;

                    while (j < listaPersonas[i].getListaMatricula().Count && !encontradoVehiculo) // Busqueda por los diferentes vehiculos que puede tener esa persona
                    {
                        if (listaPersonas[i].getMatriculaVehiculo(j) == Matricula)
                        {
                            encontradoVehiculo = true;
                            puntos = listaPersonas[i].getPuntosTotales();
                        }
                        else
                            j++;
                    }
                }
                else
                    i++;
            }

            Console.WriteLine("SERVIDOR ha hecho: Comprobar Puntos--> " + puntos);

            return puntos;
        }
        public LinkedList<Multa> ComprobarMultas(int Dni, string Matricula)
        {
            LinkedList<Multa> mu = new LinkedList<Multa>();
            Multa[] m;
            //bool encontradaMatricula = false;
            bool encontradoDni = false;
            int i = 0;
            int j = 0;

            while (i < listaPersonas.Count && !encontradoDni)
            {
                if (listaPersonas[i].getDni() == Dni)
                {
                    encontradoDni = true;
                    m = new Multa[listaPersonas[i].getListaMultas().Count];
                    listaPersonas[i].getListaMultas().CopyTo(m, 0);

                    for (int k = 0; k < m.Length; k++)
                    {
                        if (m[k].Matricula == Matricula)
                            mu.AddLast(m[k]);
                    }

                    //for (int k = 0; k < m.Length; k++)
                    //{
                    //    if (m[k].getMatricula() == Matricula)
                    //        Console.WriteLine(m[k].ToString());
                    //}


                    //while (j < listaPersonas[i].getListaMatricula().Count && !encontradaMatricula)
                    //{
                    //    if (listaPersonas[i].getListaMatricula()[j] == Matricula)
                    //    {
                    //        encontradaMatricula = true;
                    //        mu.AddLast(m.)
                    //    }
                    //    else
                    //        j++;
                    //}
                }
                else
                    i++;
            }

            Console.WriteLine("SERVIDOR ha hecho: Comprobar Multas ");

            return mu;
        }
        public int Identificacion(String Password)
        {
            int devolver = 0;

            if (Password.Equals("541293AGP"))
                devolver = 1;

            Console.WriteLine("SERVIDOR ha hecho: Identificacion (" + devolver + ")");

            return devolver;
        }
        public int PonerMulta(String Matricula, String Fecha, int Puntos)
        {
            int devolver = 0;
            int i = 0;
            bool encontradaMatricula = false;

            while (i < listaPersonas.Count && !encontradaMatricula) //Busqueda por el listado de las personas
            {
                int j = 0;

                while (j < listaPersonas[i].getListaMatricula().Count && !encontradaMatricula) // En cada persona hacemos un recorrido por su lista de matriculas (para ver si tiene el coche dado de alta)
                {
                    if (listaPersonas[i].getListaMatricula()[j] == Matricula)
                        encontradaMatricula = true;
                    else
                        j++;
                }

                if (!encontradaMatricula) // Si en la iteración que hemos hecho no la hemos encontrado, pues seguimos buscando mientras cumplamos la condicion del bucle
                    i++;
            }

            if (encontradaMatricula)  // En caso de que hayamos encontrado la matricula haciendo la busqueda anterior (while's)
            {
                devolver = 1;
                Multa m = new Multa(Matricula, Fecha, Puntos);
                listaPersonas[i].getListaMultas().AddLast(m);
                listaPersonas[i].setPuntos(listaPersonas[i].getPuntosTotales() - Puntos);
            }

            Console.WriteLine("SERVIDOR ha hecho: Poner Multa (" + devolver + ")");

            return devolver;
        }
        public int QuitarMulta(String Matricula, String Fecha)
        {
            int devolver = 0;
            int i = 0;
            int j = 0;
            bool encontradaMatriculayFecha = false;
            Multa mPar = new Multa(Matricula, Fecha, 0);
            Multa[] m;

            while (i < listaPersonas.Count && !encontradaMatriculayFecha) //Busqueda por la lista de personas
            {
                j = 0;

                m = new Multa[listaPersonas[i].getListaMultas().Count];
                listaPersonas[i].getListaMultas().CopyTo(m, 0);

                while (j < listaPersonas[i].getListaMultas().Count && !encontradaMatriculayFecha)
                {
                    if (m[j].Equals(mPar))
                    {
                        encontradaMatriculayFecha = true;
                        devolver = 1;
                        listaPersonas[i].setPuntos(listaPersonas[i].getPuntosTotales() + m[j].PuntosPerdidos);
                        listaPersonas[i].getListaMultas().Remove(m[j]);
                    }
                    else
                        j++;
                }

                if (!encontradaMatriculayFecha)
                    i++;
            }

            Console.WriteLine("SERVIDOR ha hecho: Quitar Multa (" + devolver + ")");

            return devolver;
        }
        public int AltaVehiculo(int Dni, String Matricula)
        {
            int devolver = 0;
            int i = 0;
            bool encontradoPersona = false;
            bool encontradaMatricula = false;

            while (i < listaPersonas.Count && !encontradoPersona) // Búsqueda por la lista de personas
            {
                if (listaPersonas[i].getDni() == Dni) //En caso de encojtrar una persona con dni = al que nos pasan por parámetro
                {
                    encontradoPersona = true;
                    int j = 0;

                    while (j < listaPersonas[i].getListaMatricula().Count && !encontradaMatricula)
                    {
                        if (Matricula == listaPersonas[i].getMatriculaVehiculo(j))
                            encontradaMatricula = true;
                        else
                            j++;
                    }
                }
                else
                    i++;
            }

            if (!encontradoPersona && !encontradaMatricula)
            {
                Persona p = new Persona(Dni, Matricula);
                listaPersonas.Add(p);
                devolver = 1;
            }

            if (encontradoPersona && !encontradaMatricula)
            {
                listaPersonas[i].getListaMatricula().Add(Matricula);
                devolver = 1;
            }

            Console.WriteLine("SERVIDOR ha hecho: Alta Vehiculo (" + devolver + ")");

            return devolver;
        }
        public int BajaVehiculo(int Dni, String Matricula)
        {
            int devolver = 0;
            int i = 0;
            bool encontradaPersona = false;
            bool encontradaMatricula = false;

            while (i < listaPersonas.Count && !encontradaPersona) //Busqueda por la lista de personas
            {
                if (listaPersonas[i].getDni() == Dni)
                {
                    encontradaPersona = true;
                    int j = 0;

                    while (j < listaPersonas[i].getListaMatricula().Count && !encontradaMatricula) // Busqueda por la lista de matriculas
                    {
                        if (listaPersonas[i].getMatriculaVehiculo(j) == Matricula) // En caso de que la encontremos 
                        {
                            encontradaMatricula = true;

                            if (ComprobarMultas(Dni, Matricula).Count == 0)
                            {
                                listaPersonas[i].getListaMatricula().RemoveAt(j);
                                devolver = 1;
                            }

                            //if (listaPersonas[i].getListaMultas().Contains(new Multa(Dni,Matricula))) // si hemos encontrado la matricula y el dni, para quitarla solo queda que no tenga multas
                            //{
                            //    listaPersonas[i].getListaMatricula().RemoveAt(j);
                            //    devolver = 1;
                            //}
                        }
                        else
                            j++;
                    }
                }
                else
                    i++;
            }

            Console.WriteLine("SERVIDOR ha hecho: Baja Vehiculo (" + devolver + ")");

            return devolver;
        }
    }
}
