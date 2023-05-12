class Box<T> {
    private T val;
    public Box(T v) { val=v; }
    public void f() { System.out.println(val); }
}

public class Generic {

    public static void main(String[] args) {
        Box ibox = new Box<Integer>(123);
        Box dbox = new Box<Double>(1.23);
        ibox.f();
        dbox.f();
    }

}
