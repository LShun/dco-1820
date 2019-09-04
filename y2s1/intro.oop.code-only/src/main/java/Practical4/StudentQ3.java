package Practical4;

public class StudentQ3 {
    private String ID, name;
    private int quizTaken, totalQuizScore;
    private static double quizContribution;

    public StudentQ3() {
        this("", "", 0, 0);

        System.out.println("New blank student created with all fields either blank or zero");
    }

    public StudentQ3(String ID, String name, int qt, int ts) {
        this.ID = ID;
        this.name = name;
        this.quizTaken = qt;
        this.totalQuizScore = ts;
    }

    public String getID() {
        return ID;
    }

    public int getQuizTaken() {
        return quizTaken;
    }

    public int getTotalQuizScore() {
        return totalQuizScore;
    }

    public String getName() {
        return name;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setQuizTaken(int quizTaken) {
        this.quizTaken = quizTaken;
    }

    public void setTotalQuizScore(int totalQuizScore) {
        this.totalQuizScore = totalQuizScore;
    }

    // each quiz is worth 10 marks
    public void addQuiz(int score) {
        this.quizTaken += score / 10;
    }

    // gets the total score for all the quiz
    public int getTotalScore() {
        return this.quizTaken * 10;
    }

    // gets average score
    public double getAverageScore() {
        return (double) this.getTotalQuizScore() / this.getQuizTaken();
    }

    public static double getQuizContribution() {
        return quizContribution;
    }

    public static void setQuizContribution(double quizContribution) {
        StudentQ3.quizContribution = quizContribution;
    }

    public double getContributionScore() {
        return StudentQ3.quizContribution * (double) getTotalQuizScore() / getTotalScore() * 100;
    }
}
