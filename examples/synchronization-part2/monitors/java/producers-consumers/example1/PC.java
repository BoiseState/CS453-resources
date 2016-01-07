import java.util.Vector;

/**
	A general simulation of the Producers and Consumers problem.
	@author Larelise Kintz
	
	Minor changes by Amit Jain (for presenting in CS 453/552)
*/

class PC
{
  public static void main (String args[]){

    if (args.length != 5)
    {
    	System.out.println("Usage:  PC" + " <queue size> <#producers> <#consumers> <producer_sleep_time(millisecs)> <consumer_sleep_time(millisecs)>");
	System.exit(1);
    }
    int maxSize = Integer.parseInt(args[0]);
    int num_producers = Integer.parseInt(args[1]);
    int num_consumers = Integer.parseInt(args[2]);
    int prodSleep = Integer.parseInt(args[3]);
    int conSleep = Integer.parseInt(args[4]);
    
    System.out.println(maxSize);

    SharedQueue Q = new SharedQueue(maxSize);
    for (int i=0; i<num_producers; i++)
    	new Producer(i, Q, prodSleep).start();
    for (int i=0; i<num_consumers; i++)
    	new Consumer(i, Q, conSleep).start();
  }
}  
