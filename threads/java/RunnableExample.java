
	
class AnotherGrape implements Runnable 
{
	private String name;
    AnotherGrape(String s) {name = s;}
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
        AnotherGrape g1 = new AnotherGrape("merlot");
        AnotherGrape g2 = new AnotherGrape("pinot");
        AnotherGrape g3 = new AnotherGrape("cabernet");
		new Thread(g1).start();
		new Thread(g2).start();
		new Thread(g3).start();
    }
}
        
