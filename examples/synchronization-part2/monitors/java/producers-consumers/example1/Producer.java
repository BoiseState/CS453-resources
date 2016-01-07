import java.util.Vector;

public class Producer implements Runnable
{
    private Thread producerThread;
    private SharedQueue Q;
    private int id;
    private int sleep_time;
	private boolean stopFlag = false;

    public Producer(int id, SharedQueue Q, int time){
      this.Q = Q;
      this.id = id;
      this.sleep_time = time;

    }  
    
    public void run() {
		try {
			while ( !stopFlag ) {
				String msg = new java.util.Date().toString() ;
				Q.putMessage(msg);
				System.out.println("Producer " + id + " put message: "+msg);
				// try commenting out the sleep
				producerThread.sleep( sleep_time );
			}
		} catch( InterruptedException e ) { }
    }

    public void start() {
    		if (producerThread == null) {
			producerThread = new Thread(this);
			producerThread.start();
		}
    }

    public void stop(){
    		if (producerThread != null) {
			stopFlag = true;
			producerThread = null;
		}
    }

}
