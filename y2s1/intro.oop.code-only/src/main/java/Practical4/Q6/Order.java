package Practical4.Q6;

public class Order {
    private Cake cake;
    private int weight;
    private int qty;

    public Order() {
        this.cake = new Cake();
        this.weight = 0;
        this.qty = 0;
    }

    public Order(Cake cake, int weight, int qty) {
        this.cake = cake;
        this.weight = weight;
        this.qty = qty;
    }

    public Cake getCake() {
        return cake;
    }

    public void setCake(Cake cake) {
        this.cake = cake;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getQty() {
        return qty;
    }

    public void setQty(int qty) {
        this.qty = qty;
    }
}
