
import java.util.Random;

/**
 * Runs the widget maker faster by using multiple threads.
 * 
 * @author amit
 * @author taylor
 */
public class FasterWidgetMaker extends Thread
{
    private Random generator = new Random();
    private final int RANGE = 100;
    private final int BASE = 100;
    private static final int INCORRECT_ARGUMENTS = 1;
    private int startIndex;
    private int count;
    private int threadNum;

    /**
     * @param count
     */
    public FasterWidgetMaker(int threadNum, int startIndex, int count) {
	this.threadNum = threadNum;
	this.startIndex = startIndex;
	this.count = count;
    }


    /**
     * The main method for a thread. Just calls make.
     */
    public void run() {
	make();
    }


    /**
     * Simulate making the widgets with indices: startIndex, startIndex + 1, ... ,
     * startIndex + count - 1.
     */
    public void make() {
	for (int i = startIndex + 1; i < count + startIndex + 1; i++) {
	    int time = generator.nextInt(RANGE) + BASE;
	    // simulate variable amount of time to make one widget
	    try {
		Thread.sleep(time);
	    } catch (InterruptedException e) {
		e.printStackTrace();
	    }
	    System.out.println("Widget# " + i + " ready on thread " + threadNum);
	}
    }


    /**
     * Create the threads that do the work in parallel.
     * 
     * @param n
     *                       number of widgets to make
     * @param numThreads
     *                       number of threads to use
     * @throws InterruptedException
     */
    private static void createAndRunThreads(int n, int numThreads) throws InterruptedException {
	int count = n / numThreads;
	FasterWidgetMaker[] robotFactory = new FasterWidgetMaker[numThreads];
	for (int i = 0; i < numThreads - 1; i++) {
	    robotFactory[i] = new FasterWidgetMaker(i + 1, i * count, count);
	}
	robotFactory[numThreads - 1] = new FasterWidgetMaker(numThreads, (numThreads - 1) * count,
	        count + n % numThreads);

	for (int i = 0; i < numThreads; i++) {
	    robotFactory[i].start();
	}

	for (int i = 0; i < numThreads; i++) {
	    robotFactory[i].join();
	}
    }


    /**
     * Creates the threads and then divide the work of making widgets amongst the
     * threads.
     * 
     * @param args
     * @throws InterruptedException
     */
    public static void main(String[] args) throws InterruptedException
    {

	final int DEFAULT_NUM_THREADS = 8;
	if (args.length != 1 && args.length != 2) {
	    System.out.println("Usage: java WidgetMaker <number of widgets> [<numThreads>]");
	    System.exit(INCORRECT_ARGUMENTS);
	}
	int n = Integer.parseInt(args[0]);
	int numThreads = 0;
	if (args.length == 2) {
	    numThreads = Integer.parseInt(args[1]);
	} else {
	    numThreads = DEFAULT_NUM_THREADS;
	}
	// or ask the system for the number of CPUs available!
	//numThreads = Runtime.getRuntime().availableProcessors();

	long startTime = System.currentTimeMillis();
	createAndRunThreads(n, numThreads);
	long totalTime = System.currentTimeMillis() - startTime;
	System.out.println("WidgetMaker: made " + n + " widgets in " + totalTime / 1000.0 + " seconds -- using "
	        + numThreads + " threads");
    }

}
