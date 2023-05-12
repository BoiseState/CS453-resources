public class OO {

    public static void main(String[] args) {
        Person pp=new Person("Ann",21);
        Student ss=new Student("Bob",22,"cs");
        Person ps=new Student("Carla",23,"math");
        System.out.println("pp.name() => "+pp.name());
        System.out.println("ss.name() => "+ss.name());
        System.out.println("pp.toString() => "+pp);
        System.out.println("ss.toString() => "+ss);
        System.out.println("ps.name() => "+ps.name());
        System.out.println("ps.toString() => "+ps);
    }

}
