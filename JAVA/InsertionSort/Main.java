package Arnab.com;

public class Main {

    public static void main(String[] args) {
	    InsertionSort insertionSort = new InsertionSort();
	    int[] arr = {6,3,1,9,3,8,6,6,0,99,12,-22,23};
		System.out.println("The Array before sorting");
		for(int i: arr) {
			System.out.print(i + " ");
		}
		System.out.println("\nThe Array after Insertion sort");
	    arr = insertionSort.insertionSort(arr , arr.length);
	    for(int i : arr) {
	        System.out.print(i + " ");
        }
    }
}
