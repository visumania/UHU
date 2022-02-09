﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ClienteCalculadora
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceReference1.SCalculadoraClient Calculadora=new ServiceReference1.SCalculadoraClient();
            int opcionMC = 0;
            int opcionMG = 0;
            string password = " ", matricula = " ", fecha = " ";
            int puntos = 0, dni = 0;

            do
            {
                Console.Clear();
                Console.WriteLine("Menú Consultas");
                Console.WriteLine("*************************\n");
                Console.WriteLine("1.- Identificación");
                Console.WriteLine("2.- Consultar Puntos");
                Console.WriteLine("3.- Consultar Multas");
                Console.WriteLine("4.- Salir");
                Console.WriteLine("\nElige opción: ");
                int.TryParse(Console.ReadLine(), out opcionMC);

                switch (opcionMC)
                {
                    case 1:
                        Console.WriteLine("\nIntroduzca contraseña de identificación: ");
                        password = Console.ReadLine();

                        if (Calculadora.Identificacion(password) == 1)
                        {
                            Console.WriteLine("\nEntrando en el Menú de Gestión");
                            Console.WriteLine("\nPulse enter para continuar");
                            Console.ReadKey();
                            do
                            {
                                Console.Clear();
                                Console.WriteLine("Menú Gestión");
                                Console.WriteLine("*************************\n");
                                Console.WriteLine("1.- Poner Multa");
                                Console.WriteLine("2.- Quitar Multa");
                                Console.WriteLine("3.- Alta de un Vehículo");
                                Console.WriteLine("4.- Baja de un Vehículo");
                                Console.WriteLine("5.- Salir");
                                Console.WriteLine("\nElige opción: ");
                                int.TryParse(Console.ReadLine(), out opcionMG);

                                switch (opcionMG)
                                {
                                    case 1:
                                        Console.WriteLine("\nIntroduzca matricula del coche a multar(1111AAA): ");
                                        matricula = Console.ReadLine();

                                        Console.WriteLine("Introduzca fecha de la multa(dd/mm/aaaa): ");
                                        fecha = Console.ReadLine();

                                        Console.WriteLine("Introduzca cantidad de puntos perdidos: ");
                                        int.TryParse(Console.ReadLine(), out puntos);

                                        if (Calculadora.PonerMulta(matricula, fecha, puntos) == 1)
                                            Console.WriteLine("\nMulta puesta correctamente");
                                        else
                                            Console.WriteLine("\nError: no se ha podido poner la multa");

                                        Console.WriteLine("\nPulse enter para continuar");
                                        Console.ReadKey();
                                        break;
                                    case 2:
                                        Console.WriteLine("\nIntroduzca matricula del coche a quitar la multa(1111AAA): ");
                                        matricula = Console.ReadLine();

                                        Console.WriteLine("Introduzca la fecha de la multa(dd/mm/aaaa): ");
                                        fecha = Console.ReadLine();

                                        if (Calculadora.QuitarMulta(matricula, fecha) == 1)
                                            Console.WriteLine("\nMulta quitada correctamente");
                                        else
                                            Console.WriteLine("\nError: no se ha podido quitar la multa");

                                        Console.WriteLine("\nPulse enter para continuar");
                                        Console.ReadKey();
                                        break;
                                    case 3:
                                        Console.WriteLine("\nIntroduzca DNI (solo numeros): ");
                                        int.TryParse(Console.ReadLine(), out dni);

                                        Console.WriteLine("Introduzca matricula del coche a registrar(1111AAA): ");
                                        matricula = Console.ReadLine();

                                        if (Calculadora.AltaVehiculo(dni, matricula) == 1)
                                            Console.WriteLine("\nVehiculo dado de alta correctamente");
                                        else
                                            Console.WriteLine("\nError: el vehiculo ya se encuentra registrado en el servidor");

                                        Console.WriteLine("\nPulse enter para continuar");
                                        Console.ReadKey();
                                        break;
                                    case 4:
                                        Console.WriteLine("\nIntroduzca DNI (solo numeros): ");
                                        int.TryParse(Console.ReadLine(), out dni);

                                        Console.WriteLine("Introduzca matricula del coche a dar de baja(1111AAA): ");
                                        matricula = Console.ReadLine();

                                        if (Calculadora.BajaVehiculo(dni, matricula) == 1)
                                            Console.WriteLine("\nVehiculo dado de baja correctamente");
                                        else
                                            Console.WriteLine("\nError: el vehiculo no se encuentra registrado en el servidor o tiene multas");

                                        Console.WriteLine("\nPulse enter para continuar");
                                        Console.ReadKey();
                                        break;
                                    case 5:
                                        Console.WriteLine("\nVolviendo al menú de consultas");
                                        Console.WriteLine("\nPulse enter para continuar");
                                        Console.ReadKey();
                                        break;
                                    default:
                                        Console.WriteLine("\nError, opción incorrecta");
                                        Console.WriteLine("\nPulse enter para continuar");
                                        Console.ReadKey();
                                        break;
                                }
                            } while (opcionMG != 5);
                        }
                        else
                        {
                            Console.WriteLine("\nPassword de identificación incorrecto");

                            Console.WriteLine("\nPulse enter para continuar");
                            Console.ReadKey();
                        }
                        break;
                    case 2:
                        Console.WriteLine("\nIntroduzca DNI de la persona a consultar los puntos (Solo numeros): ");
                        int.TryParse(Console.ReadLine(), out dni);

                        Console.WriteLine("Introduzca matricula del coche(1111AAA): ");
                        matricula = Console.ReadLine();

                        puntos = Calculadora.ComprobarPuntos(dni, matricula);

                        if (puntos != -1)
                            Console.WriteLine("\nEl usuario con DNI: " + dni + " y matricula " + matricula + " tiene " + puntos + " puntos");
                        else
                            Console.WriteLine("\nError: no se ha encontrado al usuario o no tiene registrado un coche con matricula " + matricula);

                        Console.WriteLine("\nPulse enter para continuar");
                        Console.ReadKey();
                        break;
                    case 3:
                        Console.WriteLine("\nIntroduzca DNI de la persona a consultarle las multas: ");
                        int.TryParse(Console.ReadLine(), out dni);

                        Console.WriteLine("Introduzca matricula del coche: ");
                        matricula = Console.ReadLine();

                       // LinkedList<Multa> m;// Calculadora.ComprobarMultas(dni, matricula);
                        // Calculadora.ComprobarMultas(dni, matricula);

                       // if (m.Count != 0)
                        //{
                        //    for (LinkedListNode<Multa> nodo = m.First; nodo != null; nodo = nodo.Next)
                        //        Console.WriteLine(nodo.Value.ToString());
                        //}
                        //else
                            Console.WriteLine("\nLa persona con DNI: " + dni + " y matricula: " + matricula + " no tiene multas ");

                        Console.WriteLine("\nPulse enter para continuar");
                        Console.ReadKey();
                        break;
                    case 4:
                        Console.WriteLine("\nSaliendo del programa ...");
                        Console.WriteLine("\nPulse enter para continuar");
                        Console.ReadKey();
                        break;
                    default:
                        Console.WriteLine("\nError, opción incorrecta\n\nPulse enter para continuar");
                        Console.ReadKey();
                        break;
                }
            } while (opcionMC != 4);
        }
       
    }

    public class Multa
    {
        private string matricula;
        private string fecha;
        private int puntosPerdidos;

        public Multa() //Constructor vacío para inicializar las variables
        {
            puntosPerdidos = 0;
            fecha = " ";
            matricula = " ";
        }

        public Multa(string m, string f, int p)
        {
            this.matricula = m;
            this.fecha = f;
            this.puntosPerdidos = p;
        }

        public Multa multa
        {
            get { return this; }
            set { this.puntosPerdidos = value.puntosPerdidos; this.matricula = value.matricula; this.fecha = value.fecha; }
        }

        public string Matricula
        {
            get { return matricula; }
            set { matricula = value; }
        }

        public string Fecha
        {
            get { return fecha; }
            set { fecha = value; }
        }

        public int PuntosPerdidos
        {
            get { return puntosPerdidos; }
            set { puntosPerdidos = value; }
        }

        public override string ToString()
        {
            string s = "\nMatricula: " + Matricula + "\nFecha: " + fecha + "\nPuntos perdidos: " + puntosPerdidos + "\n";

            return s;
        }

        public override bool Equals(object obj)
        {
            if (this == obj) return true;
            if (obj == null) return false;

            if (this.GetType() != obj.GetType())
                return false;

            Multa c = (Multa)obj;

            return (matricula.Equals(c.matricula) && fecha.Equals(c.fecha));
        }
    }
}
