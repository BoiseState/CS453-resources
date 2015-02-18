public class List<T extends Comparable<T>>
{
	private int size;
	private Node<T> head;

	public List()
	{
		size = 0;
		head = null;
	}

	/**
	 * Adds element to head of list.
	 */
	public void addAtFront(T element)
	{
		if(element == null)
			return;
		if(head == null) {
			head = new Node<T>(element);
		} else {
			Node<T> node = new Node<T>(element);
			node.setNext(head);
			head = node;
		}
		size++;
	}

	public void reverseList()
	{
		Node<T> front = null;
		Node<T> curr = head;
		while(curr != null)
		{
			Node<T> temp = curr;
			curr = curr.getNext();
			temp.setNext(front);
			front = temp;
		}
		head = front;
	}

	public void printList()
	{
		Node<T> curr = head;
		while(curr != null)
		{
			System.out.printf("%s --> ", curr);
			curr = curr.getNext();
		}
		System.out.println("\n");
	}
}
