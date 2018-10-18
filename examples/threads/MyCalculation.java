
public class MyCalculation implements Runnable
{
    private int[] values;


    /**
     * @param n
     *            How many values to calculate.
     */
    public MyCalculation(int n) {
	values = new int[n];
    }


    /*
     * (non-Javadoc)
     * 
     * @see java.lang.Runnable#run()
     */
    public void run() {
	for (int i = 0; i < values.length; i++)
	    values[i] = i * i;
    }


    /**
     * @return the array of calculated values
     */
    public int[] getValues() {
	return values;
    }
}
