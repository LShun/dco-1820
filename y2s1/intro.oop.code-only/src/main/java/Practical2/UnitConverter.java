package Practical2;

public class UnitConverter {

    public static void main(String args[]) {
        System.out.printf("%-12s%-20s%-12s%-10s\n", "Inches", "Centimeters", "Centimeters", "Inches");
        // print integers, then centimeters, then centimeters, then integers
        for (double i = 0.0; i < 10; i++)
            System.out.printf("%-12.1f%-20.2f%-12.1f%-10.2f\n", i, UnitConverter.inchToCentimeter(i), (i * 5), UnitConverter.centimeterToInch((i * 5)));

    }

    // Double -> Double
    /** Converts from inches to centimeters */
    public static double inchToCentimeter(double in) {
        return in * 2.54;
    }

    // Double -> Double
    /** Converts from centimeters to inches */
    public static double centimeterToInch(double cm) {
        return cm / 2.54;
    }
}
