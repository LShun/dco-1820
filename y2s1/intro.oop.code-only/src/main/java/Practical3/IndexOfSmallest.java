package Practical3;

public class IndexOfSmallest {
    public static void main(String args[]) {
        int[] loi = {1, 2, 4, 5, 10, 100, 2, -22};

        int si = SmallestLocation(loi);
        System.out.printf("Index of smallest number (smallest index) is %d\n", si);
    }

    // (listofInteger) -> Integer
    // return the index with the smallest number, if multiple smallest number are found, return the smallest index containing the smallest number
    public static int SmallestLocation(int[] loi) {
        int index = 0;
        int smallest = loi[0];
        for (int i = 1; i < loi.length; i++) {
            if (loi[i] < smallest) {
                index = i;
                smallest = loi[i];
            }
        }
        return index;
    }
}
