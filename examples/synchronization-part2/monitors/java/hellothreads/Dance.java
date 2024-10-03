
/**
 * Basic example of creating and running threads.
 * 
 * @author amit
 */
public class Dance extends Thread
{
    public Dance(String name)
    {
	super(name); // pass the name along to the superclass
    }


    /**
     * This is the main for the thread. Do the dance!
     */
    public void run()
    {
	for (int i = 0; i < 20; i++) {
	    System.out.println("This is the " + this.getName() + " thread.");
	}
    }


    /**
     * Create five threads to run simultaneously to create a dance flash mob.
     * 
     * @param args
     *                 No command line arguments are used.
     */
    public static void main(String args[])
    {
	new Dance("Dab").start();
	new Dance("Wobble").start();
	new Dance("Shuffle").start();
	new Dance("Sprinkler").start();
	new Dance("Fik-shun").start();
    }
}
