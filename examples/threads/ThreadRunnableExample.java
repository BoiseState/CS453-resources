
/**
 * Shows how to create threads by implementing Runnable interface.
 */
class RunnableElement implements Runnable
{
    private String name;

    public RunnableElement(String s) {
	name = s;
    }

    public String getName() {
	return name;
    }

    public void run() {
	for (int i = 0; i < 10; i++) {
	    System.out.println("This is the " + this.getName() + " thread.");
	}
    }
}

public class ThreadRunnableExample
{
    public static void main(String args[]) {
	RunnableElement g1 = new RunnableElement("water");
	RunnableElement g2 = new RunnableElement("fire");
	RunnableElement g3 = new RunnableElement("earth");
	RunnableElement g4 = new RunnableElement("air");
	RunnableElement g5 = new RunnableElement("void");

	new Thread(g1).start();
	new Thread(g2).start();
	new Thread(g3).start();
	new Thread(g4).start();
	new Thread(g5).start();
    }
}
