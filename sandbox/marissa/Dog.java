public class Dog implements Comparable<Dog>
{
	private int id;
	private String name;

	public Dog(int id, String name)
	{
		this.id = id;
		this.name = name;
	}

	public int compareTo(Dog other)
	{
		if(id < other.id)
			return -1;
		else if (id > other.id)
			return 1;
		else
			return 0;
	}

	public String toString()
	{
		return id + " " + name;
	}
}
