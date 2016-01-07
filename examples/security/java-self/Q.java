
import java.io.*;

public class Q
{
	public static void main(String [] argv)
	throws IOException
	{
		FileReader fin = new FileReader(argv[0]);

		// skip over the class header
		int next = fin.read();
		while ((char)next != '{')
			next = fin.read();


		// produce character array version of the rest of the class
		StringBuffer result = new StringBuffer("static char [] s = {");
		next = fin.read();
		while (next != -1)
		{
			char ch = (char) next;
			if (!Character.isISOControl(ch)) 
				result.append("'"+ch+"'"+",");

			next = fin.read();
		}
		result.deleteCharAt(result.length()-1);
		result.append("};");
		System.out.println(result.toString());
	}
}
