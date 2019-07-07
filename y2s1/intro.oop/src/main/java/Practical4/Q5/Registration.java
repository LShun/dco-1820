package Practical4.Q5;

import java.util.concurrent.atomic.AtomicInteger;

public class Registration {
    private static AtomicInteger totalReg = new AtomicInteger(0);
    private int regNo = totalReg.incrementAndGet();
    private Owner owner;
    private Car car;

    public Registration(Owner owner, Car car) {
        this.owner = owner;
        this.car = car;
    }

    @Override
    public String toString() {
        return String.format("%-8s\t", regNo) + owner.toString() + car.toString();
    }
}
