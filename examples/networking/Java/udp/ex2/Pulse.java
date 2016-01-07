import java.net.*;
import java.io.*;

public class Pulse {
	public static void main( String [] argv ) 
	{
		if (argv.length == 0) {
			System.out.println("Usage: java Pulse <port#>");
			System.exit(1);
		}
		try {
			DatagramSocket s = new DatagramSocket( Integer.parseInt(argv[0]) );

			while ( true ) {
			DatagramPacket packet = new DatagramPacket(new byte [1024], 1024);
			s.receive( packet );
			String message = new String( packet.getData() );
			System.out.println( "Heartbeat from: " + 
						packet.getAddress().getHostName() + " - " + message );
			}
		}
		catch (Exception e)
		{
			System.out.println(e);
		}
	}
}

