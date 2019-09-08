package PYQ.y2018;

public class VerifyBookID {
    public static boolean verifyBookId(String id) {
        if (id.length() != 10) {return false;}
        for (int i = 0; i < 5; i++) {
            if (!Character.isDigit(id.charAt(i))) {return false;}
        }
        if (id.charAt(5) != '_') {return false;}
        for (int i = 6; i < 10; i++) {
            if (!Character.isDigit(id.charAt(i))) {return false;}
        }
        int year = Integer.parseInt(id.substring(6,10));
        return year >= 2013 && year <= 2018;
    }
}
