package Tutorial6.Q6;

public class Q6Driver {
    public static void main(String[] args) {
        FixedDepositAccount fdAcc = new FixedDepositAccount(126, "David", 100, 0.06, 3);
        OverdraftAccount oaPrem = new OverdraftAccount(123, "Adam", 1000, "Premium");
        OverdraftAccount oaGold = new OverdraftAccount(124, "Brian", 30, "Gold");
        OverdraftAccount oaSilver = new OverdraftAccount(125, "Christian", -100, "Silver");

        System.out.println(fdAcc.toString());
        System.out.println(oaPrem.toString());
        System.out.println(oaGold.toString());
        System.out.println(oaSilver.toString());
    }

}
