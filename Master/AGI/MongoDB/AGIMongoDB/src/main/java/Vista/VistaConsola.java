package Vista;

public class VistaConsola
{
    public void vistaConsolaLogin(String texto)
    {
        System.out.println("***********************");
        System.out.println(texto);
        System.out.println("***********************");
    }
    
    public void vistaConsolaLogin(String texto, String error)
    {
        System.out.println("***********************");
        System.out.println(texto);
        System.out.println("***********************");
        System.out.println(error);
    }
}
