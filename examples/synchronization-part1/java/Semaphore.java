
/**
	A simple implementation of a semaphore object in Java.
*/


import java.io.*;


public class Semaphore {
  private int  count = 0;

  
public Semaphore(int i) {
  count = i;
}


public Semaphore() {
  count = 0;
}


public synchronized void init(int i) {
  count = i;
}


public synchronized void semDown() {
  boolean interrupted = false;
  while (count == 0) {
    try {wait();} 
    catch (InterruptedException ie) {interrupted=true;}
  }
  count--;
  if (interrupted) Thread.currentThread().interrupt();
}


public synchronized void semUp() {
  count++;
  notify();
}

}
