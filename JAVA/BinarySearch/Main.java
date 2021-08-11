package Arnab.com;

public class Main {

    public static void main(String[] args) {
        RecursiveBinarySearch recursiveBinarySearch = new RecursiveBinarySearch();
        int[] arr = {-33 , -22 , -13 , 0 , 2 , 8, 44 , 66 , 78 , 90 , 110};
        int res = recursiveBinarySearch.binarySearch(arr , -33 , 0 , arr.length-1);
        System.out.println(res);
    }
}
