package c4ExceptionsHandling;

import java.io.FileNotFoundException;
import java.io.PrintWriter;

// EXAMPLE of a checked exception, FileNotFoundException, being properly caught
public class CheckedException3 {
    public static void main(String[] args) throws FileNotFoundException {
        PrintWriter output = new PrintWriter("testfile.txt");
        output.println("Welcome to Java");
        if (output != null)
            output.close();
    }
}