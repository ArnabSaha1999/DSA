package Arnab.com;

public class Main {

    public static void main(String[] args) {
	    SelectionSort selectionSort = new SelectionSort();
	    int arr[] = {123,23,23,1,4,55,22,6,-12,0};
        System.out.println("The Array before sorting");
	    for(int i : arr) {
            System.out.print(i + " ");
        }
	    arr = selectionSort.selectionSort(arr , arr.length);
        System.out.println("\nThe Array after Selection sort");
	    for(int i : arr) {
            System.out.print(i + " ");
        }
    }
}
