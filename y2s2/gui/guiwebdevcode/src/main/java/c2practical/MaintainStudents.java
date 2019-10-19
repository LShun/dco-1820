package c2practical;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class MaintainStudents extends JFrame {
    private JButton createBtn = new JButton("Create");
    private JButton retrieveBtn = new JButton("Retrieve");
    private JButton updateBtn = new JButton("Update");
    private JButton deleteBtn = new JButton("Delete");
    private ArrayList<String> students = new ArrayList<>();

    private MaintainStudents() {
        // add elements
        setLayout(new FlowLayout());
        add(createBtn);
        add(retrieveBtn);
        add(updateBtn);
        add(deleteBtn);

        createBtn.addActionListener(new Create());
        retrieveBtn.addActionListener(new Retrieve());
        updateBtn.addActionListener(new Update());
        deleteBtn.addActionListener(new Delete());
    }

    // Listeners

    // EFFECTS: Add a new student into students
    private class Create implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = JOptionPane.showInputDialog("Enter new student's name:");
            if (name != null) {
                students.add(name);
            }
        }
    }

    // EFFECTS: Obtain a list of student names
    private class Retrieve implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            StringBuilder stud = new StringBuilder();
            if (students.size() == 0) {
                JOptionPane.showMessageDialog(null, "No student in system");
            }
            else {
                for (int i = 0; i < students.size(); i++) {
                    stud.append(i).append(1).append(". ").append(students.get(i)).append("\n");
                }
                JOptionPane.showMessageDialog(null, stud);
            }
        }
    }

    // EFFECTS: Change a student name.
    private class Update implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // ask for student name
            String name = JOptionPane.showInputDialog("Enter name: ");

            if (name != null) {
                int selected = getStudent(name);

                if (selected == -1) {
                    JOptionPane.showMessageDialog(null, "Can't find " + name,
                            "Error", JOptionPane.ERROR_MESSAGE);
                }
                else {
                    // ask for new student name
                    String newName = JOptionPane.showInputDialog("Enter new name: ");
                    // change name
                    students.set(selected, newName);
                    // display change
                    JOptionPane.showMessageDialog(null,
                            name + " changed to " + newName, "Confirmation",
                            JOptionPane.INFORMATION_MESSAGE);
                }
            }
        }
    }

    private int getStudent(String name) {
        int selected = -1;

        if (students.size() == 0) {
            return -1;
        }
        for (int i = 0; i < students.size(); i++) {
            if (name.equals(students.get(i))) {
                selected = i;
                break;
            }
        }
        return selected;
    }

    // EFFECT: Delete a student name from students.
    private class Delete implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // ask for student name
            String name = JOptionPane.showInputDialog("Enter name: ");
            int stud = getStudent(name);

            if (name == null) {
                return;
            }

            if (stud == -1) {
                JOptionPane.showMessageDialog(null, "Can't find " + name,
                        "Error", JOptionPane.ERROR_MESSAGE);
            }
            else {
                students.remove(stud);
            }
        }
    }

    public static void main(String[] args) {
        MaintainStudents ms = new MaintainStudents();
        ms.setTitle("Maintain Students");
        ms.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ms.pack();
        ms.setVisible(true);
    }
}
