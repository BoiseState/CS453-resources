import java.io.IOException;

/**
 * Demonstrates how to create child processes and wait for them to finish. Run
 * the program and then from a console check the processes created using the
 * following command:
 * 
 * ps augx | grep sleep
 * 
 * @author amit
 */
public class ProcessExample
{
    private static final int NUM_PROCESS = 5;


    public static void main(String[] args) throws IOException, InterruptedException {
	Process[] child = new Process[NUM_PROCESS];
	for (int i = 0; i < NUM_PROCESS; i++) {
	    child[i] = new ProcessBuilder("sleep", "30").start();
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