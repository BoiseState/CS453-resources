import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.util.regex.Matcher;
import java.util.regex.Pattern;



public class HttpdConnection 
{
	private static Charset charset = Charset.forName("8859_1");
	private static Pattern httpGetPattern = Pattern.compile("(?s)GET /?(\\S*).*");
	private SocketChannel clientSocket;
	private ByteBuffer buff = ByteBuffer.allocateDirect(64*1024);
	private String request;
	private String response;
	private FileChannel file;
	private int filePosition;

	public HttpdConnection (SocketChannel clientSocket) {
		this.clientSocket = clientSocket;
	}

	public void processRequest(SelectionKey key) {
		buff.flip();
		request = charset.decode(buff).toString();
		System.out.println("Request: " + request);
		Matcher get = httpGetPattern.matcher(request);
		if (get.matches()) {
			request = get.group(1);
			if (request.endsWith("/") || request.equals(""))
				request = request + "index.html";
			//System.out.println("Request: "+request);
			try {
				file = new FileInputStream(request).getChannel();
			} catch (FileNotFoundException e) {
				response = "404 Object Not Found";
			}
		} else
			response = "400 Bad Request" ;

		if (response != null) {
			buff.clear();
			charset.newEncoder().encode(CharBuffer.wrap(response), buff, true);
			buff.flip();
		}
		key.interestOps(SelectionKey.OP_WRITE);
	}
	
	public void read(SelectionKey key) throws IOException {
		if (request == null && (clientSocket.read(buff) == -1 || buff.get(buff.position()-1) == '\n'))
			processRequest(key);
		else
			key.interestOps(SelectionKey.OP_READ);
	}

	public void write(SelectionKey key) throws IOException {
		if (response != null) {
			clientSocket.write(buff);
			if (buff.remaining() == 0) 
				response = null;
		} else if (file != null) {
			int remaining = (int)file.size() - filePosition;
			long got = file.transferTo(filePosition, remaining, clientSocket);
			if (got == -1 || remaining <= 0) {
				file.close();
				file = null;
			} else
				filePosition += got;
		} 
		if (response == null && file == null) {
			clientSocket.close();
			key.cancel();		
		} else 
			key.interestOps(SelectionKey.OP_WRITE);
	}
}

