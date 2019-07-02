package Lecture4a;

class Circle {
    private double radius;
    private static int numberOfObjects = 0;

    public Circle(double radius) {
        this.radius = radius;
        numberOfObjects++;
    }
    public Circle() {
        this(1.0);
    }
    public double getRadius() {
        return radius;
    }
    public void setRadius(double radius) {
        this.radius = radius;
    }
    public static int getNoOfObjects() {
        return numberOfObjects;
    }
    public double findArea() {
        return Math.PI * radius * radius;
    }
}
