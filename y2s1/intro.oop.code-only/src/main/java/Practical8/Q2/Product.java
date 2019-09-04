package Practical8.Q2;

public class Product {

    private String prodNum;
    private String desc;
    private double unitPrice;

    public Product() {
    }

    public Product(String prodNum, String desc, double unitPrice) {
        this.prodNum = prodNum;
        this.desc = desc;
        this.unitPrice = unitPrice;
    }

    public String getProdNum() {
        return prodNum;
    }

    public void setProdNum(String prodNum) {
        this.prodNum = prodNum;
    }

    public String getDesc() {
        return desc;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public double getUnitPrice() {
        return unitPrice;
    }

    public void setUnitPrice(double unitPrice) {
        this.unitPrice = unitPrice;
    }

    @Override
    public String toString() {
        return "Product{" +
                "prodNum='" + prodNum + '\'' +
                ", desc='" + desc + '\'' +
                ", unitPrice=" + unitPrice +
                '}';
    }
}
