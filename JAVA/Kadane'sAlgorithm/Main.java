package Arnab.com;

public class Main {

    public static void main(String[] args) {
        KedaneAlgo kedaneAlgo = new KedaneAlgo();
        int[] arr = {-2 , -3 , 4 , -3 , 1 , 0 , 1};
        int res = kedaneAlgo.maxSubArraySum(arr , arr.length);
        System.out.println(res);
    }
}
