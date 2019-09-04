package Practical8.Q2;

public class Customer {
    private String custId;
    private Address add;

    public Customer() {
    }

    public Customer(String custId, Address add) {
        this.custId = custId;
        this.add = add;
    }

    public String getCustId() {
        return custId;
    }

    public void setCustId(String custId) {
        this.custId = custId;
    }

    public Address getAdd() {
        return add;
    }

    public void setAdd(Address add) {
        this.add = add;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "custId='" + custId + '\'' +
                '}';
    }
}
