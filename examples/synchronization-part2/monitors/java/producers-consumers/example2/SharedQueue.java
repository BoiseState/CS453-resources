
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Vector;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.Timer;


/**
 * A shared queue that displays itself graphically.
 * @author amit
 *
 */
public class SharedQueue extends JFrame
{
	static final long serialVersionUID = 4341937266846499391L;
	private Vector<String> messages = new Vector<String>();
	Timer timer;
	public int size;
	JProgressBar progressBar;
	int i = 0;

	/**
	 * Constructor
	 * @param size  maximum size of the queue
	 */
	public SharedQueue(int size)
	{
		super("new queue");
		addWindowListener(new ExitListener());
		this.size = size;
		progressBar = new JProgressBar();
		progressBar.setMinimum(0);
		progressBar.setMaximum(size);
		progressBar.setValue(0);
		JPanel contentPane = new JPanel();
		contentPane.add(progressBar);
		contentPane.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		setContentPane(contentPane);
	}

	/**
	 * 
	 * Put a message into the queue
	 * @param msg
	 * @throws InterruptedException
	 */
	public synchronized void putMessage(String msg) throws InterruptedException
	{
		while (messages.size() == size)
			wait();
		messages.addElement(msg);
		progressBar.setValue(messages.size());
		notifyAll(); // for multiple consumers
	}

	/**
	 * Get a message from the queue
	 * @return
	 * @throws InterruptedException
	 */
	public synchronized String getMessage() throws InterruptedException
	{
		while (messages.size() == 0)
			wait();
		String message = (String) messages.firstElement();
		messages.removeElement(message);
		progressBar.setValue(messages.size());
		notifyAll(); // no need to change for a single producer
		return message;
	}
}


class ExitListener extends WindowAdapter
{
	public void windowClosing(WindowEvent event)
	{
		System.exit(0);
	}
}
