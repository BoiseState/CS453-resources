import java.util.ArrayList;

/**
 * A simple shared queue monitor that is synchronized for use by multiple
 * threads.
 * 
 * @author amit
 */

public class SharedQueue {

	private ArrayList<String> queue;
	private int maxSize;

	public SharedQueue(int max) {
		queue = new ArrayList<String>();
		maxSize = max;
	}


	public synchronized int size() 
	{
		return queue.size();
	}


	public synchronized void removeElement(String obj)
	{
		queue.remove(obj);
	}


	public synchronized String firstElement()
	{
		return queue.getFirst();
	}


	public synchronized void addElement(String obj)
	{
		queue.add(obj);
	}


	public synchronized void putMessage(String msg) throws InterruptedException
	{
		while (size() == maxSize) {
			wait();
		}
		addElement(msg);
		notifyAll(); // for multiple consumers
	}


	public synchronized String getMessage() throws InterruptedException
	{
		while (size() == 0) {
			wait();
		}
		String message = (String) firstElement();
		removeElement(message);
		notifyAll(); // for multiple producers
		return message;
	}

}
