package Practical4;

public class CourseDriver {
    public static void main(String args[]) {
        Course introComp = new Course("Introduction to Computers", 250);

        introComp.addStudent("Ali Said");
        introComp.addStudent("Wong Ken");
        introComp.addStudent("Peter Lim");

        System.out.println(introComp.toString());
        System.out.println("\nStudents in course: ");
        for (int i = 0; i < introComp.getNoOfStudents(); i++) {
            System.out.println(introComp.getStudentNames()[i]);
        }
    }
}
