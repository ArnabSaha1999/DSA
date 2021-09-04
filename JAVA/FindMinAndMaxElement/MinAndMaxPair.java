package Arnab.com;

class MinAndMaxPair {
    public Pair findMinAndMax (int[] arr , int n) {
        Pair minAndMaxPair = new Pair();
        if(n == 1) {
            minAndMaxPair.min = minAndMaxPair.max = arr[0];
            return minAndMaxPair;
        }
        if(arr[0] < arr[1]) {
            minAndMaxPair.min = arr[0];
            minAndMaxPair.max = arr[1];
        } else {
            minAndMaxPair.min = arr[1];
            minAndMaxPair.max = arr[0];
        }
        for(int i = 2 ; i < n ; i++) {
            if(minAndMaxPair.min > arr[i]) {
                minAndMaxPair.min = arr[i];
            } else if(minAndMaxPair.max < arr[i]) {
                minAndMaxPair.max = arr[i];
            }
        }
        return minAndMaxPair;
    }
}
