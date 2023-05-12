import java.util.*;

public class Bank {

    private Set<Account> accounts=new HashSet<Account>();

    public void add(Account account) {
	accounts.add(account);
    }

    public void accrue(double rate) {
	for (Account account: accounts)
	    account.accrue(rate);
    }

    public String toString() {
	String r="";
	for (Account account: accounts)
	    r+=account+"\n";
	return r;
    }

    public static void main(String[] args) {
	Bank bank=new Bank();
	Customer c=new Customer("Ann");
	bank.add(new CheckingAccount("01001",c,100.00));
	bank.add(new SavingAccount("01002",c,200.00));
	bank.accrue(0.02);
	System.out.println(bank);
    }

}
