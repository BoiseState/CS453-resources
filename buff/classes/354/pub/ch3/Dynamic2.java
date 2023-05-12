// javac Dynamic2.java && java Dynamic2

public class Dynamic2 {

    private static int i = 1;

    private static void f() {
        i = 2;
    }

    private static void g() {
        int i;
        f();
    }

    public static void main(String[] args) {
        System.out.println(i); // 1
        g();
        System.out.println(i); // 1
        f();
        System.out.println(i); // 2
    }

}
