// Threads Example 2.
// See how many threads can be created,
// or, how big a quagmire we can create.
//
// ch2/MaxThreads.java
//
// Amit Jain.  amit@cs.boisestate.edu


public class MaxThreads {
	final static int MAX = 50000;
    public static void  main (String args[]) 
	throws InterruptedException
	{
        for(int i=0; i<MAX; i++) {
            Integer I = new Integer(i);
            new nuts(I.toString()).start();
        }
    }
}


class nuts extends Thread {
    nuts(String s) {super(s);} //constructor

    public void run() 
	{
        System.out.println("Thread number " + this.getName());
        /*System.out.flush();*/
		try {
			Thread.sleep(20000); //in millisecs
		} catch (InterruptedException e) {
			System.err.println(e);
		}
    }
}
