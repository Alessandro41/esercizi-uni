package it.unisa.quiz;

public class DataSet {

    private double sum;
    private /* TODO */ minimum;
    private /* TODO */ maximum;
    private int count;

    public DataSet() {
        count = 0;
        sum = 0;
        minimum = null;
        maximum = null;
    }

    public double getAverage() {
        if (count == 0) return 0;
        else return sum / count;
    }

    public /* TODO */ getMaximum() {
        return maximum;
    }

    public /* TODO */ getMinimum() {
        return minimum;
    }

    public void add(/* TODO */ x) {
        /* TODO */
    }
}