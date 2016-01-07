import java.io.*;
import java.net.*;
/**
 * A multi-threaded time server.
 * @author amit
 */
public class TimeServer
{
	private int port;
	ServerSocket ss;

	public TimeServer(int port) {
		try {
			ss = new ServerSocket(port);
		} catch (IOException e) {
			System.err.println(e);
		}
	}

	public void runServer() {
		Socket client;
		try {
			while (true) {
				client = ss.accept();
				System.out.println("Received connect from " + 
						            client.getInetAddress().getHostName() + " [ " + 
									client.getInetAddress().getHostAddress() + " ] ");
				new ServerConnection(client).start();
			}
		} catch  (IOException e) {
			System.err.println(e);
		}
	}

	public static void main (String args[]) {
		if (args.length < 1) {
			System.err.println("Usage: java TimeServer <port>");
			System.exit(1);
		}
		TimeServer server = new TimeServer(Integer.parseInt(args[0]));
		server.runServer();
	}
}

class ServerConnection extends Thread {
	Socket client;
	ServerConnection (Socket client) throws SocketException {
		this.client = client;
		setPriority(NORM_PRIORITY - 1);
		System.out.println("Created thread "+this.getName());
	}

	public void run() {
		try {
			InputStream in = client.getInputStream();
			OutputStream out = client.getOutputStream();
			ObjectOutputStream oout = new ObjectOutputStream(out);
			Thread.sleep(10000); 
			oout.writeObject(new java.util.Date());
			oout.flush();
			client.close();
		} catch (InterruptedException e) {
			System.out.println(e);
		} catch (IOException e) {
			System.out.println("I/O error " + e); 
		}
	}
}
