public class Box {

    private Object contents;

    public synchronized Object get() {
        while (contents==null)
            try { wait(); } catch (Exception e) {}
        Object o=contents;
        contents=null;
        notify();
        return o;
    }

    public synchronized void put(Object o) {
        while (contents!=null)
            try { wait(); } catch (Exception e) {}
        contents=o;
        notify();
    }

}
