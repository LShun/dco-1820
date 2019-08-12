package Practical8.Q1;

public class partTime {
    private static double hourlyRate = 5.30;
    private static int hoursWorked;

    public static double getHourlyRate() {
        return hourlyRate;
    }

    public static int getHoursWorked() {
        return hoursWorked;
    }

    public static void setHoursWorked(int hoursWorked) {
        partTime.hoursWorked = hoursWorked;
    }
}
