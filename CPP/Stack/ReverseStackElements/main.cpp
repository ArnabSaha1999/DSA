#include<iostream>
#include<stack>
#include<queue>

using namespace std;

// Recursively pushes the given value at the bottom of the stack
void pushAtBottom(stack<int> &inputStack, int val) {
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

//Approach 1: Reverses the stack using recursion
void reverseStack(stack<int> &inputStack) {
    if(inputStack.empty()) {
        return;
    }
    // Pop the top element
    int element = inputStack.top();
    inputStack.pop();
    // Recursively reverse the remaining stack
    reverseStack(inputStack);
    // Push the popped element to the bottom
    pushAtBottom(inputStack, element);
}

//Approach 2: Reverses the stack using an auxiliary stack
void reverseStackUsingStack(stack<int> &inputStack) {
    if(inputStack.empty() || inputStack.size() == 1) {
        return;
    }
    stack<int> st;
    // Transfer elements from inputStack to auxStack
    while(!inputStack.empty()) {
        st.push(inputStack.top());
        inputStack.pop();
    }
    // Transfer elements back from auxStack to inputStack (reversed order)
    inputStack = st;
}

//Approach 3: Reverses the stack using a queue
void reverseStackUsingQueue(stack<int> &inputStack) {
    if(inputStack.empty() || inputStack.size() == 1) {
        return;
    }
    queue<int> q;
    // Transfer elements from inputStack to a queue
    while(!inputStack.empty()) {
        q.push(inputStack.top());
        inputStack.pop();
    }
    // Transfer elements back from the queue to inputStack (reversed order)
    while(!q.empty()) {
        inputStack.push(q.front());
        q.pop();
    }
}

int main() {
    stack<int> st, st1, st2, st3;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    st1 = st;
    st2 = st;
    st3 = st;

    cout<<"The Stack elements: "<<endl;
    while(!st1.empty()) {
        cout<<st1.top()<<" ";
        st1.pop();
    } cout<<endl;

    reverseStack(st);
    cout<<"The Stack after reversing using Recursion: "<<endl;
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;
    
    st = st2;
    reverseStackUsingStack(st);
    cout<<"The Stack after reversing using Auxiliary Stack: "<<endl;
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;

    st = st3;
    reverseStackUsingStack(st);
    cout<<"The Stack after reversing using Queue: "<<endl;
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;

    st2.empty();
    st3.empty();

    return 0;
}
