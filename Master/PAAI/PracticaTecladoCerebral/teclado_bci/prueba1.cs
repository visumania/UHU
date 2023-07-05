using System;

using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.IO;
using System.IO.Ports;

//using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
//using System.Drawing;
using System.Linq;
//using System.Text;
//using System.Windows.Form;

using NeuroSky.ThinkGear;
using NeuroSky.ThinkGear.Algorithms;


namespace testprogram {
    class Program {
        
        static  int num1;
        public static int num2;
        
        public static void Main(string[] args) {

            //int num1;
            //int num2;
            MessageBox.Show("Esto es una prueba de C#");
            Console.ReadKey();
            Console.WriteLine("\nIntroducir el primer dato");
            num1=Int32.Parse(Console.ReadLine());

            Console.WriteLine("El primer dato es " + num1.ToString());
            Console.ReadKey();

        }
    }

}
