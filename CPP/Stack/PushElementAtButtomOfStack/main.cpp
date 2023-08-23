#include<iostream>
#include<stack>

using namespace std;

// Recursively pushes the given value at the bottom of the stack
void pushAtBottom(stack<int>&inputStack, int val) {
    // Base case: if the stack is empty, push the value and return
    if(inputStack.empty()) {
        inputStack.push(val);
        return;
    }
    // Pop the top element and recurse to push the value at the bottom
    int element = inputStack.top();
    inputStack.pop();
    // Recursive call for the remaining elements
    pushAtBottom(inputStack, val);
    // Push back the stored element
    inputStack.push(element);
}

//Approach 1: Function to push the given value at the bottom of the stack using recursion
stack<int> pushAtBottomRecusively(stack<int> &inputStack, int val) {
    pushAtBottom(inputStack, val);
    return inputStack;
}

//Approach 2: Function to push the given value at the bottom of the stack using iteration
stack<int> pushAtBottomIteratively(stack<int> &inputStack, int val) {
    stack<int> tempStack;
    // Transfer elements from inputStack to tempStack
    while(!inputStack.empty()) {
        tempStack.push(inputStack.top());
        inputStack.pop();
    }
    // Push the value at the bottom of inputStack
    inputStack.push(val);
    // Transfer elements back from tempStack to inputStack
    while(!tempStack.empty()) {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
    return inputStack;
}

int main() {
    stack<int> st, st1;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    st1 = st;
    cout<<"The Stack elements: "<<endl;
    while(!st1.empty()) {
        cout<<st1.top()<<" ";
        st1.pop();
    } cout<<endl;

    st = pushAtBottomIteratively(st, 0);
    cout<<"After adding element at the bottom of Stack: "<<endl;
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;

    return 0;
}
