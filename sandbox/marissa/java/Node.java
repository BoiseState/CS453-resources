public class Node<T extends Comparable<T>>
{
	private Node<T> next;
	private T element;

	public Node()
	{
		this.next = null;
		this.element = null;
	}

	public Node(T element)
	{
		this.next = null;
		this.element = element;
	}

	public void setNext(Node<T> next)
	{
		this.next = next;
	}

	public Node<T> getNext()
	{
		return this.next;
	}

	public T getElement()
	{
		return this.element;
	}

	public void setElement(T element)
	{
		this.element = element;
	}

	public String toString()
	{
		return element.toString();
	}
}
