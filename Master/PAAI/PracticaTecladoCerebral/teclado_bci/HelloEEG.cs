using System;

using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.IO;
using System.IO.Ports;

using NeuroSky.ThinkGear;
using NeuroSky.ThinkGear.Algorithms;


namespace testprogram {
    class Program {
        static Connector connector;
        static byte poorSig;
        static byte valor;
        static int j;
        static int passwd;
        static int[] passwd_final = new int[4];

        public static void Main(string[] args) {

            Console.WriteLine("HelloEEG!");

            // Initialize a new Connector and add event handlers

            connector = new Connector();
            connector.DeviceConnected += new EventHandler(OnDeviceConnected);
            connector.DeviceConnectFail += new EventHandler(OnDeviceFail);
            connector.DeviceValidating += new EventHandler(OnDeviceValidating);

            // Scan for devices across COM ports
            // The COM port named will be the first COM port that is checked.
            connector.ConnectScan("COM40");

            // Blink detection needs to be manually turned on
            connector.setBlinkDetectionEnabled(true);
            Thread.Sleep(450000);




            System.Console.WriteLine("Goodbye.");
            connector.Close();
            Environment.Exit(0);
        }


        // Called when a device is connected 

        static void OnDeviceConnected(object sender, EventArgs e) {

            Connector.DeviceEventArgs de = (Connector.DeviceEventArgs)e;

            Console.WriteLine("Device found on: " + de.Device.PortName);
            de.Device.DataReceived += new EventHandler(OnDataReceived);

        }




        // Called when scanning fails

        static void OnDeviceFail(object sender, EventArgs e) {

            Console.WriteLine("No devices found! :(");

        }



        // Called when each port is being validated

        static void OnDeviceValidating(object sender, EventArgs e) {

            Console.WriteLine("Validating: ");

        }

        // Called when data is received from a device

        static void OnDataReceived(object sender, EventArgs e) {

            //Device d = (Device)sender;

            Device.DataEventArgs de = (Device.DataEventArgs)e;
            DataRow[] tempDataRowArray = de.DataRowArray;

            TGParser tgParser = new TGParser();
            tgParser.Read(de.DataRowArray);



            /* Loops through the newly parsed data of the connected headset*/
            // The comments below indicate and can be used to print out the different data outputs. 
            
            for (int i = 0; i < tgParser.ParsedData.Length; i++){
                
                if (tgParser.ParsedData[i].ContainsKey("Raw")){

                    //Console.WriteLine("Raw Value:" + tgParser.ParsedData[i]["Raw"]);

                }

                if (tgParser.ParsedData[i].ContainsKey("PoorSignal")){

                    //The following line prints the Time associated with the parsed data
                    //Console.WriteLine("Time:" + tgParser.ParsedData[i]["Time"]);
                    
                    //A Poor Signal value of 0 indicates that your headset is fitting properly
                    //Console.WriteLine("Poor Signal:" + tgParser.ParsedData[i]["PoorSignal"]);

                    poorSig = (byte)tgParser.ParsedData[i]["PoorSignal"];
                }


                if (tgParser.ParsedData[i].ContainsKey("Meditation")) {

                    
                    //Console.WriteLine("Att Value:" + tgParser.ParsedData[i]["Attention"]);

                    
                    valor = (byte)tgParser.ParsedData[i]["Meditation"];
                    if (valor < 10 && valor != 0)
                    {
                        Console.Write("0");
                        passwd = 0;
                    } 
                    else if (valor < 20) 
                    {
                        Console.Write("1");
                        passwd = 1;
                    }
                    else if (valor < 30)
                    {
                        Console.Write("2");
                        passwd = 2;
                    }
                    else if (valor < 40)
                    {
                        Console.Write("3");
                        passwd = 3;
                    }
                    else if (valor < 50)
                    {
                        Console.Write("4");
                        passwd = 4;
                    }
                    else if (valor < 60)
                    {
                        Console.Write("5");
                        passwd = 5;
                    }
                    else if (valor < 70)
                    {
                        Console.Write("6");
                        passwd = 6;
                    }
                    else if (valor < 80)
                    {
                        Console.Write("7");
                        passwd = 7;
                    }
                    else if (valor < 90)
                    {
                        Console.Write("8");
                        passwd = 8;
                    }
                    else
                    {
                        Console.Write("9");
                        passwd = 9;
                    }
                    

                }


                if (tgParser.ParsedData[i].ContainsKey("Meditation")) {

                    //Console.WriteLine("Med Value:" + tgParser.ParsedData[i]["Meditation"]);

                }


                if(tgParser.ParsedData[i].ContainsKey("EegPowerDelta")) {

                    //Console.WriteLine("Delta: " + tgParser.ParsedData[i]["EegPowerDelta"]);

                }

                if (tgParser.ParsedData[i].ContainsKey("BlinkStrength"))
                {

                    //Console.WriteLine("Eyeblink " + tgParser.ParsedData[i]["BlinkStrength"]);

                    
                    valor = (byte)tgParser.ParsedData[i]["BlinkStrength"];
                    if (valor > 70)
                    {
                        passwd_final[j] = passwd;

                        Console.WriteLine("");
                        Console.Write("Passwd: ");
                        for (int k=0; k <= j ; k++)
                        {
                            Console.Write(passwd_final[k]);
                        }
                        Console.WriteLine("");

                        if (j < 3)
                        {
                            j++;
                        } else
                        {
                            j = 0;
                            Console.WriteLine("***********************************************************************");
                        }
                    }
                    // Console.WriteLine("\n" + valor + "\n");


                }


            }

        }

    }

}
