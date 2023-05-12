// javac Dynamic1.java && java Dynamic1

public class Dynamic1 {

    private static int i = 1;

    private static void f() {
        System.out.println(i); // 1, 2
    }

    private static void g() {
        int i = 2;
        f();
    }

    public static void main(String[] args) {
        f();
        g();
    }

}
