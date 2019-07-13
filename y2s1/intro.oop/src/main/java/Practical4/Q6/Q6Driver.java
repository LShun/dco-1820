package Practical4.Q6;

import java.util.Scanner;

public class Q6Driver {
    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        Cake[] cakeMenu = {new Cake("Chocolate Moist", 40.00), new Cake("Strawberry", 50.00), new Cake("Blueberry", 45.00), new Cake("American Chocolate", 55.00), new Cake("Tiramisu", 30.00)};

        System.out.println("Mickey Cake House\n");
        System.out.print("How many types of cake you would like to order: ");
        int orders = in.nextInt();
        Order[] cakeOrders = new Order[orders];

        for (int i = 0; i < orders; i++) {
            System.out.println();
            System.out.println("No Flavours						1kg			\t2kg			\t3kg");
            for (Cake c : cakeMenu) {
                System.out.printf("%d. %-24s RM %6s\t\tRM %6s\t\tRM %6s\n", c.getCakeNo(), c.getFlavor(), String.format("%6.2f", c.getBasePrice()), String.format("%6.2f", (c.getBasePrice() * 2)) , String.format("%6.2f", (c.getBasePrice() * 3)));
            }
            System.out.println();

            System.out.println("Cake item " + (i+1));
            System.out.println("-----------");
            System.out.print("Enter your choice of cake flavor (1 - " + cakeMenu.length + "): ");
            int choice = in.nextInt();
            System.out.print("Enter the weight of the cake (1 - 1kg, 2 - 2kg and 3 - 3kg): ");
            int weight = in.nextInt();
            System.out.print("Enter quantity ordered: ");
            int qty = in.nextInt();

            cakeOrders[i] = new Order(cakeMenu[choice-1], weight, qty);
        }

        System.out.println();

        System.out.println("Order Details: ");
        System.out.println("----------------");
        System.out.println("No\tCake Flavour\t\tWeight\t\tUnit Price(RM)\tQuantity\tTotal Price(RM)");
        System.out.println("--  ------------   \t    ------\t\t--------------\t--------    --------------");

        System.out.println();

        double grandTotal = 0;
        for (int i = 0; i < cakeOrders.length; i++) {
            double price = cakeOrders[i].getCake().basePrice * cakeOrders[i].getWeight();
            double netTotal = cakeOrders[i].getQty() * price;
            System.out.printf("%d\t%-19s %6d      %13.2f %10d    %14.2f\n", i+1, cakeOrders[i].getCake().getFlavor(), cakeOrders[i].getWeight(), price, cakeOrders[i].getQty(), cakeOrders[i].getQty() * price);
            grandTotal += netTotal;
        }

        System.out.println("------------------------------------------------------------------------------");
        System.out.printf("                                                    Grand Total: RM %10.2f\n", grandTotal);

    }
}
