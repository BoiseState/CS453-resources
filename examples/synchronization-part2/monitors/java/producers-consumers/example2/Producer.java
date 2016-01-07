

/**
 * The Producer Thread
 * @author amit
 *
 */
public class Producer implements Runnable
{
	SharedQueue[] Q;
	int name, sleep, start, howmany, pos;
	int i = 0;

	/**
	 * @param name
	 * @param Q  array of shared queues
	 * @param sleep
	 * @param size
	 */
	public Producer(int name, SharedQueue[] Q, int sleep, int size)
	{
		this.Q = Q;
		this.name = name;
		this.start = name;
		this.sleep = sleep;
		this.howmany = size;
	}

	/* (non-Javadoc)
	 * @see java.lang.Runnable#run()
	 */
	public void run()
	{
		try {
			while (true) {
				String msg = new java.util.Date().toString();
				if (start >= howmany)
					start = 0;
				Q[start++].putMessage(msg);
				System.out.println("Producer " + name + " put message: " + msg);
				Thread.sleep(sleep);
			}
		} catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}

/* vim: set ts=4: */
