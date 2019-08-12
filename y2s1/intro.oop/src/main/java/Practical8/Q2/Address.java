package Practical8.Q2;

public class Address {
    private String building;
    private String street;
    private String po;
    private String state;

    public Address() {
    }

    public Address(String building, String street, String po, String state) {
        this.building = building;
        this.street = street;
        this.po = po;
        this.state = state;
    }

    public String getBuilding() {
        return building;
    }

    public void setBuilding(String building) {
        this.building = building;
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getPo() {
        return po;
    }

    public void setPo(String po) {
        this.po = po;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    @Override
    public String toString() {
        return "Address{" +
                "building='" + building + '\'' +
                ", street='" + street + '\'' +
                ", po='" + po + '\'' +
                ", state='" + state + '\'' +
                '}';
    }
}
