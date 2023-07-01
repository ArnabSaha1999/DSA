#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
    stack<int> stack, stack1, stack2;

    // Push elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);

    // Print the top element
    cout<<"Top element: "<<stack.top()<<endl;

    // Check if the stack is empty
    if(stack.empty()) {
        cout<<"Stack is empty."<<endl;
    } else {
        cout<<"Stack is not empty."<<endl;
    }

    // Get the size of the stack
    cout<<"Size of stack: "<<stack.size()<<endl;

    // Pop elements from the stack and print
    cout<<"Printing Stack elements: ";
    while(!stack.empty()) {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<endl;

    stack1.push(55);
    stack1.push(45);
    stack1.push(88);
    stack1.push(89);
    stack2.swap(stack1); // Swap the contents of stack1 and stack2

    if(stack1.empty()) {
        cout<<"Stack1 is Empty after swapping with Stack2"<<endl;
    }

    stack2 = stack1; //Assign Stack1 to Stack2
    if(stack1.empty() && stack2.empty()) {
        cout<<"Now both the stacks are empty";
    }
    return 0;
}
