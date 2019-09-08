package PYQ.y2017;

public class DataPlanDriver {
    public static void main(String[] args) {
        DataPlan[] dataPlans = {new PostpaidPlan("POS89", "Happy Moments", 15, 78, 200, 1000),
        new PrepaidPlan("PRE153", "Smart Traveler", 3, 28, 7)};

        for (DataPlan d : dataPlans) {
            System.out.println(d);
        }
    }
}
