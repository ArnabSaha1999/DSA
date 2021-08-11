class QuickSort {
    public int[] quickSort(int[] arr , int low , int high) {
        if(low < high) {
            int pivot = partition(arr , low , high);
            quickSort(arr , low , pivot-1);
            quickSort(arr , pivot+1 , high);
        }
        return arr;
    }
    public int partition (int[] arr , int low , int high) {
        int i = low , j = high , pivot = arr[low];
        while(i < j) {
            while(pivot >= arr[i] && i < high){
                i++;

            }
            while(pivot < arr[j] && j > 0){
                j--;
            }
            if(i < j) {
                this.swap(arr , i , j);
            }
        }
        this.swap(arr, low , j);
        return j;
    }
    public void swap(int[] arr , int first , int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
