package Tutorial4;

public class AirplaneDriver {
    public static void main(String args[]) {
        Airplane a1 = new Airplane();
        Airplane a2 = new Airplane("XYZ001", 250000, 2005, 100);

        a1.setId("AWX003");
        a1.setNumOfPassenger(190);

        // SOP = a1.toString() + a1.calCurrentValue;
        // SOP = a2.toString() + a2.calCurrentValue;
    }


}
