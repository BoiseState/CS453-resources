import java.util.Vector;

/*
 * A simple shared queue that is synchronized for use by multiple threads
 * @author amit
 */

public class SharedQueue 
{

  private Vector<String> v;
  private int maxSize;

  public SharedQueue(int max) 
  {
    v = new Vector<String>();
    maxSize = max;
  }

  public synchronized int size() 
  {
    return v.size();
  }

  public synchronized void removeElement(String obj) 
  {
    v.removeElement(obj);
  }

  public synchronized String firstElement() 
  {
    return v.firstElement();
  }

  public synchronized void addElement(String obj) 
  {
    v.addElement(obj);
  }

  public synchronized void putMessage(String msg) throws InterruptedException 
  {
		while ( this.size() == maxSize )
			wait();
		this.addElement(msg);
		notifyAll(); // for multiple consumers
  }

  public synchronized String getMessage() throws InterruptedException 
  {
		notifyAll(); // use notify for single producer
		while ( this.size() == 0 )
			wait();
		String message = (String)this.firstElement();
		this.removeElement( message );
        return message;
    }

}

