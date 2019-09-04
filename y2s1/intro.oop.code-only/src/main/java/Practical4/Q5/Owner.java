package Practical4.Q5;

public class Owner {
    String name;
    String icNo;

    public Owner(String name, String icNo) {
        this.name = name;
        this.icNo = icNo;
    }

    @Override
    public String toString() {
        return String.format("%-18s\t%-12s\t", this.name, this.icNo);
    }
}
