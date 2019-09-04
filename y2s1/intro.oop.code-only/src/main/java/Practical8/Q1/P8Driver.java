package Practical8.Q1;

public class P8Driver {
    public static void main(String[] args) {
        Employee[] listOfEmployees = new Employee[]{
                new fullTime("001", "Pinkerton", 500, 800, 100),
                new fullTime("002", "Delta", 300, 1000, 200),
                new fullTime("002", "Delta", 200, 1000, 300),
                new fullTime("002", "Delta", 200, 1000, 0),};

        System.out.println(countDonation(listOfEmployees) + " people out of " + listOfEmployees.length + " people donated");
        System.out.println(totalDonations(listOfEmployees) + " is the total donation amount");
    }

    public static int countDonation(Employee[] employees) {
        int donations = 0;
        if (employees.length == 0) {
            return 0;
        }
        for (Employee e : employees) {
            if (e instanceof fullTime) {
                if (((fullTime) e).getDonationAmt() != 0) {
                    donations++;
                }
            }
        }
        return donations;
    }

    public static double totalDonations(Employee[] employees) {
        double donations = 0;
        if (employees.length == 0) {
            return 0;
        }
        for (Employee e : employees) {
            if (e instanceof fullTime) {
                if (((fullTime) e).getDonationAmt() != 0) {
                    donations += ((fullTime) e).getDonationAmt();
                }
            }
        }
        return donations;
    }
}
