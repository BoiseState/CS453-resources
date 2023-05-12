interface F { int f(); }

public class Closure {

    public F closure(final int i) {
	return new F() {
	    public int f() { return i; }
	};			// inner class
    }

    public static void main(String[] args) {
	F f=new Closure().closure(123);
	System.out.println(f.f());
    }

}
