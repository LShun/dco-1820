package PYQ.y2017;

public class TicketDriver {
    public static void main(String[] args) {
        Ticket t = new Ticket();
        t.setTicketId("P01C");
        t.setPark("Water Park");
        t.setTicketType("Children");
        t.setPrice(20);

        Ticket t2 = new Ticket("P02A", "Adventure Park", "Adult", 45);

        System.out.println(t);
        System.out.println(t2);

        System.out.println("Total no. of tickets: " + Ticket.getTotalNoOfTicket());
    }
}
