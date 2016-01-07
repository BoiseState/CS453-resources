
/**
 * A producer consumer with multiple queues, with graphical display.
 * 
 * @author Bryan Bolles, modified by amit
 */

public class PC
{
	public static void main(String args[])
	{
		if (args.length != 6) {
			System.out
					.println("Usage: java PC  (#queues) (queue size) (producers) (producers sleep) (consumers) (consumers sleep) \n");
			System.exit(1);
		}
		int numqueues = Integer.parseInt(args[0]);
		int queuesize = Integer.parseInt(args[1]);
		int prod = Integer.parseInt(args[2]);
		int prodsl = Integer.parseInt(args[3]);
		int cons = Integer.parseInt(args[4]);
		int conssl = Integer.parseInt(args[5]);

		SharedQueue[] Q = new SharedQueue[numqueues];
		for (int i = 0; i < numqueues; i++) {
			Q[i] = new SharedQueue(queuesize);
			Q[i].pack();
			Q[i].setVisible(true);
		}
		for (int i = 0; i < prod; i++)
			new Thread(new Producer(i, Q, prodsl, numqueues)).start();

		for (int i = 0; i < cons; i++)
			new Thread(new Consumer(i, Q, conssl, numqueues)).start();
	}
}

/* vim: set ts=4: */
