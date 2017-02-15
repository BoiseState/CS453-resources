
	
class AnotherWater implements Runnable 
{
	private String name;
    AnotherWater(String s) {name = s;}
	public String getName() {return name;}

    public void run() {
        for (int i=0; i<10000; i++) {
            System.out.println("This is the " + this.getName() + " thread.");
        }
    }
}


public class RunnableExample {
    public static void main (String args[]) 
	{
        AnotherWater g1 = new AnotherWater("Tap Water");
        AnotherWater g2 = new AnotherWater("Filtered Water");
        AnotherWater g3 = new AnotherWater("Spring Water");
		new Thread(g1).start();
		new Thread(g2).start();
		new Thread(g3).start();
    }
}
        
