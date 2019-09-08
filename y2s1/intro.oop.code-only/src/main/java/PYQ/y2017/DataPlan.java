package PYQ.y2017;

public abstract class DataPlan {
    protected String planId;
    protected String planName;
    protected int dataSize;
    protected double price;

    public DataPlan() {
    }

    public DataPlan(String planId, String planName, int dataSize, double price) {
        this.planId = planId;
        this.planName = planName;
        this.dataSize = dataSize;
        this.price = price;
    }

    @Override
    public String toString() {
        return String.format("Plan id: %s\n" +
                "Plan name: %s\n" +
                "Data size: %dGB\n" +
                "Price: RM%4.2f\n", planId, planName, dataSize, price);
    }
}
