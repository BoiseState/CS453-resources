class C {
  public void f() { System.out.println("C"); }
}

class C1 extends C {
  public void f() { System.out.println("C1"); }
}

class C2 extends C {
  public void f() { System.out.println("C2"); }
}

public class Polymorphic {

  public static void main(String[] args) {
    C c;
    c=new C();  c.f();
    c=new C1(); c.f();
    c=new C2(); c.f();
  }

}
