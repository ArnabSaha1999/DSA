package Arnab.com;

class BruteForce {
    public int getPairCount(int arr[] , int n , int k) {
        int count = 0;
        for(int i = 0 ; i < n ; i ++) {
            for(int j = i+1 ; j < n ; j++) {
                if(arr[i] + arr[j] == k) {
                    System.out.println(arr[i] + "+" +arr[j]);
                    count++;
                }
            }
        }
        return count;
    }
}
