package Arnab.com;

class IterativeBinarySearch {
    public int binarySearch(int[] arr , int key , int low , int high) {
        while(low <= high) {
            int mid = (low+high)/2;
            if(arr[mid] == key) {
                return mid;
            } else if(arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
}
