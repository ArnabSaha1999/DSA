#include <iostream>
#define SIZE 10
using namespace std;
class Stack{
    //creates a stack with the initialized SIZE and top of the stack set to -1
    int stack[SIZE] , top = -1;
public:
    //checks if the stack is empty
    bool isEmpty() {
        if(top == -1){
            return true;
        }
        return false;
    }
//    checks if the stack is full
    bool isFull() {
        if(top == SIZE-1) {
            return true;
        }
        return false;
    }
//pushes an element onto the stack
    void push(int element) {
        if(isFull()){
            cout << "Stack Overflow"<<endl;
        }
        else{
            top++;
            stack[top] = element;
        }
    }
//    pops an element out of the stack
    int pop() {
        if(isEmpty()) {
            cout << "Stack Underflow"<<endl;
            return -1;
        }
        top--;
        return stack[top+1];
    }
    //seeks the top element of the stack
    int seek() {
        return stack[top];
    }
    //displays the stack
    void display() {
        if(isEmpty()) {
            cout << "The Stack is Empty"<<endl;
        }
        else{
            for(int i = 0 ; i <= top; i++) {    //loops over the elements of the stack
                cout << stack[i]<< " ";
            }
            cout<<endl;
        }
    }

};
int main() {
    Stack stack;
    stack.push(23);
    stack.push(22);
    cout<<stack.seek()<<endl;
    stack.push(21);
    cout<<stack.pop()<<endl;
    stack.push(20);
    stack.display();
    return 0;
}
