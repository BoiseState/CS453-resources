// javac Box.java && java Box

public class Box<Item> {

    private Item item;

    public void put(Item item) {
	this.item=item;
    }

    public Item get() {
	return item;
    }

    public static void main(String[] args) {
	Box<String> box=new Box<String>();
	String s="stuff";
	box.put(s);
	System.out.println(box.get());
    }
	
}
