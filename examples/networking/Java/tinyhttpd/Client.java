
import java.net.*;
import java.io.*;

public class Client {
	public static void main( String [] args ) 
    throws IOException 
    {
		if (args.length == 0)
		{
			throw new IOException("\n Usage: java client <hostname>");
        }
		System.out.println("connecting...");
		Socket s = new Socket(args[0], 5005);
		String page;
		if (args.length < 2)
			page = "index.html";
		else
			page = args[1];
		new PrintStream( s.getOutputStream() ).println("GET /"+page);
		/*DataInputStream bin = new DataInputStream( s.getInputStream() );*/
		BufferedReader bin = 
                new BufferedReader( new InputStreamReader(s.getInputStream()));
		String line;
		while ( (line = bin.readLine()) != null )
			System.out.println(line);
	}
}
