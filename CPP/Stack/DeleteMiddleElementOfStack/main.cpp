#include<iostream>
#include<stack>

using namespace std;

// Recursive function to delete middle element
void solve(stack<int> &inputStack, int size, int count) {
    // If we have reached the middle element, pop it and return
    if(count == size / 2) {
        inputStack.pop();
        return;
    }
    // Pop the current element and store it
    int element = inputStack.top();
    inputStack.pop();
    // Recursive call for the remaining elements
    solve(inputStack, size, count + 1);
    // Push back the stored element
    inputStack.push(element);
}

//Approach 1: Function to delete the middle element from the stack using recursion
void deleteMiddleElement(stack<int> &inputStack, int size) {
    solve(inputStack, size, 0);
}

//Approach 2: Function to remove the middle element from the stack using iteration
void removeMiddleElement(stack<int> &inputStack, int size) {
    // Calculate the middle index
    int middle = size / 2;
    // Create a temporary stack to store half of the elements
    stack<int> tempStack;
    // Move the first half of elements to tempStack
    for(int i = 0; i < middle; i++) {
        tempStack.push(inputStack.top());
        inputStack.pop();
    }
    // Skip the middle element
    inputStack.pop();
    // Move elements back to inputStack
    while(!tempStack.empty()) {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> st, st1;
    st.push(13);
    st.push(89);
    st.push(2);
    st.push(44);
    st.push(7);
    st.push(34);
    st.push(22);

    st1 = st;
    cout<<"The Stack elements: "<<endl;
    while(!st1.empty()) {
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<endl;

    cout<<"The Stack after deleting middle element: "<<endl;
    deleteMiddleElement(st, st.size());
    // removeMiddleElement(st, st.size());
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;
    return 0;
}
