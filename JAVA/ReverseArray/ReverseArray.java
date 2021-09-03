package Arnab.com;

class ReverseArray {
    public int[] reverse (int[] arr) {
        for(int i = 0 , j = arr.length - 1 ; i < j ; i++ , j--) {
            arr[i] = arr[i] ^ arr[j];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
        }
        return arr;
    }
    public void printArray (int[] arr) {
        System.out.println("The Array elements are ");
        for(int i : arr) {
            System.out.print(i + " ");
        }
    }
}
