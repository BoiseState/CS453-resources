import java.util.Timer;
import java.util.TimerTask;

/**
 * Demonstrate a alarm clock monitor that uses wait and notify.
 * @author amit
 */
public class AlarmMonitor extends TimerTask 
{
	private long now = 0;
	private Timer timer;

	public AlarmMonitor() 
	{
		now = System.currentTimeMillis();
		timer = new Timer(true); // timer with a daemon thread
		timer.scheduleAtFixedRate(this, 1000, 1000); // every second after one second
	}


	public synchronized void setAlarm(long period)
	{
		period = period + now;
		while (now < period) {
			try {
				wait();
			} catch (InterruptedException e) {
				System.err.println(e);
			}
		}
	}


	/**
	 * Simulates the system clock.
	 */
	public synchronized void run()
	{
		now++;
		notifyAll();
	}
}
