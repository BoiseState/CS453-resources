public class Person {

    private String name;
    private int age;

    public Person(String name, int age) {
        init(name,age);
    }

    private void init(String name, int age) {
        this.name=name;
        this.age=age;
    }

    public String name() { return name; }

    protected String string() { return name()+" "+age; }

    public String toString() { return string(); }

}
