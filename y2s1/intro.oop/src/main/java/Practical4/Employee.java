package Practical4;

public class Employee {
    private String name, address, company;
    private int age;
    private double salary;

    public Employee(String employeeName, double currentSalary) {
        name = employeeName;
        salary = currentSalary;
    }

    public void raiseSalary(double percent) {
        salary = salary + (salary * percent / 100.0);
    }

    public String getName() {
        return name;
    }

    public void setName(String nName) {
        name = nName;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double nSalary) {
        salary = nSalary;
    }

    public String getAddress() {
        return address;
    }

    public String getCompany() {
        return company;
    }

    public void setAddress(String nCompany) {
        company = nCompany;
    }

    public void setCompany(String nAddress) {
        address = nAddress;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int nAge) {
        age = nAge;
    }

    public void emptyName() {
        name = "";
    }


}