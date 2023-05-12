// javac BoxConstrained.java && java BoxConstrained

public class BoxConstrained
    <Item extends Constraint<Item>>  {

    private Item item;

    public void put(Item item) {
	this.item=item;
    }

    public Item get() {
	return item.foo();	// Item is required to provide foo()
    }

    public static void main(String[] args) {
	String s="stuff";
	Value<String> v=
	    new Value<String>(s);
	BoxConstrained<Value<String>> box=
	    new BoxConstrained<Value<String>>();
	box.put(v);
	System.out.println(box.get());
    }
	
}
