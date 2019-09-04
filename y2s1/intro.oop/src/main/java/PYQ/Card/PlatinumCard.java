package PYQ.Card;

public class PlatinumCard extends CreditCard {
    private static int minTransaction = 10;

    public PlatinumCard() {
    }

    public PlatinumCard(int cardNo, String ownerName, int totalTransaction, double totalSpend) {
        super(cardNo, ownerName, totalTransaction, totalSpend);
    }

    @Override
    double calculateRebate() {
        return 0;
    }

    @Override
    public String toString() {
        return "PlatinumCard{" +
                "cardNo=" + cardNo +
                ", ownerName='" + ownerName + '\'' +
                ", totalTransaction=" + totalTransaction +
                ", totalSpend=" + totalSpend +
                "} " + super.toString();
    }
}
