package Practical8.Q2;

import java.time.LocalDate;

public class Invoice {
    private String invNo;
    private LocalDate date;
    private Customer cust;
    private Order[] orders;

    public Invoice() {};

    public Invoice(String invNo, LocalDate date, Customer cust, Order[] orders) {
        this.invNo = invNo;
        this.date = date;
        this.cust = cust;
        this.orders = orders;
    }

    public String getInvNo() {
        return invNo;
    }

    public void setInvNo(String invNo) {
        this.invNo = invNo;
    }

    public Customer getCust() {
        return cust;
    }

    public void setCust(Customer cust) {
        this.cust = cust;
    }

    public String stringOrders() {
        StringBuilder orderList = new StringBuilder();
        for (Order o : orders) {
            orderList.append(o.toString());
        }
        return orderList.toString();
    }

    public void setOrders(Order[] orders) {
        this.orders = orders;
    }

    @Override
    public String toString() {
        if (this.date == null) return "";
        else {
            return String.format(
                    "                               INVOICE              " + "\n" +
                            "                                               Invoice No: " + invNo + '\n' +
                            "                                                     Date: " + date + "\n" +
                            "                                                 Cust. ID: " + cust.getCustId() + "\n" +
                            "BILL  TO: " + "\n" +
                            "       " + cust.getAdd().getBuilding()+ "\n" +
                            "       " + cust.getAdd().getStreet() + "\n" +
                            "       " + cust.getAdd().getPo() + "\n" +
                            "       " + cust.getAdd().getState() + "\n" +
                            "-----------------------------------------------------------------------\n" +
                            "Product No  Description          Qty      Unit Price(RM)  Line Total(RM) \n" +
                            stringOrders() +
                            "-----------------------------------------------------------------------\n" +
                            "Grand Total:                                               RM%10.2f  \n", calculateGrandTotal());
        }
    }

    public double calculateGrandTotal() {
        double total = 0;
        for (Order o : orders) {
            total += (o.getProduct().getUnitPrice() * o.getQty());
        }
        return total;
    }
}
