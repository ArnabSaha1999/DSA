package Arnab.com;

class InsertionSort {
    public int[] insertionSort (int[] arr , int n) {
        int temp;
        for(int i = 1 ; i < n ; i++) {
            temp = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > temp) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
        return arr;
    }
}
