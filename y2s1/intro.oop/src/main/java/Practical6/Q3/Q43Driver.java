package Practical6.Q3;

public class Q43Driver {

    public static void main(String[] args) {
        Employee[] empArray = new Employee[] {new Employee("Pink", 0, 0.0), new Clerk("Pink", 0, 0.0, 0.0, 0), new CommissionEmployee("Pink", 0, 0, 0, 0)};
        printElements(empArray);
        System.out.println(empArray[1].equals(empArray[2]));
    }
    public static void printElements(Employee[] emp) {
        for (Employee e : emp) {
            System.out.println(e.toString());
        }
    }
}
