package PYQ.Card;

public class GoldCard extends CreditCard {
    private static double minSpend = 2000;

    public GoldCard() {
    }

    public GoldCard(int cardNo, String ownerName, int totalTransaction, double totalSpend) {
        super(cardNo, ownerName, totalTransaction, totalSpend);
    }

    @Override
    double calculateRebate() {
        if (super.totalSpend > minSpend) {
            return super.totalSpend * 0.05;
        }
        else {
            return super.totalSpend * 0.01;
        }
    }
}
