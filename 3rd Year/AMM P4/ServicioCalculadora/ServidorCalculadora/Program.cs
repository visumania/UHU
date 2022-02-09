using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;

namespace ServidorCalculadora
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("****** Host del servicio Calculadora de WCF ***************");
            using (ServiceHost host = new ServiceHost(typeof(ServicioCalculadora2.SCalculadora)))
            {
                host.Open();
                Console.WriteLine("Servidor funcionando............");
                Console.WriteLine("Nombre: {0}", host.Description.ConfigurationName);
                Console.WriteLine("URI:    {0}", host.BaseAddresses[0].AbsoluteUri);
                Console.WriteLine("Puerto: {0}", host.BaseAddresses[0].Port);
                Console.WriteLine("Path {0}", host.BaseAddresses[0].LocalPath);
                Console.WriteLine("Protocolo: {0}", host.BaseAddresses[0].Scheme);
                Console.WriteLine("\nPulsa una tecla para cerrar el host");
                Console.ReadLine();
                host.Close();
            }

        }
    }
}
