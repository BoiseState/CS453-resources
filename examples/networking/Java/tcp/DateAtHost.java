//
// May have to enable time service as follows:
//  Set disable flag to "no" in /etc/xinetd.d/time-stream
//  Reload xinetd with: /sbin/service xinetd reload
// When done, disable service by setting disable flag and reloading xinetd.

import java.net.Socket;
import java.io.*;

public class DateAtHost extends java.util.Date {
    static int timePort = 37;
    static final long offset = 2208988800L;   //  Seconds from century to 
                                              //   Jan 1, 1970 00:00 GMT

	public DateAtHost( String host, int port ) throws IOException {
        Socket server = new Socket( host, port );
        DataInputStream din = new DataInputStream( server.getInputStream() );
        int time = din.readInt();
        server.close();
 
        setTime( (((1L << 32) + time) - offset) * 1000 );
	}

	public DateAtHost( String host ) throws IOException {
		this( host, timePort );
	}

	public static void main (String [] args) 
	throws Exception 
	{
		if (args.length == 0)
		{
			throw new IOException("\n Usage: java DateAtHost <hostname>");
		}

		System.out.println( new DateAtHost( args[0] ) );
	}
}

