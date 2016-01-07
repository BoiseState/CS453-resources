
import java.io.*;
import java.net.*;

public class SocketOptions
{
	public static void main (String args[])
	{
		try {
			Socket s = new Socket("localhost", 5005);
			System.out.println("Socket s"); 
			System.out.println("SO_TIMEOUT = "+s.getSoTimeout());
			System.out.println("Receive Buffer Size = "+s.getReceiveBufferSize());
			System.out.println("Send Buffer Size = "+s.getSendBufferSize());
			System.out.println("TCP_NODELAY  = "+s.getTcpNoDelay());
			System.out.println("SO_LINGER  = "+s.getSoLinger());
			System.out.println("TCP_KEEPALIVE  = "+s.getKeepAlive());
			System.out.println("SO_REUSEADDR  = "+s.getReuseAddress());
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}
