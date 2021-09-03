public class Main {

    public static void main(String[] args) {
        int[] arr = {1 , 2 , 3 , 4 , 5 , 6};
        ReverseArray reverseArray = new ReverseArray();
        arr = reverseArray.reverse(arr);
        reverseArray.printArray(arr);
    }
}
