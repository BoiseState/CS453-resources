//package exploringjava.net;

import java.net.Socket;
import java.io.*;

public class FingerAtHost 
{
    static int fingerPort = 79; // port for finger daemon

	public FingerAtHost (String user, String host, int port) 
	throws IOException 
	{
        Socket server = new Socket( host, port );
        InputStreamReader din = 
		   new InputStreamReader(server.getInputStream());
        PrintStream dout = 
		  new PrintStream(server.getOutputStream());

		// send user name to the remote finger daemon
		dout.println(user);
		/*dout.close();*/

		// read response from the remote finger daemon
		int ch;
		String s = "";
		while ( (ch = din.read()) != -1)
		{
			s = s + (char) ch;
		}
        server.close();
		System.out.println(s);
	}

	public FingerAtHost( String user, String host ) 
	throws IOException 
	{
		this(user, host, fingerPort);
	}

	public static void main (String [] args) 
	throws Exception 
	{
		if (args.length < 2)
		{
		 throw new IOException("\n Usage: java FingerAtHost <user> <hostname>");
		}

		new FingerAtHost (args[0], args[1]);
	}
}

