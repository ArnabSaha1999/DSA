package Arnab.com;

class RecursiveBinarySearch {
    public int binarySearch (int[] arr , int key , int low , int high) {
        int mid = (low + high)/2;
        if(low > high) {
            return -1;
        }
        if(arr[mid] == key) {
            return mid;
        }
        if(arr[mid] < key) {
            return binarySearch(arr , key , mid+1 , high);
        }
        return binarySearch(arr , key , low , mid-1);
    }

}
