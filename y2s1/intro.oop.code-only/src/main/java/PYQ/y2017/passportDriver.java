package PYQ.y2017;

public class passportDriver {
    public static boolean verifyPassportNo(String passportNo) {
        if (passportNo.length() != 9) {return false;}
        if (passportNo.charAt(0) != 'A' && passportNo.charAt(0) != 'H' && passportNo.charAt(0) != 'K') {return false;}
        for (int i = 1; i < passportNo.length(); i++) {
            if (!Character.isDigit(passportNo.charAt(i))) {return false;}
        }
        return true;
    }
}
