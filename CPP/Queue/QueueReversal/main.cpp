#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

//Approach 1: Function to reverse a queue using a stack
void reverseUsingStack(queue<int> &q) {
    stack<int> st;
    // Move all elements from the queue to the stack
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    // Move elements from the stack back to the queue to reverse their order
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

//Approach 2: Function to reverse a queue using an array
void reverseUsingArray(queue<int> &q) {
    int size = q.size();
    vector<int> nums(size);
    // Copy elements from the queue to the array in reverse order
    for(int i = size - 1; i >= 0; i--) {
        nums[i] = q.front();
        q.pop();
    }
    // Copy elements from the array back to the queue to reverse their order
    for(int i = 0; i < size; i++) {
        q.push(nums[i]);
    }
}

//Approach 3: Function to reverse a queue using recursion
void reverseRecursively(queue<int> &q) {
    if(q.empty()) {
        return;
    }
    int front = q.front();
    q.pop();
    // Recursively reverse the remaining elements in the queue
    reverseRecursively(q);
    // Push the front elements back in reverse order
    q.push(front);
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    queue<int> q1 = q;

    cout<<"The Input Queue: "<<endl;
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;

    q1 = q;
    cout<<"After reversing the queue using stack: "<<endl;
    reverseUsingStack(q1);
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;

    q1 = q;
    cout<<"After reversing the queue using array: "<<endl;
    reverseUsingArray(q1);
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;

    q1 = q;
    cout<<"After reversing the queue using recursion: "<<endl;
    reverseRecursively(q1);
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;
    
    return 0;
}
