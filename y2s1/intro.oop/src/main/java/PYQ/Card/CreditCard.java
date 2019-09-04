package PYQ.Card;

abstract class CreditCard {
    protected int cardNo;
    protected String ownerName;
    protected int totalTransaction;
    protected double totalSpend;

    public CreditCard() {
    }

    public CreditCard(int cardNo, String ownerName, int totalTransaction, double totalSpend) {
        this.cardNo = cardNo;
        this.ownerName = ownerName;
        this.totalTransaction = totalTransaction;
        this.totalSpend = totalSpend;
    }

    abstract double calculateRebate();

    @Override
    public String toString() {
        return "CreditCard{" +
                "cardNo=" + cardNo +
                ", ownerName='" + ownerName + '\'' +
                ", totalTransaction=" + totalTransaction +
                ", totalSpend=" + totalSpend +
                '}';
    }
}
