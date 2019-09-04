import java.util.List;

public class errorFullProgram {
    public static void switchCasePrimer() {
        int caseIndex = 0;
        switch (caseIndex) {
            case 0:
                System.out.println("Zero");
            case 1:
                System.out.println("One");
                break;
            case 2:
                System.out.println("Two");
                break;
            default:
                System.out.println("Default");
        }
    }
    public static void oneMillionHello() {
        String oneMillionHello = "";
        for (int i = 0; i < 1000000; i++) {
            oneMillionHello = oneMillionHello + "Hello!";
        }
        System.out.println(oneMillionHello.substring(0, 6));
    }

}
