public class TryBox extends Thread {

    private Box _box;
    private String _msg;

    public TryBox(Box box, String msg) {
        _box=box;
        _msg=msg;
    }

    public void run() {
        _box.put(_msg);
        System.out.println(_box.get());
    }

    public static void main(String[] args) {
        Box box=new Box();
        TryBox t1=new TryBox(box,"t1");
        TryBox t2=new TryBox(box,"t2");
        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (Exception e) {}
    }

}
