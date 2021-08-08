package Arnab.com;

class MergeSort {
    public void mergeSort(int[] arr , int left , int right) {
        if(left < right) {
            int mid = (left + right) / 2 ;
            mergeSort(arr , left , mid);
            mergeSort(arr , mid+1 , right);
            merge(arr , left , mid , right);
        }
    }

    public void merge(int[] arr , int left , int mid , int right){
        int[] mergedArray = new int[arr.length];
        int i = left , j = mid+1 , k = left;
        while(i <= mid && j <= right) {
            if(arr[i] < arr[j]) {
                mergedArray[k] = arr[i];
                i++;
            } else {
                mergedArray[k] = arr[j];
                j++;
            }
            k++;
        }

        while(j <= right) {
            mergedArray[k] = arr[j];
            j++;
            k++;
        }

        while (i <= mid) {
            mergedArray[k] = arr[i];
            i++;
            k++;
        }

        for(k = left ; k <= right ; k++) {
            arr[k] = mergedArray[k];
        }
    }
    public void printArray(int[] arr) {
        for(int i:arr) {
            System.out.print(i + " ");
        }
    }
}
