package Practical4;

public class Staff {
    String name, address, company;
    int age;

    Staff(String staffName, String staffAddress, String staffCompany, int staffAge) {
        name = staffName;
        address = staffAddress;
        age = staffAge;
    }

    String getName() {
        return name;
    }

    void setName(String nName) {
        name = nName;
    }

    String getAddress() {
        return address;
    }

    String getCompany() {
        return company;
    }

    void setAddress(String nCompany) {
        company = nCompany;
    }

    void setCompany(String nAddress) {
        address = nAddress;
    }

    int getAge() {
        return age;
    }

    void setAge(int nAge) {
        age = nAge;
    }
}