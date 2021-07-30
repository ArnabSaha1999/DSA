package Arnab.com;

public class Stack {
    //creates an empty stack of the SIZE and top of with -1
    private int SIZE = 10;
    private int[] stack = new int[SIZE];
    private int top = -1;
    //checks if the stack is empty
    public boolean isEmpty() {
        if(top == -1){
            return true;
        }
        return false;
    }
    //checks if the stack is full
    public boolean isFull() {
        if(top >= SIZE-1) {
            return true;
        }
        return false;
    }
    //pushes an element onto the stack
    public void push(int element){
        if(isFull()){
            System.out.println("Stack Overflow");
        }else {
            top++;
            stack[top] = element;
        }
    }
    //pops an element out of the stack
    public int pop() {
        if(isEmpty()){
            System.out.println("Stack Underflow");
            return -1;
        }
        top--;
        int element = stack[top+1];
        return element;
    }
    //seeks the top element of the stack
    public int seek() {
        return stack[top];
    }
    //displays the elements of the stack
    public void display() {
        if(isEmpty()){
            System.out.println("Stack is Empty.");
        }else{
            for(int i = 0 ; i <= top ; i++) {   //loops through all the elements of the stack
                System.out.println(stack[i]);
            }
        }
    }
}
