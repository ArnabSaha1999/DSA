package Arnab.com;

class SelectionSort {
    public int[] selectionSort(int [] arr , int n) {
        for(int i = 0 ; i < n ; i++) {
            int min = i;
            for(int j = i+1; j < n ; j++) {
                if(arr[j] < arr[min]) {
                    min = j;
                }
            }
            if(min != i) {
                this.swap(arr , i , min);
            }
        }
        return arr;
    }
    public void swap (int [] arr , int i , int min) {
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
