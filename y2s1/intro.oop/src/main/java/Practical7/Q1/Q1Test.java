package Practical7.Q1;

public class Q1Test {
    public static void main(String[] args) {
        PatientBill[] patientBillArray = {new OutpatientBill("1", "Pinkerton", 120), new OutpatientBill("2", "Turnip", 80), new InpatientBill("3", "Godilock", 120, 60, 'S', 3), new InpatientBill("4", "Calidron", 120, 80, 'P', 4)};
        for (PatientBill p : patientBillArray) {
            System.out.println(p.toString());
        }

        System.out.println(computeTotalCollection(patientBillArray));
    }

    public static double computeTotalCollection(PatientBill[] patientBills) {
        double total = 0;
        for (PatientBill p : patientBills) {
            total += p.calculateTotalCharges();
        }
        return total;
    }
}
