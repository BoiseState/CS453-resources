import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * A simple example of using an Executor to manage a thread pool.
 * 
 * @author amit
 */
public class ExecutorExample {
	public static final int NUM_THREADS = 10;
	public static final int EXIT_FAILURE = 1;
	public static final ExecutorService pool = Executors.newFixedThreadPool(NUM_THREADS);

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Usage: java ExecutorExample <n>");
			System.exit(EXIT_FAILURE);
		}

		int n = Integer.parseInt(args[0]);
		MyCalculation[] tasks = new MyCalculation[n];

		for (int i = 0; i < n; i++) {
			tasks[i] = new MyCalculation(n);
			pool.execute(tasks[i]);
		}

		pool.shutdown(); //will wait until previously scheduled tasks have completed

		for (MyCalculation task: tasks) {
			System.out.println(Arrays.toString(task.getValues()));
		}
	}
}
