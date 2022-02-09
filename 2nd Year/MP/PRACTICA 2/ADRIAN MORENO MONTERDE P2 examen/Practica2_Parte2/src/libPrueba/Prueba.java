package libPrueba;

import libClases.*;

public class Prueba 
{

	public static void main(String[] args) 
	{
		//MAIN PARA COMPROBAR EL FUNCIONAMIENTO DE LA CLASE FECHA
		
		/*Fecha f1 = new Fecha(29,2,2001) , f2 = new Fecha(f1) , f3 = new Fecha(29,2,2004);
		final Fecha f4 = new Fecha(05,12,2023);
		System.out.println("Fechas: " + f1.toString() + ", " + f2 + ", " + f3 + ", " + f4 );
		
		f1 = new Fecha (31,12,2016); // 31/12/2016
		f4.setFecha(28, 2, 2008);
		System.out.println(f1 + " " + f2.toString() + " " + f3 + " " + f4 + " " + f1);
		
		f1 = new Fecha(f4.getDia()-10 , f4.getMes() , f4.getAnio()-7); //f1 = 18/02/2001
		f3 = Fecha.pedirFecha(); // Pide una fecha por teclado 
		if(f3.bisiesto() && Fecha.mayor(f2,f1))
			System.out.println("El " + f3.getAnio() + " fue bisiesto, " + f1 + ", " + f3);
		*/
		
		
		//MAIN PARA COMPROBAR EL FUNCIONAMIENTO DE LA CLASE CLIENTE Y SUS HIJAS: CLIENTETARIFAPLANA Y CLIENTE MOVIL 
		/*
		final Fecha f1 = new Fecha(29,2,2001) , f2 = new Fecha(f1) , f3 =  (Fecha) f1.clone();
		Fecha fnac1 = new Fecha(7,3,1980) , fnac2 = fnac1.diaSig() , fnac3 = new Fecha(27,06,1995) , aux; 
		System.out.print("Fechas: " + f1.toString() + ", " + f2 + ", " + f3 + "\n");
		System.out.println(f2.diaSig() + " " + (f2.getDia()-2) + " " + f2 + " " + f2.getAnio());
		
		if(!f3.bisiesto() && f1.equals(f2))
			System.out.println(f3.getAnio() + " no fue bisiesto. " + f1 + " igual a " + f2);
		
		f3.setFecha(5, 12, 2001);
		
		if(!f1.equals(f3) && Fecha.mayor(f1, f2) == false && Fecha.mayor(f3, f1))
			System.out.println(f3 + " es mayor que " + f1 + ". " + f1 + " no es mayor que " + f2);
		
		f1.setFecha(1,1,2001); f2.setFecha(2,2,2002); f3.setFecha(3, 3, 2003);
		System.out.print("Fecha alta por defecto: " + Cliente.getFechaPorDefecto() + "\n");
				
		Cliente c1 = new Cliente("793X" , "Ana Pi" , new Fecha(2,2,1972) , f3) , c2 = new Cliente(c1);
		Cliente c3 = new Cliente("953H" , "Susana" , new Fecha(7,2,1984)) , c4 = (Cliente) c3.clone();
		
		
		
		c1.setFechaAlta(fnac1); c1.setNombre("Luis");
		c3.setFechaAlta(fnac3); c3.setNombre("Juan");
		
		aux = c1.getFechaNac(); aux.setFecha(5, 5, 2005); // aux es una objeto tipo fecha
		aux = c1.getFechaAlta(); aux.setFecha(7, 7, 2020);
		
		c1.getFechaNac();
		
		c1.ver(); c2.ver(); c3.ver(); c4.ver();
		
		//System.out.println(f3 + "\n" + f3.diaSig());
		
		if(c2.equals(c1) && c3.equals(c4))
			Cliente.setFechaPorDefecto(f3.diaSig());
		
		System.out.print("Fecha alta por defecto: " + Cliente.getFechaPorDefecto() + "\n");
		
		Cliente [] c = new Cliente[6]; //array de 6 elementos de tipo cliente
		
		//A partir de aqui tengo que crear las clases de cliente movil y cliente de tarifa plana 
		
		c[0] = new ClienteMovil("547B" , "Bo Derek" , fnac1 , f3 , f3 , 50.50f , 0.03f);
		c[1] = new ClienteMovil("107J" , "Messi" , fnac2 , 35.00f , 0.02f);
		
		ClienteMovil cm = (ClienteMovil) c[1].clone();
		
		c[2] = cm; cm.setNombre(c1.getNombre()); cm.setFechaAlta(f1); cm.setFPermanencia(f1);
		
		f1.setFecha(4, 4, 2004); aux = cm.getFPermanencia(); aux.setFecha(20, 20, 2020);
		
		c[3] = new ClienteTarifaPlana("805W" , "Iker" , fnac2 , f1, 375.09f , "Española");
		c[4] = new ClienteTarifaPlana("953H" , "Paz" , fnac3 , 290.00f , "Polaca");
		
		ClienteTarifaPlana ct = (ClienteTarifaPlana) c[3].clone();
		
		c[5] = ct; ct.setNombre("Pepe"); ct.setNacionalidad("India"); ct.setMinutos(500);
		cm.ver(); ct.ver();
		
		ClienteTarifaPlana.setTarifa(350, 22.50f); // Cambia la tarifa plana a 350 min x 22.50 ES ESTATICO
		System.out.print("Tarifa Plana: " + ClienteTarifaPlana.getLimite() + " minutos por " + ClienteTarifaPlana.getTarifa() + " euros\n"); //GETTARIFA ES ESTATICO y  getlimite tambien 
		
		for(int i=0 ; i<6 ; i++)
			System.out.println(c[i].getNif() + ", " + c[i].getFechaAlta() + ", " + c[i]);
		
		if(c[2].equals(c[1]))
			System.out.println("c[2] y c[1] son iguales");
		
		if(c[4].equals(c[3]))
			System.out.println("c[4] y c[3] no son iguales (mismo dni pero distinto tipo)");
		
			*/
		
		//MAIN PARA COMPROBAR EL FUNCIONAMIENTO DE LA CLASE EMPRESA 
		
				
				Fecha f1 = new Fecha(29,2,2001) , f2 = new Fecha(f1) , f3 = new Fecha(29,2,2004);
				Fecha fnac1 = new Fecha(7,3,1980) , fnac2 = new Fecha(27,06,1995);
				
				System.out.println("Fechas:" + f1 + ", " + f2 + ", " + f3); 
				
				ClienteTarifaPlana[] ct = new ClienteTarifaPlana[4]; 
				ClienteMovil cm1 = new ClienteMovil("547B", "Luis Perez", fnac2, 50.50f, 0.03f);
				ClienteMovil cm2 = (ClienteMovil) cm1.clone(); // lo crea con los mismo datos que c1
				ClienteMovil cm3 = new ClienteMovil("777F", "Joe Sam", fnac2.diaSig(), 50.50f, 0.02f);
				
				ct[0] = new ClienteTarifaPlana("805W", "Luz Casal", fnac1, f3, 375.09f, "Española");
				ct[1] = new ClienteTarifaPlana("953H", "Paz Padilla", fnac2, f2, 290.00f, "Española");
				ct[2] = new ClienteTarifaPlana("106T", "Elton John", fnac2, 340.75f, "Inglesa");
				ct[3] = new ClienteTarifaPlana("467X", "Messi", fnac2.diaSig(), 300.00f, "Argentina");
				
				System.out.println("Codigos: " + cm1.getCodCliente() + ", " + cm2.getCodCliente() + ", " + ct[0].getCodCliente() + ", " + ct[2].getCodCliente() + "\n");
				
				Empresa g = new Empresa(), gcopia;
				
				g.alta(cm1); g.alta(ct[0]); g.alta(ct[2]); g.alta(cm2); g.alta(ct[1]); g.alta(cm3);
				g.alta(); g.alta(); //Añade un ClienteMovil 100Z Pepe Luis , fnac 2/2/1972, minutosHablados 40.30, precioPorMinuto 0.04 , fAlta 1/1/2010 y otro nif 106T
				g.alta(ct[1]); //no lo debe añadir ya que existe
				
				
				System.out.println("Grupo g:\n" + g.toString());
				
				g.baja("547B");  //elimina el cliente con nif 547B
				g.baja(); //Pregunta que cliente desea eliminar (953H) y decimos que NO
				g.baja(); //Pregunta que cliente desea eliminar (106T) y decimos que SI
				g.alta(cm2);
				
				System.out.println("#####\nClientes del grupo g:");
				System.out.println(g + "Factura: " + g.factura() + "\n---\n");
				
				gcopia = (Empresa) g.clone(); 
				gcopia.baja("805W"); gcopia.baja("106T"); gcopia.alta(ct[3]); //El 106T no existe
				g.baja("953H"); //elimina el cliente con 953H
				gcopia.descuento(50); 
				
				System.out.println("Grupo g:\n" + g + "\nGrupo gcopia:\n" + gcopia + "\n");
				System.out.println("g tiene " + g.getN() + " clientes y gcopia " + gcopia.getN());
				System.out.print("g tiene " + g.nClienteMovil() + " clientes de Tarifa Movil ");
				System.out.println("y " + (g.getN()-g.nClienteMovil()) + " de Tarifa Plana");	
				
				//Main Correspondiente al examen de modificaci�n 
				
				Cliente.mayorQue(cm1, ct[1]);
				
				//System.out.println("\nGanancia: ");
				g.ganancia(fnac1, f3);
				
				Empresa ladrona = new Empresa();
				
				ladrona.robarClientesTarifaPlana(g);
				System.out.println("\nEmpresa ladrona: " + ladrona);
	}
}
