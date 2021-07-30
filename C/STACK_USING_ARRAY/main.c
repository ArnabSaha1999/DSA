#include <stdio.h>
#include <conio.h>
#define SIZE 10
//creates an empty stack of initialized SIZE , top of -1 and length of 0
int stack[SIZE];
int top = -1 , length = 0;
//checks if the stack is empty
void is_empty() {
    if(top == -1){
        printf("Stack is Empty.\n");
    }
}
//checks if the stack is full
void is_full() {
    if(top == SIZE-1) {
        printf("Stack is Full.\n");
    }
}
//pushes an element onto the stack
void push(int element){
    if(SIZE <= length) {
        printf("Stack Overflow\n");
    }
    else{
        top = top+1;
        stack[top] = element;
        length++;
    }
}
//pops and element out of the stack
int pop() {
    if(top == -1){
        printf("Stack Underflow\n");
        return 0;
    }
    top = top - 1;
    int element = stack[top+1];
    stack[top+1] = NULL;
    length--;
    return element;
}
//checks the length of the stack
int stack_length() {
    return length;
}
//seeks the top element of the stack
int seek() {
    return stack[top];
}
//displays the element of the stack
void display() {
    if(top == -1){
        printf("Stack Underflow\n");
    }
    for(int i = 0 ; i < length ; i++){  //loops through all the elements of the stack
        printf("  %d" , stack[i]);
    }
    printf("\n");
}
int main() {
    is_empty();
    printf("Stack length is %d \n" , stack_length());
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    printf("Stack length is %d \n" , stack_length());
    push(8);
    push(9);
    push(10);
    is_full();
    printf("Popped Out element is %d \n" ,pop());
    push(11);
    printf("Popped Out element is %d \n" ,pop());

    printf("Element at top : %d \n" , seek());
    display();
    return 0;
}
