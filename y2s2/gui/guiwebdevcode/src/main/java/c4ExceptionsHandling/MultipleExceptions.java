package c4ExceptionsHandling;

import javax.swing.*;

public class MultipleExceptions {
    public static void main(String[] args) {
        int[] studentMarks = {90, 70, 85, 52, 92};
        int classSize = 0;
        int totalMarks = 0;

        try {
            JOptionPane.showMessageDialog(null, "*** TRACE: In try block");
            for (int i = 0; i < studentMarks.length; i++) {
                totalMarks += studentMarks[i];
            }
            int classAverage = totalMarks / classSize;
            JOptionPane.showMessageDialog(
                    null, "Class Average Mark: " + classAverage);
            JOptionPane.showMessageDialog(null, "***TRACE: Exiting try block");
        }
        catch (ArrayIndexOutOfBoundsException ex) {
            JOptionPane.showMessageDialog(null, "***TRACE: In first catch block");
            JOptionPane.showMessageDialog(
                    null, "Out of Bounds. Valid index range is from 0..." +
                            (studentMarks.length - 1), "ERROR", JOptionPane.ERROR_MESSAGE);
        }
        catch (ArithmeticException ex) {
            JOptionPane.showMessageDialog(null, "***TRACE: 2nd block");
            JOptionPane.showMessageDialog(null, "Division by 0", "ERROR",
                    JOptionPane.ERROR_MESSAGE);
            JOptionPane.showMessageDialog(null, "***TRACE: Exit 2nd catch block");
        }
    }
}
