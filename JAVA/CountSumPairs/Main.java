package Arnab.com;

public class Main {

    public static void main(String[] args) {
        BruteForce bruteForce = new BruteForce();
        int[] arr = {1,4,5,1};
        int res = bruteForce.getPairCount(arr , arr.length , 5);
        System.out.println(res);
    }
}
