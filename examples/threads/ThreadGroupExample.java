
/**
 * Shows how to create and use a thread group
 * 
 * @author amit
 */
public class ThreadGroupExample
{
    public static void main(String args[]) {
	ThreadGroup myTaskGroup = new ThreadGroup("My Task Group");

	Thread thread1 = new Thread(myTaskGroup, new MyThread(), "one");
	Thread thread2 = new Thread(myTaskGroup, new MyThread(), "two");
	Thread thread3 = new Thread(myTaskGroup, new MyThread(), "three");

	thread1.start();
	thread2.start();
	thread3.start();

	System.out.println("group has " + myTaskGroup.activeCount() + " threads");

	Thread[] tasks = new Thread[myTaskGroup.activeCount()];
	myTaskGroup.enumerate(tasks);
	for (int i = 0; i < tasks.length; i++)
	    System.out.println(tasks[i].toString());

	System.out.println(myTaskGroup.toString());

	myTaskGroup.stop(); // stop all threads in the group
	// JVM should now quit
    }
}

class MyThread implements Runnable
{
    public void run() {
	while (true) {
	    try {
		Thread.sleep(10000);
	    } catch (InterruptedException e) {
		System.err.println(e);
	    }
	}
    }
}
