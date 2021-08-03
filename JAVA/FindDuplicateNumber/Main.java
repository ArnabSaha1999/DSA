package Arnab.com;

public class Main {

    public static void main(String[] args) {
        BruteForce bruteForce = new BruteForce();
        int[] arr = {1,2,3,3,4};
        int res = bruteForce.findDuplicate(arr);
        System.out.println(res);
    }
}
