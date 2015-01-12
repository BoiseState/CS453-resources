
import java.util.LinkedList;
import java.util.Enumeration;
import java.util.Iterator;
import java.awt.Color;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class LoadList {
	public static void main (String [] args) {
		try {
			FileInputStream fileIn = new FileInputStream("list.serial");
			ObjectInputStream in = new ObjectInputStream(fileIn);
			LinkedList list = (LinkedList) in.readObject();
			System.out.println(list.toString());
			Iterator e = list.iterator();
			while (e.hasNext()) {
				System.out.println((Color)e.next());
			}
		}
		catch (ClassNotFoundException e) {
			System.out.println(e);
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
		catch (IOException e) {
			System.out.println(e);
		}
	}
}	

