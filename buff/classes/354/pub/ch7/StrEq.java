// javac StrEq.java && java StrEq

public class StrEq {

    public static void main(String[] args) {
	String s1="hello world";
	String s2="hello world";
	String s3="hello"+" "+"world";
	String w="world";
	String s4="hello"+" "+w;
	String s5=new String("hello world");
	String s6=new String(s1);
	System.out.println(s1==s2 ? "s1 eq s2" : "s1 neq s2");
	System.out.println(s1==s3 ? "s1 eq s3" : "s1 neq s3");
	System.out.println(s1==s4 ? "s1 eq s4" : "s1 neq s4");
	System.out.println(s1==s5 ? "s1 eq s5" : "s1 neq s5");
	System.out.println(s1==s6 ? "s1 eq s6" : "s1 neq s6");
    }

}
