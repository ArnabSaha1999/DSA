package Arnab.com;

class RotateArray {
    public int[] rotate (int[] arr , int n) {
        for(int i = 0 ; i < n ; i++) {      //changing the index of array and then swapping the index and last element
            int temp = arr[i];
            arr[i] = arr[n-1];
            arr[n-1] = temp;
        }
        return arr;
    }
}
