package Arnab.com;

public class Main {

    public static void main(String[] args) {
        RotateArray rotateArray = new RotateArray();
        int[] arr = {1,2,3,4,5};
        int[] arr1 = rotateArray.rotate(arr , arr.length);
        for(int i : arr1) {
            System.out.println(i);
        }
    }
}
