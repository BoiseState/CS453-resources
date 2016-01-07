import java.io.*;
import java.net.*;

/** 
   A single-threaded time server.
   You may need to open port 5005 in the firewall on the host machine.
   @author amit
*/

public class TimeServer
{
	private InputStream in;
	private OutputStream out;
	private int port = 5005;
	private ServerSocket s;

	public static void main (String args[]) {
		TimeServer server = new TimeServer();
		server.serviceClients();
	}

	public TimeServer() {
		try {
			s = new ServerSocket(port);
		} catch (IOException e) {
			System.err.println(e);
		}
	}

	public void serviceClients()
	{
		Socket sock;

		while (true)
		{
			try {
				sock = s.accept();
				in = sock.getInputStream();
				out = sock.getOutputStream();
				System.out.println("Received connect from "+sock.getInetAddress().getHostAddress());
				ObjectOutputStream oout = new ObjectOutputStream(out);
				oout.writeObject(new java.util.Date());
				oout.flush();
				Thread.sleep(4000); //4 secs
				sock.close();
			} catch (InterruptedException e) {
				System.err.println(e);
			} catch (IOException e) {
				System.err.println(e);
			}
		}
	}
}
