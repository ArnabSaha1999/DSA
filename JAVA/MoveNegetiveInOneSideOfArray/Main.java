package Arnab.com;

public class Main {

    public static void main(String[] args) {
        MoveNegetiveIntegers moveNegetiveIntegers = new MoveNegetiveIntegers();
        int arr[] = {1,2,3,4,-1,-2,-3,-4,0,-99};
        moveNegetiveIntegers.moveNegetive(arr , arr.length);
    }
}
