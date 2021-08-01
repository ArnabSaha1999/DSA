package Arnab.com;

public class MoveNegetiveIntegers {
    public void moveNegetive (int[] a , int n) {
        int temp , j = 0;
        for(int i = 0 ; i < n ; i++) {
            if(a[i] < 0) {
                if(i != j) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
                j++;
            }
        }
        printArray(a);
    }
    private void printArray (int [] a) {
        for(int i : a) {
            System.out.print(i + " ");
        }
    }
}
