
public class InterruptTest implements Runnable {

	public static void main( String [] args ) throws Exception {
		Thread sleepyThread = new Thread( new InterruptTest() );
		sleepyThread.setName("SleepyThread");
		sleepyThread.start();
        // now we two threads running, the main thread and the sleepy thread,
		// which goes to sleep after printing a message.

		Thread.sleep(500);// put main thread to sleep for a while
		sleepyThread.interrupt();// interrupt sleepyThread's beauty sleep
		Thread.sleep(500);// put main thread to sleep for a while
		sleepyThread.interrupt();// interrupt sleepyThread's beauty sleep
	}
	
	public void run() {
		Thread me = Thread.currentThread();
		while (true) {
			try {
				System.out.println(me.getName() + ": sleeping...");
				Thread.sleep(5*1000); // in millisecs
			} catch (InterruptedException e) {
				System.out.println(me.getName() +": argh! let me sleep #$@!");
			}
		}
	}
}
