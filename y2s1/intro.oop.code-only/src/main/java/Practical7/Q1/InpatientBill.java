package Practical7.Q1;

public class InpatientBill extends PatientBill {
    private static double standardRoom = 100;
    private static double privateRoom = 200;

    private double specialistCharges;
    private double labCharges;
    private char roomType;
    private int durationOfStay;

    public InpatientBill() {};

    public InpatientBill(String visitId, String name, double specialistCharges, double labCharges, char roomType, int durationOfStay) {
        super(visitId, name);
        this.specialistCharges = specialistCharges;
        this.labCharges = labCharges;
        this.roomType = roomType;
        this.durationOfStay = durationOfStay;
    }

    @Override
    public double calculateTotalCharges() {
        double roomRate;
        if (roomType == 'S') {
            roomRate = standardRoom;
        }
        else {
            roomRate = privateRoom;
        }

        return specialistCharges + labCharges + (durationOfStay * roomRate);
    }

    @Override
    public String toString() {
        return "InpatientBill{" +
                "specialistCharges=" + specialistCharges +
                ", labCharges=" + labCharges +
                ", roomType=" + roomType +
                ", durationOfStay=" + durationOfStay +
                "} " + super.toString();
    }


}