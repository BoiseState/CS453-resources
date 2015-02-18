public class Job implements Comparable<Job>
{
	private int id;
	private String name;
	private String[] args;

	public Job(int id, String name, String[] args)
	{
		this.id = id;
		this.name = name;
		this.args = args;
	}

	public int compareTo(Job other)
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
		StringBuilder builder = new StringBuilder();
		builder.append(id + " " + name + " ");
		if(args != null)
		{
			for(String arg : args)
				builder.append("[" + arg + "]");
		}
		return builder.toString();
	}
}
