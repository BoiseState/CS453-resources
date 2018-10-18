
/**
 * Creates two threads that simulate "playing" ping-pong in a synchronized
 * manner using wait/notify methods.
 * 
 * @author amit
 */

public class SynchronizedPingPong
{
    public static void main(String[] args) {
	if (args.length != 1) {
	    System.err.println("Usage: java SynchronizedPingPong <delay>");
	    System.exit(1);
	}
	int delay = Integer.parseInt(args[0]);
	Ping ping = new Ping("ping", delay);
	Pong pong = new Pong("PONG", delay);
	ping.setPong(pong);
	pong.setPing(ping);

	new Thread(ping).start();
	new Thread(pong).start();
    }
}

class Ping implements Runnable
{
    private String word; // what word to print
    private int delay; // how long to pause (in milliseconds)
    private Pong pong;


    public Ping(String whatToSay, int delayTime) {
	word = whatToSay;
	delay = delayTime;
    }


    public void setPong(Pong pong) {
	this.pong = pong;
    }


    public void run() {
	try {
	    for (;;) {
		System.out.println(word + " ");
		Thread.sleep(delay); // wait until next time
		synchronized (pong) {
		    pong.notify();
		}
		synchronized (this) {
		    wait();
		}
	    }
	} catch (InterruptedException e) {
	    System.err.println(e);
	    return; // end this thread
	}
    }
}

class Pong implements Runnable
{
    private String word; // what word to print
    private int delay; // how long to pause, in milliseconds
    private Ping ping;


    public Pong(String whatToSay, int delayTime) {
	word = whatToSay;
	delay = delayTime;
    }


    public void setPing(Ping ping) {
	this.ping = ping;
    }


    public void run() {
	try {
	    for (;;) {
		synchronized (this) {
		    wait();
		}
		System.out.println(word + " ");
		Thread.sleep(delay); // wait until next time
		synchronized (ping) {
		    ping.notify();
		}
	    }
	} catch (InterruptedException e) {
	    System.err.println(e);
	    return; // end this thread
	}
    }
}
