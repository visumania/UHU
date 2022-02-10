package libTests;

import libClasses.*;

public class Test1 
{
	public static void main(String[] args)
	{
		final Date d1 = new Date(29,2,2001), d2 = new Date(d1), d3 = (Date) d1.clone();
        Date fnac1 = new Date(7,3,1980), fnac2 = fnac1.nextDay(),
        fnac3 = new Date(27,06,1995), aux;
        
        
        System.out.print("Dates: " + d1.toString() + ", " + d2 + ", " + d3 + "\n");
        System.out.println(d2.nextDay()+ " " + (d2.getDay()-2) + " " +d2+ " " + d2.getYear());
        if (!d3.leap() && d1.equals(d2))
        System.out.println(d3.getYear() + " no fue bisiesto. " + d1 + " igual a " + d3);
        d3.setDate(5,12,2001);
        if (!d1.equals(d3) && Date.higher(d1,d2)==false && Date.higher(d3,d1))
        d1.setDate(1,1,2001); d2.setDate(2,2,2002); d3.setDate(3,3,2003);
        System.out.print("Date alta por defecto: " + Client.getDefaultDate() + "\n");
        Client c1=new Client("793X","Ana Pi",new Date(2,2,1972),d3), c2=new Client(c1);
        Client c3=new Client("953H","Susana", new Date(7,2,1984)), c4=(Client) c3.clone();
        c1.setDischargeDate(fnac1); c1.setName("Luis");
        c3.setDischargeDate(fnac3); c3.setName("Juan");
        aux = c1.getDateBirth(); aux.setDate(5, 5, 2005);
        aux = c1.getDischargeDate(); aux.setDate(7, 7, 2020);
        c1.see(); c2.see(); c3.see(); c4.see();
        if (c2.equals(c1) && c3.equals(c4))
            Client.setDefaultDate(d3.nextDay());
        System.out.print("Date alta por defecto: " + Client.getDefaultDate() + "\n");
        Client [] c = new Client[6]; //array de 6 elementos de tipo Client
        c[0]= new ClientMobile("547B","Bo Derek", fnac1, d3, d3, 50.50f, 0.03f);
        c[1]= new ClientMobile("107J","Messi", fnac2, 35.00f, 0.02f);
        ClientMobile cm= (ClientMobile) c[1].clone();
        c[2]=cm; cm.setName(c1.getName()); cm.setDischargeDate(d1); cm.setPermanenceDate(d1);
        d1.setDate(4,4,2004); aux=cm.getPermanenceDate(); aux.setDate(20, 20, 2020);
        c[3]=new ClientFlatRate("805W","Iker", fnac2, d1, 375.09f, "Española");
        c[4]=new ClientFlatRate("953H","Paz", fnac3, 290.00f, "Polaca");
        ClientFlatRate ct= (ClientFlatRate) c[3].clone();
        c[5]=ct; ct.setName("Pepe"); ct.setNationality("India"); ct.setMinutes(500);
        cm.see(); ct.see();
        ClientFlatRate.setRate(350, 22.50f); //cambia la Tarifa Plana a 350 min x 22.50
        System.out.print("Tarifa Plana: " + ClientFlatRate.getLimit() + " minutos por "
        + ClientFlatRate.getRate() + " euros\n");
        for(int i=0; i<6; i++)
            System.out.println(c[i].getNif() + ", " + c[i].getDischargeDate() + ", " + c[i]);
        if (c[2].equals(c[1]))
            System.out.println("c[2] y c[1] son iguales");
        if (c[4].equals(c3)==false)
            System.out.println("c[4] y c3 no son iguales (mismo dni pero distinto tipo)");
	}
}
