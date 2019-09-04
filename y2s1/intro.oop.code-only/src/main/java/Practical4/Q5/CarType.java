package Practical4.Q5;

public class CarType {
    private String make, model;
    private double capacity;

    public CarType(String make, String model, double capacity) {
        this.make = make;
        this.model = model;
        this.capacity = capacity;
    }

    @Override
    public String toString() {
        return String.format("%-10s\t%-10s\t%-10s", this.make, this.model, this.capacity);
    }
}
