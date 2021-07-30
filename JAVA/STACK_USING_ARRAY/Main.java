package Arnab.com;

public class Main {

    public static void main(String[] args) {
	    Stack stack = new Stack();
		stack.display();
	    stack.push(10);
	    stack.push(11);
	    stack.push(12);
	    stack.push(13);
	    System.out.println("The Popped element is : "+stack.pop());
	    stack.push(14);
	    System.out.println("Top element of the stack is : " + stack.seek());
	    stack.display();
	    ReverseString reverseString = new ReverseString();
	    char[] s = {'h' , 'i' , ' ' , 't' , 'h' , 'e' , 'r' , 'e'};
	    char[] p = {'a' , 'b' , 'b' , 'a' , 'a'};
	    reverseString.reverseString(s);
	    Palindrome palindrome = new Palindrome();
	    System.out.println(palindrome.isPalindrome("abba"));
	    StringOrdering str = new StringOrdering();
	    System.out.println(str.isinOrder("abc"));
	    System.out.println(str.isinOrder("123"));
	    System.out.println(str.isinOrder("xyzz"));
	    System.out.println(str.isinOrder("edabit"));
    }
}
