import java.io.IOException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;


/**
 * @author Learning Java (3rd ed), modified by Amit Jain
 *
 */
public class LargerHttpd {
	private Selector clientSelector;
	private ClientQueue readyClients = new ClientQueue();

	public void run(int port, int threads) throws IOException 
	{
		clientSelector = Selector.open();
		ServerSocketChannel ssc = ServerSocketChannel.open();
		ssc.configureBlocking(false);
		InetSocketAddress sa = new InetSocketAddress(InetAddress.getLocalHost(), port);
		ssc.socket().bind(sa);
		ssc.register(clientSelector, SelectionKey.OP_ACCEPT);
	
		for (int i = 0; i < threads; i++)
			new Thread() {
				public void run() {
					while (true)
						try { handleClient(); } catch (IOException e) { System.err.println(e); }
				}
			}.start();
			

		while (true) 
			try {
				while (clientSelector.select(50) == 0); // wait 50 millisecs between checks
				Set<SelectionKey> readySet = clientSelector.selectedKeys();
				for (Iterator<SelectionKey> iterator = readySet.iterator(); iterator.hasNext();) {
					SelectionKey key = iterator.next();
					iterator.remove();
					if (key.isAcceptable())
						acceptClient(ssc);
					else {
						key.interestOps(0);
						readyClients.add(key);
					}
				}
			} catch (IOException e) {
				System.out.println(e);
			}
	}
	

	void acceptClient(ServerSocketChannel ssc) throws IOException 
	{
		SocketChannel clientSocket = ssc.accept();
		clientSocket.configureBlocking(false);
		SelectionKey key = clientSocket.register(clientSelector, SelectionKey.OP_READ);
		HttpdConnection client = new HttpdConnection(clientSocket);
		key.attach(client);
	}
	

	void handleClient() throws IOException 
	{
		SelectionKey key = readyClients.next();
		HttpdConnection client = (HttpdConnection) key.attachment();
		if (key.isReadable())
			client.read(key);
		else 
			client.write(key);
	}
	

	public static void main(String args[]) throws IOException 
	{
		if (args.length == 0) {
			System.err.println("Usage: java LargerHttpd <port#> <max #threads>");
			System.exit(1);
		}
		int port = Integer.parseInt(args[0]);
		int maxThreads = Integer.parseInt(args[1]);
		new LargerHttpd().run(port, maxThreads);
	}
	
}




