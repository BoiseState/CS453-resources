// javac Cast.java && java Cast

import java.util.*;

public class Cast {

    public static void main(String[] args) {
	Stack s=new Stack();	// stack of Object
	s.push("Hi!");
	System.out.println(s.peek());
	System.out.println((String)s.peek());
	System.out.println((Integer)s.peek());
    }

}
