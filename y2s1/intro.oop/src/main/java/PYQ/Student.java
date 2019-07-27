package PYQ;

public class Student {
    String name;
    int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    Student[] student = new Student[10];

    public void setStudent() {
        student[1].age = 21;
    }

}
