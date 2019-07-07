package Practical4.Q5;

public class Car {
    private String plateNo, color;
    private int year;
    private CarType carType;

    public Car(String plateNo, String color, int year, CarType carType) {
        this.plateNo = plateNo;
        this.color = color;
        this.year = year;
        this.carType = carType;
    }

    @Override
    public String toString() {
        return String.format("%-8s\t%-10s\t%-6s\t", this.plateNo, this.color, this.year) + this.carType;
    }
}
