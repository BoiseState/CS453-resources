public abstract class Account {

    protected String number;
    protected Customer customer;
    protected double balance;

    public abstract void accrue(double rate);

    public double balance() {
	return balance;
    }

    public void deposit(double amount) {
	balance+=amount;
    }

    public void withdraw(double amount) {
	balance-=amount;
    }

    public String toString() {
	return number+":"+customer+":"+balance;
    }

}
