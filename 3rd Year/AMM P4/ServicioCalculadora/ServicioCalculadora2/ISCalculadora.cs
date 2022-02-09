using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace ServicioCalculadora2
{
    // NOTA: puede usar el comando "Rename" del menú "Refactorizar" para cambiar el nombre de interfaz "IService1" en el código y en el archivo de configuración a la vez.

    [ServiceContract]
    public interface ISCalculadora
    {
        [OperationContract]
        int ComprobarPuntos(int Dni, string Matricula);

        [OperationContract]
        LinkedList<Multa> ComprobarMultas(int Dni, string Matricula);

        [OperationContract]
        int Identificacion(string Password);

        [OperationContract]
        int PonerMulta(string Matricula, string Fecha, int Puntos);

        [OperationContract]
        int QuitarMulta(string Matricula, string Fecha);

        [OperationContract]
        int AltaVehiculo(int Dni, string Matricula);

        [OperationContract]
        int BajaVehiculo(int Dni, string Matricula);
    }

    //Clase adicional que contiene los datos necesarios para almacenar una multa
    [DataContract]
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

        [DataMember]
        public Multa multa
        {
            get { return this; }
            set { this.puntosPerdidos = value.puntosPerdidos; this.matricula = value.matricula; this.fecha = value.fecha; }
        }

        [DataMember]
        public string Matricula
        {
            get { return matricula; }
            set { matricula = value; }
        }

        [DataMember]
        public string Fecha
        {
            get { return fecha; }
            set { fecha = value; }
        }

        [DataMember]
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

    class Persona
    {
        private int dni;
        private List<string> matriculas;
        private LinkedList<Multa> multas;
        private int puntosTotales;

        public Persona(int d, string m)
        {
            this.dni = d;
            this.puntosTotales = 12; //suponemos que al registrar a un persona esta tiene su totalidad de puntos

            matriculas = new List<string>();
            matriculas.Add(m);

            multas = new LinkedList<Multa>();
        }

        public int getDni()
        {
            return this.dni;
        }

        public int getPuntosTotales()
        {
            return this.puntosTotales;
        }

        public List<string> getListaMatricula()
        {
            return this.matriculas;
        }

        public string getMatriculaVehiculo(int pos)
        {
            return matriculas[pos];
        }

        public LinkedList<Multa> getListaMultas()
        {
            return this.multas;
        }

        public void setPuntos(int p)
        {
            this.puntosTotales = p;
        }
    }
}

