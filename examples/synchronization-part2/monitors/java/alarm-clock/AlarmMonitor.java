
import java.util.*;

public class AlarmMonitor extends TimerTask
{
	private long now = 0;
	private Timer timer;

	public AlarmMonitor()
	{
		now = System.currentTimeMillis();
		timer = new Timer(true); //timer with a daemon thread
		timer.scheduleAtFixedRate(this, 1000, 1000); // every second after one second
	}

	public synchronized void setAlarm(long period)
	{
		period = period + now;
		while (now < period) 
		{
			try {wait();} catch (InterruptedException e) {System.err.println(e);}
		}
	}

	public synchronized void run()
	{
		now++;
		notifyAll();
	}
}

