
import java.util.*;
import java.text.*;

public class Turtle extends Thread
{
	private AlarmMonitor monitor;
	private Random generator = new Random();
	private final int RANGE = 3;
	private int id;

	public Turtle(int id, AlarmMonitor monitor)
	{
		this.monitor = monitor;
		this.id = id;
	}

	public void run()
	{
		while (true)
		{
			int delay = generator.nextInt(RANGE)+1;
			String time = DateFormat.getTimeInstance(DateFormat.MEDIUM).format(new Date());
			System.out.println("Turtle: "+id+" setting alarm for " + delay 
			                  +" seconds at "+ time);
			monitor.setAlarm(delay);
			time = DateFormat.getTimeInstance().format(new Date());
			System.out.println("Turtle: "+id+" waking from alarm at "+ time);

		}
	}


}
