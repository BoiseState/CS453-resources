
public class TestAccount {

	public static void main(String args[]) throws java.lang.InterruptedException
	{
		if (args.length != 3) {
			System.err.println("Usage: java TestAccount <numThreads> <iterations> <good|bad>");
			System.exit(1);
		}

		int numThreads = Integer.parseInt(args[0]);
		if (numThreads > 1000) {
			System.err.println("Maximum number of threads allowed is 1000!");
			System.exit(1);
		}

		int iterations = Integer.parseInt(args[1]);
		Account account = new Account();
		if (args[2].compareTo("good") == 0) account = new ThreadsafeAccount();

		Thread[] tids = new Thread[numThreads];
		for (int i = 0; i < numThreads; i++) {
			tids[i] = new Thread(new TestThread(account, iterations));
			tids[i].start();
		}

		for (int i = 0; i < numThreads; i++) {
			tids[i].join();
		}
		System.out.println(account);
	}
}

class TestThread implements Runnable {

	private int iterations;
	private Account account;

	public TestThread(Account account, int iterations) {
		this.account = account;
		this.iterations = iterations;
	}


	public void run()
	{
		for (int i = 0; i < iterations; i++) {
			double amount = 1.0;
			account.deposit(amount);
		}
	}
}
