
import java.io.*;
import java.net.*;


public class ServerSocketOptions
{
	private static final int BACKLOG = 1024;

	public static void main (String args[])
	{
		try {
			ServerSocket s = new ServerSocket(5005, BACKLOG);

			System.out.println("ServerSocket"); 
			System.out.println("SO_TIMEOUT = "+s.getSoTimeout());
			System.out.println("Receive Buffer Size = "+s.getReceiveBufferSize());
			s.setSoTimeout(5000); // 5 seconds 
			System.out.println("New SO_TIMEOUT = "+s.getSoTimeout());

			serverClients(s);
			
		} catch (IOException e) {
			System.err.println(e);
		}
	}

	private static void serverClients(ServerSocket s)
	{
		boolean shutdown = false;

		while (!shutdown)
		{
			try {
				s.accept();
			} catch (InterruptedIOException e) {
				System.err.println("accept timed out");
				shutdown = true;
			} catch (IOException e) {
				System.err.println(e);
			}
		}
	}

}
