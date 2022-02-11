import java.util.Scanner;

public class Test 
{
	public static void main(String []args)
	{
		Scanner keyboard = new Scanner(System.in);
		
		MyDirectory md1 = new MyDirectory("C:/Program Files/Java/");
		MyDirectory md2 = new MyDirectory("C:/Program Files/Java/bin/");
		MyDirectory md3 = new MyDirectory("C:/Program Files/Microsoft/");
		
		MyFile mf1 = new MyFile("README.txt", "This is the content of README.txt file");
		MyFile mf2 = new MyFile("Welcome.html", "This is the content of Welcome.html file");
		MyFile mf3 = new MyFile("java.jar", "This is the content of java.jar file");
		MyFile mf4 = new MyFile("javaw.jar", "This is the content of javaw.jar file");
		MyFile mf5 = new MyFile("eula.docx", "This is the content of eula.docx");
		MyFile mf6 = new MyFile("readme.html", "This is the content of readme.html");
		MyFile mf7 = new MyFile("thirdpartynotices.docx", "This is the content of thirdpartynotices.docx");
		
		md1.addContent(mf1);
		md1.addContent(mf2);
		md2.addContent(mf3);
		md2.addContent(mf4);
		md3.addContent(mf5);
		md3.addContent(mf6);
		md3.addContent(mf7);
		
		md1.readContent();
		md2.readContent();
		md3.readContent();
		
		System.out.println();
		
		md1.calculateSize();
		md2.calculateSize();
		md3.calculateSize();
		
		keyboard.close();
	}
}
