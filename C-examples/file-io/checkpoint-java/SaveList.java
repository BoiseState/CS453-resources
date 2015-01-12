
import java.util.LinkedList;
import java.awt.Color;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class SaveList {
	public static void main (String [] args) {
		LinkedList<Color> list = new LinkedList<Color>(); 
		list.addFirst(Color.red);
		list.addFirst(Color.black);
		list.addFirst(new Color(100, 100, 100));
		// LinkedList implements the serializable interface so we can
		// serialize it
		try {
			FileOutputStream fileout = new FileOutputStream("list.serial");
			ObjectOutputStream out = new ObjectOutputStream(fileout);
			out.writeObject(list);
		}
		catch (Exception e) {
			System.out.println(e);
		}
	}
}	



