using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;

namespace GestorDeMultas
{
    class Servidor
    {
        static void Main(string[] args)
        {
            ChannelServices.RegisterChannel(new TcpChannel(12345), false);
            Console.WriteLine("Registrando el servicio de Gestor de Multas en modo Singleton...");
            RemotingConfiguration.RegisterWellKnownServiceType(typeof(Gestor), "GestorDeMultas", WellKnownObjectMode.Singleton);

            //RemotingConfiguration.Configure("Servidor.exe.config", false);

            Console.WriteLine("Esperando llamadas remotas...");
            Console.WriteLine("Pulsa enter para salir...\n");
            Console.ReadLine();
        }
    }
}
