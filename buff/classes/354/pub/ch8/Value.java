public class Value<Item>
    implements Constraint<Value<Item>> {

    private Item item;

    public Value(Item item) {
	this.item=item;
    }

    public Value<Item> foo() {
	return this;		// do something foo-ish
    }

    public String toString() {
	return item.toString();
    }

}
