package it.unisa.country;

import org.junit.Assert;
import org.junit.Test;

public class DataSetTest {
    @Test
    public void testMinimum() {
        DataSet data = new DataSet();
        data.add(new Country("country1", 500));
        data.add(new Country("country2", 250));
        data.add(new Country("country3", 750));
        Assert.assertEquals("country2", data.getMinimum().getName());
    }

    @Test
    public void testMaximum() {
        DataSet data = new DataSet();
        data.add(new Country("country1", 500));
        data.add(new Country("country2", 250));
        data.add(new Country("country3", 750));
        Assert.assertEquals("country3", data.getMaximum().getName());
    }
}