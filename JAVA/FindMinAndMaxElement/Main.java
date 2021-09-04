public class Main {

    public static void main(String[] args) {
        int[] arr = {1,2};
	    MinAndMaxPair pair = new MinAndMaxPair();
	    Pair minMax = pair.findMinAndMax(arr , arr.length);
        System.out.println("The Min element is : " + minMax.min);
        System.out.println("The Max element is : " + minMax.max);
    }
}
