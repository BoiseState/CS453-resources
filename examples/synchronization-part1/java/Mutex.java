//              Extensions/Mutex.java

/*
  Pthreads style mutexes.  Not recursive.
  */


import java.io.*;


public class Mutex extends Object
{
  private Thread  owner = null;

  
public String toString() {
  String name;

  if (owner == null) 
    name = "null";
  else
    name = owner.getName();

  return ("<" + super.toString() + "owner:" + name +">");
}
  

  // Note that if we are interrupted, we will simply resend that
  // interrupt to ourselves AFTER we've locked the mutex.  The caller
  // code will have to deal with the interrupt.

public synchronized void lock() {
  boolean   interrupted = false;

  while (owner != null) {
    try {wait();} 
    catch (InterruptedException ie) {interrupted=true;}
  }
  owner = Thread.currentThread();
  if (interrupted) Thread.currentThread().interrupt();
}

  
public synchronized void unlock() {
  if (!owner.equals(Thread.currentThread()))
    throw new IllegalMonitorStateException("Not owner");

  owner = null;
  notify();
}

}
