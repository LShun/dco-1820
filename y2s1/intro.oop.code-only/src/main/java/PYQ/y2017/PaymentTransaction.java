package PYQ.y2017;

public class PaymentTransaction implements Discount {
    private double totalPurchase;

    @Override
    public double calTotalDisc() {
        return totalPurchase * DISCOUNT_RATE;
    }
}
