/**
 * The Consumer thread
 * @author amit
 *
 */
public class Consumer implements Runnable
{
	SharedQueue[] Q;
	int name, sleep, start, size, howmany;
	int i = 0;

	/**
	 * Constructor
	 * @param name
	 * @param Q     array of shared queues
	 * @param sleep
	 * @param pos
	 */
	public Consumer(int name, SharedQueue[] Q, int sleep, int pos)
	{
		this.Q = Q;
		this.name = name;
		this.start = name;
		this.sleep = sleep;
		this.howmany = pos;
	}

	/* (non-Javadoc)
	 * @see java.lang.Thread#run()
	 */
	public void run()
	{
		try {
			while (true) {
				String message = Q[start++].getMessage();
				if (start >= howmany)
					start = 0;
				System.out.println("Consumer " + name + " got message: "
						+ message);

				Thread.sleep(sleep);
			}
		} catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}
