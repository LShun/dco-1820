package c4ExceptionsHandling;

import javax.swing.*;

public class UncheckedException {
    public static void main(String[] args) {
        String[] students = {"Clark Kent", "Natalie Teeger", "Adrian Monk",
                "Kevin Rudd", "Jessica Tandy"};
        String input = JOptionPane.showInputDialog("Enter index[1.." + students.length + "]");
        int index = Integer.parseInt(input) - 1;
        JOptionPane.showMessageDialog(null, "Student #" + input + ": " + students[index]);
    }
}
