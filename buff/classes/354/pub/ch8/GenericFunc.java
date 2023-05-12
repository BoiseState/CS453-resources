// javac GenericFunc.java && java GenericFunc

public class GenericFunc {

    public static <Item> Item foo(Item item) {
	return item;
    }

    public static void main(String[] args) {
	String s="stuff";
	System.out.println(foo(s));
    }
	
}
