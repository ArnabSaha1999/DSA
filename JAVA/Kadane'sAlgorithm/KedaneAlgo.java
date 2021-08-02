package Arnab.com;

public class KedaneAlgo {
    public int maxSubArraySum (int[] a , int n) {
        int temp = 0;
        int sum = a[0];
        for (int i = 0 ; i < n ; i++) {
            temp += a[i];
            if(temp > sum) {    // checks if the temp value is greater than sum if greater then assign temp to sum
                sum = temp;
            }
            if(temp < 0) {  // if the value of temp is less than 0 then assign 0 to temp and start the sum again
                temp = 0;
            }
        }
        return sum;
    }
}
