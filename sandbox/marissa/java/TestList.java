public class TestList
{
	public static void main(String[] args)
	{
		List<Dog> dogList = new List<Dog>();
		dogList.addAtFront(new Dog(0, "Fido"));
		dogList.addAtFront(new Dog(1, "George"));

		dogList.printList();

		dogList.reverseList();
		dogList.printList();

		List<Job> jobList = new List<Job>();
		jobList.addAtFront(new Job(0, "ls", null));
		jobList.addAtFront(new Job(1, "cd", new String[] {"~"}));

		Node<Job> found = jobList.searchList(new Job(0, null, null));
		if(found != null)
			System.out.println("Found it! (" + found + ")");
		else
			System.out.println("Not found.");
		jobList.printList();
	}
}
