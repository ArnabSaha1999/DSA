#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//Approach 1: Function to interleave the elements of a queue using a stack-based approach.
void interLeaveQueueUsingStack(queue < int > & q) {
    // Initialize an empty stack of int type
    stack<int> s;
    int size = q.size();
    // Push first half elements into the stack.
    for(int i = 0; i < size / 2; i++) {
        s.push(q.front());
        q.pop();
    }
    // Enqueue back the stack elements.
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    // Dequeue the first half elements of queue and enqueue them back.
    for(int i = 0; i < size / 2; i++) {
        q.push(q.front());
        q.pop();
    }
    // Again push the first half elements into the stack.
    for(int i = 0; i < size / 2; i++) {
        s.push(q.front());
        q.pop();
    }
    // Interleave the elements of queue and stack.
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }  
}

//Approach 2: Function to interleave the elements of a queue using a queue-based approach.
void interLeaveQueue(queue < int > & q) {
    queue<int> firstHalf, secondHalf;
    int size = q.size();
    //Push element in the first half of queue
    for(int i = 0; i < size/2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    //pushes the second half of queue
    for(int i = 0; i < size/2; i++) {
        secondHalf.push(q.front());
        q.pop();
    }
    // Interleave and enqueue elements from both halves.
    while(!firstHalf.empty() && !secondHalf.empty()) {
        q.push(firstHalf.front());
        q.push(secondHalf.front());
        firstHalf.pop();
        secondHalf.pop();
    }
} 

int main() {
    queue<int> q,q1;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    q1 = q;
    cout<<"The input Queue: "<<endl;
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;

    q1 = q;

    cout<<"Using the Stack Based approach: "<<endl;
    interLeaveQueueUsingStack(q1);
    
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;

    q1 = q;

    cout<<"Using the Queue Based approach: "<<endl;
    interLeaveQueue(q1);
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    } cout<<endl;

    return 0;
}
