package Lecture4a;

public class TestCircle {
    public static void main(String[] args) {
        Circle circle1 = new Circle();
        Circle circle2 = new Circle(5);
        Circle circle3 = new Circle(17);

        System.out.println("circle1: radius = " +
                            circle1.getRadius() + "\n\t area = " +
                            circle1.findArea()  + "\nNo. of objects = "
                            + circle2.getNoOfObjects());

        System.out.println("Practical7.Q2.Circle.getNoOfObjects() = " + Circle.getNoOfObjects());
    }
}