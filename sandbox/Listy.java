import java.util.*;

/**
 * @brief Example code to show a similar list in Java
 */
public class Listy{

	public static void main(String foo[]){
		//struct list* mylist = createlist(Bar.equals, Bar.toString, Bar.freeObject);
		List<Bar> mylist = new LinkedList<Bar>();
		//struct object* o = createObject(/*stuff*/);
		Bar b = new Bar("1");
		//addFront(mylist, b);
		mylist.add(b);
		b = new Bar("2");
		//addFront(mylist, b);
		mylist.add(b);

		for(Bar b1: mylist){
			System.out.println(b1);
		}

		List<Foo> mylist1 = new LinkedList<Foo>();
		Foo f = new Foo("1");
		//addFront(mylist, f);
		mylist1.add(f);
		f = new Foo("2");
		mylist1.add(f);

		for(Foo b1: mylist1){
			System.out.println(b1);
		}
	}


}
