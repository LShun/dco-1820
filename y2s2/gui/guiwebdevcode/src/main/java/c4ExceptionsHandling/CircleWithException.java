package c4ExceptionsHandling;

// Example of an unchecked exception
// Note: You only need to declare exceptions with throws
//       for checked exceptions. IllegalArgumentException
//       is an unchecked exception. Therefore it is not
//       necessary.

public class CircleWithException {
    double radius;

    public void setRadius(double radius) {
        if (radius > 0)
            this.radius = radius;
        else
            throw new IllegalArgumentException("Radius cannot be negative.");
    }
}
