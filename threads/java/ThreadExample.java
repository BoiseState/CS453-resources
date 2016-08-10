/**
 * An example of thread creation in Java.
 */

class Water extends Thread {
    Water(String s) {super(s);} //constructor

    public void run() {
        for (int i = 0; i < 50000; i++) {
            System.out.println("This is the " + this.getName() + " thread.");
        }
    }
}


public class ThreadExample {
    public static void main (String args[]) {
        new Water("Tap Water").start();
        new Water("Filtered Water").start();
        new Water("Spring Water").start();
    }
}
        
