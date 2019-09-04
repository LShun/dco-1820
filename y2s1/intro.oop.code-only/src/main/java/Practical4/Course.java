package Practical4;

public class Course {
    private String courseTitle; // - courseTitle: String
    private double feesPerStudent;
    private int noOfStudents;
    private String[] studentNames;
    private static int courseCount;

    public Course(String courseTitle, double feesPerStudent) {
        this.courseTitle = courseTitle;
        this.feesPerStudent = feesPerStudent;
        this.noOfStudents = 0;
        this.studentNames = new String[100];
        courseCount++;
    }

    public double getFeesPerStudent() {
        return feesPerStudent;
    }

    public String getCourseTitle() {
        return courseTitle;
    }

    public int getNoOfStudents() {
        return noOfStudents;
    }

    public static int getCourseCount() {
        return courseCount;
    }

    public String[] getStudentNames() {
        return studentNames;
    }

    public void setCourseTitle(String courseTitle) {
        this.courseTitle = courseTitle;
    }

    public void setFeesPerStudent(double feesPerStudent) {
        this.feesPerStudent = feesPerStudent;
    }

    public static void setCourseCount(int courseCount) {
        Course.courseCount = courseCount;
    }

    public void setNoOfStudents(int noOfStudents) {
        this.noOfStudents = noOfStudents;
    }

    public void setStudentNames(String[] studentNames) {
        this.studentNames = studentNames;
    }
    public double calcFeesCollected() {
        return this.feesPerStudent * this.noOfStudents;
    }
    public void addStudent(String studName) {
        this.studentNames[this.noOfStudents] = studName;
        this.noOfStudents++;
    }
    // TODO
    public String toString() {
        return ("Course title: " + this.courseTitle + "\n" +
                "Course fees per student: " + this.feesPerStudent + "\n" +
                "Course no of students: " + this.noOfStudents + "\n" +
                "Total fees collected: " + this.calcFeesCollected() + "\n" +
                "Total course count: " + courseCount);
    }
}
