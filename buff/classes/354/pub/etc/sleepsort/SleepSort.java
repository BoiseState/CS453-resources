// javac SleepSort.java && java SleepSort

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ArrayBlockingQueue;

public class SleepSort extends Thread {

    private static void print(int[] a) {
        String sep="[";
        for (int i: a) {
            System.out.print(sep+i);
            sep=",";
        }
        System.out.println("]");
    }

    private static void sleep(BlockingQueue<Integer> q, int i) {
        try {
            Thread.sleep(i*1000);
            q.put(i);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private BlockingQueue<Integer> q;
    private int i;

    public SleepSort(BlockingQueue<Integer> q, int i) {
        this.q=q;
        this.i=i;
    }

    public void run() { sleep(q,i); }

    public static void main(String[] args) {
        try {
            BlockingQueue<Integer> q=new ArrayBlockingQueue<Integer>(1);
            int[] seq={5,6,1,8,3,7};
            for (int i: seq)
                new SleepSort(q,i).start();
            for (int i=0; i<seq.length; i++)
                seq[i]=q.take();
            print(seq);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
