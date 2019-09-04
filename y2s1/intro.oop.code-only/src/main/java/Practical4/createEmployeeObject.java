package Practical4;

public class createEmployeeObject {

    public static void main(String args[]) {
        Employee hire = new Employee("Magic", 10000.40);
        Employee newHire = new Employee("Polars", 12000.50);

        System.out.println("The salary of employee before raise: " + hire.getSalary());
        hire.raiseSalary(8);
        System.out.println("The salary after raise: " + hire.getSalary());

        // Display employee with higher salary


        // Compute and display total salary of 2 employees


    }
    // Employee Employee -> Employee
    // return the employee with the higher salary, if both same, return first one
    public static Employee higherSalary(Employee emp1, Employee emp2) {
        return(emp1.getSalary() >= emp2.getSalary() ? emp1 : emp2);
    }

    // Employee Employee -> Double
    // return the total salary of the 2 employees
    public static double totalSalary(Employee emp1, Employee emp2) {
        return emp1.getSalary() + emp2.getSalary();
    }
}



