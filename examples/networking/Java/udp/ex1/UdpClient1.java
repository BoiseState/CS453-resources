import java.net.*;
import java.io.*;

public class UdpClient1 {

	public static void main(String[] args) 
	{
		byte[] data = new byte[1024];
		if (args.length != 2) {
			System.err.println("Usage: java UdpClient1 <serverhost> <port>");
			System.exit(1);
		}
		String myHost = args[0];
		int myPort = Integer.parseInt(args[1]);
		

		try {
			InetAddress addr = InetAddress.getByName(myHost);
			DatagramPacket packet = 
				new DatagramPacket(data, data.length, addr, myPort);
			DatagramSocket ds = new DatagramSocket();
			datagramTest(ds, packet, 2000);
			ds.close();
		} catch (IOException e) {
			System.out.println(e);  // Error creating socket
		}
	}

	public static void datagramTest(DatagramSocket ds, 
									DatagramPacket packet, 
									int count)
	{
		byte[] temp = new byte[1024];

		try {
			InetAddress serverAddr = packet.getAddress();
			for (int i=0; i<count; i++) {
				packet.setData(temp);
				ds.send(packet);
				ds.receive(packet);	
				if (packet.getAddress().equals(serverAddr)) {
					System.out.println("recv'd datagram #"+i+
										" back from server "+
										packet.getAddress().getHostName());
				} else {
					System.out.println("recv'd datagram back"+
										" not from server but from  "+
									    packet.getAddress().getHostName()+
                                        " (ignored)");
				}
			}
		} catch (IOException e) {
			System.out.println(e);  // Error creating socket
		}
	}

}

