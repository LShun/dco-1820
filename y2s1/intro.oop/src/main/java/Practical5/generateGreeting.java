package Practical5;

public class generateGreeting {
    /*
        Assumptions on format of input:
            - Surname always have [] between them
            - The salutation is always placed at the last
     */
    public static void main(String args[]) {
        String surname = getSurname(args);
        String salutation = args[args.length - 1];
        String fName = formatName(args);
        System.out.println("To: " + fName);
        System.out.println("Wishing you have a Merry Christmas, " + salutation + " " + getSurname(args));
    }

    public static String getSurname(String[] name) {
        for (String s: name) {
            if (s.startsWith("[")) {
                return s.substring(1, 2).toUpperCase() + s.substring(2, s.length() - 1).toLowerCase();
            }
        }
        return "";
    }

    public static String formatName(String[] name) {
        StringBuilder fName = new StringBuilder();

        for (int i = 0; i < name.length - 1; i++) {
            if (i != 0) {
                fName.append(" ");
            }
            if (name[i].startsWith("[")) {
                fName.append(name[i].substring(1, 2).toUpperCase() + name[i].substring(2, name[i].length() - 1).toLowerCase());
            }
            else {
                fName.append(name[i].substring(0, 1).toUpperCase() + name[i].substring(1).toLowerCase());
            }
        }
        return fName.toString();
    }
}
