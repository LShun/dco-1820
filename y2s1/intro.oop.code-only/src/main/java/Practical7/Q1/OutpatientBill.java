package Practical7.Q1;

public class OutpatientBill extends PatientBill {
    private static double registrationFee = 30.00;
    private double consultationFees;

    public OutpatientBill() {};

    public OutpatientBill(String visitId, String name,double consultationFees) {
        super(visitId, name);
        this.consultationFees = consultationFees;
    }

    @Override
    public double calculateTotalCharges() {
        return registrationFee + consultationFees;
    }

    @Override
    public String toString() {
        return "OutpatientBill{" +
                "consultationFees=" + consultationFees +
                "} " + super.toString();
    }
}
