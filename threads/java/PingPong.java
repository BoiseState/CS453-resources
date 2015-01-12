
class PingPong extends Thread {
	String word; // what word to print
	int delay;	 // how long to pause

	PingPong(String whatToSay, int delayTime) {
		word = whatToSay;
		delay = delayTime;
	}
	
	public void run() {
		try {
			for (;;) {
				System.out.println(word+" ");
				sleep(delay); //wait until next time
			}
		} catch (InterruptedException e) {
			return; 	//end this thread
		}
	}

	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Usage: java PingPong <delay>");
			System.exit(1);
		}
		int delay = Integer.parseInt(args[0]);
		new PingPong("ping", delay).start();  //in millisecs
		new PingPong("PONG", delay).start(); //in millisecs
	}
}
	
