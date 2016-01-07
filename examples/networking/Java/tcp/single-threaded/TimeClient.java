
import java.io.*;
import java.net.*;
import java.util.Date;

public class TimeClient
{
	public static void main (String args[])
	{
		if (args.length != 2) {
			System.err.println("Usage: java TimeClient <serverhost> <port>");
			System.exit(1);
		}
		String host = args[0];
		int port = Integer.parseInt(args[1]);
		
		try {
			Socket s = new Socket(host, port);
			InputStream in = s.getInputStream();
			OutputStream out = s.getOutputStream();
			ObjectInputStream oin = new ObjectInputStream(in);
			Date date = (Date) oin.readObject();
			System.out.println("Time on host "+host+" is "+date);
		} catch (IOException e1) {
			System.out.println(e1);
		} catch (ClassNotFoundException e2) {
			System.out.println(e2);
		}
	}
}
