#include<iostream>
#include<stack>

using namespace std;

// Queue class implemented using two stacks
class Queue {
    stack<int> st1, st2;
public:

    // Constructor to initialize the queue
    Queue() {
        
    }
    
    // Method to push an element into the queue
    void push(int x) {
        // Transfer elements from st1 to st2
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        // Push the new element onto st1
        st1.push(x);
        // Transfer elements back from st2 to st1 to maintain the order
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    // Method to pop the front element from the queue
    int pop() {
        if(st1.empty()) {
            return -1;
        }
        int deleteFront = st1.top();
        st1.pop();
        return deleteFront;
    }
    
    // Method to get the front element of the queue
    int getFront() {
        if(st1.empty()) {
            return -1;
        }
        return st1.top();
    }

    // Method to get the size of the queue
    int getSize() {
        return st1.size();
    }
    
    // Method to check if the queue is empty
    bool empty() {
        if(st1.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<"The Front element of Queue: "<<q.getFront()<<endl;
    cout<<"The Size of Queue: "<<q.getSize()<<endl;
    cout<<"The popped element of Queue: "<<q.pop()<<endl;

    cout<<"The Front element of Queue: "<<q.getFront()<<endl;
    q.push(4);
    cout<<"The Size of Queue: "<<q.getSize()<<endl;

    return 0;
}

