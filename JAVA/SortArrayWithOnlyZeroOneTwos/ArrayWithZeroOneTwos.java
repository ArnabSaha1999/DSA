package Arnab.com;

public class ArrayWithZeroOneTwos {
    public void sort012(int[] a , int n) {
        int mid = 0 , low = 0 , temp = 0;
        int high = n - 1;
        while(mid <= high) {
            switch(a[mid]) {
                case 0 :
                    temp = a[low];
                    a[low] = a[mid];
                    a[mid] = temp;
                    mid++;
                    low++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    temp = a[high];
                    a[high] = a[mid];
                    a[mid] = temp;
                    high--;
                default:
                    break;
            }
        }
        printArray(a);
    }
    private void printArray (int[] a) {
        for(int i:a){
            System.out.print(i + " ");
        }
    }
}
