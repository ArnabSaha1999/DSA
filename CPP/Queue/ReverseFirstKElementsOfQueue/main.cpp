#include<iostream>
#include<queue>
#include<stack>

using namespace std;

//Approach 1: Function to reverse the first 'k' elements of a queue using a stack
queue<int> reverseKElementUsingStack(queue<int> q, int k) {
    stack<int> st;
    // Push the first 'k' elements into the stack to reverse their order
    for(int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }
    // Move the reversed elements from the stack back to the queue
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
     // Move the remaining elements to the front of the queue
    int tempSize = q.size() - k;
    for(int i = 0; i < tempSize; i++) {
        q.push(q.front());
        q.pop();
    }
    return q;
}

// Recursive function to move the first 'k' elements of a queue to the end
void solve(queue<int> &q, int k, int count) {
    if(k == count) {
        return;
    }
    int front = q.front();
    q.pop();
    // Recursively reverse the remaining elements in the queue
    solve(q, k, count + 1);
    // Push the front elements back in reverse order
    q.push(front);
}

//Approach 2: Function to reverse the first 'k' elements of a queue using recursion
queue<int> reverseKElementUsingRecursion(queue<int> q, int k) {
    solve(q,k,0);
    // Move the remaining elements to the front of the queue
    int tempSize = q.size() - k;
    for(int i = 0; i < tempSize; i++) {
        q.push(q.front());
        q.pop();
    }
    return q;
}   

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    queue<int> q1 = q;

    cout<<"The Input Queue: "<<endl;
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;
    
    cout<<"The Queue after reversing first "<<k<<" elements using stack: "<<endl;
    q1 = reverseKElementUsingStack(q, k);
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;

    cout<<"The Queue after reversing first "<<k<<" elements using recursion: "<<endl;
    q1 = reverseKElementUsingRecursion(q, k);
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;

    return 0;
}
