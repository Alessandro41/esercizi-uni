import java.util.ArrayList;
import java.util.List;

public class Bank {

    private final List<BankAccount> accounts;

    public Bank() {
        this.accounts = new ArrayList<>();
    }

    public void addAccount(double initialBalance, String customerName) {
        accounts.add(new BankAccount(initialBalance, customerName));
    }

    public BankAccount find(int accountNumber) {
        for (BankAccount ba : this.accounts) {
            if (ba.getAccountNumber() == accountNumber)
                return ba;
        }
        return null;
    }

    public void deposit(int accountNumber, double amount) {
        for (BankAccount ba : this.accounts) {
            if (ba.getAccountNumber() == accountNumber)
                ba.deposit(amount);
        }
    }

    public void withdraw(int accountNumber, double amount) {
        for (BankAccount ba : this.accounts) {
            if (ba.getAccountNumber() == accountNumber)
                ba.withdraw(amount);
        }
    }

    public double getBalance(int accountNumber) {
        for (BankAccount ba : this.accounts) {
            if (ba.getAccountNumber() == accountNumber)
                return ba.getBalance();
        }
        return -1;
    }

    public void transfer(int fromAccountNumber, int toAccountNumber, double amount) {
        BankAccount fromAccount = null, toAccount = null;
        boolean ctrl1 = false, ctrl2 = false;

        for (BankAccount ba : this.accounts) {
            if (ba.getAccountNumber() == fromAccountNumber) {
                fromAccount = ba;
                ctrl1 = true;
            }
            if (ba.getAccountNumber() == toAccountNumber) {
                toAccount = ba;
                ctrl2 = true;
            }

            if (ctrl1 && ctrl2) {
                fromAccount.withdraw(amount);
                toAccount.deposit(amount);
                break;
            }
        }
    }
}