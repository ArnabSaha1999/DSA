package Arnab.com;

public class Main {

    public static void main(String[] args) {
        int[] arr = {1,4,5,7,2,0,-1};
        MergeSort mergeSort = new MergeSort();
        mergeSort.mergeSort(arr , 0 , arr.length-1);
        mergeSort.printArray(arr);
    }
}
