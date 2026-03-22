import java.util.ArrayList;
import java.util.List;

public class Purse {

    /* TODO */

    private final List<Coin> coins;

    public Purse() {
        coins = new ArrayList<>();
    }

    public void add(Coin coin) {
        coins.add(coin);
    }

    public boolean find(Coin coin) {
        for (int i = 0; i < coins.size(); i++) {

        }
    }

    public int count(Coin coin) {
        /* TODO */
    }

    public Coin getMinimum() {
        /* TODO */
    }

    public Coin getMaximum() {
        /* TODO */
    }

    public double getTotal() {
        double total = 0;
        for (int i = 0; i < coins.size(); i++){
            Coin aCoin = coins.get(i);
            total = total + aCoin.getValue();
        }
        return total;
    }

    public void remove(Coin coin) {
        /* TODO */
    }

    public boolean hasCoin(Coin coin) {
        /* TODO */
    }

    @Override
    public String toString() {
        /* TODO */
    }

    @Override
    public boolean equals(Object o) {
        /* TODO */
    }
}