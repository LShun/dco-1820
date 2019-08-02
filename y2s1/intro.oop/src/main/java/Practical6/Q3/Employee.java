package Practical6.Q3;

import java.util.Objects;

public class Employee {
    private String name;
    private int yearJoined;
    private double basicSalary;

    public Employee() {}

    public Employee(String name, int yearJoined, double basicSalary) {
        this.name = name;
        this.yearJoined = yearJoined;
        this.basicSalary = basicSalary;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getYearJoined() {
        return yearJoined;
    }

    public void setYearJoined(int yearJoined) {
        this.yearJoined = yearJoined;
    }

    public double getBasicSalary() {
        return basicSalary;
    }

    public void setBasicSalary(double basicSalary) {
        this.basicSalary = basicSalary;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", yearJoined=" + yearJoined +
                ", basicSalary=" + basicSalary +
                '}';
    }

    public double calculateSalary() {
        return this.basicSalary;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null) return false;
        Employee employee = (Employee) o;
        return this.getName().equals(employee.getName());
    }
}
