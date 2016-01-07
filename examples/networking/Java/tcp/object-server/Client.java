import java.net.*;
import java.io.*;

public class Client { 
	public static void main( String argv[] ) 
	{
		if (argv.length < 3)
		{
			System.err.println("Usage: java Client <hostname> <port> <n>");
			System.exit(1);
		}
		try {
			int n = Integer.parseInt(argv[2]);
			Socket server = new Socket(argv[0], Integer.parseInt(argv[1]));
			ObjectOutputStream out = 
				new ObjectOutputStream(server.getOutputStream());
			ObjectInputStream in = 
				new ObjectInputStream(server.getInputStream());

			out.writeObject( new DateRequest());
			out.flush();
			System.out.println( in.readObject());

			long timeTaken = System.currentTimeMillis();
			out.writeObject( new MyCalculation(n));
			out.flush();
			Object obj = in.readObject();
			timeTaken = System.currentTimeMillis() - timeTaken;
			System.out.println("Time taken to receive reply from server = " + 
			                                     timeTaken/1000.0 + " seconds.");
			if (obj instanceof int[])
			{
				if (n < 100) {
					System.out.println(obj);

					int [] results = (int []) obj;
					String padString = " ";
					for (int i=0; i<results.length; i++)
					{
						System.err.print(results[i]+padString);
					}
					System.err.println();
				}
			}

			server.close();
		} catch ( IOException e ) {
			System.out.println( "I/O error " + e ); // I/O error
		} catch ( ClassNotFoundException e2 ) {
			System.out.println( e2 ); // Unknown type of response object
		}
	}
}
