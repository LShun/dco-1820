package Practical8.Q1;

public class fullTime extends Employee {
    private double allowance;
    private double basicSalary;
    private double donationAmt;

    public fullTime(String id, String name, double allowance, double basicSalary, double donationAmt) {
        super(id, name);
        this.allowance = allowance;
        this.basicSalary = basicSalary;
        this.donationAmt = donationAmt;
    }

    public fullTime() {};

    public double getAllowance() {
        return allowance;
    }

    public void setAllowance(double allowance) {
        this.allowance = allowance;
    }

    public double getBasicSalary() {
        return basicSalary;
    }

    public void setBasicSalary(double basicSalary) {
        this.basicSalary = basicSalary;
    }

    public double getDonationAmt() {
        return donationAmt;
    }

    public void setDonationAmt(double donationAmt) {
        this.donationAmt = donationAmt;
    }

    @Override
    public String toString() {
        return "fullTime{" +
                ", allowance=" + allowance +
                ", basicSalary=" + basicSalary +
                ", donationAmt=" + donationAmt +
                ", id='" + id + '\'' +
                ", name='" + name + '\'' +
                "} " + super.toString();
    }
}
