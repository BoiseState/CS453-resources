
import java.util.Random;

/**
 * A simple program that simulates a widget factory. Each widget takes a
 * variable (random) amount of time to make.
 * 
 * @author amit
 * @author taylor
 */
public class WidgetMaker
{
    private Random generator = new Random();
    private final int RANGE = 100; // milliseconds
    private final int BASE = 100; // milliseconds
    private static final int INCORRECT_ARGUMENTS = 1;
    private int startIndex;
    private int count;

    /**
     * Sets the number of widgets to make and the starting index to use.
     * 
     * @param startIndex
     *                       the starting index for the widgets
     * @param count
     *                       the number of widgets to make
     */
    public WidgetMaker(int startIndex, int count) {
	this.startIndex = startIndex;
	this.count = count;
    }


    /**
     * Simulate making the widgets with indices: startIndex, startIndex + 1, ... ,
     * startIndex + count - 1.
     */
    private void make() {
	for (int i = startIndex; i < count + startIndex; i++) {
	    int time = generator.nextInt(RANGE) + BASE;
	    // simulate variable amount of time to make one widget
	    try {
		Thread.sleep(time);
	    } catch (InterruptedException e) {
		e.printStackTrace();
	    }
	    System.out.println("Widget# " + i + " ready.");
	}
    }


    /**
     * @param args
     * @throws InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {

	if (args.length != 1) {
	    System.out.println("Usage: java WidgetMaker <number of widgets>");
	    System.exit(INCORRECT_ARGUMENTS);
	}
	int n = Integer.parseInt(args[0]);

	long startTime = System.currentTimeMillis();

	// make n widgets, numbered 1..n
	WidgetMaker robotFactory = new WidgetMaker(1, n);
	robotFactory.make();

	long totalTime = System.currentTimeMillis() - startTime;
	System.out.println("WidgetMaker: made " + n + " widgets in " + totalTime / 1000.0 + " seconds");
    }

}
