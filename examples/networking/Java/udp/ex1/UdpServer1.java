import java.net.*;
import java.io.*;

public class UdpServer1 
{
	private int count;
	private DatagramSocket s;
	private DatagramPacket packet;

	public UdpServer1(int port)
	{
		try {
			s = new DatagramSocket(port);
			packet = new DatagramPacket(new byte [1024], 1024);
		}
		catch (Exception e)
		{
			System.out.println(e);
		}

	}

	public int getCount() { return count; }

	public void runServer() 
	{
		count = 0;
		try {
			while (true) {
				s.receive(packet);
				s.send(packet); // echo back the datagram 
				count++;
			}
		}
		catch (Exception e)
		{
			System.out.println(e);
		}
	}



	public static void main(String [] args) 
	{
		int port = 0;
		if (args.length != 1) {
			System.err.println("Usage: java UdpServer1 <port#>");
			System.exit(1);
		}
		port = Integer.parseInt(args[0]);
		UdpServer1 server = new UdpServer1(port);

		StatsThread stats = new StatsThread(server);
		Runtime current = Runtime.getRuntime();
		current.addShutdownHook(stats);

		server.runServer();

	}
} 

class StatsThread extends Thread 
{
	UdpServer1 server;

	public StatsThread(UdpServer1 server) 
	{
		this.server = server;
	}

	public void run() 
	{
		int count = server.getCount();
		System.err.println("Number of datagrams received by server: "+count);
	}
}
