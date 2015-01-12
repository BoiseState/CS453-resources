// An example of threads in Java
//
// ch2/threadsExample.java

	
class Grape extends Thread {
    Grape(String s) {super(s);} //constructor

    public void run() {
        for (int i=0; i<50000; i++) {
            System.out.println("This is the " + this.getName() + " thread.");
            /*this.yield();*/
        }
    }
}


public class ThreadExample {
    public static void main (String args[]) {
        new Grape("merlot").start();
        new Grape("pinot").start();
        new Grape("cabernet").start();
    }
}
        
