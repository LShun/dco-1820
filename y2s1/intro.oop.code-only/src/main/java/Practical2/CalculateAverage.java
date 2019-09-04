package Practical2;

public class CalculateAverage {
    public static void main(String args[]) {
        System.out.println(averageTwoInt(1, 3));
        System.out.println(averageThreeInt(1, 2, 3));
        System.out.println(averageTwoDouble(1.5, 4.5));
        System.out.println(averageThreeDouble(1.5, 3.0, 4.5));
    }

    public static double averageTwoInt(int x, int y) {
        return (((double) x) + ((double) y)) / 2;
    }

    public static double averageThreeInt(int x, int y, int z) {
        return (((double) x) + ((double) y) + ((double) z)) / 2;
    }

    public static double averageTwoDouble(double x, double y) {
        return (x + y) / 2;
    }

    public static double averageThreeDouble(double x, double y, double z) {
        return (x + y + z) / 2;
    }
}
