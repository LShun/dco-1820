package Lecture4a;

public class testVehicle {
    public static void main(String args[]) {
        Vehicle car = new Vehicle();
        car.plateNo = "WWW 1234";
        car.passengers = 4;
        car.fuelCap = 20;
        car.mpg = 10;

        System.out.print("Plate No. " + car.plateNo);
    }
}
