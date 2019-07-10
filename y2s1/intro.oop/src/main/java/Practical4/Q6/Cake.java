package Practical4.Q6;

import java.util.concurrent.atomic.AtomicInteger;

public class Cake {
    private static AtomicInteger totalCakes = new AtomicInteger(0);
    int cakeNo = totalCakes.incrementAndGet();
    String flavor;
    double basePrice;

    public Cake() {
        this.flavor = "";
        this.basePrice = 0.0;
    }

    public Cake(String flavor, double basePrice) {
        this.flavor = flavor;
        this.basePrice = basePrice;
    }

    public static AtomicInteger getTotalCakes() {
        return totalCakes;
    }

    public int getCakeNo() {
        return cakeNo;
    }

    public String getFlavor() {
        return flavor;
    }

    public double getBasePrice() {
        return basePrice;
    }

    public void setFlavor(String flavor) {
        this.flavor = flavor;
    }

    public void setBasePrice(double basePrice) {
        this.basePrice = basePrice;
    }
}
