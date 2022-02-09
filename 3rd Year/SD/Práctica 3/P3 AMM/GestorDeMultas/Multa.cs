using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GestorDeMultas
{
    public class Multa: MarshalByRefObject
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

        public Multa getMulta()
        {
            return this;
        }

        public string getMatricula()
        {
            return this.matricula;
        }

        public string getFecha()
        {
            return this.fecha;
        }

        public int getPuntosPerdidos()
        {
            return this.puntosPerdidos;
        }

        public void setMatricula(string mat)
        {
            this.matricula = mat;
        }

        public void setFecha(string fech)
        {
            this.fecha = fech;
        }

        public void setPuntosPerdidos(int p)
        {
            this.puntosPerdidos = p;
        }

        public void setMulta(Multa mul)
        {
            this.puntosPerdidos = mul.puntosPerdidos;
            this.matricula = mul.matricula;
            this.fecha = mul.fecha;
        }

        public override string ToString()
        {
            string s = "\nMatricula: " + getMatricula() + "\nFecha: " + getFecha() + "\nPuntos perdidos: " + getPuntosPerdidos() + "\n";

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
