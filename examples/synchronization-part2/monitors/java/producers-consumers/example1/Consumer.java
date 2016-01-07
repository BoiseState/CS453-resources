import java.util.Vector;

public class Consumer implements Runnable
{
    private Thread consumerThread;
    private SharedQueue Q;
    private int id;
    private int sleep_time;
	private boolean stopFlag = false;
	
    public Consumer(int id, SharedQueue Q, int time) {
    	this.Q = Q;
	this.id = id;
	this.sleep_time = time;
    }
 
    public void run() {
		try {
			while ( !stopFlag ) {
				String message = Q.getMessage();
				System.out.println("Consumer " + id + " got message: " + message);
				consumerThread.sleep( sleep_time );
			}
		} catch( InterruptedException e ) { }
    }

    public void start(){
    		if (consumerThread == null){
			consumerThread = new Thread(this);
			consumerThread.start();
		}
    }

    public void stop(){
    		if (consumerThread != null){
			stopFlag = true;
			consumerThread = null;
		}
    }		
 
}
