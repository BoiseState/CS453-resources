import java.io.IOException;

/**
 * Demonstrates how to create child processes and wait for them to finish.
 * 
 * @author amit
 */
public class MaxPrcoesses
{
    private static final int NUM_PROCESS = 50000;


    public static void main(String[] args) throws IOException, InterruptedException {
	Process[] child = new Process[NUM_PROCESS];
	for (int i = 0; i < NUM_PROCESS; i++) {
	    child[i] = new ProcessBuilder("sleep", "20").start();
	    System.out.println("Child process " + i + " created");
	}
	System.out.println();

	for (int i = 0; i < NUM_PROCESS; i++) {
	    child[i].waitFor();
	    System.out.println("Child process " + i + " finished");
	}
	System.out.println();
    }
}