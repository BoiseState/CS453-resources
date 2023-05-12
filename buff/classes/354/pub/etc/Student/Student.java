public class Student extends Person {

    private String major;

    public Student(String name, int age, String major) {
        super(name,age);
        init(major);
    }

    private void init(String major) {
        this.major=major;
    }

    protected String string() { return super.string()+" "+major; }

    public String toString() { return string(); }

}
