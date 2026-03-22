import java.util.Random;
import java.util.Scanner;
import java.util.random.RandomGenerator;

public class Dice {

    public static void main(String[] args) {
        BankAccount playerAccount = new BankAccount(1000);
        BankAccount casinoAccount = new BankAccount(100000);
        int predictedValue, actualValue;
        double bet;
        String choice = "no";
        Scanner in = new Scanner(System.in);

        while (true) {
            System.out.println("current balance:" + playerAccount.getBalance() + "$");

            System.out.print("Insert prediction: ");
            predictedValue = in.nextInt();
            if (predictedValue > 6 || predictedValue < 0) {
                System.out.println("Insert valid prediction\nretry\n\n");
                continue;
            }

            System.out.print("Insert bet: ");
            bet = in.nextDouble();
            if (bet > playerAccount.getBalance() || bet <= 0) {
                System.out.println("your balance is:" + playerAccount.getBalance() + "\nretry\n\n");
                continue;
            }

            if (bet > 5 * casinoAccount.getBalance()) {
                System.out.println("bax bet is: " + casinoAccount.getBalance()/5 + "$\nretry\n\n");
                continue;
            }

            Random generator = new Random();
            actualValue = 1 + generator.nextInt(6);
            System.out.println("Dice roll: " + actualValue);

            if (predictedValue == actualValue) {
                System.out.println("You won " + bet * 5 + "$");
                casinoAccount.withdraw(bet * 5);
                playerAccount.deposit(bet * 5);
            } else {
                System.out.println("You lost");
                playerAccount.withdraw(bet);
                casinoAccount.deposit(bet);
            }

            if (playerAccount.getBalance() <= 0) {
                System.out.println("ran out of money");
                break;
            }

            System.out.println("insert \"si\" to continue");
            in.nextLine();
            String answer = in.nextLine();
            if (answer.compareTo("si") != 0)
                break;
        }

        System.out.println("Il tuo saldo è " + playerAccount.getBalance());
    }

}