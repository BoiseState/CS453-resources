
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
