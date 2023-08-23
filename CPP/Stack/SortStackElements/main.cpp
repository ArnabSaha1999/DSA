#include<iostream>
#include<stack>
using namespace std;

// Helper function to push a value in the correct sorted position within the stack
void pushSorted(stack<int> &inputStack, int val) {
    // Base case: if the stack is empty or the value is greater than the top element, push the value
    if(inputStack.empty() || (!inputStack.empty()) && val > inputStack.top()) {
        inputStack.push(val);
        return;
    }
    // Pop the top element and recursively push the value in the correct position
    int element = inputStack.top();
    inputStack.pop();
    pushSorted(inputStack, val);
    inputStack.push(element);
}

//Approach 1: Recursive function to sort the stack
void sortStack(stack<int> &inputStack) {
    if(inputStack.empty()) {
        return;
    }
    // Pop the top element and recursively sort the remaining stack
    int element = inputStack.top();
    inputStack.pop();
    sortStack(inputStack);
    // Push the element in the correct sorted position within the stack
    pushSorted(inputStack, element);
}

//Approach 2: Iterative function to sort the stack
void sortStackIteratively(stack<int> &inputStack) {
    stack<int> auxStack;
    while(!inputStack.empty()) {
        int element = inputStack.top();
        inputStack.pop();
        // Move elements from auxStack to inputStack until the correct position is found
        while(!auxStack.empty() && auxStack.top() < element) {
            inputStack.push(auxStack.top());
            auxStack.pop();
        }
        auxStack.push(element);
    }
    // Transfer sorted elements back from auxStack to inputStack
    while(!auxStack.empty()) {
        inputStack.push(auxStack.top());
        auxStack.pop();
    }
}

int main() {
    stack<int> st, st1, st2;
    st.push(12);
    st.push(23);
    st.push(3);
    st.push(-4);
    st.push(4);
    st.push(66);
    st1 = st;
    st2 = st;

    cout<<"The Stack elements: "<<endl;
    while(!st1.empty()) {
        cout<<st1.top()<<" ";
        st1.pop();
    } cout<<endl;

    cout<<"Sorting the Stack using recursive approach: "<<endl;
    sortStack(st);
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;

    cout<<"Sorting the Stack using iterative approach: "<<endl;
    sortStackIteratively(st2);
    while(!st2.empty()) {
        cout<<st2.top()<<" ";
        st2.pop();
    } cout<<endl;
    
    return 0;
}
