import java.net.*;
import java.io.*;

public class HeartBeat extends java.applet.Applet {
	String myHost;
	int myPort;

	public void init() {
		myHost = getCodeBase().getHost();
		myPort = Integer.parseInt( getParameter("myPort") );
	}

	private void sendMessage( String message ) {
		try {
			byte [] data = message.getBytes();
			InetAddress addr = InetAddress.getByName( myHost );
			DatagramPacket pack = 
				new DatagramPacket(data, data.length, addr, myPort );
			DatagramSocket ds = new DatagramSocket();
			System.out.println( "Sending message to pulse server");  
			ds.send( pack );
			ds.close();
		} catch ( IOException e ) {
			System.out.println( e );  // Error creating socket
		}
	}

	public void start() {
		sendMessage("Arrived");
	}
	public void stop() {
		sendMessage("Departed");
	}
}

