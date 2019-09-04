package Practical4.Q5;

import java.util.Scanner;

public class P4Q5Driver {

    public static void main(String args[]) {

        // Constants
        final int totalRecords = 2;  // Modify this to change number of records
        final CarType[] carTypeList = {new CarType("Toyota", "Vios", 1.5),
                new CarType("Nissan", "Teana", 2.0),
                new CarType("Honda", "City", 1.6)};

        // Program variables
        Car[] carList = new Car[totalRecords];
        Registration[] registrations = new Registration[totalRecords];
        Owner[] ownerList = new Owner[totalRecords];
        int selection;
        CarType userCarType;
        Scanner in = new Scanner(System.in);

        // Owner
        String name, icNo;

        // Car
        String plateNo, color;
        int year, carType;

        for (int i = 0; i < totalRecords; i++) {
            carList[i] = getCar(carTypeList, in);
            ownerList[i] = getOwner(in);
            registrations[i] = new Registration(ownerList[i], carList[i]);
        }
        System.out.printf("\n%70s\n", "Car Registration Listing");
        System.out.printf("%-8s\t%-18s\t%-12s\t%-8s\t%-10s\t%-6s\t%-10s\t%-10s\t%-10s\n", "Reg No.", "Name", "IC No.", "Plate No.", "Color", "Year", "Make", "Model", "Capacity");

        for (int i = 0; i < registrations.length; i++) {
            System.out.println(registrations[i].toString());
        }
    }

    private static Owner getOwner(Scanner in) {
        String name;
        String icNo;
        System.out.print("Enter name: ");
        name = in.nextLine();

        System.out.print("Enter IC: ");
        icNo = in.nextLine();

        return new Owner(name, icNo);
    }

    private static Car getCar(CarType[] carTypeList, Scanner in) {
        String plateNo;
        String color;
        int year;
        int selection;
        System.out.print("Enter plate number: ");
        plateNo = in.nextLine();

        System.out.print("Enter color: ");
        color = in.nextLine();

        System.out.print("Enter year: ");
        year = in.nextInt();
        in.nextLine();

        System.out.println("Please select a car type: ");
        for (int j = 0; j < carTypeList.length; j++) {
            System.out.println("Enter " + (j+1) + " for: ");
            System.out.println(carTypeList[j].toString());
            System.out.println();
        }
        System.out.print("Enter your selection: ");
        selection = in.nextInt() - 1;
        in.nextLine();

        return new Car(plateNo,color,year,carTypeList[selection]);
    }
}
