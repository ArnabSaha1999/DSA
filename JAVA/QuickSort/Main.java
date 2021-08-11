package Arnab.com;

public class Main {

    public static void main(String[] args) {
        QuickSort quickSort = new QuickSort();
        int[] arr = {555 , 554};
        System.out.println("Array elements before Sorting");
        for(int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println("\nArray after sorting");
	    arr = quickSort.quickSort(arr , 0 , arr.length-1);
	    for(int i : arr) {
	        System.out.print(i + " ");
        }
    }
}
