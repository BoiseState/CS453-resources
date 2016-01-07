import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;



public class Server { 
	public static void main(String argv[]) throws IOException 
	{
		if (argv.length < 1)
		{
			System.err.println("Usage: java Server <port>");
			System.exit(1);
		}
		ServerSocket ss = new ServerSocket(Integer.parseInt(argv[0]));
		while (true)
			new ServerConnection(ss.accept()).start();
	}
}
class ServerConnection extends Thread {
	Socket client;
	ServerConnection (Socket client) throws SocketException {
		this.client = client;
		setPriority(NORM_PRIORITY - 1);
	}

	public void run() {
		try {
			ObjectOutputStream out = 
				new ObjectOutputStream(client.getOutputStream());
			ObjectInputStream in = 
				new ObjectInputStream(client.getInputStream());
			System.out.println("Received connect from "+client.getInetAddress().getHostAddress());

			while (true) {
				out.writeObject(processRequest(in.readObject()));
				out.flush();
			}
		} catch (EOFException e3) { // Normal EOF
			try {
				client.close();
			} catch (IOException e) { }
		} catch (IOException e) {
			System.out.println("I/O error " + e); // I/O error
		} catch (ClassNotFoundException e2) {
			System.out.println(e2); // Unknown type of request object
		}
	}

	private Object processRequest(Object request) {
		if (request instanceof DateRequest) 
			return new java.util.Date();
		else if (request instanceof WorkRequest)
			return ((WorkRequest)request).execute();
		else
			return null;
	}
}
