package Practical7.Q1;

abstract class PatientBill {
    protected String visitId;
    protected String name;

    public PatientBill() {};

    public PatientBill(String visitId, String name) {
        this.visitId = visitId;
        this.name = name;
    }

    abstract double calculateTotalCharges();

    @Override
    public String toString() {
        return "PatientBill{" +
                "visitId='" + visitId + '\'' +
                ", name='" + name + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        PatientBill that = (PatientBill) o;

        return name != null ? name.equals(that.name) : that.name == null;
    }
}
