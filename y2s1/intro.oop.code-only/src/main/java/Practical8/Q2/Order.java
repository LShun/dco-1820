package Practical8.Q2;

class Order {
    int qty;
    Product product;

    public Order(Product product, int qty) {
        this.product = product;
        this.qty = qty;
    }

    public Order() {
    }

    public Product getProduct() {
        return product;
    }

    public void setProduct(Product product) {
        this.product = product;
    }

    public int getQty() {
        return qty;
    }

    public void setQty(int qty) {
        this.qty = qty;
    }

    public double getOrderTotal() {
        return qty * product.getUnitPrice();
    }

    @Override
    public String toString() {
        // "Product No  Description          Qty      Unit Price(RM)  Line Total(RM) \n"
        return String.format("%-10s  %-19s  %2d  %18.2f  %14.2f\n", product.getProdNum(), product.getDesc(), qty, product.getUnitPrice(), getOrderTotal());
    }
}
