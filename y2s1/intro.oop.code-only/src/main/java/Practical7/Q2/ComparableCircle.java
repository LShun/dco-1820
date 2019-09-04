package Practical7.Q2;

public class ComparableCircle extends Circle implements Comparable, Colorable {
    @Override
    public int compareTo(Object o) {
        if (this.getRadius() > ((Circle) o).getRadius()) {
            return 1;
        }
        else if (this.getRadius() < ((Circle) o).getRadius()) {
            return -1;
        }
        else {
            return 0;
        }
    }

    @Override
    public void howToColor() {

    }
}
