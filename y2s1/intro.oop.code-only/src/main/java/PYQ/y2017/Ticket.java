package PYQ.y2017;

public class Ticket {
    private String ticketId;
    private String park;
    private String ticketType;
    private double price;
    private static int totalNoOfTicket;

    public Ticket() {
        totalNoOfTicket++;
    }

    public Ticket(String ticketId, String park, String ticketType, double price) {
        this.ticketId = ticketId;
        this.park = park;
        this.ticketType = ticketType;
        this.price = price;
        totalNoOfTicket++;
    }

    public String getTicketId() {
        return ticketId;
    }

    public void setTicketId(String ticketId) {
        this.ticketId = ticketId;
    }

    public String getPark() {
        return park;
    }

    public void setPark(String park) {
        this.park = park;
    }

    public String getTicketType() {
        return ticketType;
    }

    public void setTicketType(String ticketType) {
        this.ticketType = ticketType;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public static int getTotalNoOfTicket() {
        return totalNoOfTicket;
    }

    @Override
    public String toString() {
        return String.format("Ticket id: %s\n" +
                "Park: %s\n" +
                "Ticket type: %s\n" +
                "Price: RM%4.2f\n", ticketId, park, ticketType, price);
    }
}
