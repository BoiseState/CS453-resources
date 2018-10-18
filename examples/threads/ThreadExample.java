
/**
 * Basic example of creating and running threads.
 * 
 * @author amit
 */
class Element extends Thread
{

    public Element(String s) {
	super(s);
    }


    /*
     * (non-Javadoc)
     * 
     * @see java.lang.Thread#run()
     */
    public void run() {
	for (int i = 0; i < 100; i++) {
	    System.out.println("This is the " + this.getName() + " thread.");
	    /* this.yield(); */
	}
    }
}

public class ThreadExample
{
    public static void main(String args[]) {
	new Element("water").start();
	new Element("fire").start();
	new Element("earth").start();
	new Element("air").start();
	new Element("void").start();
    }
}
