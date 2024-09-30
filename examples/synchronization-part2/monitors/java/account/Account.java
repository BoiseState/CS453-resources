
/**
 * A simple unprotected account class to demonstrate race conditions.
 * 
 * @author amit
 */
public class Account {
	protected double balance;

	public double getBalance()
	{
		return balance;
	}


	public void deposit(double amount)
	{
		balance += amount;
	}


	public void withdraw(double amount)
	{
		balance -= amount;
	}


	public Account() {
		balance = 0;
	}


	public String toString()
	{
		return String.format("balance = %lf ", balance);
	}
}
