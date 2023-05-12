public class Args {

    public static int sum(int... seq) {
	int s=0;
	for (int i: seq)
	    s+=i;
	return s;
    }

    public static void main(String[] args) {
	System.out.println(sum(5,6,1,8,3,7));
    }

}
