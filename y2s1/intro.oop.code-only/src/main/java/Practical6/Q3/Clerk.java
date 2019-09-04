package Practical6.Q3;

import java.util.Objects;

public class Clerk extends Employee {
    private double allowance;
    private int overtimeHours;
    private static double overtimeRate;

    public Clerk() {
    }

    public Clerk(String name, int yearJoined, double basicSalary, double allowance, int overtimeHours) {
        super(name, yearJoined, basicSalary);
        this.allowance = allowance;
        this.overtimeHours = overtimeHours;
    }

    public double getAllowance() {
        return allowance;
    }

    public void setAllowance(double allowance) {
        this.allowance = allowance;
    }

    public int getOvertimeHours() {
        return overtimeHours;
    }

    public void setOvertimeHours(int overtimeHours) {
        this.overtimeHours = overtimeHours;
    }

    public static double getOvertimeRate() {
        return overtimeRate;
    }

    public static void setOvertimeRate(double overtimeRate) {
        Clerk.overtimeRate = overtimeRate;
    }

    @Override
    public String toString() {
        return "Clerk{" + super.toString() + "," +
                "allowance=" + allowance +
                ", overtimeHours=" + overtimeHours +
                '}';
    }
}
