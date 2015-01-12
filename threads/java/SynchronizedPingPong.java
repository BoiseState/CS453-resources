
/**
	An example of synchronization in Java. Creates two threads that play
	ping-pong. The threads synchronize using semaphore objects.
*/

public class SynchronizedPingPong 
{
	public static void main(String[] args) 
	{
		Ping ping = new Ping("ping", 10);
		Pong pong = new Pong("pong", 10);
		ping.setPong(pong);
		pong.setPing(ping);
		
		new Thread(ping).start(); 
		new Thread(pong).start();
	}
}


class Ping implements Runnable 
{
	String word; // what word to print
	int delay;	 // how long to pause (in milliseconds)
	Pong pong;

	Ping(String whatToSay, int delayTime) {
		word = whatToSay;
		delay = delayTime;
	}
	
	public void setPong(Pong pong) { this.pong = pong; }

	public void run() {
		try {
			for (;;) {
				System.out.println(word+" ");
				Thread.sleep(delay); //wait until next time
				synchronized(pong) { pong.notify();} 
				synchronized(this) { wait(); };
			}
		} catch (InterruptedException e) {
			return;
		}
	}
}

	

class Pong implements Runnable 
{
	String word; // what word to print
	int delay;	 // how long to pause
	Ping ping;


	Pong(String whatToSay, int delayTime) {
		word = whatToSay;
		delay = delayTime;
	}

	public void setPing(Ping ping) { this.ping = ping; }
	
	public void run() {
		try {
			for (;;) {
				synchronized(this) {wait();}
				System.out.println(word+" ");
				Thread.sleep(delay); //wait until next time
				synchronized(ping) {ping.notify();}
			}
		} catch (InterruptedException e) {
			return; 	//end this thread
		}
	}
}

