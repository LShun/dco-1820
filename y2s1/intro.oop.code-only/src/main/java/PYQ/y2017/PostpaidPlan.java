package PYQ.y2017;

public class PostpaidPlan extends DataPlan {
    private int freeTalkTime;
    private int freeSms;

    public PostpaidPlan() {
    }

    public PostpaidPlan(String planId, String planName, int dataSize, double price, int freeTalkTime, int freeSms) {
        super(planId, planName, dataSize, price);
        this.freeTalkTime = freeTalkTime;
        this.freeSms = freeSms;
    }

    public String toString() {
        return "Postpaid Plan\n" +
                super.toString() +
                "Free call: " + freeTalkTime + " minutes\n" +
                "Free sms: " + freeSms + " sms" + "\n";
    }
}
