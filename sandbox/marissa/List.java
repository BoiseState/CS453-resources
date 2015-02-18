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
			System.out.println(node.getNext());
		}
		size++;
	}

	public Node<T> searchList(T element)
	{
		if(head == null) return null;
		if(element == null) return null;
		Node<T> curr = head;
		while(curr != null)
		{
			if(curr.getElement().compareTo(element) == 0)
				return curr;
			curr = curr.getNext();
		}
		return null;

	}

	public void printList()
	{
		Node<T> curr = head;
		while(curr != null)
		{
			System.out.printf("%s --> ", curr);
			curr = curr.getNext();
		}
	}
}
