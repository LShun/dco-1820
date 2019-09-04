package Lecture5;

public class StringBuilderTest {
    public static void main(String args[]) {
        StringBuilder stringBuilder = new StringBuilder("Welcome to ");
        stringBuilder.append("Java"); // builder contains "Welcome to Java"

        stringBuilder.insert(11, "HTML and ");
        stringBuilder.delete(8,11);
        stringBuilder.reverse();
        stringBuilder.replace(11, 15, "HTML");
        stringBuilder.setCharAt(0, 'w');

        System.out.println(stringBuilder);
    }
}
