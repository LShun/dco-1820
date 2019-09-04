package Practical4;

import org.junit.Test;

import static org.junit.Assert.*;

public class createEmployeeObjectTest {

    @Test
    public void higherSalary() {
        // emp1 > emp2
        Employee emp1 = new Employee("Wing", 15000.23);
        Employee emp2 = new Employee("Wong", 12000.23);
        assertEquals(emp1, createEmployeeObject.higherSalary(emp1,emp2));

        // emp1 = emp2
        emp1 = new Employee("Wing", 12000.23);
        emp2 = new Employee("Wong", 12000.23);
        assertEquals(emp1, createEmployeeObject.higherSalary(emp1,emp2));

        // emp1 < emp2
        emp1 = new Employee("Wing", 5000.23);
        emp2 = new Employee("Wong", 9000.23);
        assertEquals(emp2, createEmployeeObject.higherSalary(emp1,emp2));

    }

    @Test
    public void totalSalary() {
        Employee emp1 = new Employee("Wing", 15000.23);
        Employee emp2 = new Employee("Wong", 12000.27);
        assertEquals(27000.50, createEmployeeObject.totalSalary(emp1,emp2), 0.01);
    }
}