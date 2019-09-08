package PYQ.y2017;

public class PrepaidPlan extends DataPlan {
    private int validity;

    public PrepaidPlan() {
    }

    public PrepaidPlan(String planId, String planName, int dataSize, double price, int validity) {
        super(planId, planName, dataSize, price);
        this.validity = validity;
    }

    public String toString() {
        return String.format("Prepaid Plan\n" +
                super.toString() +
                "Validity: " + validity + " days\n");
    }
}
