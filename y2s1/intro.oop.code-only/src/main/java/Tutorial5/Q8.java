package Tutorial5;

public class Q8{
    public static void main(String[] args){
        String s = "Java";
        StringBuffer buf = new StringBuffer(s);
        change(s, buf);
        System.out.println(s);
        System.out.println(buf);
    }

    public static void change(String s, StringBuffer b){
        s = s + " and html";
        b.append(" and html");
    }
}
