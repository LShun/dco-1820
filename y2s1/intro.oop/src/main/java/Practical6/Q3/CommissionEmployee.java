package Practical6.Q3;

public class CommissionEmployee extends Employee {
    private double grossSale;
    private double commissionRate;

    public CommissionEmployee() {
    }

    public CommissionEmployee(String name, int yearJoined, double basicSalary, double grossSale, double commissionRate) {
        super(name, yearJoined, basicSalary);
        this.grossSale = grossSale;
        this.commissionRate = commissionRate;
    }

    public double getGrossSale() {
        return grossSale;
    }

    public void setGrossSale(double grossSale) {
        this.grossSale = grossSale;
    }

    public double getCommissionRate() {
        return commissionRate;
    }

    public void setCommissionRate(double commissionRate) {
        this.commissionRate = commissionRate;
    }

    @Override
    public String toString() {
        return "CommissionEmployee{" +
                super.toString() + "," +
                "grossSale=" + grossSale +
                ", commissionRate=" + commissionRate +
                '}';
    }

    public double calculateSalary() {
        return this.getBasicSalary() + this.grossSale * this.commissionRate;
    }
}
