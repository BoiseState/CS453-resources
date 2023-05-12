public class Overloaded {

    private static void f(int i) {
        System.out.println("int: " + i);
    }

    private static void f(double d) {
        System.out.println("double: " + d);
    }

    public static void main(String[] args) {
        f(123);
        f(1.23);
    }

}
