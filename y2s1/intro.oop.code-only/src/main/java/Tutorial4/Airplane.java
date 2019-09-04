package Tutorial4;

public class Airplane {
    String id;
    static double price;
    static int yearOfPurchased, numOfPassenger;
    static int numOfAirplane;

    public Airplane() {
        this.id = "";
        this.price = 0.00;
        this.yearOfPurchased = 2001;
        this.numOfPassenger = 600;
        numOfAirplane++;
        /* WHY WE CANNOT USE THIS
        ("", 0.00, 2001, 600);
         */
    }

    public Airplane(String id, double price, int yearOfPurchased, int numOfPassenger) {
        this.id = id;
        this.price = price;
        this.yearOfPurchased = yearOfPurchased;
        this.numOfPassenger = numOfPassenger;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setNumOfPassenger(int numOfPassenger) {
        this.numOfPassenger = numOfPassenger;
    }

    public String getId() {
        return id;
    }

    public double getPrice() {
        return price;
    }

    public int getYearOfPurchased() {
        return yearOfPurchased;
    }

    public int getNumOfPassenger() {
        return numOfPassenger;
    }

    public int getNumOfAirplane() {
        return numOfAirplane;
    }

    public double calCurrentValue() {
        double currentValue = price - (price * 0.1 * (2011 - yearOfPurchased));

        if (currentValue < 0) {
            currentValue = 0;
        }
        return currentValue;
    }

    public String toString() {
        return ("ID: " + id + "\n" +
                "Price: " + price + "\n" +
                "YearOfPurchased: " + yearOfPurchased + "\n" +
                "numOfPassenger: " + numOfPassenger + "\n");
    }
}