package libTests;

import libClasses.*;

public class Test2 
{
	public static void main(String[] args)
	{
		Date f1=new Date(29,2,2001), f2= new Date(f1), f3=new Date(29,2,2004);
        Date fnac1 = new Date(7,3,1980), fnac2 = new Date(27,06,1995);
        System.out.println("Dates:" + f1 + ", " + f2 + ", " + f3);
        ClientFlatRate [] ct= new ClientFlatRate[4];
        ClientMobile cm1 = new ClientMobile("547B", "Luis Perez", fnac2, 50.50f, 0.03f);
        ClientMobile cm2 = (ClientMobile) cm1.clone(); //lo crea con los mismos datos que cm1
        ClientMobile cm3 = new ClientMobile("777F", "Joe Sam", fnac2.nextDay(), 50.50f, 0.02f);
        ct[0] = new ClientFlatRate("805W","Luz Casal", fnac1, f3, 375.09f, "Española");
        ct[1] = new ClientFlatRate("953H","Paz Padilla", fnac2,f2, 290.00f, "Española");
        ct[2] = new ClientFlatRate("106T","Elton John", fnac2, 340.75f, "Inglesa");
        ct[3] = new ClientFlatRate("467X","Messi", fnac2.nextDay(), 300.00f, "Argentina");
        System.out.println("Codigos: " + cm1.getCodClient() +","+ cm2.getCodClient() + ", "+ ct[0].getCodClient() +", "+ ct[2].getCodClient() +"\n");
        Company g=new Company(), gcopia;
        g.add(cm1);
        g.add(ct[0]);
        g.add(ct[2]);
        g.add(cm2);
        g.add(ct[1]);
        g.add(cm3);
        g.add();   //añade un ClientMobile 100Z Pepe Luis, 2/2/1972 1/1/2001 40.30, 0.04 1/1/2010
        g.add();   //otro con nif 106T
        g.add(ct[1]);  //no lo debe de añadir ya que existe
        System.out.println("Grupo g:\n" + g);
        g.delete("547B"); //elimina el cliente con nif 547B
        g.delete(); //pregunta que cliente desea eliminar (953H) y decimos que NO
        g.delete(); //pregunta que cliente desea eliminar (106T) y decimos que SI
        g.add(cm2);System.out.println("#####\nClientes del grupo g:");
        System.out.println(g + "bill: " + g.bill() +"\n---\n");
        gcopia=(Company)g.clone();
        gcopia.delete("805W");
        gcopia.delete("106T");
        gcopia.add(ct[3]); //el 106T no existe
        g.delete("953H"); //elimina el cliente con 953H
        gcopia.discount(50);
        System.out.println("Grupo g:\n" + g + "\nGrupo gcopia:\n" + gcopia + "\n");
        System.out.println("g tiene " + g.getNumberClients() + " clientes y gcopia " + gcopia.getNumberClients());
        System.out.print("g tiene " + g.nClientMobile() + " clientes de Tarifa Movil");
        System.out.println("y "+(g.getNumberClients()-g.nClientMobile())+" de TarifaPlana");
	}
}
