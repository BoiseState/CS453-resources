// C# OO sum program

public class Sum {

    private int s;

    public Sum() {
	init();
    }

    public void init() {
	s=0;
    }

    public int sum(int[] seq) {
	foreach (int v in seq)
	    s+=v;
	return s;
    }

    public static void Main() {
	int[] seq=new int[] {5,6,1,8,3,7};
	Sum sum=new Sum();
	System.Console.WriteLine(sum.sum(seq));
    }

}
