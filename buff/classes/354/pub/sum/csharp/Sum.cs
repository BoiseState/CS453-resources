// C# sum program

public class Sum {

    public static int sum(int[] seq) {
	int s=0;
	foreach (int v in seq)
	    s+=v;
	return s;
    }

    public static void Main() {
	int[] seq=new int[] {5,6,1,8,3,7};
	System.Console.WriteLine(sum(seq));
    }

}
