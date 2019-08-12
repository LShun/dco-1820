package Practical8.Q2;

import java.time.LocalDate;
import java.util.Date;

public class InvoiceGenerator {
    public static void main(String[] args) {
        Address[] addresses = {
                new Address("Big Sdn. Bhd.", "23 Jalan D9", "42100", "Selangor"),
                new Address("Tiger Sdn. Bhd.", "25 Jalan 12", "53000", "Kuala Lumpur")};
        Customer[] cust = {
                new Customer("ABC123", addresses[0]),
                new Customer("ABC124", addresses[1])};
        Product[] products = {
                new Product("1111", "Toaster", 90.00),
                new Product("2222", "Electric Iron", 120.00),
                new Product("3333", "Air-conditioner", 1200.00)
        };
        Order[][] ordersArray = {
                new Order[]{
                        new Order(products[0], 3),
                        new Order(products[1], 1)},
                new Order[]{
                        new Order(products[1], 2),
                        new Order(products[2],1)}};
        Invoice[] invoices = {
                new Invoice("INV0001", LocalDate.now(), cust[0], ordersArray[0]),
                new Invoice("INV0002", LocalDate.now(), cust[1], ordersArray[1])};

        for (Invoice i : invoices) {
            System.out.println(i.toString());
        }
    }
}
