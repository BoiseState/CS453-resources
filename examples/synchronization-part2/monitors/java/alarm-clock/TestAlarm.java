
/**
	Watch the behavior by running it for 3 threads.

	java TestAlarm 3 

	To check, redirect output to a file.

	java TestAlarm 3 > log

	Then sort it to check the results:

	cat log | sort --key=1,2 --stable | less

*/
public class TestAlarm
{
	public static void main (String[] args)
	{
		if (args.length == 0) {
			System.err.println("Usage: java TestAlarm <n>");
			System.exit(1);
		}
		int n = Integer.parseInt(args[0]);

		AlarmMonitor monitor = new AlarmMonitor();
		for (int i=0; i<n; i++)
		{
			new Turtle(i,monitor).start();
		}
	}

}
