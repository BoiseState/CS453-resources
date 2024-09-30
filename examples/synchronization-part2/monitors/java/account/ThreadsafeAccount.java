
/**
 * Shows how to synchronize base class by using synchronized keyword
 * while overriding the methods from the base class.
 * 
 * @author amit
 */
public class ThreadsafeAccount extends Account
{
	public synchronized void deposit(double amount) 
	{ 
		super.deposit(amount);
	}

	public synchronized void withdraw(double amount) 
	{ 
		super.withdraw(amount);
	}
}
